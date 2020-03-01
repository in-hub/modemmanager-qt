/*
    SPDX-FileCopyrightText: 2008 Will Stephenson <wstephenson@kde.org>
    SPDX-FileCopyrightText: 2010 Lamarque Souza <lamarque@kde.org>
    SPDX-FileCopyrightText: 2013-2015 Jan Grulich <jgrulich@redhat.com>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#ifndef MODEMMANAGER_SIM_P_H
#define MODEMMANAGER_SIM_P_H

#include "dbus/siminterface.h"
#include "interface_p.h"
#include "sim.h"

namespace ModemManager
{

class SimPrivate : public QObject
{
    Q_OBJECT
public:
    explicit SimPrivate(const QString &path, Sim *q);
    OrgFreedesktopModemManager1SimInterface simIface;
    QString uni;
    QString simIdentifier;
    QString imsi;
    QString operatorIdentifier;
    QString operatorName;

    Q_DECLARE_PUBLIC(Sim)
    Sim *q_ptr;
private Q_SLOTS:
    void onPropertiesChanged(const QString &interface, const QVariantMap &properties, const QStringList &invalidatedProps);
};

} // namespace ModemManager

#endif
