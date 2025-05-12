#ifndef DLL_H
#define DLL_L

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Macros for return status
#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND -2
#define LIST_EMPTY -3

//Node Stucture
typedef struct node
{
	char *line_data;
	unsigned int len;
	struct node *prev;
	struct node *next;
}Dnode;




//Doubly linked list basic operations
int dl_insert_first(Dnode **head, Dnode **tail, char data[]);
int dl_insert_last(Dnode **head, Dnode **tail, char data[]);
int dl_delete_first(Dnode **head, Dnode **tail);
int dl_delete_last(Dnode **head, Dnode **tail);
int dl_delete_list(Dnode **head, Dnode **tail);
int dl_insert_after(Dnode **head, Dnode **tail, char gdata[], char ndata[]);
int dl_insert_before(Dnode **head, Dnode **tail, char gdata[], char ndata[]);
int dl_delete_element(Dnode **head, Dnode **tail, char data[]);
void print_list(Dnode *head);
#endif