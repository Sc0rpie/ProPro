#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    Node *head = NULL; /* Sukuriama Node tipo rodyklė */

    /* Reikšmių įvedimas į sąraša*/
    push(&head, 2);
    push(&head, 10);
    push(&head, 12);
    push(&head, 9);
    push(&head, 30);

    /* Pradinio sąrašo rašymas, didžiausio elemento panaikinimas ir pakeisto sąrašo rašymas */
    print(head);
    removeMax(&head);
    print(head);
    pop(&head);
    print(head);
    return 0;
}
