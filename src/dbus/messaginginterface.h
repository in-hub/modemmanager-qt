/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generictypes.h -p messaginginterface /home/jgrulich/development/projects/libmm-qt/dbus/introspection/org.freedesktop.ModemManager1.Modem.Messaging.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef MODEMMANAGERQT_MESSAGINGINTERFACE_H
#define MODEMMANAGERQT_MESSAGINGINTERFACE_H

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
 * Proxy class for interface org.freedesktop.ModemManager1.Modem.Messaging
 */
class OrgFreedesktopModemManager1ModemMessagingInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
#ifdef MMQT_STATIC
    { return "org.kde.fakemodem.Modem.Messaging"; }
#else
    { return "org.freedesktop.ModemManager1.Modem.Messaging"; }
#endif
public:
    OrgFreedesktopModemManager1ModemMessagingInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgFreedesktopModemManager1ModemMessagingInterface();

    Q_PROPERTY(uint DefaultStorage READ defaultStorage)
    inline uint defaultStorage() const
    { return qvariant_cast< uint >(property("DefaultStorage")); }

    Q_PROPERTY(QList<QDBusObjectPath> Messages READ messages)
    inline QList<QDBusObjectPath> messages() const
    { return qvariant_cast< QList<QDBusObjectPath> >(property("Messages")); }

    Q_PROPERTY(ModemManager::UIntList SupportedStorages READ supportedStorages)
    inline ModemManager::UIntList supportedStorages() const
    { return qvariant_cast< ModemManager::UIntList >(property("SupportedStorages")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QDBusObjectPath> Create(const QVariantMap &properties)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(properties);
        return asyncCallWithArgumentList(QLatin1String("Create"), argumentList);
    }

    inline QDBusPendingReply<> Delete(const QDBusObjectPath &path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path);
        return asyncCallWithArgumentList(QLatin1String("Delete"), argumentList);
    }

    inline QDBusPendingReply<QList<QDBusObjectPath> > List()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("List"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void Added(const QDBusObjectPath &path, bool received);
    void Deleted(const QDBusObjectPath &path);
};

#endif
