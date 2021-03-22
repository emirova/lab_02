#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>

void ReadListFromFile(FILE* file, node_t** p_head);
void printList(node_t* p_head);
void AddToList(node_t** p_head);
void AddFirstToList(node_t** p_head, node_t* p_new);
void AddIntoList(node_t* p_new, node_t** p_run);
void AddLastToList(node_t* p_new, node_t* p_run);
void DeleteFromList(node_t** p_head, double average[], int size);
void AverageMark(node_t* p_head, double aver[], int size);
void FreeList(node_t* p_head);

#endif
