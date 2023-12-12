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
    QVector<int> getChannelsToSend();
    void addRow(const QList<QVariant> &rowData);

    int getColumnCount() const { return numColumns; }
    static int checkBoxStateRole() {return CheckBoxStateRole;}

    bool fdChanSet();
    int getfdChan() {return FDChan;}

public slots:
    void setChannels();
    bool setData(int row, int column, const QVariant &value, int role);
    void restoreChannels();

signals:
    void columnCountChanged();
    void rowsAdded(int first, int last);
//    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());
    void channelsUpdated(bool channelsSetOrNah);
    void callQmlFunction(const QString& functionName);

private:
    QVector<QVector<bool>> checkboxStates;  // To keep track of checkbox states for each row false detection or ripple detection channel.
    QVector<int> RDChans;
    int FDChan;
    QList<QList<QVariant>> rows;
    QList<QList<QVariant>> originalRows;
    int numColumns;
    int numRows;
    int totalRows;
};

class ChannelSelection : public QObject{
    Q_OBJECT
public:
    enum dataTypes {
        NPX_IMEC = 1,
        TRODES_INTAN,
        NPX_TRODES
    };

    ChannelSelection(QObject *parent = nullptr);
    ~ChannelSelection();

    // probably dangerous/bad practice so don't use it if you don't have to?
    // necessary in a manner of speaking though for the qml so let's try not
    // to use it beyond that if we can avoid it. The C++ side shouldn't need
    // direct access to the table model. if we mess up anything within it we
    // can mess up the UI so let's avoid editing it via the pointer from a
    // ChannelSelection object...
    ChannelDataTable* getProbeChannelsModel(){ return probeChannels; }

    int getfdChan() {return probeChannels->getfdChan();}
    bool fdChanSet() {return probeChannels->getfdChan() != -1;}

public slots:
    void updateChannels(bool channelsSetOrNah);

signals:
    void sendData(/*dataType, dataPacket*/);
    void theseChannels(QVector<int> theseAreTheChannelsIwantSent);

private:
    ChannelDataTable *probeChannels;
    int dataType;
    bool channelsSet;
};

#endif // CHANNELSELECTION_H
