//
// Created by 24216 on 2022/5/19.
//

#include "SantiMatrix.h"

#include "SantiMath.h"

#ifdef ENABLE_SANTICCORE_DEBUG
#include <SantiError.h>
#endif

static inline void check_matrix(const scStruct_matrix* m){
    if(m == NULL)
        SC_ERROR_REPORT(BAD_PARAMETER);
}

static inline void check_r_c_range(const scStruct_matrix* m, const scInt32 r, const scInt32 c){
    check_matrix(m);
    if(m->columns < c || m->rows < r || m->m == NULL)
        SC_ERROR_REPORT(BAD_PARAMETER);
}

static inline void check_r_range(const scStruct_matrix* m, const scInt32 r){
    check_matrix(m);
    if(m->rows < r || m->m == NULL)
        SC_ERROR_REPORT(BAD_PARAMETER);
}

static inline void check_r_c_new_valid(const scInt32 r, const scInt32 c){
    if(r<0 || c<0)
        SC_ERROR_REPORT(BAD_PARAMETER);
}

scStruct_matrix scMatrix_init(scInt32 rows, scInt32 columns, scFloat* m){
    if(rows<0 || columns<0)
        SC_ERROR_REPORT(BAD_PARAMETER);
    for(int i=0;i<rows*columns;++i)
        m[i]=0;
    scStruct_matrix res = {rows, columns, m};
    return res;
}

scFloat scMatrix_get(const scStruct_matrix* m, const scInt32 r, const scInt32 c){
    check_r_c_range(m, r, c);
    return m->m[r * m->columns + c];
}

void scMatrix_set(const scStruct_matrix* m, const scInt32 r, const scInt32 c, const scFloat val){
    check_r_c_range(m, r, c);
    m->m[r * m->columns + c] = val;
}

void scMatrix_add(const scStruct_matrix* m, const scInt32 r, const scInt32 c, const scFloat val){
    check_r_c_range(m, r, c);
    m->m[r * m->columns + c] += val;
}

void scMatrix_reshape(scStruct_matrix* m, const scInt32 rows_new, const scInt32 columns_new, scFloat* mem){
    check_matrix(m);
    check_r_c_new_valid(rows_new, columns_new);
    if(mem == NULL)
        SC_ERROR_REPORT(BAD_PARAMETER);
    for(scInt32 i=0; i < scMath_min_Float(m->rows * m->columns, rows_new * columns_new); ++i)
        mem[i] = m->m[i];
    m->m = mem;
    m->rows = rows_new;
    m->columns = columns_new;
}

void scMatrix_swap_line(scStruct_matrix* m, const scInt32 r1, const scInt32 r2){
    check_r_range(m, r1);
    check_r_range(m, r2);
    scInt32 r1s = r1 * m->columns;
    scInt32 r2s = r2 * m->columns;
    for(scInt32 i=0; i < m->columns; ++i)
        scMath_swap_Float(&m->m[r1s+i], &m->m[r2s+i]);
}

void scMatrix_multiply(const scStruct_matrix* m1, const scStruct_matrix* m2, scStruct_matrix* ans){
    if(m1->columns != m2->rows)
        SC_ERROR_REPORT(MATH_INVALID);
    if(ans->rows!=m1->rows || ans->columns!=m2->columns)
        SC_ERROR_REPORT(BAD_PARAMETER);
    for (scInt32 i = 0; i < m1->rows; ++i)
        for (scInt32 j = 0; j < m2->columns; ++j)
            for (scInt32 k = 0; k < m1->columns; ++k)
                scMatrix_add(ans, i, j, scMatrix_get(m1, i, k) * scMatrix_get(m2, k, j));
}

bool scMatrix_solve_equation(scStruct_matrix* m, scStruct_matrix* ans){
    if(m->rows+1 != m->columns || ans->rows != m->rows || ans->columns != 1)
        SC_ERROR_REPORT(BAD_PARAMETER);
    for(scInt32 i=0; i < m->rows; ++i){
        if(scMath_equal_Float(scMatrix_get(m, i, i), 0)){
            // find a line that x_val(i) is not zero
            for(scInt32 j= i + 1; j < m->rows; ++j)
                if(!scMath_equal_Float(scMatrix_get(m, j, i), 0)){
                    scMatrix_swap_line(m, i, j);
                    break;
                }
            // if fail to find one
            if (scMath_equal_Float(scMatrix_get(m, i, i), 0))
                return FALSE;
        }
        //
        for (scInt32 j = 0; j < m->rows; ++j) {
            if (scMath_equal_Float(scMatrix_get(m, i, i), 0) || j == i) continue;
            scFloat t = scMatrix_get(m, j, i) / scMatrix_get(m, i, i);
            for (scInt32 k = 0; k < m->columns; ++k)
                scMatrix_add(m, j, k, -scMatrix_get(m, i, k) * t);
        }
    }
    //
    for (scInt32 i = 0; i < m->rows; ++i) {
        scMatrix_set(ans, i, 0, scMatrix_get(m, i, m->columns-1) / scMatrix_get(m, i, i));
        scMatrix_set(m, i, m->columns-1, scMatrix_get(ans, i, 0));
        scMatrix_set(m, i, i, 1);
    }
    return TRUE;
}

#ifdef ENABLE_SANTICCORE_DEBUG

void scMatrix_print(const scStruct_matrix* m){
    printf("Matrix[\n");
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->columns; ++j)
            printf("%12f ", scMatrix_get(m, i, j));
        if (i != m->rows - 1)
            printf("\n");
        else
            printf("\n]\n");
    }
}

#endif