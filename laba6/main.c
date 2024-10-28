#include <stdio.h>

// Структура для представления комплексного числа 
typedef struct {
    double real;
    double imag;
} Complex;

// Функция для сложения двух комплексных чисел
void addComplex(Complex a, Complex b, Complex* result) {
    result->real = a.real + b.real;
    result->imag = a.imag + b.imag;
}

int main() {
    int n = 5; // размер массивов
    Complex A[n], B[n], C[n];

    // Заполнение массива A комплексными числами
    for (int i = 0; i < n; i++) {
        A[i].real = i + 1; // например, 1, 2, 3, ...
        A[i].imag = (i % 2 == 0) ? i : -i; // чередуем мнимую часть
    }

    // Заполнение массива B комплексными числами
    for (int i = 0; i < n; i++) {
        B[i].real = (i * 2); // например, 0, 2, 4, ...
        B[i].imag = -(i + 1); // отрицательные мнимые части
    }

    // Сложение A и B
    for (int i = 0; i < n; i++) {
        addComplex(A[i], B[i], &C[i]);
    }

    // Нахождение максимальной реальной части в массиве A
    double maxRealA = A[0].real;
    for (int i = 1; i < n; i++) {
        if (A[i].real > maxRealA) {
            maxRealA = A[i].real;
        }
    }
    printf("Максимальная реальная часть A: %.2f\n", maxRealA);

    // Подсчет количества мнимых частей, которые меньше 0 в массиве B
    int countImagNegativeB = 0;
    for (int i = 0; i < n; i++) {
        if (B[i].imag < 0) {
            countImagNegativeB++;
        }
    }
    printf("Количество мнимых частей < 0 в B: %d\n", countImagNegativeB);

    // Вычисление среднего арифметического элементов массива C
    double sumReal = 0, sumImag = 0;
    for (int i = 0; i < n; i++) {
        sumReal += C[i].real;
        sumImag += C[i].imag;
    }
    double averageReal = sumReal / n;
    double averageImag = sumImag / n;

    printf("Среднее арифметическое реальной части C: %.2f\n", averageReal);
    printf("Среднее арифметическое мнимой части C: %.2f\n", averageImag);

    return 0;
}
