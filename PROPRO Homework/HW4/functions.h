#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct Node{ /* Struktūros aprašymas */
    int data;
    struct Node *next;
} Node;

/* Funkcijų aprašymai */
void print(Node *n);
int findMax(Node *n);
void push(Node **head, int n_data);
void removeMax(Node **head);
void pop(Node **head);

#endif
