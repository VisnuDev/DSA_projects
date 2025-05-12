#include "dll.h"

/*
int dl_insert_after(Dnode **head, Dnode **tail, char gdata, char ndata)
{
    if(*head==NULL)
        return LIST_EMPTY;
        
    Dnode *temp= *head;
    
    while(temp)
    {
        if(temp->data != gdata)
            temp=temp->next;
            
        else
        {
            Dnode *node= malloc(sizeof(Dnode));
            
            if(node==NULL)
                return FAILURE;
                
            node->data=ndata;
            node->prev=temp;
            
            node->next=temp->next;
            
            temp->next = node;
            
            if(temp != *tail)
                node->next->prev = node;
            
            else
                *tail=node;
                
            return SUCCESS;
        }
        
    }
    
    return DATA_NOT_FOUND;
    
    
}

*/