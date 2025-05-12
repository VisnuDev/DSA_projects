#include "dll.h"
#include<stdio.h>
#include "editor.h"

int show_cursor(Dbll *data_list)
{
    printf("\nCursor position : Line %d, Column %d\n", data_list->cursor_pos[x], data_list->cursor_pos[y]);
    return SUCCESS;
}