#include "dll.h"

int dl_delete_list(Dnode **head, Dnode **tail)
{
    if(*head==NULL && *tail==NULL)
    {
        return LIST_EMPTY;
    }
    
    Dnode *first=*head, *sec=NULL;
    
    //Traverse and dlete all nodes
    while(first)
    {
        sec= first->next;
        free(first);
        first=sec;
    }
    
    *head=NULL;
    *tail=NULL;
    
    return SUCCESS;
}