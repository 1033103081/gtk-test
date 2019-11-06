#include  <gtk/gtk.h>

//点击按钮后被调用的函数，用于输出hello，world
static void print_msg (GtkWidget *button , gpointer data)
{
    printf("Hello , world!\n");
}

static void activate (GtkApplication *app , gpointer data)
{
    GtkWidget *win;

    //申明一个按钮
    GtkWidget *button;
    //申明一个盒容器，用于容纳按钮，控制大小
    GtkWidget *button_box;

    win = gtk_application_window_new(app);

    gtk_window_set_title(GTK_WINDOW(win) , "Button test");
    gtk_window_set_default_size(GTK_WINDOW(win) , 200 , 200);

    //创建一个盒容器，并设置水平放置
    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL); //gtk_orientation_horizontal

    //将盒容器包含进window中
    gtk_container_add(GTK_CONTAINER(win) , button_box);

    //创建一个按钮，并带有“My button” 的标签
    button = gtk_button_new_with_label("My button");

    //连接信号，让点击按钮后，便调用 print_msg 函数
    g_signal_connect(button , "clicked" , G_CALLBACK( print_msg ) , NULL);
    //将按钮放入盒容器中
    gtk_container_add(GTK_CONTAINER(button_box) , button);

    //显示window及其所有控件
    gtk_widget_show_all(win);
}

int main(int argc , char **argv)
{
    GtkApplication *app;
    int app_status;

    app = gtk_application_new("org.gtk.exmple" , G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app , "activate" , G_CALLBACK(activate) , NULL);

    app_status = g_application_run(G_APPLICATION(app) , argc , argv);

    g_object_unref(app);

    return app_status;
}
