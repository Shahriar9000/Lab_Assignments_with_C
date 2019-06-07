#include <stdio.h>
#include <stdint.h> // for uint8_t
#include <stdlib.h>
#include <string.h>
#include "image3.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

using namespace std;

/* Constructs an image of 0x0 pixels. */
Image::Image() : cols(0), rows(0), pixels(NULL){
    
}


/* Frees all memory allocated for img */
Image::~Image(){
    if(pixels){
        for(int i = 0; i < rows; i++){
            delete[] pixels[i];
        }
        delete[] pixels;
    }
}

/* Changes the size of an image, allocating memory as necessary, and
 setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/



int Image::resize(unsigned int width, unsigned int height, uint8_t fillcolor) {
/*Width of the image is stored in columns.
Height of the image is stored in rows.*/
cols=width;
rows=height;
pixels=(uint8_t**)malloc(sizeof(uint8_t*)*cols);
if(pixels==NULL) {
return -1;
}
for(int i=0; i<cols; i++) {
pixels[i]=(uint8_t*)malloc(sizeof(uint8_t)*rows);
if(pixels[i]==NULL) {
return -1;
}
for(int j=0; j<rows; j++) {
pixels[i][j]=fillcolor;
}
}
return 0;
}


int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
    if(pixels) {
        if(x < cols && y < rows) {
            pixels[y][x] = color;
            return 0;
        }
    }
    return 1;
}

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ) {
    if(pixels && colorp != NULL) {
        if(x < cols && y < rows)  {
            *colorp = pixels[y][x];
            return 0;
        }
    }
    return 1;
}


int Image::save( const char* filename) {
	if (filename == NULL)
	{ return 1;}
    ofstream output_file(filename,ios::binary);
    if (!output_file) {
        return 1;
    }
    output_file.write(reinterpret_cast<char*>(&cols), sizeof(unsigned int));
    output_file.write(reinterpret_cast<char*>(&rows), sizeof(unsigned int));
 
    for (int i = 0; i < cols; i++) {
        uint8_t *eachRow = pixels[i];
        output_file.write(reinterpret_cast<char*>(&eachRow), sizeof(uint8_t) * rows);
    }
   output_file.write(reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows);
	output_file.close();
    return 0;
}


int Image::load( const char* filename ){
if (filename == NULL)
	{ return 1;}

    ifstream input_file(filename,ios::binary);
    if (!input_file) {
        return 1;
    }
    input_file.read(reinterpret_cast<char*>(&cols), sizeof(unsigned int));
    input_file.read(reinterpret_cast<char*>(&rows), sizeof(unsigned int));
  
    for (int i = 0; i < cols; i++) {
        uint8_t *eachRow = pixels[i];
        input_file.read(reinterpret_cast<char*>(&eachRow), sizeof(uint8_t) * rows);
    }
  input_file.read(reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows);
	input_file.close();
	delete input_file;
    
    return 0;
}
