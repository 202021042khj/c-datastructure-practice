#include <stdio.h>

/* 기수 정렬 (LSD): 자릿수별로 안정 정렬(계수 정렬)을 반복. 0 이상 정수 기준 */
static void counting_sort_by_digit(int a[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int d = 1; d < 10; d++)
        count[d] += count[d - 1];      /* 누적 개수 = 위치 */

    /* 뒤에서부터 채워야 안정성이 유지됨 */
    for (int i = n - 1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        output[count[d] - 1] = a[i];
        count[d]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radix_sort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort_by_digit(a, n, exp);
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a) / sizeof(a[0]);

    radix_sort(a, n);
    print_array(a, n);      /* 2 24 45 66 75 90 170 802 */
    return 0;
}
