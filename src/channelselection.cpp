#include "channelselection.h"

ChannelDataTable::ChannelDataTable(QObject *parent)
    : QAbstractTableModel(parent), numColumns(4), numRows(1)
{
    // table header
    rows.append({"Channel","μ","σ","FD?"});
}

int ChannelDataTable::rowCount(const QModelIndex &parent) const {
    if(parent.isValid())
        return 0;
    return rows.size();
}

int ChannelDataTable::columnCount(const QModelIndex & parent) const {
    if(parent.isValid())
        return 0;
    return numColumns;
}

QVariant ChannelDataTable::data(const QModelIndex &index, int role) const {
    if(!index.isValid())
        return QVariant();

    if(index.row() >= rows.size() || index.column() >= numColumns)
        return QVariant();

    if (role == Qt::DisplayRole){
        return rows.at(index.row()).at(index.column());
    }

    return QVariant();
}

ChannelSelection::ChannelSelection()
{

}
