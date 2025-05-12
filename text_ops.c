#include "dll.h"
#include<stdio.h>
#include "editor.h"



int delete_line(Dbll *data_list)
{
    if(delete_nth_node(data_list, data_list->cursor_pos[x] + 1) == SUCCESS)
    {
        data_list->line_count--;

        data_list->cursor_pos[x]--;
        data_list->cursor_pos[y]=0;

        return SUCCESS;
    }
}

/*
int delete_n_chars(Dbll  *data_list, int n)
{
    char *string= 
}
*/

int delete_nth_node(Dbll *data_list, int n)
{
    Dnode *temp=data_list->head, *prev;

    if(temp==NULL)
        return FAILURE;

    if(n<1 || n>data_list->line_count)
    {
        printf("\nThe line number is not in range");

        return FAILURE;
    }

    if(n==1)
    {
        data_list->head= data_list->head->next;

        free(temp);

        return SUCCESS;
    }


    for(int i=1; i<n; i++)
    {
        prev=temp;
        temp=temp->next;
    }


    prev->next=temp->next;

    free(temp);

    
    return SUCCESS;
    
}