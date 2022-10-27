#include <stdio.h>

#include "linked_list.h"

int main(void) {

    Node* root = NULL;
    root = list_ordered_push_back(root, 1);
    root = list_ordered_push_back(root, 15);
    root = list_ordered_push_back(root, 5);
    root = list_ordered_push_back(root, 43);
    root = list_ordered_push_back(root, 2);
    root = list_ordered_push_back(root, 9);
    root = list_ordered_push_back(root, 400);
    root = list_ordered_push_back(root, 5);
    list_print(root);

    list_insert(root, 5, 99999);
    list_print(root);
    printf("root_1 size: %d\n", list_size(root));

    Node* root2 = NULL;
    root2 = list_push_back(root2, 99);
    root2 = list_push_back(root2, 99);
    root2 = list_push_back(root2, 54);
    root2 = list_push_back(root2, 989848994);
    root2 = list_remove(root2, 99);
    root2 = list_remove_idx(root2, 1);
    list_print(root2);

    printf("root_2 size: %d\n", list_size(root2));

    list_destroy(root);

    return 0;
}