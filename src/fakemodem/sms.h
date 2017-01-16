/*
    Copyright 2015 Jan Grulich <jgrulich@redhat.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MODEMMANAGERQT_FAKE_MODEM_SMS_H
#define MODEMMANAGERQT_FAKE_MODEM_SMS_H

#include "generictypes.h"

#include <QObject>

#include <QDBusObjectPath>

class Sms : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.fakemodem.Sms")
public:
    explicit Sms(QObject * parent = nullptr);
    virtual ~Sms();

    Q_PROPERTY(int SmsClass READ smsClass)
    Q_PROPERTY(QByteArray Data READ data)
    Q_PROPERTY(bool DeliveryReportRequest READ deliveryReportRequest)
    Q_PROPERTY(uint DeliveryState READ deliveryState)
    Q_PROPERTY(QString DischargeTimestamp READ dischargeTimestamp)
    Q_PROPERTY(uint MessageReference READ messageReference)
    Q_PROPERTY(QString Number READ number)
    Q_PROPERTY(uint PduType READ pduType)
    Q_PROPERTY(QString SMSC READ SMSC)
    Q_PROPERTY(uint ServiceCategory READ serviceCategory)
    Q_PROPERTY(uint State READ state)
    Q_PROPERTY(uint Storage READ storage)
    Q_PROPERTY(uint TeleserviceId READ teleserviceId)
    Q_PROPERTY(QString Text READ text)
    Q_PROPERTY(QString Timestamp READ timestamp)
    Q_PROPERTY(ModemManager::ValidityPair Validity READ validity)

    int smsClass() const;
    QByteArray data() const;
    bool deliveryReportRequest() const;
    uint deliveryState() const;
    QString dischargeTimestamp() const;
    uint messageReference() const;
    QString number() const;
    uint pduType() const;
    QString SMSC() const;
    uint serviceCategory() const;
    uint state() const;
    uint storage() const;
    uint teleserviceId() const;
    QString text() const;
    QString timestamp() const;
    ModemManager::ValidityPair validity() const;

    /* Not part of dbus interface */
    QString smsPath() const;
    void setSmsPath(const QString &path);
    void setEnableNotifications(bool enable);
    void setSmsClass(int smsClass);
    void setData(const QByteArray &data);
    void setDeliveryReportRequest(bool deliveryReportRequest);
    void setDeliveryState(uint state);
    void setDischargeTimestamp(const QString &timestamp);
    void setMessageReference(uint messageReference);
    void setNumber(const QString &number);
    void setPduType(uint pduType);
    void setSMSC(const QString &smsc);
    void setServiceCategory(uint serviceCategory);
    void setState(uint state);
    void setStorage(uint storage);
    void setTeleserviceId(uint teleserviceId);
    void setText(const QString &text);
    void setTimestamp(const QString &timestamp);
    void setValidity(const ModemManager::ValidityPair &validity);

public Q_SLOTS:
    Q_SCRIPTABLE void Send();
    Q_SCRIPTABLE void Store(uint storage);

private:
    QString m_smsPath;
    bool m_enabledNotifications;
    int m_smsClass;
    QByteArray m_data;
    bool m_deliveryReportRequest;
    uint m_deliveryState;
    QString m_dischargeTimestamp;
    uint m_messageReference;
    QString m_number;
    uint m_pduType;
    QString m_SMSC;
    uint m_serviceCategory;
    uint m_state;
    uint m_storage;
    uint m_teleserviceId;
    QString m_text;
    QString m_timestamp;
    ModemManager::ValidityPair m_validity;
};

#endif
