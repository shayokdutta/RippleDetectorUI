#include "channelselection.h"

ChannelDataTable::ChannelDataTable(QObject *parent)
    : QAbstractTableModel(parent), numColumns(5), numRows(1) // Assuming you want 5 columns and at least 1 row initially
{
    // Initialize the first row with headers
    rows.append({"Channel", "μ", "σ", "RD?", "FD?"});
}

void ChannelDataTable::setChannels() {
    RDChans.clear();  // Clear the existing channels
    FDChan = -1;  // Reset FDChan

    // Iterate over each row, skipping the header row
    qDebug() << "Channels for ripple detection are as follows:";
    for (uint row = 1; row < numRows; ++row) {  // Start from 1 to skip header
        bool ok;
        int channelNum = rows[row][0].toInt(&ok);  // Convert the first column data to int
        if (!ok) {
            qDebug() << "Conversion to int failed for row" << row;
            continue;
        }

        // Check if the first checkbox (RD?) is true
        if (checkboxStates[row - 1][0]) {
            RDChans.append(channelNum);  // Append the number to RDChans
            qDebug() << channelNum;
        }

        // Check if the second checkbox (FD?) is true
        if (checkboxStates[row - 1][1]) {
            FDChan = channelNum;  // Store the number in FDChan
        }
    }
    if(RDChans.size() == 0){
        qDebug() << "NO CHANNELS SELECTED?";
    }
    if(FDChan!=-1){
        qDebug() << "False Detection Channel Set to " + QString::number(FDChan);
    }
    else{
        // Emit a signal or perform other actions if needed
        emit channelsUpdated();  // Assuming you have declared this signal
    }
}

int ChannelDataTable::rowCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : numRows;
}

int ChannelDataTable::columnCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : numColumns;
}

QVariant ChannelDataTable::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= numRows || index.column() >= numColumns) {
//        qDebug() << "Invalid index or out of bounds: Row" << index.row() << "Column" << index.column();
        return QVariant();
    }

    if (role == DisplayTextRole) {
        if (index.row() < rows.size() && index.column() < rows.at(index.row()).size()) {
            return rows.at(index.row()).at(index.column());
        } else {
//            qDebug() << "Attempt to access out-of-bounds element in rows";
            return QVariant();
        }
    } else if (role == IsHeaderRole) {
        return index.row() == 0; // True for the header row
    }

    // Checkboxes are in the last two columns for non-header rows
    if (role == IsCheckBoxRole && index.row() > 0) {
        if (index.column() == numColumns - 2 || index.column() == numColumns - 1) {
            return true;
        }
        return false;
    }

    // Return the checkbox state for non-header rows
    if (role == CheckBoxStateRole && index.row() > 0) {
        int checkboxIndex = index.column() - numColumns + 2;
        if (checkboxIndex >= 0 && checkboxIndex < checkboxStates.at(index.row() - 1).size()) {
            return checkboxStates.at(index.row() - 1).at(checkboxIndex);
        } else {
//            qDebug() << "Attempt to access out-of-bounds element in checkboxStates";
            return false;
        }
    }

    return QVariant();
}

QModelIndex ChannelDataTable::index(int row, int column, const QModelIndex &parent) const {
    if (parent.isValid() || row >= rowCount() || column >= columnCount()) {
        return QModelIndex();  // Returns an invalid index
    }
    return createIndex(row, column);
}


bool ChannelDataTable::setData(int row, int column, const QVariant &value, int role){
    QModelIndex index = this->index(row, column, QModelIndex()); // Create the QModelIndex
    if (!index.isValid())
        return false;
    if (role == CheckBoxStateRole && index.row() > 0) { // Skip header row
        int adjustedRow = index.row() - 1;
        int checkboxIndex = index.column() - numColumns + 2;
        if (adjustedRow >= 0 && adjustedRow < checkboxStates.size() &&
            checkboxIndex >= 0 && checkboxIndex < checkboxStates[adjustedRow].size()) {
            bool checked = value.toBool();
            checkboxStates[adjustedRow][checkboxIndex] = checked;
            // If the FD checkbox is being checked, uncheck all other FD checkboxes
            if (index.column() == numColumns - 1 && checked) {
                for (int row = 0; row < checkboxStates.size(); ++row) {
                    if (row != adjustedRow) {
                        checkboxStates[row][1] = false;  // Uncheck FD checkbox in other rows
                        QModelIndex otherIndex = this->index(row + 1, index.column(), QModelIndex());
                        emit dataChanged(otherIndex, otherIndex, QVector<int>() << CheckBoxStateRole);
                    }
                }
            }

            // Emit dataChanged for the current index
            emit dataChanged(index, index, QVector<int>() << CheckBoxStateRole);
            return true;
        }
    }
    return false;
}


void ChannelDataTable::addRow(const QList<QVariant> &rowData)
{
    int newRow = rows.count();

    if(rowData.count() != numColumns){
        qDebug() << "Shay what are you doing the table size is limited.\n";
        return;
    }

    // Resize and append the checkboxStates for the new data row
    QVector<bool> newRowState(numColumns - 3, false); // Last two columns minus the header column
    checkboxStates.append(newRowState);

    beginInsertRows(QModelIndex(), newRow , newRow);
    rows.append(rowData);
    endInsertRows();
    ++numRows; // increment rows b/c we're adding one. I'm dumb...
    emit rowsAdded(newRow, newRow);
}


QHash<int, QByteArray> ChannelDataTable::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[DisplayTextRole] = "displayText";
    roles[IsHeaderRole] = "isHeader";
    roles[IsCheckBoxRole] = "isCheckable";
    roles[CheckBoxStateRole] = "checkBoxState";
    return roles;
}

ChannelSelection::ChannelSelection():channelsSet(false)
{
    probeChannels = new ChannelDataTable();
}

ChannelSelection::~ChannelSelection(){
    delete probeChannels;
}
