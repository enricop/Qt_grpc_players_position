
#include "playermodel.h"

QVariant PlayerData::getRole(int role) const
{
    switch (role)
    {
        case Roles::RoleAzimuth:
            return Azimuth;
        case Roles::RoleLatitude:
            return Latitude;
        case Roles::RoleLongitude:
            return Longitude;

    default:
        return QVariant();
    }
}

PlayerModel::PlayerModel()
{

    resetModel();

    connect(&thread, SIGNAL(newPosition(int,float,float)), this, SLOT(updatePlayer(int,float,float)));

    thread.start();
}

PlayerModel::~PlayerModel()
{

}

int PlayerModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_lstValues.size();
}

QVariant PlayerModel::data( const QModelIndex & index, int role ) const
{
    if ( (index.row() < 0) || (index.row() >= rowCount()) )
        return QVariant();

    if (role == PlayerData::RolePlayerID)
        return index.row();

    return m_lstValues[index.row()].getRole(role);

}

void PlayerModel::resetModel()
{
    qDebug() << "Reset players model";

    beginResetModel();

    m_lstValues.clear();
    //populate with dummy value

    m_lstValues.push_back( PlayerData( 0,  47.1, -1.6 ));
    m_lstValues.push_back( PlayerData( 0,  47.2, -1.6 ));
    m_lstValues.push_back( PlayerData( 0,  47.1, -1.5 ));
    m_lstValues.push_back( PlayerData( 0,  47.2, -1.5 ));

    endResetModel();
}

void PlayerModel::updateModel()
{
    qDebug() << "update players model upon timeout";

    //change the Azimuth of every model items
    int row = 0;
    for (PlayerData player : m_lstValues)
    {
        setData( index(row), (player.Azimuth + 1) % 360, PlayerData::RoleAzimuth);
        row++;
    }

    //qDebug() << "First element azimuth is now : " << data( index(0),PlayerData::RoleAzimuth).toInt() << "°";
}

void PlayerModel::updatePlayer(int playerindex, float latitude, float longitude)
{
    qDebug() << "updating player coordinates";

    setData( index(playerindex), longitude, PlayerData::RoleLongitude);
    setData( index(playerindex), latitude, PlayerData::RoleLatitude);
}

bool PlayerModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if ( (index.row() < 0) || (index.row() >= rowCount()) ) return false;

    PlayerData& player = m_lstValues[ index.row() ];
    switch (role)
    {

        case PlayerData::RoleAzimuth:
            player.Azimuth = value.toInt();
            break;
        case PlayerData::RoleLatitude:
            player.Latitude = value.toFloat();
            break;
        case PlayerData::RoleLongitude:
            player.Longitude = value.toFloat();
            break;
        default:
            break;

    }
    emit dataChanged(index, index );//, QVector<int>( role));

    return true;
}

bool PlayerModel::removeRows(int row, int count, const QModelIndex & parent)
{
    Q_UNUSED(count);
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row);
    m_lstValues.remove( row);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> PlayerModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[PlayerData::Roles::RoleAzimuth] = "Azimuth";
    roles[PlayerData::Roles::RoleLatitude] = "Latitude";
    roles[PlayerData::Roles::RoleLongitude] = "Longitude";
    roles[PlayerData::Roles::RolePlayerID] = "PlayerID";

    return roles;

}

Qt::ItemFlags PlayerModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
            return 0;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}
