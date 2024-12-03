#include <stdio.h>
#include "time_operations.h"

int main() {
    int n;

    printf("Введите количество этапов: ");
    scanf("%d", &n);

    Time stages[n];
    for (int i = 0; i < n; i++) {
        int hours, minutes;
        printf("Введите время этапа %d (часы и минуты): ", i + 1);
        scanf("%d %d", &hours, &minutes);
        stages[i] = initialize_time(hours, minutes);
    }

    // Подсчет общего времени
    Time total_time = calculate_total_time(stages, n);

    // Поиск минимального времени этапа
    Time min_time = find_min_time(stages, n);

    printf("Общее время: %d часов %d минут\n", total_time.hours, total_time.minutes);
    printf("Минимальное время этапа: %d часов %d минут\n", min_time.hours, min_time.minutes);

    return 0;
}