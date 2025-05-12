#include "dll.h"
/*
int dl_insert_before(Dnode **head, Dnode **tail, char gdata, char ndata)
{
        if(*head==NULL)
            return LIST_EMPTY;
        
        Dnode *temp= *head;
        
        while(temp)
        {
            if(temp->data != gdata)
                temp= temp->next;
                
            else
            {
                Dnode *node= malloc(sizeof(Dnode));
                
                if(node==NULL)
                    return FAILURE;
                    
                node->data= ndata;
                
                node->prev=temp->prev;
                
                node->next= temp;
                
                
                temp->prev=node;
                
                if(temp != *head)
                    node->prev->next=node;
                
                else
                    *head=node;
                    
                return SUCCESS;
                
            }
    
        }
        
        return DATA_NOT_FOUND;
}

*/