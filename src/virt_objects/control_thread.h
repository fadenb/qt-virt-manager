#ifndef CONTROL_THREAD_H
#define CONTROL_THREAD_H

#include <QThread>
#include <QDir>
#include <QTemporaryFile>
#include <QStringList>
#include "libvirt/libvirt.h"
#include "libvirt/virterror.h"
#include <QDebug>

struct Result {
    QString         name   = QString();
    bool            result = false;
    QStringList     msg    = QStringList();
};

class ControlThread : public QThread
{
    Q_OBJECT
public:
    explicit ControlThread(QObject *parent = 0);
    QStringList      args;
    bool             keep_alive;
    virConnect      *currWorkConnect = NULL;
    virErrorPtr      virtErrors;

signals:
    void errorMsg(QString);

public slots:
    bool setCurrentWorkConnect(virConnectPtr);
    void stop();

    void sendConnErrors();
    void sendGlobalErrors();

    virtual void run();

};

#endif // CONTROL_THREAD_H