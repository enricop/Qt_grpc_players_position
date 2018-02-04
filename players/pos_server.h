#ifndef POS_SERVER_H
#define POS_SERVER_H

#include <QThread>

class PosServerThread : public QThread
{
    Q_OBJECT

public:
    PosServerThread(QObject *parent = 0);
    ~PosServerThread();

signals:
    void newPosition(int playerID, double latitude, double longitude);

protected:
    void run() override;
};

#endif // POS_SERVER_H
