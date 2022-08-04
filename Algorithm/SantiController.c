//
// Created by 24216 on 2022/5/21.
//

#include "SantiController.h"

#include "SantiMath.h"

void scPID_set(scStruct_pid* pid, scFloat p, scFloat i, scFloat d, scFloat i_max, scFloat low_pass){
    pid->kp = p;
    pid->ki = i;
    pid->kd = d;
    pid->i_max = i_max;
    pid->low_pass = low_pass;
    pid->t_p = 0;
    pid->t_i = 0;
    pid->t_d = 0;
}

scFloat scPID_calc_incremental(scStruct_pid* pid, scFloat error){
    pid->t_p = error;
    pid->t_d = (error - pid->t_p) * pid->low_pass + pid->t_d * (1 - pid->low_pass);
    pid->t_i += error;

//    if(pid->ki != 0)
//        pid->t_i = scMath_safe_rangeF(pid->t_i, -pid->i_max/pid->ki, pid->i_max/pid->ki);

    return pid->kp * pid->t_p + pid->ki * pid->t_i + pid->kd * pid->t_d;
}