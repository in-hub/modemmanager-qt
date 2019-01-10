#add_subdirectory(dbus)

include_directories(
    ${MODEMMANAGER_INCLUDE_DIRS}
)

set(ModemManagerQt_SRCS
    bearer.cpp
    generictypes.cpp
    interface.cpp
    manager.cpp
    modem.cpp
    modem3gpp.cpp
    modemdevice.cpp
    modemmessaging.cpp
    sim.cpp
    sms.cpp
)

set(DBUS_INTERFACES_FILES
   dbus/bearerinterface.cpp
   dbus/dbus_manager.cpp
   dbus/messaginginterface.cpp
   dbus/modem3gppinterface.cpp
   dbus/modeminterface.cpp
   dbus/modemmanager1interface.cpp
   dbus/siminterface.cpp
   dbus/smsinterface.cpp
)

add_library(KF5ModemManagerQt SHARED ${ModemManagerQt_SRCS} ${DBUS_INTERFACES_FILES})
generate_export_header(KF5ModemManagerQt BASE_NAME ModemManagerQt)
add_library(KF5::ModemManagerQt ALIAS KF5ModemManagerQt)

target_include_directories(KF5ModemManagerQt INTERFACE "$<INSTALL_INTERFACE:${KF5_INCLUDE_INSTALL_DIR}/ModemManagerQt>")

target_link_libraries(KF5ModemManagerQt PUBLIC Qt5::Core Qt5::DBus Qt5::Xml)

set_target_properties(KF5ModemManagerQt PROPERTIES VERSION ${MODEMMANAGERQT_VERSION_STRING}
                                                   SOVERSION ${MODEMMANAGERQT_SOVERSION}
                                                   EXPORT_NAME ModemManagerQt
)

target_include_directories(KF5ModemManagerQt PUBLIC ${MODEMMANAGER_INCLUDE_DIRS})

ecm_generate_headers(ModemManagerQt_HEADERS
  HEADER_NAMES
  Call
  Bearer
  GenericTypes
  Interface
  Manager
  Modem
  Modem3Gpp
  Modem3GppUssd
  ModemCdma
  ModemDevice
  ModemFirmware
  ModemLocation
  ModemMessaging
  ModemSignal
  ModemSimple
  ModemTime
  ModemOma
  ModemVoice
  Sim
  Sms

  REQUIRED_HEADERS ModemManagerQt_HEADERS
)

install(TARGETS KF5ModemManagerQt EXPORT KF5ModemManagerQtTargets ${KF5_INSTALL_TARGETS_DEFAULT_ARGS})

# KF6: install to path having both include visibility layer & namespace dir prefix
# CamelCase includes to ${KF5_INCLUDE_INSTALL_DIR}/ModemManagerQt/ModemManagerQt
# normal headers to ${KF5_INCLUDE_INSTALL_DIR}/ModemManagerQt/modemmanagerqt
# The generated cmake config files are already accidentally pointing to the first layer, by
# target_include_directories(KF5ModemManagerQt INTERFACE "$<INSTALL_INTERFACE:${KF5_INCLUDE_INSTALL_DIR}/ModemManagerQt>")
# next to the actual include base ${KF5_INCLUDE_INSTALL_DIR} being set via KF5_INSTALL_TARGETS_DEFAULT_ARGS
# so this can stay untouched
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/modemmanagerqt_export.h
  ${ModemManagerQt_HEADERS}
  DESTINATION ${KF5_INCLUDE_INSTALL_DIR}/ModemManagerQt COMPONENT Devel
)

ecm_qt_install_logging_categories(
    EXPORT MODEMMANAGERQT
    FILE modemmanagerqt.categories
    DESTINATION ${KDE_INSTALL_LOGGINGCATEGORIESDIR}
)

if(BUILD_QCH)
    ecm_add_qch(
        KF5ModemManagerQt_QCH
        NAME ModemManagerQt
        BASE_NAME KF5ModemManagerQt
        VERSION ${KF5_VERSION}
        ORG_DOMAIN org.kde
        SOURCES # using only public headers, to cover only public API
            ${ModemManagerQt_HEADERS}
        MD_MAINPAGE "${CMAKE_SOURCE_DIR}/README.md"
        LINK_QCHS
            Qt5Core_QCH
            Qt5DBus_QCH
            Qt5Xml_QCH
        BLANK_MACROS
            MODEMMANAGERQT_EXPORT
            MODEMMANAGERQT_DEPRECATED
            MODEMMANAGERQT_DEPRECATED_EXPORT
        TAGFILE_INSTALL_DESTINATION ${KDE_INSTALL_QTQCHDIR}
        QCH_INSTALL_DESTINATION ${KDE_INSTALL_QTQCHDIR}
        COMPONENT Devel
    )
endif()
