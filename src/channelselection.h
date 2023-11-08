#ifndef CHANNELSELECTION_H
#define CHANNELSELECTION_H

#include <QQmlContext>
#include <QAbstractTableModel>

class ChannelDataTable : public QAbstractTableModel {
    // Implement necessary functions like rowCount(), columnCount(), data(), etc.
    // ...
public:
    ChannelDataTable();
};

class ChannelSelection
{
private:
    ChannelDataTable probeChannels;
public:
    ChannelSelection();
};

#endif // CHANNELSELECTION_H
