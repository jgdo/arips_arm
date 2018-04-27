/*
 * Servo.h
 *
 *  Created on: Apr 20, 2018
 *      Author: jgdo
 */

#ifndef HW_SERVO_H_
#define HW_SERVO_H_


namespace hw {

struct Servo {
    virtual ~Servo() {}
    virtual void setDegrees(float) = 0;
};


}


#endif /* HW_SERVO_H_ */
