#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

Node* list_push(Node* root, int x) {

    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->next = NULL;
        root->x = x;
        return root;
    }
    
    Node* iter = root;

    while (iter->next != NULL) {
        iter = iter->next;
    }

    iter->next = (Node*)malloc(sizeof(Node));
    iter->next->next = NULL;
    iter->next->x = x;

    return root;
}

Node* list_ordered_push(Node* root, int x) {

    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->next = NULL;
        root->x = x;
        return root;
    }

    if (x < root->x) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->next = root;
        temp->x = x;
        return temp;
    }

    Node* iter = root;

    while (iter->next != NULL && x > iter->next->x) {
        iter = iter->next;
    }

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->next = iter->next;
    temp->x = x;
    iter->next = temp;

    return root;
}

void list_insert_x(Node* root, int index, int x) {
    if (root != NULL) {
        
        Node* iter = root;
        for (int i = 0; i < index; ++i) {
            if (iter->next != NULL)
                iter = iter->next;
        }
        
        iter->x = x;
    }
}

void list_insert(Node* root, int index, int x) {
    if (root != NULL) {
        
        Node* iter = root;
        for (int i = 0; i < index; ++i) {
            if (iter->next != NULL)
                iter = iter->next;
        }
        
        if (iter->next != NULL)
            iter->x = x;
    }
}

Node* list_remove(Node* root, int x) {

    Node* temp = NULL;
    Node* iter = root;

    if (root->x == x) {
        temp = root;
        root = root->next;
        free(temp);
        return root;
    }

    while (iter->next != NULL && iter->next->x != x) {
        iter = iter->next;
    }

    if (iter->next == NULL)
        return root;

    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return root;
}

Node* list_remove_idx(Node* root, int index) {

    Node* temp = NULL;
    Node* iter = root;

    if (index == 0) {
        temp = root;
        root = root->next;
        free(temp);
        return root;
    }

    int i = 0;

    while (iter->next != NULL && i < index - 1) {
        iter = iter->next;
        ++i;
    }

    if (iter->next == NULL)
        return root;

    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return root;
}

int list_destroy(Node* root) {
    if (root == NULL)
        return 0;

    Node* iter = root;
    Node* temp;

    while (iter != NULL) {
        temp = iter->next;
        free(iter);
        iter = temp;
    }

    root = NULL;

    return 1;
}

int list_size(Node* root) {
    int i = 0;

    while(root != NULL) {
        root = root->next;
        ++i;
    }

    return i;
}

void list_print(Node* root) {
    while (root != NULL) {
        printf("%d ", root->x);
        root = root->next;
    }
    printf("\n");
}
