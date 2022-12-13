#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void print(Node *n) /* Sąrašo rašymas į konsolę */
{
    while (n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int findMax(Node *n) /* Surandama didžiausios reikšmės pozicijas */
{
    int pos = 1;
    int maxPos = pos;
    int max = n->data;
    n = n->next;
    while (n != NULL)
    {
        pos++;
        if (n->data >= max)
        {
            max = n->data;
            maxPos = pos;
        }

        n = n->next;
    }
    return maxPos;
}

void push(Node **head, int n_data) /* n_data - new data */
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = n_data;
    new_node->next = *head;
    *head = new_node;
}

void removeMax(Node **head) /* Trinama didžiausia reikšmė */
{
    int i;
    int pos;
    Node *tmp = *head;
    Node *prev = *head;
    if (tmp == NULL)
        return;

    pos = findMax(*head);

    if (pos == 1)
    {
        *head = (*head)->next;
        free(tmp);
        return;
    }
    for (i = 0; i < pos; i++)
    {
        /*if (i == pos-1 && tmp)*/
        if (i == pos - 1)
        {
            /*printf("%d\n", i);*/
            /*printf("YIF ||| %p | %p\n", prev, tmp);*/
            prev->next = tmp->next;
            free(tmp);
        }
        else
        {
            prev = tmp;
            /*printf("NIF ||| %p | %p\n", prev, tmp);*/
            tmp = tmp->next;
            /*printf("NTP ||| %p\n", tmp);*/
        }
    }
}

void pop(Node **head)
{
    Node *tmp = *head;
    if (tmp)
    {
        *head = tmp->next;
        free(tmp);
    }
}
