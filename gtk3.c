#include <gtk/gtk.h>

static void activate(GtkApplication *app , gpointer data);

//从文件中加载一张图片
GdkPixbuf *create_pixbuf(const char *image_name);         

int main(int argc , char **argv)
{
    GtkApplication *app;
    int app_status;

    app = gtk_application_new("org.rain.gtk" , G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app , "activate" , G_CALLBACK(activate) , NULL);

    app_status = g_application_run(G_APPLICATION(app) , argc , argv);

    g_object_unref(app);

    return app_status;
}



static void activate(GtkApplication *app , gpointer data)
{
    GtkWidget *window;
    GdkPixbuf *icon;
    GtkWidget *button;
    GtkWidget *button_box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window) , "icon test");
    gtk_window_set_default_size(GTK_WINDOW(window) , 200 , 200);
    gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER);

    //创建图标控件icon
    icon = create_pixbuf("./icon.png");
    //为窗口设置图标
    gtk_window_set_icon(GTK_WINDOW(window) , icon);

    //创建一个带有加速键的按钮，按住 Alt 不放，再按C，即相当于点击按钮
    button = gtk_button_new_with_mnemonic("_Close");

    //为按钮设置一个信息提示条
    gtk_widget_set_tooltip_text(button , "Click button to quit.");

    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add(GTK_CONTAINER(button_box) , button);
    gtk_container_add(GTK_CONTAINER(window) , button_box);
    
    g_signal_connect_swapped(button 
            , "clicked" , G_CALLBACK(gtk_widget_destroy) , window);

    g_object_unref(icon);

    gtk_widget_show_all(window);
}

GdkPixbuf *create_pixbuf(const char *image_name)
{
    GdkPixbuf *pixbuf;

    //加载图片文件，第二个参数设置错误变量的，不需要则设为 NULL
    pixbuf = gdk_pixbuf_new_from_file(image_name , NULL);

    if(!pixbuf) {
        perror("gdk_pixbuf_new_from_file()\n");
        return NULL;
    }

    return pixbuf;
}
