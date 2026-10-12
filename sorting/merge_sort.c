#include <stdio.h>

/* 합병 정렬: 반으로 나눠 각각 정렬한 뒤 합침 */
static void merge(int a[], int left, int mid, int right) {
    int tmp[100];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= right)
        tmp[k++] = a[j++];

    for (k = 0; k < right - left + 1; k++)
        a[left + k] = tmp[k];
}

void merge_sort(int a[], int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid, right);
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int a[] = {5, 3, 8, 1, 9, 2};
    int n = sizeof(a) / sizeof(a[0]);

    merge_sort(a, 0, n - 1);
    print_array(a, n);      /* 1 2 3 5 8 9 */
    return 0;
}
