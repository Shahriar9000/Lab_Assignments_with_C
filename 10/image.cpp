#include <stdio.h>
#include <stdint.h> // for uint8_t
#include <stdlib.h>
#include <string.h>
#include "image.hpp"

/* Constructs an image of 0x0 pixels. */
Image::Image() : cols(0), rows(0), pixels(NULL){

}


/* Frees all memory allocated for img */
Image::~Image(){
    // free everything that could have been allocated inside this object
    if( pixels != NULL ) {
        delete[] pixels;
    }
}

/* Changes the size of an image, allocating memory as necessary, and
 setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/
int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
    delete[] pixels;
    pixels = new uint8_t[width * height];
    if(pixels == NULL) return 1;
    for (int i = 0; i < width*height; i++) {
        pixels[i] = fillcolor;
    }
    
    cols = width;
    rows = height;
    return 0;
}

int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
    if(pixels) {
        if(x < cols && y < rows) {
            pixels[(cols * y) + x] = color;
            return 0;
        }
    }
    return 1;
}

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ) {
    if(pixels && colorp != NULL) {
        if(x < cols && y < rows)  {
            *colorp = pixels[(cols * y) + x];
            return 0;
        }
    }
    return 1;
}

