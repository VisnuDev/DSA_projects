#include "dll.h"

int dl_delete_first(Dnode **head, Dnode **tail)
{

    //Empty list
    if(*head==NULL)
    {
        return LIST_EMPTY;    
    }
    
    //Single node
    if(*head==*tail)
    {
        free(*head);
        *head=NULL;
        *tail=NULL;
        return SUCCESS;
    }
    
    //Delete the first node
    Dnode *temp= (*head)->next;
    
    free(*head);
    
    temp->prev=NULL;
    
    *head=temp;
    
    return SUCCESS;
}