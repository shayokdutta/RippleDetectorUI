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
        IsHeaderRole,
        IsCheckBoxRole,
        CheckBoxStateRole
    };
    Q_ENUM(CustomRoles)

    Q_PROPERTY(int columnCount READ getColumnCount NOTIFY columnCountChanged)


    explicit ChannelDataTable(QObject *parent = nullptr);

    // Overridden from QAbstractTableModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QHash<int, QByteArray> roleNames() const override;
    void addRow(const QList<QVariant> &rowData);

    // Property getter
    int getColumnCount() const { return numColumns; }
    static int checkBoxStateRole() {return CheckBoxStateRole; }

public slots:
    void setChannels();
    bool setData(int row, int column, const QVariant &value, int role);

signals:
    void columnCountChanged();
    void rowsAdded(int first, int last);
//    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());
    void channelsUpdated();
    void callQmlFunction(const QString& functionName);

private:
    QVector<QVector<bool>> checkboxStates;  // To keep track of checkbox states for each row false detection or ripple detection channel.
    QVector<int> RDChans;
    int FDChan;
    QList<QList<QVariant>> rows;
    int numColumns;
    int numRows;
};

class ChannelSelection
{
public:
    ChannelSelection();
    ~ChannelSelection();
    ChannelDataTable* getProbeChannelsModel(){ return probeChannels; }

private:
    ChannelDataTable *probeChannels;
    bool channelsSet;
};

#endif // CHANNELSELECTION_H
