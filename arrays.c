#include <stdio.h>

int array_max(int arr[], int len);

int main(void) {
        
    int scores[8] = {72, 95, 68, 88, 91, 77, 84, 79};
    int n = sizeof(scores) / sizeof(scores[0]);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }

    int max = array_max(scores, n);

    int avg = sum / n;
    printf("max: %d\n", max);
    printf("avg: %d\n", avg);
    return 0;
}
int array_max(int arr[], int len) {
    int max = arr[0];
    for (int i = 0; i < len; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }

    return max;
}