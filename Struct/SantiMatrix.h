//
// Created by 24216 on 2022/5/19.
//

#ifndef SANTICCORE_SANTIMATRIX_H
#define SANTICCORE_SANTIMATRIX_H

#include "SantiDefine.h"
#include "SantiError.h"

/*
 * Matrix
 */

typedef struct Struct_SantiMatrix{
    scInt32 rows, columns;
    scFloat* m;
} scStruct_matrix;

scStruct_matrix scMatrix_init(scInt32 rows, scInt32 columns, scFloat* m);

scFloat scMatrix_get(const scStruct_matrix* m, scInt32 r, scInt32 c);

void scMatrix_set(const scStruct_matrix* m, scInt32 r, scInt32 c, scFloat val);

void scMatrix_add(const scStruct_matrix* m, scInt32 r, scInt32 c, scFloat val);

// reshape the matrix which is filled with the original value in order
void scMatrix_reshape(scStruct_matrix* m, scInt32 rows_new, scInt32 columns_new, scFloat* mem);

void scMatrix_swap_line(scStruct_matrix* m, scInt32 r1, scInt32 r2);

void scMatrix_multiply(const scStruct_matrix* m1, const scStruct_matrix* m2, scStruct_matrix* ans);

// solve the matrix equation and return true if there is a unique solution.
bool scMatrix_solve_equation(scStruct_matrix* m, scStruct_matrix* ans);

#ifdef ENABLE_SANTICCORE_DEBUG

void scMatrix_print(const scStruct_matrix* m);

#endif

#endif //SANTICCORE_SANTIMATRIX_H
