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
    void newPosition(int playerID, float latitude, float longitude);

protected:
    void run() override;
};

#endif // POS_SERVER_H
