#include <stdio.h>

double determinant2x2(double a, double b, double c, double d) { // 2x2 NOT WORK 
    return a * d - b * c; // Определитель 2x2
}

double determinant3x3(double a1, double a2, double a3,
                       double b1, double b2, double b3,
                       double c1, double c2, double c3) {
    return a1 * (b2 * c3 - b3 * c2) -
           a2 * (b1 * c3 - b3 * c1) +
           a3 * (b1 * c2 - b2 * c1); // Определитель 3x3
}

// Функция для решения системы уравнений методом Крамера
void solveCramer(int N, double A[N][N], double B[N]) {
    double D = 0, Dx[N];

    // Вычисляем определитель D для матрицы A
    if (N == 2) {
        D = determinant2x2(A[0][0], A[0][1], A[1][0], A[1][1]);
    } else if (N == 3) {
        D = determinant3x3(A[0][0], A[0][1], A[0][2],
                           A[1][0], A[1][1], A[1][2],
                           A[2][0], A[2][1], A[2][2]);
    }

    if (D == 0) {
        printf("Система не имеет уникального решения.\n");
        return; // Проверка на наличие решений
    }

    // Для каждой переменной вычисляем определитель Dx
    for (int i = 0; i < N; i++) {
        double temp[N][N];

        // Замена i-го столбца на B
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (k == i) {
                    temp[j][k] = B[j];  // Вставляем B[j] вместо A[j][i]
                } else {
                    temp[j][k] = A[j][k];
                }
            }
        }

        // Вычисляем определитель для новой матрицы
        if (N == 2) {
            Dx[i] = determinant2x2(temp[0][0], temp[0][1], temp[1][0], temp[1][1]);
        } else if (N == 3) {
            Dx[i] = determinant3x3(temp[0][0], temp[0][1], temp[0][2],
                                   temp[1][0], temp[1][1], temp[1][2],
                                   temp[2][0], temp[2][1], temp[2][2]);
        }
    }

    // Вычисляем и выводим решения
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, Dx[i] / D);
    }
}

int main() {
    int N;
    printf("Введите размерность системы (2 или 3): ");
    scanf("%d", &N);

    if (N < 2 || N > 3) {
        printf("Недопустимая размерность.\n");
        return 1;
    }

    double A[3][3]; // Массив для коэффициентов (максимум 3x3)
    double B[3];    // Массив для свободных членов

    printf("Введите элементы матрицы A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Введите свободные члены B:\n");
    for (int i = 0; i < N; i++) {
        scanf("%lf", &B[i]);
    }

    solveCramer(N, A, B);

    return 0;
}