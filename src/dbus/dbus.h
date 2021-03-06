/*
    SPDX-FileCopyrightText: 2008 Will Stephenson <wstephenson@kde.org>
    SPDX-FileCopyrightText: 2010 Lamarque Souza <lamarque@kde.org>
    SPDX-FileCopyrightText: 2013 Lukas Tinkl <ltinkl@redhat.com>
    SPDX-FileCopyrightText: 2013 Anant Kamath <kamathanant@gmail.com>
    SPDX-FileCopyrightText: 2015 Jan Grulich <jgrulich@redhat.com>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#ifndef MODEMMANAGER_DBUS_H
#define MODEMMANAGER_DBUS_H

#define DBUS_INTERFACE_PROPS             QLatin1String("org.freedesktop.DBus.Properties")
#define DBUS_INTERFACE_INTROSPECT        QLatin1String("org.freedesktop.DBus.Introspectable")
#define DBUS_INTERFACE_MANAGER           QLatin1String("org.freedesktop.DBus.ObjectManager")

#define MMQT_DBUS_SERVICE    MM_DBUS_SERVICE
#define MMQT_DBUS_PATH       MM_DBUS_PATH
/* Prefix for object paths */
#define MMQT_DBUS_MODEM_PREFIX  MM_DBUS_PATH "/Modem"
#define MMQT_DBUS_BEARER_PREFIX MM_DBUS_PATH "/Bearer"
#define MMQT_DBUS_SIM_PREFIX    MM_DBUS_PATH "/SIM"
#define MMQT_DBUS_SMS_PREFIX    MM_DBUS_PATH "/SMS"
#define MMQT_DBUS_CALL_PREFIX   MM_DBUS_PATH "/Call"
/* Interfaces */
#define MMQT_DBUS_INTERFACE                         MM_DBUS_INTERFACE
#define MMQT_DBUS_INTERFACE_SIM                     MM_DBUS_INTERFACE_SIM
#define MMQT_DBUS_INTERFACE_BEARER                  MM_DBUS_INTERFACE_BEARER
#define MMQT_DBUS_INTERFACE_SMS                     MM_DBUS_INTERFACE_SMS
#define MMQT_DBUS_INTERFACE_CALL                    MM_DBUS_INTERFACE_CALL
#define MMQT_DBUS_INTERFACE_MODEM                   MM_DBUS_INTERFACE_MODEM
#define MMQT_DBUS_INTERFACE_MODEM_SIMPLE            "org.freedesktop.ModemManager1.Modem.Simple"
#define MMQT_DBUS_INTERFACE_MODEM_MODEM3GPP         MM_DBUS_INTERFACE_MODEM_MODEM3GPP
#define MMQT_DBUS_INTERFACE_MODEM_MODEM3GPP_USSD    MM_DBUS_INTERFACE_MODEM_MODEM3GPP_USSD
#define MMQT_DBUS_INTERFACE_MODEM_MODEMCDMA         MM_DBUS_INTERFACE_MODEM_MODEMCDMA
#define MMQT_DBUS_INTERFACE_MODEM_MESSAGING         MM_DBUS_INTERFACE_MODEM_MESSAGING
#define MMQT_DBUS_INTERFACE_MODEM_LOCATION          MM_DBUS_INTERFACE_MODEM_LOCATION
#define MMQT_DBUS_INTERFACE_MODEM_TIME              MM_DBUS_INTERFACE_MODEM_TIME
#define MMQT_DBUS_INTERFACE_MODEM_FIRMWARE          MM_DBUS_INTERFACE_MODEM_FIRMWARE
#define MMQT_DBUS_INTERFACE_MODEM_SIGNAL            MM_DBUS_INTERFACE_MODEM_SIGNAL
#define MMQT_DBUS_INTERFACE_MODEM_OMA               MM_DBUS_INTERFACE_MODEM_OMA
#define MMQT_DBUS_INTERFACE_MODEM_VOICE             MM_DBUS_INTERFACE_MODEM_VOICE

#endif
