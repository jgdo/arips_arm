/*
 * Kalman.h
 *
 *  Created on: Jul 12, 2018
 *      Author: jgdo
 */

#ifndef UTL_KALMAN_H_
#define UTL_KALMAN_H_

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-in-bool-context"

#include <Eigen/Dense>

#pragma GCC diagnostic pop


template<unsigned SIZE_STATE, unsigned SIZE_OBS, unsigned CONTROL_SIZE>
class KalmanFilter {
public:
    KalmanFilter(): P(Eigen::Matrix<float, SIZE_STATE, SIZE_STATE>::Identity()) {
        x.setZero();
    }

    Eigen::Matrix<float, SIZE_STATE, 1> update(Eigen::Matrix<float, SIZE_OBS, 1> z, Eigen::Matrix<float, CONTROL_SIZE, 1> u) {
        auto I = Eigen::Matrix<float, SIZE_STATE, SIZE_STATE>::Identity();

        Eigen::Matrix<float, SIZE_STATE, 1> x_p = F*x + B*u;
        Eigen::Matrix<float, SIZE_STATE, SIZE_STATE> P_p = F*P*F.transpose() + Q;

        Eigen::Matrix<float, SIZE_OBS, 1> y = z - H*x_p;
        Eigen::Matrix<float, SIZE_OBS, SIZE_OBS> S = R + H*P_p*H.transpose();
        Eigen::Matrix<float, SIZE_STATE, SIZE_OBS> K = P_p*H.transpose()*S.inverse();
        x = x_p + K*y;
        P = (I - K*H)*P_p*(I - K*H).transpose() + K*R*K.transpose();

        return x;
    }

    Eigen::Matrix<float, SIZE_STATE, 1> x;

    Eigen::Matrix<float, SIZE_STATE, SIZE_STATE> F;
    Eigen::Matrix<float, SIZE_OBS, SIZE_STATE> H;
    Eigen::Matrix<float, SIZE_STATE, CONTROL_SIZE> B;


    Eigen::Matrix<float, SIZE_STATE, SIZE_STATE> Q;
    Eigen::Matrix<float, SIZE_OBS, SIZE_OBS> R;

    Eigen::Matrix<float, SIZE_STATE, SIZE_STATE> P;
};


#endif /* UTL_KALMAN_H_ */
