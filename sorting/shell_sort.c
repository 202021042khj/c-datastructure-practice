#include <stdio.h>

/* 셸 정렬: 간격(gap)을 두고 삽입 정렬을 하며, 간격을 점점 줄임 */
void shell_sort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = a[i];
            int j = i - gap;
            while (j >= 0 && a[j] > key) {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = key;
        }
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

    shell_sort(a, n);
    print_array(a, n);      /* 1 2 3 5 8 9 */
    return 0;
}
