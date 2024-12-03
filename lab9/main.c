#include <stdio.h>

#define N 3  // задаем размер матрицы

void find_min_position(int matrix[N][N], int *min_row, int *min_col) {
    int min_value = matrix[0][0];
    *min_row = 0; //номер строки с минимальным элементом 
    *min_col = 0; //номер столбца с минимальным элементом

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
                *min_row = i;
                *min_col = j;
            }
        }
    }
}

int main() {
    int matrix[N][N] = {
        {2, 1, 5},
        {1, 6, 4},
        {7, 8, 2}
    };

    int min_row, min_col;
    find_min_position(matrix, &min_row, &min_col);

    // находим сумму всех элементов матрицы, кроме минимального
    int total_sum = 0;
    int min_value = matrix[min_row][min_col];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            total_sum += matrix[i][j];
        }
    }
    total_sum -= min_value;

    // разделим элементы квадрата на сумму остальных элементов
    for (int i = 0; i <= min_row; i++) {
        for (int j = 0; j <= min_col; j++) {
            matrix[i][j] /= total_sum;
        }
    }

    // перевернём главную диагональ матрицы
    for (int i = 0; i < N / 2; i++) {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[N - 1 - i][N - 1 - i];
        matrix[N - 1 - i][N - 1 - i] = temp;
    }

    // выводим изменённую матрицу
    printf("Изменённая матрица:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}