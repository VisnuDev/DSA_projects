#include "dll.h"
#include<stdio.h>
#include "editor.h"


int move_right(Dbll *data_list)
{
    
    Dnode *temp = data_list->head;

    for(int i=0; i<data_list->cursor_pos[x]; i++)
        temp=temp->next;

    printf("\nCurrent line len: %d", temp->len);
    if(data_list->cursor_pos[y] < temp->len-1)
        (data_list->cursor_pos[y])++;
    
    else if(data_list->cursor_pos[x] < data_list->line_count -1)
    {
        data_list->cursor_pos[x]++;
        data_list->cursor_pos[y]=0;
    }

    else
        printf("\nCursor is at end of the file\n");

    
    return SUCCESS;
}

int move_left(Dbll *data_list)
{

    Dnode *temp= data_list->head, *prev;

    for(int i=0; i<data_list->cursor_pos[x]; i++)
    {
        prev=temp;
        temp=temp->next;
    }

    if(data_list->cursor_pos[y]>0)
        (data_list->cursor_pos[y])--;

    else if(data_list->cursor_pos[x]!=0)
    {
        data_list->cursor_pos[x]--;
        data_list->cursor_pos[y]= prev->len-1;
    }

    else
    {
        printf("\nCursor is at beginning of the line");
    }


    return SUCCESS;
}

