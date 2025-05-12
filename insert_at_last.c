#include "dll.h"

int dl_insert_last(Dnode **head, Dnode **tail, char data[])
{
        
        //Create new node
        
        Dnode *new_node=malloc(sizeof(Dnode));
        
        if(new_node==NULL)
            return FAILURE;
        
        new_node->prev=*tail;

        new_node->line_data = malloc(strlen(data));

        if (new_node->line_data == NULL)
        {
            free(new_node);
            return FAILURE;
        }

        printf("\nData:%s len: %lu", data, strlen(data));

        strcpy(new_node->line_data, data);
        new_node->len= strlen(new_node->line_data);

        new_node->next=NULL;
        
        //If list is empty
        if(*head==NULL && *tail==NULL)
        {
            *head=new_node;
            *tail=new_node;
            
            return SUCCESS;
        }
        
        //Insert as tail node
        (*tail)->next=new_node;
        
        *tail=new_node;
        
        return SUCCESS;
        
}