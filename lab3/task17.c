#include <stdio.h>

int main(){
int n = 2, flag = 0, b = 13;

while (b % n !=0){

	n++;
	if (n == b){
	flag = 1;
	break;
	}
	}
	if (flag == 1){
		printf("число простое");
	}


	else{
		printf("число имеет НОД:%d\n ", n);
	}
		   }


