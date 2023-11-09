#ifndef CHANNELSELECTION_H
#define CHANNELSELECTION_H

#include <QObject>
#include <QQmlContext>
#include <QAbstractTableModel>

class ChannelDataTable : public QAbstractTableModel {
    Q_OBJECT

public:
    // Define an enum for custom roles
    enum CustomRoles {
        DisplayTextRole = Qt::UserRole + 1,
        IsHeaderRole
    };


    Q_PROPERTY(int columnCount READ getColumnCount NOTIFY columnCountChanged)

    explicit ChannelDataTable(QObject *parent = nullptr);

    // Overridden from QAbstractTableModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void addRow(const QList<QVariant> &rowData);

    // Property getter
    int getColumnCount() const { return numColumns; }

signals:
    void columnCountChanged();
    void rowsAdded(int first, int last);
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());

private:
    QList<QList<QVariant>> rows;
    int numColumns;
    int numRows;
};

class ChannelSelection
{
public:
    ChannelSelection();
    ChannelDataTable* getProbeChannelsModel(){ return &probeChannels; }

private:
    ChannelDataTable probeChannels;
};

#endif // CHANNELSELECTION_H
