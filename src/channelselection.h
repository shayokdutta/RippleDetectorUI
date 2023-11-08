#ifndef CHANNELSELECTION_H
#define CHANNELSELECTION_H

#include <QQmlContext>
#include <QAbstractTableModel>

class ChannelDataTable : public QAbstractTableModel {
    Q_OBJECT // macro required for class that implments signals I think?

public:
    explicit ChannelDataTable(QObject *parent = nullptr);

    // minimum requirements
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data (const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList<QList<QVariant>> rows;
    int numColumns;
    int numRows;
};

class ChannelSelection
{
public:
    ChannelSelection();
    ChannelDataTable* getProbeChannelsModel(){return &probeChannels;};

private:
    ChannelDataTable probeChannels;
};

#endif // CHANNELSELECTION_H
