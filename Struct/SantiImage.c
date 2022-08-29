//
// Created by 24216 on 2022/5/21.
//

#include "SantiImage.h"

#include "SantiError.h"

scUInt8 scImage_get(const scStruct_img_gray* img, const scInt32 x, const scInt32 y){
    if(x>=img->w || y>=img->h)
        SC_ERROR_REPORT(ARRAY_OUT_OF_RANGE);
    return img->img[y*img->w+x];
}

void scImage_set(const scStruct_img_gray* img, const scInt32 x, const scInt32 y, scUInt8 val){
    if(x>=img->w || y>=img->h)
        SC_ERROR_REPORT(ARRAY_OUT_OF_RANGE);
    img->img[y*img->w+x] = val;
}

void scImage_zip_img(const scStruct_img_gray* img, const scInt32 scale, scStruct_img_gray* res){
    if(res->h<img->h/scale || res->w<img->w/scale)
        SC_ERROR_REPORT(BAD_PARAMETER);
    res->h = img->h/scale;
    res->w = img->w/scale;
    for(scInt32 i=0; i < res->w; ++i)
        for(scInt32 j=0; j < res->h; ++j)
            scImage_set(res, i, j, scImage_get(img, i*scale, j*scale));
}

void scImage_get_histogram(const scStruct_img_gray* img, scUInt8* res){
    for(scInt32 i=0; i < 256; ++i)
        res[i]=0;
    for(scInt32 i=0; i < img->w; ++i)
        for(scInt32 j=0; j < img->h; ++j)
            res[scImage_get(img, i, j)] += 1;
}