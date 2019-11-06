#include <gtk/gtk.h>            //每个GTK程序都要包含的头文件，里面申明了很多类型，函数原型等

static void activate (GtkApplication *app , gpointer data)
{
    GtkWidget *window;                                                                                        //申明一个窗口

    window = gtk_application_window_new(app);                                           //为app创建一个窗口

    gtk_window_set_title(GTK_WINDOW(window) , "Application");              //设置窗口的标题
    gtk_window_set_default_size(GTK_WINDOW(window) , 200 , 200);    //设置窗口默认大小为长宽各200像素
    gtk_widget_show_all(window);                                                                      //显示窗口
}


int main(int argc , char **argv)  //主函数
{
    GtkApplication *app;          //申明创建一个 GtkApplicatin对象名为app
    int app_status;               //用于拿到app 运行结束后的返回值

    app = gtk_application_new("org.rain.gtk" , G_APPLICATION_FLAGS_NONE);  //创建一个application
    g_signal_connect(app , "activate" , G_CALLBACK(activate) , NULL);      //连接信号，初始化app时，调用 activate 函数
    app_status = g_application_run(G_APPLICATION(app) , argc , argv);      //运行app

    g_object_unref(app);                                                  //销毁app

    return app_status;
}
