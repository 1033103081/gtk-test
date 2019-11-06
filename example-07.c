#include <gtk/gtk.h>
/*static gboolean*/
/*window_key_press_event_cb (GtkWidget *window,GdkEvent *event,GtkSearchBar *search_bar)*/
/*{*/
    /*return gtk_search_bar_handle_event (search_bar, event);*/
/*}*/

GtkTextIter start,end;

//获取整段文字框里面输入的内容
static void get_text(GtkWidget *widget,gpointer entry){
    
    GtkTextBuffer *hello = gtk_text_view_get_buffer(GTK_TEXT_VIEW(entry));
    gint tmp =  gtk_text_buffer_get_char_count(hello);
    gtk_text_buffer_get_iter_at_offset(hello,&start ,0);
    gtk_text_buffer_get_iter_at_offset(hello,&end,tmp);
    const gchar * ret = gtk_text_buffer_get_text(hello,&start,&end,0);
    //gchar *
    //gtk_text_buffer_get_text (GtkTextBuffer *buffer,
    //        const GtkTextIter *start,
    //        const GtkTextIter *end,
    //        gboolean include_hidden_chars);
    g_print(ret,"\n");
    g_print("\n");

}
int main(int argc, char** argv) {

    GtkWidget *window;
    GtkWidget *frame;
    /*GtkWidget *entry;*/
    GtkWidget *button;
    /*GtkWidget *search_bar;*/
    /*GtkWidget *box;*/
    /*GtkWidget *entry_box;*/
    /*GtkWidget *menu_button;*/
    GtkWidget *text_view;
    GtkTextBuffer *buffer=0; 


    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 500);
    gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
    gtk_window_set_title(GTK_WINDOW(window), "准备实现图形用户界面");

    frame = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), frame);

    button = gtk_button_new_with_label("发送");
    gtk_widget_set_size_request(button, 80, 35);
    gtk_fixed_put(GTK_FIXED(frame), button, 740,420);

    /*entry = gtk_entry_new();*/
    /*gtk_entry_set_width_chars ((GtkEntry *)entry,40);*/
    /*gtk_fixed_put(GTK_FIXED(frame), entry, 500, 380); */

    gtk_text_buffer_set_text(buffer,"Hello , this is a demo",-1);
    text_view=gtk_text_view_new_with_buffer(buffer);/*创建文本框构件*/
    /*buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));[>获得文本框缓冲区<] */
    gtk_fixed_put(GTK_FIXED(frame),text_view,500,280); 


/*    search_bar = gtk_search_bar_new ();*/
    /*gtk_fixed_put (GTK_FIXED (frame), search_bar,0,0);*/
    /*gtk_widget_show (search_bar);*/

    /*box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 6);*/
    /*gtk_container_add (GTK_CONTAINER (search_bar), box);*/
    /*gtk_widget_show (box);*/

    /*entry_box = gtk_search_entry_new ();*/
    /*gtk_box_pack_start (GTK_BOX (box), entry, TRUE, TRUE, 0);*/
    /*gtk_widget_show (entry);*/

    /*menu_button = gtk_menu_button_new ();*/
    /*gtk_box_pack_start (GTK_BOX (box), menu_button, FALSE, FALSE, 0);*/
    /*gtk_widget_show (menu_button);*/

    /*gtk_search_bar_connect_entry (GTK_SEARCH_BAR (search_bar), GTK_ENTRY (entry_box));*/

    /*g_signal_connect (window, "key-press-event",G_CALLBACK (window_key_press_event_cb), search_bar);*/
    /*g_signal_connect(window, "destroy",G_CALLBACK (gtk_main_quit), NULL);*/
    g_signal_connect(button, "clicked", G_CALLBACK(get_text), GTK_TEXT_VIEW(text_view));

    g_signal_connect(window, "destroy",G_CALLBACK (gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
