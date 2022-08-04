//
// Created by 24216 on 2022/5/20.
//

#ifndef SANTICCORE_SANTIERROR_H
#define SANTICCORE_SANTIERROR_H

#define SC_ERROR_ARRAY_OUT_OF_RANGE 1
#define SC_ERROR_MATH 2
#define SC_ERROR_BAD_PARAMETER 3
#define SC_ERROR_UNSOLVABLE 4

void scError_handle(char scError_id, const char* where);

#endif //SANTICCORE_SANTIERROR_H
