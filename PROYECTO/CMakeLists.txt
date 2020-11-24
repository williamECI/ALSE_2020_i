cmake_minimum_required( VERSION 3.10 )

project (clima)

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS})
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable (${PROJECT_NAME} "main.cpp" "Dato.h" "Dato.cpp" "Muestreador.h" "Muestreador.cpp" "Estacion_meteo.h" "Estacion_meteo.cpp" "estacion_interface.h" "estacion_interface.cpp" "estacion_interface.ui" "DB_local.h" "DB_local.cpp" "DB_remota.h" "DB_remota.cpp")

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets sqlite3 mysqlclient)



