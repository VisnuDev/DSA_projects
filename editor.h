#ifndef EDITOR_H
#define EDITOR_H


//Macro definition for color text
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define RESET "\033[0m"


#define uint unsigned int

#define MAX_LINE_SIZE 200

#define Oper_type_val 4


#define SUCCESS 0
#define FAILURE -1

#define x 0
#define y 1

typedef enum
{
    file_ops,
    text_ops,
    cursor_ops,
    disp_and_search,
    invalid_operation

}Oper_type;


typedef struct dll
{

    Dnode *head;
    Dnode *tail;
    

   // Dnode *line[10000];
    uint size;
    uint line_count;
    uint curr_line;
    uint cursor_pos[2];
    uint word_count;
    Dnode **line;
    char *cur_ptr;

}Dbll;


typedef struct command
{
    char command[50];
    Oper_type type;
    char *arg_string;
    int arg1, arg2, comm_ind;
}Comm;

int validate_operation_type(char command[], Comm *);

int  open_file(Dbll *data_list, char file_name[]);

int print_file_data(Dbll *data_list);

int save_file(Dbll *data_list, char file_name[], FILE *fptr);

int save_as(Dbll *data_list, char file_name[]);

int operation_routing(char command[], Comm *cmd, Dbll *);


//Cursor functions


int move_left(Dbll *data_list);
int move_right(Dbll *data_list);



//Display functions

int show_cursor(Dbll *data_list);


#endif