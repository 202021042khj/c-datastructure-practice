#include <stdio.h>

/* 선택 정렬: 남은 원소 중 최솟값을 골라 앞에 놓음 */
void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        int tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int a[] = {5, 3, 8, 1, 9, 2};
    int n = sizeof(a) / sizeof(a[0]);

    selection_sort(a, n);
    print_array(a, n);      /* 1 2 3 5 8 9 */
    return 0;
}
