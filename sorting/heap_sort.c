#include <stdio.h>

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 0번 인덱스 기준 힙: i의 자식은 2i+1, 2i+2 */
static void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

/* 1단계: 최대 힙 만들기, 2단계: 루트를 맨 뒤로 보내며 크기를 줄임 */
void heap_sort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int end = n - 1; end > 0; end--) {
        swap(&a[0], &a[end]);
        heapify(a, end, 0);
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

    heap_sort(a, n);
    print_array(a, n);      /* 1 2 3 5 8 9 */
    return 0;
}
