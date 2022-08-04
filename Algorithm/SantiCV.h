//
// Created by 24216 on 2022/5/20.
//

#ifndef SANTICCORE_SANTICV_H
#define SANTICCORE_SANTICV_H

#include "SantiDefine.h"

#include "SantiPoint.h"
#include "SantiMatrix.h"

/*
 * General Visual Algorithm
 */

// get the perspective transformation matrix (3*3) according to 4 points
// return false if there is not a unique solution for matrix
bool scCV_perspective_trans_get_matrix(const scStruct_pointlist_Float * pl, const scStruct_pointlist_Float * pl_to,
                                       scStruct_matrix* m_ans);

// calculate the perspective transformed point
scStruct_point_Float scCv_perspective_trans_calc_point(scStruct_point_Int32 p, const scStruct_matrix* matrix_trans);

// use Otsu's method to perform automatic image thresholding
scUInt8 scCV_threshold_OTSU(const scUInt8* histogram);

#endif //SANTICCORE_SANTICV_H
