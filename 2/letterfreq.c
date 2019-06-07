#include <stdio.h>
#include <ctype.h>

int main()
{


char l;
int i;
float frequency;
int a[128]= {0};

while ((l= getchar()) != EOF) {

    if (isalpha(l)){
      a[l]++;
    }
}

for (i =65; i<=90; i++){
    a[i] = a[i] + a[i+32];
    frequency = frequency + a[i];
}

for (i =65; i<=90; i++){
    if (a[i] != 0){
        printf( "%c %.4f\n", i+32, a[i]/frequency);
    }
}
return 0;
}
