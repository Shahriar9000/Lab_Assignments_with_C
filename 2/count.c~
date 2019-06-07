/*#include <stdio.h>
#include <string.h>

int main()
{
char ch;
unsigned long int charcount =0;	
unsigned long int wordcount =0;	
unsigned long int linecount =0;	
	
while ( (ch= getchar()) != EOF){
	
 if (ch != ' ' && ch != '\n' && ch != '\'') { ++charcount; }
  if (ch == ' ' || ch == '\n') { ++wordcount; }
    if (ch == '\n') { ++linecount; }

}


printf( "%lu %lu %lu\n", charcount, wordcount, linecount );


return 0;
}*/

#include <stdio.h>

int main() {

    char iochar;
    unsigned long int charcount = 0;
    unsigned long int wordcount = 0;
    unsigned long int linecount = 0;
    int flag =0;

    while ((iochar = getchar ()) !=EOF) {

        if (iochar != ' ' || iochar != '\n') {
          ++charcount;
         }

         if (iochar == '\n') {
           ++linecount;
         }

        if(((iochar >= 'a') && (iochar <= 'z')) || ((iochar >= 'A') && (iochar <= 'Z')) ||  (iochar == '\'')) {

                flag=1;
          }

          else if(flag==1){
            ++wordcount;
            flag=0;
            }

}

printf( "%lu %lu %lu\n", charcount, wordcount, linecount );
return 0;

}
