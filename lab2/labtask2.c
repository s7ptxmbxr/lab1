#include <stdio.h>

void main(){

char a;
float b;

printf("enter number and C or F:\n");
scanf("%f %c", &b, &a);

if (a == 'c'|| a == 'C'){

printf("%f", b * 1.8 + 32);

}
else if (a == 'f'|| a == 'F'){

printf("%f", (b - 32) / 1.8);

}


}
