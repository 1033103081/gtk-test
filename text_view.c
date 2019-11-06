#include <gtk/gtk.h> 

int main(int argc,char *argv[ ]) {
    GtkWidget *window; 
    GtkWidget *text_view;
    /*GtkTextBuffer *buffer; */
    gtk_init(&argc,&argv);

    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window,200,150);
    text_view=gtk_text_view_new();/*创建文本框构件*/
    /*buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));[>获得文本框缓冲区<] */
    gtk_container_add(GTK_CONTAINER(window),text_view); 

    g_signal_connect(GTK_WINDOW(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show(text_view);
    gtk_widget_show(window);
    gtk_main();
}
