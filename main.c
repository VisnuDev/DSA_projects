#include "dll.h"
#include<stdio.h>
#include "editor.h"

char src_file_name[]="sample_file.txt";

int main(int argc, char *argv[])
{
    char command[50];
    printf(GREEN"\n-------------------------TEXT EDITOR PROJECT-------------------\n\n"RESET);

    printf("\nEnter the command: ");
    scanf(" %[^\n]", command);

    Oper_type type;

    int comm_ind;
    Comm cmd; 

    //classify the operation type based on command 
    validate_operation_type(command, &cmd);

    if(cmd.type==invalid_operation)
    {
        printf("\nInvalid command\n");
        return 0;
    }

    Dbll data_list;
    data_list.head = data_list.tail = NULL;
    data_list.line_count = data_list.size = 0;
    data_list.cursor_pos[x] = data_list.cursor_pos[y] = 0;

    
    if(open_file(&data_list, src_file_name) == SUCCESS)
    {

        print_file_data(&data_list);
    }

    operation_routing(command, &cmd, &data_list );

    while(1)
    {
        printf("\nEnter the command: ");
        scanf(" %[^\n]", command);

        validate_operation_type(command, &cmd);

        if(cmd.type==invalid_operation)
        {
            printf("\nInvalid command\n");
            return 0;
        }
    
        operation_routing(command, &cmd, &data_list );
    }

    return 0;
}