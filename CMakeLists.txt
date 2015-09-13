cmake_minimum_required(VERSION 3.3)
PROJECT( PICLUSTERLED )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

INCLUDE_DIRECTORIES( libs/wiringPi/wiringPi )

add_subdirectory( src )
add_subdirectory( libs )

#add_custom_command (
#	OUTPUT ${PROJECT_SOURCE_DIR}/led
#	WORKING_DIR ${PROJECT_SOURCE_DIR}/libs/wiringPi
#	COMMAND bash ${PROJECT_SOURCE_DIR}/libs/wiringPi/build
#	DEPENDS led
#)

#add_custom_target (run ALL
#	DEPENDS led)
