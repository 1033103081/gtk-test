#include "single_user.h"
#include "my_sqlite.h"
#include <stdio.h>
#include <stdlib.h>

extern GtkWidget *right_top_dialog_box ;
/*static void update_message_window(GtkWidget *widget,gpointer text);*/

gchar * store_button_label(GtkWidget *button){
    
    //意味着button的字符串长度必须小于100
    gchar * malloc_string =(gchar *)malloc(100) ;
    memset(malloc_string,0,100);
    strcpy(malloc_string, gtk_button_get_label(GTK_BUTTON(button)));
    return malloc_string;
    
}
//获取一个用户的信息
GtkWidget * single_user(char *priority){
    
    //查数据库，实现在my_sqlite.c中得到一个全局变量结构体 　_user_info
    get_single_user_info(priority);
    GtkWidget  * pane = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    GtkWidget *button_image ;
    GtkWidget *image_name ;
    GtkWidget *button ;
    
    button_image = gtk_button_new();
    image_name = gtk_image_new_from_file(_user_info.image_path);
    button = gtk_button_new_with_label(_user_info.name);
    gtk_button_set_image(GTK_BUTTON(button_image),image_name);
    
    //将数据库查找的产生的垃圾free 掉，这是我的数据库实现的不好必须要做的
    /*gtk_widget_set_size_request(GTK_WIDGET(pane),240,4);*/
    gtk_paned_pack1(GTK_PANED(pane),button_image,0,0);
    gtk_paned_pack2(GTK_PANED(pane),button,1,0);
    /*g_signal_connect(button,"clicked",G_CALLBACK(update_message_window),*/
            /*store_button_label(button));*/
    /*g_signal_connect(button_image,"clicked",G_CALLBACK(update_message_window),*/
            /*store_button_label(button));*/
    return pane;
}



//将所有朋友添加到左边列表中
void Load_all_user_to_widget(GtkWidget *widget){
    
    //TODO get_user_number() 在my_sqlite.c中的实现
    // 39是一个maginc number 因为我创建的实验数据库生拉硬凑了39个人
    int num = get_message_row_number("user");
    for (int i = 0; i < num; ++i) {
        char str[20];
        sprintf(str,"%d",i);
        GtkWidget * iter = single_user(str);
        gtk_list_box_insert(GTK_LIST_BOX(widget),iter,i+3);
    }   


}

void Load_all_user_to_widget2(GtkWidget *widget){
    
    int num = get_message_row_number("user");
    for (int i = 0; i < num;++i) {
        char str[20];
        sprintf(str,"%d",i);
        GtkWidget * iter = single_user(str);
        gtk_list_box_insert(GTK_LIST_BOX(widget),iter,i+200);
    }   


}


