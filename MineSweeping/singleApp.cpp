#include "singleApp.h"
#include <QLocalSocket>

SingleApp::SingleApp(int &argc, char *argv[], const QString uniqueKey)
: QApplication(argc, argv), m_StrUniqueKey(uniqueKey)
{
    m_sharedMemory.setKey(m_StrUniqueKey);
    if (m_sharedMemory.attach())
		m_bIsRunning = true;
    else
    {
        m_bIsRunning = false;
        if (!m_sharedMemory.create(1))
        {
            qDebug() << "Unable to create single instance:" << m_sharedMemory.errorString().toLatin1();
            return;
        }

        m_localServer = new QLocalServer(this);
        connect(m_localServer, SIGNAL(newConnection()), this, SLOT(receiveMessage()));
        m_localServer->listen(m_StrUniqueKey);
    }
}

void SingleApp::receiveMessage()
{
    QLocalSocket * pLocalSocket = m_localServer->nextPendingConnection();
    if (!pLocalSocket->waitForReadyRead(m_constTimeout))
    {
        qDebug(pLocalSocket->errorString().toLatin1());
        return;
    }

    QByteArray byteArray = pLocalSocket->readAll();
    QString strMsg = QString::fromUtf8(byteArray.constData());
    emit recvMsg(strMsg);
    pLocalSocket->disconnectFromServer();
}

bool SingleApp::isRunning()
{
    return m_bIsRunning;
}

bool SingleApp::sendMessage(const QString &message)
{
    if (!m_bIsRunning)
        return false;
    QLocalSocket localSocket(this);
    localSocket.connectToServer(m_StrUniqueKey, QIODevice::WriteOnly);
    if (!localSocket.waitForConnected(m_constTimeout))
    {
        qDebug(localSocket.errorString().toLatin1());
        return false;
    }

    localSocket.write(message.toUtf8());
    if (!localSocket.waitForBytesWritten(m_constTimeout))
    {
        qDebug(localSocket.errorString().toLatin1());
        return false;
    }

    localSocket.disconnectFromServer();
    return true;
}