#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#define NAME_SIZE 20        //available string size for name
#define MARKS 5         //available amount of marks
#define LENGTH 12        //number of students

void ReadListFromFile(FILE* file, node_t** p_head) {
    int counter = 0;
    node_t* pNew = (node_t*)malloc(sizeof(node_t));

    if (!pNew)
    {
        printf("Error with dynamically memory ");
        return;
    }

    counter = fread(&pNew->newStud, sizeof(Students), 1, file);

    if (!(*p_head) && counter == 1)
        *p_head = pNew;
    for (int i = 0; i < LENGTH-1; i++) {
        node_t* p_temp = (node_t*)malloc(sizeof(node_t));

        if (!p_temp) {
            printf("Error with dynamically memory ");
            return;
        }

        pNew->next = p_temp;
        pNew = p_temp;
        pNew->next = NULL;
        fread(&(pNew->newStud), sizeof(Students), 1, file);
    }
    return;
}

//__________________________________________________________________________________________________________________

void printList(node_t* p_head) {
    node_t* p_run = p_head;
    printf("\n___________________________________________________________________________\n");
    while (p_run) {
        printf("%s    \t%s    \t%s    \t", p_run->newStud.surname, p_run->newStud.name, p_run->newStud.date);
        for (int i = 0; i < MARKS; ++i) {
            printf("%4d ", p_run->newStud.marks[i]);
        }
        printf("\n___________________________________________________________________________\n");
        p_run = p_run->next;
    }
}
//__________________________________________________________________________________________________________________
//add student to the first position in tje list
void AddFirstToList(node_t** p_head, node_t* p_new) {
    p_new->next = *p_head;
    *p_head = p_new;
    return;
}
//__________________________________________________________________________________________________________________
//add student anywhere to the list except first and last positions
void AddIntoList(node_t* p_new, node_t** p_run) {
    p_new->next = (*p_run)->next;
    (*p_run)->next = p_new;
    return;
}
//__________________________________________________________________________________________________________________
//add student to the last position in the list
void AddLastToList(node_t* p_new, node_t* p_run) {
    p_run->next = p_new;
    p_new->next = NULL;
    return;
}
//__________________________________________________________________________________________________________________

void AddToList(node_t** p_head) {
    
    node_t* p_new = (node_t*)malloc(sizeof(node_t));
    node_t* p_run = *p_head;

    if (!p_new) {
        printf("Error with dynamically memory ");
        return;
    }

    printf("\n\tEnter surname of new student:\n");
    scanf("%s", &p_new->newStud.surname);

    printf("\tEnter name:\n");
    scanf("%s", &p_new->newStud.name);

    printf("\tEnter date of their birthday:\n");
    scanf("%s", &p_new->newStud.date);

    for (int i = 0; i < MARKS; ++i) {
        printf("\tEnter mark:\n");
        scanf("%d", &p_new->newStud.marks[i]);
    }

    while (1) {
        if (strcmp(p_new->newStud.surname, (*p_head)->newStud.surname) > 0) {
            AddFirstToList(p_head, p_new);
            break;
        }

        if (strcmp(p_new->newStud.surname, p_run->newStud.surname) < 0 && p_run->next == NULL) {
            AddLastToList(p_new, p_run);
            break;
        }

        if (strcmp(p_new->newStud.surname, p_run->next->newStud.surname) > 0 
            && strcmp(p_new->newStud.surname, p_run->newStud.surname) == 1) {
            AddIntoList(p_new, &p_run);
            break;
        }
        p_run = p_run->next;
    }
    return;
}
//__________________________________________________________________________________________________________________
//finds the average mark of every student
void AverageMark(node_t* p_head, double average[], int size)
{
    node_t* p_run = p_head;
    int sum = 0;
    int mark = 0;
    while (p_run->next) {
        for (int i = 0; i < MARKS; ++i) {
            sum += p_run->newStud.marks[i];
        }
        average[mark] = sum / 5.0;
        sum = 0;
        mark++;
        p_run = p_run->next;
    }
}
//__________________________________________________________________________________________________________________

void DeleteFromList(node_t** p_head, double average[], int size)
{
    node_t* p_run = *p_head;
    for (int i = 1; i < LENGTH; i++) {
        node_t* p_new = p_run;
        p_run = p_run->next;

        if (p_run->next == NULL) {
            break;
        }
        if (average[i] < 51) {
            p_new->next = p_run->next;
            free(p_run);
            p_run = p_new;
        }
        //p_run = p_run->next;
    }

    p_run = p_head;
    if (average[0] < 51) {
        p_head = p_run->next;
        free(p_run);
    }
}
//__________________________________________________________________________________________________________________
//free memory
void FreeList(node_t* p_head)
{
    node_t* p_temp = p_head;

    while (p_temp) {
        p_head = p_head->next;
        free(p_temp);
        p_temp = p_head;
    }
    return;
}
