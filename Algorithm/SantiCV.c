//
// Created by 24216 on 2022/5/20.
//

#include "SantiCV.h"

#include "SantiError.h"
#include "SantiMath.h"

#define PX(i) (pl->p[i].x)
#define PY(i) (pl->p[i].y)

bool scCV_perspective_trans_get_matrix(const scStruct_pointlist_Float * pl, const scStruct_pointlist_Float * pl_to,
                                       scStruct_matrix* m_ans){
    if(pl->len!=4 || pl_to->len!=4 || m_ans->rows!=8 || m_ans->columns!=1)
        scError_handle(SC_ERROR_BAD_PARAMETER, "scCV_perspective_trans_get_matrix");
    float m_data[8*9]={0};
    scStruct_matrix m = {8, 9, m_data};
    for(scChar i=0;i<4;++i){
        scMatrix_set(&m, i*2, 0, PX(i));
        scMatrix_set(&m, i*2, 1, PY(i));
        scMatrix_set(&m, i*2, 2, 1);
        scMatrix_set(&m, i*2, 6, -PX(i) * pl_to->p[i].x);
        scMatrix_set(&m, i*2, 7, -PY(i) * pl_to->p[i].x);

        scMatrix_set(&m, i*2+1, 3, PX(i));
        scMatrix_set(&m, i*2+1, 4, PY(i));
        scMatrix_set(&m, i*2+1, 5, 1);
        scMatrix_set(&m, i*2+1, 6, -PX(i) * pl_to->p[i].y);
        scMatrix_set(&m, i*2+1, 7, -PY(i) * pl_to->p[i].y);

        scMatrix_set(&m, i*2, 8, pl_to->p[i].x);
        scMatrix_set(&m, i*2+1, 8, pl_to->p[i].y);
    }
    if(!scMatrix_solve_equation(&m, m_ans))
        return FALSE;
    scMatrix_reshape(m_ans, 3, 3, m_ans->m);
    m_ans->m[8] = 1;
    return TRUE;
}

scStruct_point_Float scCv_perspective_trans_calc_point(scStruct_point_Int32 p, const scStruct_matrix* matrix_trans){
    float m_data[3]={0};
    scStruct_matrix m = {3, 1, m_data};
    float m_p_data[3]= {p.x, p.y, 1};
    scStruct_matrix m_p = {3, 1, m_p_data};
    scMatrix_multiply(matrix_trans, &m_p, &m);
    scStruct_point_Float res = {scMatrix_get(&m, 0, 0)/scMatrix_get(&m, 2, 0),
                           scMatrix_get(&m, 1, 0)/scMatrix_get(&m, 2, 0)};
    return res;
}

scUInt8 scCV_threshold_OTSU(const scUInt8* histogram){
    scFloat w0=0,u0=0,u=0,pixel_cnt_sum=0;
    for(scInt16 i=0; i < 256; ++i)
        pixel_cnt_sum += histogram[i]*1.0;
    for(scInt16 i=0; i < 256; ++i)
        u += i * histogram[i] * 1.0/pixel_cnt_sum;
    scInt16 ret_ans = 0;
    scFloat g_mx = 0;
    for(;ret_ans<256;++ret_ans){
        scFloat ww = histogram[ret_ans]*1.0/pixel_cnt_sum;
        w0 += ww;
        scFloat w1 = 1- w0;
        u0 += ret_ans*1.0 * ww;
        scFloat u1 = u - u0;
        scFloat g = w0*scMath_sqr_Float(u0-u) + w1*scMath_sqr_Float(u1-u);
        g_mx = g;
        // optimized
        if(g<g_mx)
            break;
    }
    return ret_ans;
}