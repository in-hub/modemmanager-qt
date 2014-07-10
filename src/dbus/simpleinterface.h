/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generictypes.h -p simpleinterface /home/jgrulich/development/projects/libmm-qt/dbus/introspection/org.freedesktop.ModemManager1.Modem.Simple.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef MODEMMANAGERQT_SIMPLEINTERFACE_H
#define MODEMMANAGERQT_SIMPLEINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "generictypes.h"
#include "generictypes_p.h"

/*
 * Proxy class for interface org.freedesktop.ModemManager1.Modem.Simple
 */
class OrgFreedesktopModemManager1ModemSimpleInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.ModemManager1.Modem.Simple"; }

public:
    OrgFreedesktopModemManager1ModemSimpleInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopModemManager1ModemSimpleInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QDBusObjectPath> Connect(const QVariantMap &properties)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(properties);
        return asyncCallWithArgumentList(QLatin1String("Connect"), argumentList);
    }

    inline QDBusPendingReply<> Disconnect(const QDBusObjectPath &bearer)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(bearer);
        return asyncCallWithArgumentList(QLatin1String("Disconnect"), argumentList);
    }

    inline QDBusPendingReply<QVariantMap> GetStatus()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetStatus"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

#endif