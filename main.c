#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "func.h"
#define NAME_SIZE 20        
#define MARKS 5         //available amount of marks
#define LENGTH 12        //number of students



int main() {

    FILE* fb = fopen("E:\\students.bin", "rb");

    if (!fb)
    {
        printf("Error with file open ");
        return -1;
    }

    node_t* p_head = NULL;

    ReadListFromFile(fb, &p_head);

    printf("\tOriginal list of students:\n");

    printList(p_head);

    AddToList(&p_head);

    printf("\n\tAfter adding new student:\n");

    printList(p_head);

    double average[LENGTH+1];

    AverageMark(p_head, average, LENGTH+1);

    DeleteFromList(&p_head, average, LENGTH+1);

    printf("\n\tAfter deleting students:\n");

    printList(p_head);

    FreeList(p_head);

    return (0);
}
