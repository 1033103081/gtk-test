#include <string.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    char *priority =" 1";
    char test[200] = "SELECT * FROM ";
    char * db_name = "mydata.db";
    /*char * num =" WHERE priority=";*/
    /*char * cmd = strcat(strcat(strcat ("SELECT * FROM  ",db_name), " WHERE priority="),num);*/
    printf("到这里了\n");
    char * cmd = strcat(strcat(test, db_name), priority);
    printf("%s\n",cmd );
    return 0;
}
