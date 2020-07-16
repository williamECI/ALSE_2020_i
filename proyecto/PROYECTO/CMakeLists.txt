cmake_minimum_required( VERSION 3.10 )

project (clima)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

add_executable (${PROJECT_NAME} "main.cpp" "Dato.h" "Dato.cpp" "Muestreador.h" "Muestreador.cpp" "Estacion_meteo.h" "Estacion_meteo.cpp" "alarma_class.h" "alarma_class.cpp" "DB_local.h" "DB_local.cpp")

target_link_libraries(${PROJECT_NAME} Qt5::Core sqlite3)


