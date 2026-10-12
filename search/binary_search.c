#include <stdio.h>

/* 이진 탐색: 정렬된 배열에서 가운데 값과 비교해 범위를 절반씩 줄임 */
int binary_search(int a[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(void) {
    int a[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(a) / sizeof(a[0]);

    printf("index of 7: %d\n", binary_search(a, n, 7));    /* 3 */
    printf("index of 4: %d\n", binary_search(a, n, 4));    /* -1 */
    return 0;
}
