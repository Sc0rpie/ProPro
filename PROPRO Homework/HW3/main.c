#include <stdio.h>
#include <stdlib.h>
#include <functions.h>

int main()
{
    Node* head = NULL;

    pushNodeF(&head, 2);
    pushNodeF(&head, 10);
    pushNodeF(&head, 30);
    pushNodeF(&head, 12);
    pushNodeF(&head, 9);
    

    printNode(head);
    removeMax(&head, findMax(head));
    printNode(head);
    return 0;
}