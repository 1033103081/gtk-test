#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <my_sqlite.h>


static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    /*printf("一共%d行数据\n",argc );*/
    for(i=0; i<argc; i++){
        /*printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");*/
        if (strcmp(azColName[i], "user_difined_name")==0) {
            /*_user_info.name = (char *)malloc(sizeof(200));*/
            char * test1 =(char *) malloc(100);
            strcpy(test1,argv[i]);
            _user_info.name = test1;
        }
        if (strcmp(azColName[i],"image_file_location")==0) {
            char * test1 =(char *) malloc(100);
            strcpy(test1,argv[i]);
            _user_info.image_path = test1; 
        }
    }
    /*printf("\n");*/
    return 0;
}

void get_single_user_info(char *priority){
   
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char cmd1[200] = "SELECT * FROM  ";
    char * table_name = "user ";
    char * cmd = strcat(strcat(strcat (cmd1,table_name), "WHERE priority="),priority);
    /*printf("%s\n",cmd );*/

    rc = sqlite3_open("mydata.db", &db);
    if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }
    rc = sqlite3_exec(db, cmd, callback, 0, &zErrMsg);
    if( rc!=SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);

}


//瞎扯淡　这个就没有在堆内存中
//整个进程维护一个简单的全局变量是cheap的

int row_num =0;
/*void free_single_user_info_garbage(){*/
    /*free(_user_info.name);*/
    /*free(_user_info.image_path);*/
/*}*/

static int callback1(void *NotUsed, int argc, char **argv, char **azColName){
   /* int i;*/
    /*[>printf("一共%d行数据\n",argc );<]*/
    /*for(i=0; i<argc; i++){*/
        /*[>printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");<]*/
        /*if (strcmp(azColName[i], "user_difined_name")==0) {*/
            /*[>_user_info.name = (char *)malloc(sizeof(200));<]*/
            /*char * test1 =(char *) malloc(sizeof(argv[i]));*/
            /*strcpy(test1,argv[i]);*/
            /*_user_info.name = test1;*/
        /*}*/
        /*if (strcmp(azColName[i],"image_file_location")==0) {*/
            /*char * test1 =(char *) malloc(sizeof(argv[i]));*/
            /*strcpy(test1,argv[i]);*/
            /*_user_info.image_path = test1; */
        /*}*/
    /*}*/
    /*printf("\n");*/
    /*printf("我执行了\n");*/
    row_num = atoi(argv[0]);
    /*printf("argc = %d\n",argc );*/
    /*printf("argv[0]= %s\n",argv[0] );*/
    return 0;
}



int get_message_row_number(char * table_name){


 
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char cmd1[200] = "SELECT Count(*) FROM  ";
    char * cmd = strcat(cmd1,table_name);
    /*printf("%s\n",cmd );*/

    rc = sqlite3_open("mydata.db", &db);
    if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }
    /*void *num = malloc(sizeof(int));*/
    rc = sqlite3_exec(db, cmd, callback1, 0, &zErrMsg);
    if( rc!=SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    
    /*printf("row_num is %d\n",row_num );*/
    return row_num;
}


/*int main(int argc, char *argv[])*/
/*{*/
    /*get_single_user_info("1");   */
    /*printf("user_info.name is %s \n",_user_info.name);*/
    /*printf("user_info.image_location is %s \n",_user_info.image_path);*/
    /*free_single_user_info_garbage();*/
    /*return 0;*/
/*}*/
