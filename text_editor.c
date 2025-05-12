#include "dll.h"
#include <stdio.h>
#include "editor.h"

char *file_comms[]={"open", "save", "saveas", "close", "\0"};

char *text_comms[]={"insert", "delete", "delete line", "copy", "cut", "paste", "undo", "redo", "\0"}; 

char *cursor_comms[]={"move up", "move down", "move left", "move right", "jump to start", "jump to end", "jump to start of line",
                        "jump to end of line", "\0"};

char *display_comms[]={"display", "show cursor", "find", "replace", "\0"};

char **all_comms[]={file_comms, text_comms, cursor_comms, display_comms};


int validate_operation_type(char command[], Comm *cmd)
{
  
    int i, flag=0;
    printf("\nCheck operation type\n");
    for(i=0; i<Oper_type_val; i++)
    {
        for(int j=0; all_comms[i][j]; j++)
        {
            if(strcmp(all_comms[i][j], command)==0)
            {
                cmd->comm_ind=j;
                printf("\n Operation name : %s", all_comms[i][j]);
                flag=1;
                break;
            }
               
        }

        if(flag==1)
            break;
    }

    if(i==Oper_type_val)
    {
        printf("\nNo mathcing command\n");
        cmd->type= invalid_operation;

    }
    
    else
    {
        switch (i)
        {
            case 0:
                    cmd->type= file_ops;
                     break;
            
            case 1:
                    cmd->type= text_ops;
                    break;
            
            case 2:
                    cmd->type=cursor_ops;
                    break;
            
            case 3:
                    cmd->type=disp_and_search;
                    break;
            
            //default:
                    //cmd->type= invalid_operation;
                    //break;
        }
    }
    
    return SUCCESS;
}




int operation_routing(char command[], Comm *cmd, Dbll *data_list)
{
    printf("\nOP routing\n");
    if(cmd->type==file_ops)
    {
        switch (cmd->comm_ind)
        {
        case 0:
                //open_file();
            break;
        
        default:
            break;
        }
    }


    else if(cmd->type == cursor_ops)
    {
        switch (cmd->comm_ind)
        {
        case 2:
                move_left(data_list);
            break;

        case 3: 
                move_right(data_list);
            break;
            
        default:
            break;
        }
    }



    else if(cmd->type == text_ops)
    {
        switch (cmd->comm_ind)
        {
        case 0:
            
            
            break;
        
        default:
            break;
        }
    }


    else if(cmd->type == disp_and_search)
    {
        switch (cmd->comm_ind)
        {
        case 1:
            
            show_cursor(data_list);
            
            break;
        
        default:
            break;
        }
    }

}





int print_file_data(Dbll *data_list)
{
    printf(YELLOW"\n");
    /*
    Dnode *temp = data_list->head;
    
    while(temp)
    {
        printf("%s\n", temp->line_data);
        temp=temp->next;
    }

    */

    for(int i=0; i<data_list->line_count; i++)
    {
        printf("%s\n", data_list->line_ptr[i]->line_data);
    }

    printf("\n");
    return 0;
}


