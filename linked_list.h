#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct _Node_ {
    int x;
    struct _Node_* next;
};

typedef struct _Node_ Node;

Node* list_push(Node* root, int x);
Node* list_ordered_push(Node* root, int x);

void list_insert_x(Node* root, int index, int x);
void list_insert(Node* root, int index, int x);

Node* list_remove(Node* root, int x);
Node* list_remove_idx(Node* root, int index);

int list_destroy(Node* root);

int list_size(Node* root);

void list_print(Node* root);

#endif /* LINKED_LIST_H */
