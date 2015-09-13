FIND_PACKAGE (Threads)

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

ADD_LIBRARY (wiringPi
        drcSerial.c
        max31855.c
        max5322.c
        mcp23008.c
        mcp23016.c
        mcp23017.c
        mcp23s08.c
        mcp23s17.c
        mcp3002.c
        mcp3004.c
        mcp3422.c
        mcp4802.c
        pcf8574.c
        pcf8591.c
        piHiPri.c
        piThread.c
        sn3218.c
        softPwm.c
        softServo.c
        softTone.c
        sr595.c
        wiringPi.c
        wiringPiI2C.c
        wiringPiSPI.c
        wiringSerial.c
        wiringShift.c
        wpiExtensions.c
)

TARGET_LINK_LIBRARIES (wiringPi ${CMAKE_THREAD_LIBS_INIT})

