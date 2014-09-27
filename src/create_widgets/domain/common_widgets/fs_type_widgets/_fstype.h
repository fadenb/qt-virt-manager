#ifndef _FSTYPE_H
#define _FSTYPE_H

#include <QPushButton>
#include <QFileDialog>
#include <QStringList>
#include "create_widgets/domain/_qwidget.h"

#define LXC_DRIVER_TYPES QStringList()<<"default"<<"loop"<<"nbd"
#define QEMU_DRIVER_TYPES QStringList()<<"default"<<"path"<<"handle"
#define FORMAT_TYPES QStringList()<<"bochs"<<"cloop"<<"cow"\
    <<"dmg"<<"fat"<<"iso"<<"qcow"<<"qcow2"<<"qed"<<"raw"<<"vdi"\
    <<"vhd"<<"vmdk"<<"vpc"

class _FsType : public _QWidget
{
    Q_OBJECT
public:
    explicit _FsType(
            QWidget *parent = 0,
            QString _type = "lxc");
    QString          connType;
    QLabel          *driverLabel, *wrPolicyLabel,
                    *formatLabel, *accessModeLabel,
                    *targetLabel;
    QPushButton     *sourceLabel;
    QComboBox       *driver, *wrPolicy,
                    *format, *accessMode;
    QLineEdit       *source, *target;
    QCheckBox       *readOnly;
    QGridLayout     *commonLayout;

    virtual QDomDocument getDevDocument() const;

 private slots:
    void driverTypeChanged(QString);
};

#endif // _FSTYPE_H