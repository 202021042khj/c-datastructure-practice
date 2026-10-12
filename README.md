# C 자료구조 & 알고리즘 연습 코드

시험 대비용으로 자주 나오는 기본 구현을 주제별로 모아 둔 폴더입니다. 각 파일은 단독으로 컴파일하고 실행할 수 있으며, `main`에서 결과를 출력합니다. 주석에 예상 출력을 적어 두었습니다.

## 폴더 구성

| 폴더 | 파일 |
|------|------|
| `lists/` | `linked_list.c`, `circular_list.c`, `doubly_list.c`, `list_adt.c` |
| `stacks/` | `array_stack.c`, `int_array_stack.c`, `struct_array_stack.c`, `linked_stack.c` |
| `queues/` | `circular_queue.c`, `linked_queue.c`, `deque.c` |
| `trees/` | `linked_binary_tree.c`, `tree_traversal.c`, `bst.c`, `avl.c` |
| `heaps/` | `max_heap.c`, `min_heap.c`, `priority_queue.c` |
| `sorting/` | `selection_sort.c`, `insertion_sort.c`, `bubble_sort.c`, `shell_sort.c`, `merge_sort.c`, `quick_sort.c`, `heap_sort.c`, `radix_sort.c` |
| `graph/` | `dfs.c`, `bfs.c`, `kruskal.c`, `prim.c`, `dijkstra.c`, `floyd.c`, `topological_sort.c` |
| `search/` | `binary_search.c`, `index_sequential_search.c`, `interpolation_search.c` |

## 컴파일 및 실행

```bash
gcc lists/linked_list.c -o out && ./out
```

파일마다 같은 방식으로 실행하면 됩니다.

## 참고

- 이 코드는 일반적인 교과서 구현 형태를 바탕으로 작성했습니다. 교재와 함수 이름, 오류 처리 방식(`printf` 또는 반환값)이 다를 수 있으니 시험 전에 교재와 대조하세요.
- 외운 뒤에는 빈 종이에 처음부터 다시 쓰는 연습을 하세요.
