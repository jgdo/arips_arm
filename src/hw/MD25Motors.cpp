/*
 * MD25Motors.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: jgdo
 */

#include <hw/MD25Motors.h>

#include <Arduino.h>

#if 0
#include <Wire.h>
#if defined(ARDUINO_SAM_DUE)
 #define WIRE Wire1
#else
 #define WIRE Wire
#endif

#endif

namespace hw {

#define MD25_I2C_ADDR   (0xB0 >> 1)

#define MD25_REG_SPEED1             0
#define MD25_REG_SPEED2             1
#define MD25_REG_ENC1               2
#define MD25_REG_ENC2               6
#define MD25_REG_FIRMWARE_VERSION   13
#define MD25_REG_COMMAND            16

#define MD25_CMD_RESET_ENCODERS     0x20

void MD25Motors::init() {
    Serial3.begin(38400, UARTClass::MODE_8N2);

    setSpeedLeftRight(0, 0);
}

void MD25Motors::_setMotorPWM(int motor, float percent) {
    assignMotorSpeed(motor, percent);
    sendI2CSpeedCommand();
}

void MD25Motors::assignMotorSpeed(int motor, float percent) {
    speed[motor] = 128 + percent * 127;
    if (speed[motor] < 0)
        speed[motor] = 0;
    else if (speed[motor] > 255)
        speed[motor] = 255;
}

void MD25Motors::setSpeedLeftRight(float left, float right) {
    assignMotorSpeed(MOTOR_LEFT, left);
    assignMotorSpeed(MOTOR_RIGHT, right);
    sendI2CSpeedCommand();
}

int MD25Motors::readDistance(int32_t * left, int32_t * right) {
    uint8_t writebuf[] = {0, 0x25};
    Serial3.write(writebuf, sizeof(writebuf));

   if(Serial3.available() >= 8) {
       uint8_t buf[8];
       Serial3.readBytes(buf, sizeof(buf));

       *left = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | (buf[3] << 0);
       *right = (buf[4] << 24) | (buf[5] << 16) | (buf[6] << 8) | (buf[7] << 0);
       return 0;
   } else {
       return -1;
   }

#if 0
    WIRE.beginTransmission(MD25_I2C_ADDR);
    WIRE.write(MD25_REG_ENC1);
    WIRE.endTransmission(false);

    uint8_t buf[8];

    WIRE.requestFrom(MD25_I2C_ADDR, 8);

    if(WIRE.available() < sizeof(buf))
        return -1;

    WIRE.readBytes(buf, sizeof(buf));

    // WIRE.endTransmission();

    // data is big endian
    *left = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | (buf[3] << 0);
    *right = (buf[4] << 24) | (buf[5] << 16) | (buf[6] << 8) | (buf[7] << 0);
    return 0;

#endif
}

int MD25Motors::resetEncoder() {
    uint8_t buf[] = {0, 0x35};
    Serial3.write(buf, sizeof(buf));
    return 0;

#if 0
    uint8_t buf[2] = { MD25_REG_COMMAND, MD25_CMD_RESET_ENCODERS };

    WIRE.beginTransmission(MD25_I2C_ADDR);
    WIRE.write(buf, sizeof(buf));
    WIRE.endTransmission();

    return 0;
#endif
}

void MD25Motors::sendI2CSpeedCommand() {
#if 0
    WIRE.beginTransmission(MD25_I2C_ADDR);
    WIRE.write(MD25_REG_SPEED1);
    WIRE.write(speed[0]);
    WIRE.endTransmission();

    WIRE.beginTransmission(MD25_I2C_ADDR);
    WIRE.write(MD25_REG_SPEED2);
    WIRE.write(speed[1]);
    WIRE.endTransmission();

#endif

    uint8_t buf[] = {0, 0x31, speed[0], 0, 0x32, speed[1]};

    Serial3.write(buf, sizeof(buf));
}

} /* namespace hw */
