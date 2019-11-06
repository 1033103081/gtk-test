#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    
    char cmd[200] = "insert into user values(";
    char num[8] = "000000";
    for (int i = 0; i < 100; ++i) {
        char last[2];
        if(i <10){
            sprintf(last,"%d",0);
            sprintf(&last[1],"%d",i);
            
        }else{
            sprintf(last,"%d",i);
        }
        strcat(num,last); 
        strcat(cmd,num);

    }



    return 0;
}
