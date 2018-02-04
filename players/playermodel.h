#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H


#include <QObject>
#include <QAbstractListModel>
#include <QGeoPositionInfoSource>
#include <QTimer>
#include <QDebug>

#include "pos_server.h"

struct PlayerData
{
    PlayerData(){    }
    PlayerData(int azimuth, double lat, double lng){
        Azimuth = azimuth;
        Latitude = lat;
        Longitude = lng;
    }

    int Azimuth = 0;
    double Latitude = 0.;
    double Longitude = 0.;

    QVariant getRole(int role) const;

    enum Roles{
        RoleAzimuth = Qt::UserRole + 1,
        RoleLatitude,
        RoleLongitude,
        RolePlayerID

    };

};

class PlayerModel : public QAbstractListModel
{
    Q_OBJECT
public:
    PlayerModel();

    ~PlayerModel();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    Q_INVOKABLE Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

    virtual bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);

    bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());

    void resetModel();
    void updateModel();

public slots:
    void updatePlayer(int playerindex, double longitude, double latitude);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    //QTimer m_timer;
    QVector<PlayerData> m_lstValues ;

    PosServerThread thread;
};


#endif // PLAYERMODEL_H
