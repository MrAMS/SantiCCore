//
// Created by 24216 on 2022/5/21.
//

#ifndef SANTICCORE_SANTIIMAGE_H
#define SANTICCORE_SANTIIMAGE_H

#include "SantiDefine.h"

/*
 * SantiImage gray image
 */

typedef struct Struct_SantiImage_gray{
    scInt32 h,w;
    scUInt8* img;
} scStruct_img_gray;

// get g_img[y][x].
// Note that the origin is in the upper left corner.
scUInt8 scImage_get(const scStruct_img_gray* img, scInt32 x, scInt32 y);

// set g_img[y][x] to val
// Note that the origin is in the upper left corner.
void scImage_set(const scStruct_img_gray* img, scInt32 x, scInt32 y, scUInt8 val);

// simply resample the g_img to zip
void scImage_zip_img(const scStruct_img_gray* img, scInt32 scale, scStruct_img_gray* res);

// get the histogram of the image
void scImage_get_histogram(const scStruct_img_gray* img, scUInt8* res);

#endif //SANTICCORE_SANTIIMAGE_H
