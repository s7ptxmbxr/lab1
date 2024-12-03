#ifndef TIME_OPERATIONS_H
#define TIME_OPERATIONS_H

// Определение структуры "Время"
typedef struct {
    int hours;
    int minutes;
} Time;

// Прототипы функций
Time initialize_time(int hours, int minutes);
Time calculate_total_time(Time stages[], int n);
Time find_min_time(Time stages[], int n);

#endif // TIME_OPERATIONS_H