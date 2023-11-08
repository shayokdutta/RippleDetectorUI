#include "channelselection.h"

ChannelDataTable::ChannelDataTable(QObject *parent)
    : QAbstractTableModel(parent), numColumns(4), numRows(1) // Assuming you want 4 columns and at least 1 row initially
{
    // Initialize the first row with headers
    rows.append({"Channel", "μ", "σ", "FD?"});
}

int ChannelDataTable::rowCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : numRows;
}

int ChannelDataTable::columnCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : numColumns;
}

QVariant ChannelDataTable::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role == DisplayTextRole) {
        return rows.at(index.row()).at(index.column()).toString();
    } else if (role == IsHeaderRole) {
        return index.row() == 0; // Assuming the first row is the header
    }
    return QVariant();
}


QHash<int, QByteArray> ChannelDataTable::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[DisplayTextRole] = "displayText";
    roles[IsHeaderRole] = "isHeader";
    return roles;
}

ChannelSelection::ChannelSelection()
{

}
