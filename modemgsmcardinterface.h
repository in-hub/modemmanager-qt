/*
Copyright 2008,2011 Will Stephenson <wstephenson@kde.org>
Copyright 2010-2011 Lamarque Souza <lamarque@kde.org>

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

#ifndef MODEMMANAGER_MODEMGSMCARDINTERFACE_H
#define MODEMMANAGER_MODEMGSMCARDINTERFACE_H

#include "mmqt-export.h"

#include <QObject>
#include <QDBusPendingReply>
#include "modeminterface.h"

class ModemGsmCardInterfacePrivate;

namespace ModemManager
{
class MMQT_EXPORT ModemGsmCardInterface : public ModemInterface
{
Q_OBJECT
Q_DECLARE_PRIVATE(ModemGsmCardInterface)

public:
    ModemGsmCardInterface(const QString & path, QObject * parent);
    ~ModemGsmCardInterface();

    QString getImei();
    QString getImsi();
    QDBusPendingReply<> sendPuk(const QString & puk, const QString & pin);
    QDBusPendingReply<> sendPin(const QString & pin);
    QDBusPendingReply<> enablePin(const QString & pin, const bool enabled);
    QDBusPendingReply<> changePin(const QString & oldPin, const QString & newPin);

    // Properties
    ModemManager::ModemInterface::Band getSupportedBands() const;
    ModemManager::ModemInterface::Mode getSupportedModes() const;
public Q_SLOTS:
    void propertiesChanged(const QString & interface, const QVariantMap & properties);
Q_SIGNALS:
    // properties
    void supportedBandsChanged(const ModemManager::ModemInterface::Band band);
    void supportedModesChanged(const ModemManager::ModemInterface::Mode modes);

};
} // namespace ModemManager

#endif
