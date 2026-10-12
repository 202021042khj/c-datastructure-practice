#include <stdio.h>

/* 삽입 정렬: 앞부분이 정렬된 상태에서 새 원소를 알맞은 위치에 끼워 넣음 */
void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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

    insertion_sort(a, n);
    print_array(a, n);      /* 1 2 3 5 8 9 */
    return 0;
}
