/*#include "single_user.h"*/


//UI层文件，当用户点击朋友的时候，显示其历史对话窗口
#include <my_sqlite.h>
#include <gtk/gtk.h>


//
//将数据写到本地数据库中后调update_messsage_to_window()将本地的数据库中的内容添加到
//  显示窗口中去
//  ＇


//将消息填充到窗口中
//一般在刚刚启动的时候用　或者切换交流用户的时候用　
//
//
//
//
//生成历史的对话窗口，当点击的时候就将本窗口add_container_to相应的窗口，
//TODO:需要有一个维护的表，用户global_id与相应的对话窗口表
GtkWidget *generate_dialog(GtkWidget *widget,gpointer text){
    
    //函数原型 得到这个时间之后的最近一条信息
    //返回　时间　消息类型　消息内容　谁发送的　发送的方向　给谁　在数据库的第几行
    //      time  text     "你好啊"　　"global_id"  inward  "global_id"  54
    //      audio      audio    "音频位置"　"小狗蛋"　　outword  "巴嘎"　　66
    //get_message_by_time(char *username,strcut time timeid);   
    
    /*get_message_by_time()*/
    //需要实现的功能
    //  判断时间大于10分钟就显示一次时间：
    GtkWidget *message=NULL;




    return message;
}
