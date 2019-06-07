#include <sstream>
#include <stdio.h>
#include <stdint.h> // for uint8_t
#include <stdlib.h>
#include <string.h>
#include "image2.hpp"
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

/* Constructs an image of 0x0 pixels. */
Image::Image() : cols(0), rows(0), pixels(NULL){

}


/* Frees all memory allocated for img */
Image::~Image(){
    // free everything that could have been allocated inside this object
    if( pixels != NULL ) {
        delete[] pixels;
    }
    pixels = NULL;
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

int Image::save(const char* filename) {
   if (filename == NULL) {
       printf("%s\n", "Error: No name supplied!");
       return 1;
   }

   //open the file and start a string stream
   ofstream openedFile;
   openedFile.open(filename);

   //strings to store the rows and cols
   char colsString[7];
   char rowsString[7];

   //convert to strings
   sprintf(colsString, "%d", cols);
   sprintf(rowsString, "%d", rows);

   //write to file
   openedFile << colsString << std::endl;
   openedFile << rowsString << std::endl;

   //convert pixels to strings, and write to file
   for (unsigned int pos = 0; pos < rows*cols; pos++) {
       char pxString[7];
       sprintf(pxString, "%d", pixels[pos]);

       openedFile << pxString << std::endl;
   }

   //we're done so close everything and return success
   openedFile.close();
   return 0;
}




/*int Image::save( const char* filename) {
    ofstream output_file(filename,ios::binary);
    if (!output_file) {
        return 1;
    }
    output_file.write(reinterpret_cast<char*>(&cols), sizeof(unsigned int));
    output_file.write(reinterpret_cast<char*>(&rows), sizeof(unsigned int));
    output_file.write(reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows);
output_file.close();    
return 0;
}*/

/* Load the an image from the file filename, replacing the current
 image size and data. The file is in a format that was saved by
 save().  Returns 0 success, else a non-zero error code . */


int Image::load( const char* filename ){

   	
   if (filename != NULL) {

       //set up string variable to read and store each line inside
       string line;
       ifstream openedFile(filename);

       if (openedFile) {

           if (openedFile.is_open()) {
		if (!openedFile) {
       				 return 1;}

               int pos = 0;

               //once everything is allocated, set to 1 so we don't delete and allocate new memory
               //upon the next iteration of the loop
               int gotNewMemory = 0;

                while (getline(openedFile,line)) {

                   //variable to store the chars as ints
                   int numLine;
                   istringstream (line) >> numLine;

                   //get the col
                   if (pos == 0) {
                       cols = numLine;
                       pos++;
                   }

                   //get the row
                   else if (pos == 1) {
                       rows = numLine;
                       pos++;
                   }

                   //get the pixels
                   else if (pos >= 2 && pos-2 < cols*rows) {

                       //allocate memory to store everything on the first iteration
                       if (gotNewMemory == 0) {
                           if (pixels) {delete [] pixels;}
                           pixels = new uint8_t[cols * rows];
                           gotNewMemory = 1;
                       }

                       pixels[pos-2] = numLine;
                       //printf("%d\n", numLine);
                       pos++;
                   }
                }
               openedFile.close();
           }

            return 0;
       }

       return 1;
   }

   return 1;
} 




