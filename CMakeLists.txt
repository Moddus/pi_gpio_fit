cmake_minimum_required(VERSION 2.8)
PROJECT( PICLUSTERLED )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

INCLUDE_DIRECTORIES( libs/wiringPi/wiringPi )

add_subdirectory( src )
add_subdirectory( libs )

