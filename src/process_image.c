#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{

    if(x < 0){ x= 0;}   if(x >= im.w){x = im.w-1;}
    if(c < 0){c = 0;}   if(c >= im.c){c = im.c-1;}
    if(y < 0){y = 0;}   if(y >= im.h){y = im.h-1;} 

    int ind=x+y*im.w+c*im.h*im.w;


    return im.data[ind];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    
    for(int p=0; p<im.c; p++) {
        for(int q=0; q<im.h; q++) {
            for(int r=0; r<im.w; r++) {
                copy.data[r + q*im.w + p*im.w*im.h] = im.data[r + q*im.w + p*im.w*im.h];
            }
        }
    }
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    for(int i=0;i<im.h;i++){
        for(int j=0;j<im.w;j++){
            gray.data[i*im.w+j]=0.299*im.data[i*im.w+j]  + 0.587*im.data[im.w*im.h+i*im.w+j]  + 0.114*im.data[2*im.w*im.h+i*im.w+j];
        }
    }    
    return gray;
}

void shift_image(image im, int c, float v)
{
    for(int m=0;m<im.h;m++){
        for(int n=0;n<im.w;n++){
            im.data[c*im.h*im.w + m*im.w + n]+=v;
        }
    }
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}