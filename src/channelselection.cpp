#include "channelselection.h"

/**
 * @brief ChannelDataTable::ChannelDataTable
 * @param parent
 */
ChannelDataTable::ChannelDataTable(QObject *parent)
    : QAbstractTableModel(parent), numColumns(5), numRows(1) // Assuming you want 5 columns and at least 1 row initially
{
    // Initialize the first row with headers
    rows.append({"Channel", "μ", "σ", "RD?", "FD?"});
}

/**
 * @brief ChannelDataTable::restoreChannels
 */
void ChannelDataTable::restoreChannels() {
    RDChans.clear();  // Clear the RD channels list
    FDChan = -1;  // Reset the FD channel

    // Reset the checkbox states for all original rows
    // Resize checkboxStates to match the total number of rows
    checkboxStates.resize(totalRows - 1);  // Assuming the first row is a header and not included in checkboxStates
    for (int row = 0; row < checkboxStates.size(); ++row) {
        checkboxStates[row].resize(2);  // Resize each row's checkbox state list (assuming two checkboxes per row)
        for (int col = 0; col < checkboxStates[row].size(); ++col) {
            checkboxStates[row][col] = false;
        }
    }

    // Restore the rows to the original state if necessary
    // Assuming you have a method or logic to repopulate 'rows' with original data
     rows = originalRows; // Where originalRows is a stored copy of the original data

    // Update the number of rows in the model to reflect the original total
    beginResetModel();
    numRows = totalRows;
    endResetModel();

    // Optionally, emit dataChanged for the entire model to update the view
    emit dataChanged(createIndex(0, 0), createIndex(numRows - 1, numColumns - 1));
    emit channelsUpdated();
}

/**
 * @brief ChannelDataTable::setChannels
 */
void ChannelDataTable::setChannels() {
    RDChans.clear();  // Clear the existing channels
    FDChan = -1;  // Reset FDChan
    totalRows = numRows; // store total number of rows for restoration as we're about to destroy the table
    originalRows = rows;
    // Create a list to keep track of rows to be kept
    QList<int> rowsToKeep;

    // Iterate over each row, skipping the header row
    qDebug() << "Channels for ripple detection are as follows:";
    for (int row = 1; row < numRows; ++row) {  // Start from 1 to skip header
        bool ok;
        int channelNum = rows[row][0].toInt(&ok);  // Convert the first column data to int
        if (!ok) {
            qDebug() << "Conversion to int failed for row" << row;
            continue;
        }

        // Check if the first checkbox (RD?) or second checkbox (FD?) is true
        if (checkboxStates[row - 1][0] || checkboxStates[row - 1][1]) {
            rowsToKeep.append(row);
            RDChans.append(channelNum);  // Append the number to RDChans if RD? is true
            qDebug() << channelNum;
            if (checkboxStates[row - 1][1]) {
                FDChan = channelNum;  // Store the number in FDChan if FD? is true
            }
        }
    }

    // Now remove rows that are not in rowsToKeep
    for (int row = numRows - 1; row > 0; --row) {  // Iterate backwards to avoid index issues
        if (!rowsToKeep.contains(row)) {
            beginRemoveRows(QModelIndex(), row, row);
            rows.removeAt(row);
            checkboxStates.removeAt(row - 1);
            endRemoveRows();
        }
    }

    if (RDChans.isEmpty()) {
        qDebug() << "NO CHANNELS SELECTED?";
    }
    if (FDChan != -1) {
        qDebug() << "False Detection Channel Set to " + QString::number(FDChan);
    }
    emit channelsUpdated();  // Assuming you have declared this signal

    // Update the row count
    numRows = rows.count();
}

/**
 * @brief ChannelDataTable::rowCount
 * @param parent
 * @return
 */
int ChannelDataTable::rowCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : numRows;
}

/**
 * @brief ChannelDataTable::columnCount
 * @param parent
 * @return
 */
int ChannelDataTable::columnCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : numColumns;
}

/**
 * @brief ChannelDataTable::data
 * @param index
 * @param role
 * @return
 */
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

/**
 * @brief ChannelDataTable::index
 * @param row
 * @param column
 * @param parent
 * @return
 */
QModelIndex ChannelDataTable::index(int row, int column, const QModelIndex &parent) const {
    if (parent.isValid() || row >= rowCount() || column >= columnCount()) {
        return QModelIndex();  // Returns an invalid index
    }
    return createIndex(row, column);
}

/**
 * @brief ChannelDataTable::setData
 * @param row
 * @param column
 * @param value
 * @param role
 * @return
 */
bool ChannelDataTable::setData(int row, int column, const QVariant &value, int role) {
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

            // If one checkbox is checked, uncheck the other in the same row
            if (checked) {
                int otherCheckboxIndex = checkboxIndex == 0 ? 1 : 0; // Determine the index of the other checkbox
                checkboxStates[adjustedRow][otherCheckboxIndex] = false; // Uncheck the other checkbox

                // Emit dataChanged for the other checkbox in the same row
                QModelIndex otherIndex = this->index(row, numColumns - 2 + otherCheckboxIndex, QModelIndex());
                emit dataChanged(otherIndex, otherIndex, QVector<int>() << CheckBoxStateRole);
            }

            // If the FD checkbox is being checked, uncheck all other FD checkboxes
            if (index.column() == numColumns - 1 && checked) {
                for (int otherRow = 0; otherRow < checkboxStates.size(); ++otherRow) {
                    if (otherRow != adjustedRow) {
                        checkboxStates[otherRow][1] = false;  // Uncheck FD checkbox in other rows
                        QModelIndex otherIndex = this->index(otherRow + 1, index.column(), QModelIndex());
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

/**
 * @brief ChannelDataTable::addRow
 * @param rowData
 */
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

/**
 * @brief ChannelDataTable::roleNames
 * @return
 */
QHash<int, QByteArray> ChannelDataTable::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[DisplayTextRole] = "displayText";
    roles[IsHeaderRole] = "isHeader";
    roles[IsCheckBoxRole] = "isCheckable";
    roles[CheckBoxStateRole] = "checkBoxState";
    return roles;
}

/**
 * @brief ChannelSelection::ChannelSelection
 * @param parent
 */
ChannelSelection::ChannelSelection(QObject *parent):channelsSet(false), QObject(parent){
    probeChannels = new ChannelDataTable();
    connect(probeChannels, &ChannelDataTable::channelsUpdated, this, &ChannelSelection::updateChannels);
}

/**
 * @brief ChannelSelection::~ChannelSelection
 */
ChannelSelection::~ChannelSelection(){
    delete probeChannels;
}

/**
 * @brief ChannelSelection::updateChannels
 */
void ChannelSelection::updateChannels(){
    channelsSet = !channelsSet; // flip it every time. Should be false first.
}
