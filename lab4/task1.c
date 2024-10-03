#include <stdio.h>

int main(){

int a = 0, b = 0, c = 0;

	while(c < 5){

		c ++;
		a = 0;

		while(a < 5){

			a++;
			b = b + 1;
			printf("%d ",b);

		if (b % 5 == 0){
			printf("\n");
		}
	}
		}
}
