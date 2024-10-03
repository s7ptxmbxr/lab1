#include <stdio.h>

int main() {
int n1, n2;
printf("Введите два числа: ");
scanf("%d %d", &n1, &n2);

int nod = 1; // Наибольший общий делитель

  // Находим наибольший общий делитель
for (int i = 1; i <= n1 && i <= n2; i++) {
	if (n1 % i == 0 && n2 % i == 0) {
      		nod = i;
	}
}

	printf("Наибольший общий делитель %d и %d равен: %d\n", n1, n2, nod);

 return 0;
}
