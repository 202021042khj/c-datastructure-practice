#include <stdio.h>

/* 보간 탐색: 값의 분포를 가정해 key가 있을 위치를 선형 보간으로 추정 (정렬된 배열) */
int interpolation_search(int a[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= a[low] && key <= a[high]) {
        if (a[high] == a[low]) {          /* 0으로 나누기 방지 */
            if (a[low] == key)
                return low;
            break;
        }

        int pos = low + (int)((double)(key - a[low]) * (high - low) / (a[high] - a[low]));

        if (a[pos] == key)
            return pos;
        if (a[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main(void) {
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(a) / sizeof(a[0]);

    printf("index of 70: %d\n", interpolation_search(a, n, 70));  /* 6 */
    printf("index of 35: %d\n", interpolation_search(a, n, 35));  /* -1 */
    return 0;
}
