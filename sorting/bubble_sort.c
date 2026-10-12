#include <stdio.h>

/* 버블 정렬: 인접한 두 원소를 비교해 큰 값을 뒤로 보냄 */
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped)       /* 교환이 없었으면 이미 정렬됨 */
            break;
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

    bubble_sort(a, n);
    print_array(a, n);      /* 1 2 3 5 8 9 */
    return 0;
}
