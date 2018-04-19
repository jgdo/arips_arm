/*
 * MD25Motors.h
 *
 *  Created on: Apr 7, 2018
 *      Author: jgdo
 */

#ifndef HW_MD25MOTORS_H_
#define HW_MD25MOTORS_H_

#include <cstdint>

namespace hw {

class MD25Motors {
public:
    static const int MOTOR_LEFT = 0, MOTOR_RIGHT = 1;

    void init();

    void setSpeedLeftRight(float left, float right);

    void requestDistance();

    int tryReadDistance(int32_t *left, int32_t *right);

    int resetEncoder();

protected:
    void _setMotorPWM(int motor, float percent);

    void assignMotorSpeed(int motor, float percent);

    void sendI2CSpeedCommand();

private:
    int speed[2] = { 128, 128 };

    uint32_t mLastOdomotryRequestMs;
};

} /* namespace hw */

#endif /* HW_MD25MOTORS_H_ */
