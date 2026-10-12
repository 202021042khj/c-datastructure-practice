#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;

/* 배열로 구현한 리스트: list[0] ~ list[length-1]에 원소가 연속으로 저장됨 */
typedef struct {
    element list[MAX_LIST_SIZE];
    int length;
} ArrayListType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ArrayListType *L) {
    L->length = 0;
}

int is_empty(ArrayListType *L) {
    return L->length == 0;
}

int is_full(ArrayListType *L) {
    return L->length == MAX_LIST_SIZE;
}

/* position 위치에 item 삽입, 뒤의 원소들은 한 칸씩 뒤로 이동 */
void insert(ArrayListType *L, int position, element item) {
    if (!is_full(L) && (position >= 0) && (position <= L->length)) {
        for (int i = L->length - 1; i >= position; i--)
            L->list[i + 1] = L->list[i];
        L->list[position] = item;
        L->length++;
    } else {
        error("위치오류");
    }
}

/* position 위치의 원소를 삭제하고 그 값을 반환, 뒤의 원소들은 한 칸씩 앞으로 이동 */
element delete(ArrayListType *L, int position) {
    element item;

    if (position < 0 || position >= L->length)
        error("위치오류");

    item = L->list[position];
    for (int i = position; i < (L->length - 1); i++)
        L->list[i] = L->list[i + 1];
    L->length--;
    return item;
}

/* position 위치의 원소를 반환 (삭제하지 않음) */
element get_entry(ArrayListType *L, int position) {
    if (position < 0 || position >= L->length)
        error("위치오류");
    return L->list[position];
}

void print_list(ArrayListType *L) {
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->list[i]);
    printf("\n");
}

int main(void) {
    ArrayListType L;

    init(&L);
    insert(&L, 0, 10);
    insert(&L, 1, 30);
    insert(&L, 1, 20);
    print_list(&L);                              /* 10 20 30 */

    printf("get_entry(2) = %d\n", get_entry(&L, 2));  /* 30 */

    printf("delete(0) = %d\n", delete(&L, 0));        /* 10 */
    print_list(&L);                              /* 20 30 */

    return 0;
}
