/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generictypes.h -p modemcdmainterface /home/jgrulich/development/projects/libmm-qt/dbus/introspection/org.freedesktop.ModemManager1.Modem.ModemCdma.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef MODEMMANAGERQT_MODEMCDMAINTERFACE_H
#define MODEMMANAGERQT_MODEMCDMAINTERFACE_H

#include <QObject>
#include <QByteArray>
#include <QList>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QtDBus>
#include "generictypes.h"

/*
 * Proxy class for interface org.freedesktop.ModemManager1.Modem.ModemCdma
 */
class OrgFreedesktopModemManager1ModemModemCdmaInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
#ifdef MMQT_STATIC
    { return "org.kde.fakemodem.Modem.ModemCdma"; }
#else
    { return "org.freedesktop.ModemManager1.Modem.ModemCdma"; }
#endif
public:
    OrgFreedesktopModemManager1ModemModemCdmaInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgFreedesktopModemManager1ModemModemCdmaInterface();

    Q_PROPERTY(uint ActivationState READ activationState)
    inline uint activationState() const
    { return qvariant_cast< uint >(property("ActivationState")); }

    Q_PROPERTY(uint Cdma1xRegistrationState READ cdma1xRegistrationState)
    inline uint cdma1xRegistrationState() const
    { return qvariant_cast< uint >(property("Cdma1xRegistrationState")); }

    Q_PROPERTY(QString Esn READ esn)
    inline QString esn() const
    { return qvariant_cast< QString >(property("Esn")); }

    Q_PROPERTY(uint EvdoRegistrationState READ evdoRegistrationState)
    inline uint evdoRegistrationState() const
    { return qvariant_cast< uint >(property("EvdoRegistrationState")); }

    Q_PROPERTY(QString Meid READ meid)
    inline QString meid() const
    { return qvariant_cast< QString >(property("Meid")); }

    Q_PROPERTY(uint Nid READ nid)
    inline uint nid() const
    { return qvariant_cast< uint >(property("Nid")); }

    Q_PROPERTY(uint Sid READ sid)
    inline uint sid() const
    { return qvariant_cast< uint >(property("Sid")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Activate(const QString &carrier_code)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(carrier_code);
        return asyncCallWithArgumentList(QLatin1String("Activate"), argumentList);
    }

    inline QDBusPendingReply<> ActivateManual(const QVariantMap &properties)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(properties);
        return asyncCallWithArgumentList(QLatin1String("ActivateManual"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void ActivationStateChanged(uint activation_state, uint activation_error, const QVariantMap &status_changes);
};

#endif
