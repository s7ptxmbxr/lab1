#include <stdio.h>

int main(){

int a = 5;
int n;
for (n = 2; n < a; n ++){

	if (a % n == 0){
		break;
			}
	}
	if (n == a){
		puts("Good");
	}
}


//простое число
