#include "dll.h"
#include<stdio.h>
#include "editor.h"


int  open_file(Dbll *data_list, char file_name[])
{
    FILE *fptr= fopen(file_name, "r");

    if(fptr==NULL)
        return FAILURE;

    printf("\n File opened successfully\n");

    char line_string[MAX_LINE_SIZE];
    
    Dnode *curr_line=NULL;

    while(fgets(line_string, sizeof(line_string), fptr)!=NULL)
    {
        line_string[strcspn(line_string, "\r")] = '\0';
        if( (curr_line= dl_insert_last(&(data_list->head), &(data_list->tail), line_string) ) !=NULL)
        {
            data_list->line_ptr[data_list->line_count]=curr_line;

            data_list->line_count++;
        }
    }

    return SUCCESS;
}


int save_file(Dbll *data_list, char file_name[], FILE *fptr)
{
    fclose(fptr);

    fptr= fopen(file_name, "w");

    char ch;

    Dnode *temp= data_list->head;
    while(temp)
    {
        fprintf(fptr, "%s", temp->line_data);

        temp=temp->next;
    }

    fclose(fptr);
}


int save_as(Dbll *data_list, char file_name[])
{
    FILE *fptr=fopen(file_name, "w");

    if(fptr==NULL)
        return FAILURE;

    Dnode *temp=data_list->head;

    while(temp)
    {
        fprintf(fptr, "%s", temp->line_data);

        temp=temp->next;
    }

    fclose(fptr);

    return SUCCESS;
}