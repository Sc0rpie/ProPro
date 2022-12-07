#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void printNode(Node* n);
int findMax(Node* n);
void pushNodeF(Node** head, int n_data);
void removeMax(Node** head, int pos);

#endif