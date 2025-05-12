#include "dll.h"

int dl_delete_last(Dnode **head, Dnode **tail)
{

    //Empty list
    if(*tail==NULL)
        return LIST_EMPTY;

    //Single  node
    if(*head==*tail)
    {
        free(*head);
        *head=NULL;
        *tail=NULL;
        return SUCCESS;
    }
    
    //Delete the last node
    Dnode *temp= (*tail)->prev;
    
    free(*tail);
    *tail=NULL;
    
    temp->next=NULL;
    
    *tail= temp;
    
    return SUCCESS; 

}