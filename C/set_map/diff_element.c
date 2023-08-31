#include <stdio.h>
#include <stdlib.h>

// Self-implemented Set structure
typedef struct {
    int *elements;
    int size;
} Set;

void setInitialize(Set *s) {
    s->elements = NULL;
    s->size = 0;
}

void setInsert(Set *s, int value) {
    s->size++;
    s->elements = (int *)realloc(s->elements, s->size * sizeof(int));
    s->elements[s->size - 1] = value;
}

int setFind(const Set *s, int value) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == value) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

int main() {
    Set A, B, symDiff;
    setInitialize(&A);
    setInitialize(&B);

    int N, M;
    int num;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        setInsert(&A, num);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &num);
        setInsert(&B, num);
    }

    setInitialize(&symDiff);

    for (int i = 0; i < A.size; i++) {
        if (!setFind(&B, A.elements[i])) {
            setInsert(&symDiff, A.elements[i]);
        }
    }

    for (int i = 0; i < B.size; i++) {
        if (!setFind(&A, B.elements[i])) {
            setInsert(&symDiff, B.elements[i]);
        }
    }

    printf("%d\n", symDiff.size);

    free(A.elements);
    free(B.elements);
    free(symDiff.elements);

    return 0;
}
