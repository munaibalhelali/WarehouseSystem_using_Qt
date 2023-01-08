cmake_minimum_required(VERSION 3.5)

project(WarehouseSystem LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

if(ANDROID)
  add_library(WarehouseSystem SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(WarehouseSystem
    main.cpp
    mainwindow.cpp
    admincontrolwidget.cpp
    workercontrolwidget.cpp
    databaseSQL.cpp
    person.cpp
    product.cpp
    idGenerator.cpp
    zone.cpp
    driver.cpp
    adminView.cpp
    view.cpp
    login.cpp
    util.cpp
    addnewuserdialog.cpp
    removeuserdialog.cpp
    addnewproductdialog.cpp
    removeproductdialog.cpp
    addnewzonedialog.cpp
    removezonedialog.cpp
    addstockdialog.cpp
    dispatchstockdialog.cpp
    showavailablestockdialog.cpp
    signinwidget.cpp

    mainwindow.ui
    addnewuserdialog.ui
    removeuserdialog.ui
    addnewproductdialog.ui
    removeproductdialog.ui
    addnewzonedialog.ui
    removezonedialog.ui
    addstockdialog.ui
    dispatchstockdialog.ui
    showavailablestockdialog.ui

  )
endif()

target_link_libraries(WarehouseSystem PRIVATE Qt5::Widgets)
target_include_directories(WarehouseSystem PUBLIC include)
target_link_libraries(WarehouseSystem PUBLIC sqlite3)
target_link_libraries(WarehouseSystem PRIVATE Qt5::Sql)


