#ifndef SINGLEAPP_H
#define SINGLEAPP_H


#include <QApplication>
#include <QSharedMemory>
#include <QLocalServer>

class SingleApp : public QApplication
{
    Q_OBJECT
public:
    SingleApp(int &argc, char *argv[], const QString uniqueKey);
    bool isRunning();
    bool sendMessage(const QString &message);

public slots:
    void receiveMessage();

signals:
    void recvMsg(QString strMsg);
private:
    static const int m_constTimeout = 1000;

    bool m_bIsRunning;
    QString m_StrUniqueKey;
    QSharedMemory m_sharedMemory;
    QLocalServer * m_localServer;

};
#endif // SINGLEAPP_H
