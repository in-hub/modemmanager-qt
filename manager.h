/*
Copyright 2008,2011 Will Stephenson <wstephenson@kde.org>
Copyright 2010 Lamarque Souza <lamarque@kde.org>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of
the License or (at your option) version 3 or any later version
accepted by the membership of KDE e.V. (or its successor approved
by the membership of KDE e.V.), which shall act as a proxy
defined in Section 14 of version 3 of the license.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MODEMMANAGER_MODEMMANAGER_H
#define MODEMMANAGER_MODEMMANAGER_H

#include "mmqt-export.h"

#include <QObject>
#include <QDBusObjectPath>

#include "modeminterface.h"

/**
 * This namespace allows to query the underlying system to discover the available
 * modem interfaces
 * responsibility to notify when a modem interface or a modem appear or disappear.
 *
 * Note that it's implemented as a singleton and encapsulates the backend logic.
 */
namespace ModemManager
{
    extern const QString DBUS_SERVICE;
    extern const QString DBUS_DAEMON_PATH;

    class ModemInterface;
    typedef QList<ModemInterface*> ModemInterfaceList;

    class MMQT_EXPORT Notifier : public QObject
    {
    Q_OBJECT
    Q_SIGNALS:
    /**
     * This signal is emitted when a new modem interface is available.
     *
     * @param udi the network interface identifier
     */
    void modemAdded(const QString & udi);
    /**
     * This signal is emitted when a network interface is not available anymore.
     *
     * @param udi the network interface identifier
     */
    void modemRemoved(const QString & udi);
     /**
      * This signal is emitted when the ModemManager DBus service goes away
      */
     void serviceDisappeared();
     /**
      * This signal is emitted when the ModemManager DBus service appears
      */
     void serviceAppeared();
    };

    /**
     * Retrieves the list of all modem interfaces Unique Device Identifiers (UDIs)
     * in the system. This method is the equivalent of enumerateDevices described
     * in Modem Manager specification.
     * @return the list of modem interfaces available in this system
     */
    MMQT_EXPORT ModemInterfaceList modemInterfaces();
    /**
     * Find a new ModemManagerInterface object given its UDNI.  This pointer is owned by the Solid
     * infrastructure.
     *
     * @param udi the identifier of the modem interface to find
     * @returns a valid ModemManagerInterface object if there's a device having the given UDI, an invalid one otherwise
     */
    //willtodo: decide what to do with type arg
    MMQT_EXPORT ModemInterface *findModemInterface(const QString &udi, const ModemManager::ModemInterface::GsmInterfaceType ifaceType);

    MMQT_EXPORT Notifier * notifier();

}

#endif
