#include <stdio.h>

int main(){
int i, a = 11;
	for (i = 2; i < a; i ++){
		if (a % i == 0){
			break;
		}
	}
	if (i == a){
		puts("Good");
	}
}

//простое число
