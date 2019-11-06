#ifndef __MY_SQLITE_H
#define __MY_SQLITE_H

struct user_info{
    char* name;
    char* image_path;
};


struct user_info  _user_info;


void get_single_user_info(char*);   
//void free_single_user_info_garbage();
int get_message_row_number(char *table_name);

#endif /* ifndef __MY_SQLITE_H

 */
