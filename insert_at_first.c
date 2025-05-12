#include "dll.h"

/*
int dl_insert_first(Dnode **head, Dnode **tail, char data)
{
    //Create new node
   Dnode *new_node=malloc(sizeof(Dnode));
   
   if(new_node==NULL)
        return FAILURE;
   
   new_node->prev=NULL;
   
   new_node->data=data;
   
   new_node->next=*head;
   
   //If list is empty
   if(*head==NULL && *tail==NULL)
   {
       *head=new_node;
       *tail=new_node;
       return SUCCESS;
   }
   

   //Insert at head position
   (*head)->prev=new_node;
   
   *head=new_node;
   
   return SUCCESS;
   

}

*/