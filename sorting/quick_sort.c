#include <stdio.h>

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 분할: 마지막 원소를 피벗으로 두고, 피벗보다 작은 값을 앞으로 모음 (Lomuto) */
static int partition(int a[], int left, int right) {
    int pivot = a[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[right]);
    return i + 1;               /* 피벗의 최종 위치 */
}

void quick_sort(int a[], int left, int right) {
    if (left >= right)
        return;
    int p = partition(a, left, right);
    quick_sort(a, left, p - 1);
    quick_sort(a, p + 1, right);
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int a[] = {5, 3, 8, 1, 9, 2};
    int n = sizeof(a) / sizeof(a[0]);

    quick_sort(a, 0, n - 1);
    print_array(a, n);      /* 1 2 3 5 8 9 */
    return 0;
}
