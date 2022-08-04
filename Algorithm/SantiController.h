//
// Created by 24216 on 2022/5/21.
//

#ifndef SANTICCORE_SANTICONTROLLER_H
#define SANTICCORE_SANTICONTROLLER_H

#include "SantiDefine.h"

/*
 * PID
 */

typedef struct Struct_SantiPID{
    scFloat kp,ki,kd;
    // output = cur_out * low_pass + pre_out * (1-low_pass)
    scFloat low_pass;
    scFloat i_max;
    scFloat t_p, t_i, t_d;
} scStruct_pid;

void scPID_set(scStruct_pid* pid, scFloat p, scFloat i, scFloat d, scFloat i_max, scFloat low_pass);

scFloat scPID_calc_incremental(scStruct_pid* pid, scFloat error);

#endif //SANTICCORE_SANTICONTROLLER_H
