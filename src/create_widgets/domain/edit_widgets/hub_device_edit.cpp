#include "hub_device_edit.h"

HubDevice_Edit::HubDevice_Edit(QWidget *parent) :
    HubDevice(parent)
{
    connect(addr, SIGNAL(dataChanged()),
            this, SLOT(stateChanged()));
}

/* public slots */
void HubDevice_Edit::setDeviceData(QString &xmlDesc)
{
    //qDebug()<<xmlDesc;
    QDomDocument doc;
    doc.setContent(xmlDesc);
    QDomElement _device, _addr;
    _device = doc.firstChildElement("device")
            .firstChildElement("hub");
    QString _type = _device.attribute("type", "");
    int idx = addr->type->findText(_type, Qt::MatchContains);
    addr->type->setCurrentIndex( (idx<0)? 0:idx );
    _addr = _device.firstChildElement("address");
    if ( !_addr.isNull() ) {
        addr->use->setChecked(true);
        USBAddr *wdg = static_cast<USBAddr*>( addr->getCurrentAddrWidget() );
        wdg->bus->setText( _addr.attribute("bus") );
        wdg->port->setText( _addr.attribute("port") );
    };
}
