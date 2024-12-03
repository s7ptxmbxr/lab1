#include "time_operations.h"

// Функция инициализации структуры
Time initialize_time(int hours, int minutes) {
    Time t;
    t.hours = hours;
    t.minutes = minutes;
    return t;
}

// Функция подсчета общего времени
Time calculate_total_time(Time stages[], int n) {
    Time total = initialize_time(0, 0);
    for (int i = 0; i < n; i++) {
        total.hours += stages[i].hours;
        total.minutes += stages[i].minutes;

        // Перевод минут в часы, если больше 60
        if (total.minutes >= 60) {
            total.hours += total.minutes / 60;
            total.minutes %= 60;
        }
    }
    return total;
}

// Функция поиска минимального времени этапа
Time find_min_time(Time stages[], int n) {
    Time min_time = stages[0];
    for (int i = 1; i < n; i++) {
        if (stages[i].hours < min_time.hours ||
           (stages[i].hours == min_time.hours && stages[i].minutes < min_time.minutes)) {
            min_time = stages[i];
        }
    }
    return min_time;
}