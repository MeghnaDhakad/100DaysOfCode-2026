#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *prev, *next;
} Node;

typedef struct {
    Node *front;
    Node *back;
    int size;
} FrontMiddleBackQueue;

FrontMiddleBackQueue* fmbqCreate() {
    FrontMiddleBackQueue* q = malloc(sizeof(FrontMiddleBackQueue));
    q->front = q->back = NULL;
    q->size = 0;
    return q;
}

static Node* newNode(int val) {
    Node* n = malloc(sizeof(Node));
    n->val = val;
    n->prev = n->next = NULL;
    return n;
}

void fmbqPushFront(FrontMiddleBackQueue* q, int val) {
    Node* n = newNode(val);
    if (q->size == 0) {
        q->front = q->back = n;
    } else {
        n->next = q->front;
        q->front->prev = n;
        q->front = n;
    }
    q->size++;
}

void fmbqPushBack(FrontMiddleBackQueue* q, int val) {
    Node* n = newNode(val);
    if (q->size == 0) {
        q->front = q->back = n;
    } else {
        n->prev = q->back;
        q->back->next = n;
        q->back = n;
    }
    q->size++;
}

/* returns node currently at 0-based index, traversing from the nearer end */
static Node* getNodeAt(FrontMiddleBackQueue* q, int index) {
    Node* cur;
    if (index <= q->size - 1 - index) {
        cur = q->front;
        for (int i = 0; i < index; i++) cur = cur->next;
    } else {
        cur = q->back;
        for (int i = q->size - 1; i > index; i--) cur = cur->prev;
    }
    return cur;
}

void fmbqPushMiddle(FrontMiddleBackQueue* q, int val) {
    int idx = q->size / 2;          /* insertion gap index */
    if (idx == 0) { fmbqPushFront(q, val); return; }
    if (idx == q->size) { fmbqPushBack(q, val); return; }

    Node* cur = getNodeAt(q, idx);  /* new node goes right before this node */
    Node* n = newNode(val);
    Node* p = cur->prev;
    p->next = n;
    n->prev = p;
    n->next = cur;
    cur->prev = n;
    q->size++;
}

int fmbqPopFront(FrontMiddleBackQueue* q) {
    if (q->size == 0) return -1;
    Node* n = q->front;
    int val = n->val;
    q->front = n->next;
    if (q->front) q->front->prev = NULL; else q->back = NULL;
    free(n);
    q->size--;
    return val;
}

int fmbqPopBack(FrontMiddleBackQueue* q) {
    if (q->size == 0) return -1;
    Node* n = q->back;
    int val = n->val;
    q->back = n->prev;
    if (q->back) q->back->next = NULL; else q->front = NULL;
    free(n);
    q->size--;
    return val;
}

int fmbqPopMiddle(FrontMiddleBackQueue* q) {
    if (q->size == 0) return -1;
    int idx = (q->size - 1) / 2;
    Node* cur = getNodeAt(q, idx);
    int val = cur->val;
    if (cur->prev) cur->prev->next = cur->next; else q->front = cur->next;
    if (cur->next) cur->next->prev = cur->prev; else q->back = cur->prev;
    free(cur);
    q->size--;
    return val;
}

void fmbqFree(FrontMiddleBackQueue* q) {
    Node* cur = q->front;
    while (cur) { Node* nx = cur->next; free(cur); cur = nx; }
    free(q);
}

int main(void) {
    FrontMiddleBackQueue* q = fmbqCreate();

    fmbqPushFront(q, 1);
    fmbqPushBack(q, 2);
    fmbqPushMiddle(q, 3);
    fmbqPushMiddle(q, 4);

    printf("%d\n", fmbqPopFront(q));   /* 1  */
    printf("%d\n", fmbqPopMiddle(q));  /* 3  */
    printf("%d\n", fmbqPopMiddle(q));  /* 4  */
    printf("%d\n", fmbqPopBack(q));    /* 2  */
    printf("%d\n", fmbqPopFront(q));   /* -1 */

    fmbqFree(q);
    return 0;
}
