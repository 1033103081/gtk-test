#include <gtk/gtk.h>

static void get_text(GtkWidget *widget,gpointer entry){
    
    GtkTextIter start,end;
    GtkTextBuffer *hello = gtk_text_view_get_buffer(GTK_TEXT_VIEW(entry));
    gint tmp =  gtk_text_buffer_get_char_count(hello);
    gtk_text_buffer_get_iter_at_offset(hello,&start ,0);
    gtk_text_buffer_get_iter_at_offset(hello,&end,tmp);
    const gchar * ret = gtk_text_buffer_get_text(hello,&start,&end,0);
    g_print(ret,"\n");
    g_print("\n");

}


static void print_hello (GtkWidget *widget,gpointer   data)
{
    g_print ("Hello World\n");
    gtk_search_bar_set_search_mode(GTK_SEARCH_BAR(data),1);
}

int main (int   argc,char *argv[])
{
    GtkBuilder *builder;
    GObject *window;
    /*GObject *button;*/
    GError *error = NULL;

    gtk_init (&argc, &argv);

    /* Construct a GtkBuilder instance and load our UI description */
    builder = gtk_builder_new ();
    if (gtk_builder_add_from_file (builder, "testbuild.ui", &error) == 0)
    {
        g_printerr ("Error loading file: %s\n", error->message);
        g_clear_error (&error);
        return 1;
    }

    /* Connect signal handlers to the constructed widgets. */
    window = gtk_builder_get_object (builder, "window");
    

    GObject * left_pane_box_sco_win = gtk_builder_get_object(builder,"left_pane_sco_win");
    gtk_widget_set_size_request(GTK_WIDGET(left_pane_box_sco_win),240,600);
    /*GObject * left_pane = gtk_builder_get_object(builder,"left_pane");*/
    /*gtk_widget_set_size_request(GTK_WIDGET(left_pane),200,600);*/

    GObject * left_pane_box_pan = gtk_builder_get_object(builder,"left_pane_box_pan");
    gtk_widget_set_size_request(GTK_WIDGET(left_pane_box_pan),240,4);
    GObject * single_user_name = gtk_builder_get_object(builder,"single_user_name");
    gtk_button_set_label(GTK_BUTTON(single_user_name),"测试用户");
    GObject * single_user_image = gtk_builder_get_object(builder,"single_user_image");
    gtk_image_set_from_file(GTK_IMAGE(single_user_image),"./acrobat.svg");

    GObject * left_pane_box_pan1 = gtk_builder_get_object(builder,"left_pane_box_pan1");
    gtk_widget_set_size_request(GTK_WIDGET(left_pane_box_pan1),240,4);
    GObject * single_user_name1 = gtk_builder_get_object(builder,"single_user_name1");
    gtk_button_set_label(GTK_BUTTON(single_user_name1),"测试用户");
    GObject * single_user_image1 = gtk_builder_get_object(builder,"single_user_image1");
    gtk_image_set_from_file(GTK_IMAGE(single_user_image1),"./acrobat.svg");


    /*printf("是这里错了吗\n");*/

    GObject * Search_bar = gtk_builder_get_object(builder,"Search_bar");
    GObject * button = gtk_builder_get_object (builder, "single_user_name");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), Search_bar);

    /*GObject *right_top_pane =gtk_builder_get_object(builder,"right_top_pane");*/
    /*gtk_widget_set_size_request(GTK_WIDGET(right_top_pane),150,100);*/
    /*button = gtk_builder_get_object (builder, "button2");*/
    /*g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);*/

    GObject *right_top_pane_sco =gtk_builder_get_object(builder,"right_top_pane_sco");
    gtk_widget_set_size_request(GTK_WIDGET(right_top_pane_sco),-1,400);

    
    /*printf("是这里错了吗1\n");*/
    GObject *right_bottom_sco_win =gtk_builder_get_object(builder,"right_bottom_sco_win");
    gtk_widget_set_size_request(GTK_WIDGET(right_bottom_sco_win),-1,200);

    gtk_search_bar_set_search_mode(GTK_SEARCH_BAR(Search_bar),0);

    GObject *send_button =gtk_builder_get_object(builder,"send_button");
    GObject *user_edit_view=gtk_builder_get_object(builder,"user_edit_view");
    /*gtk_widget_set_size_request(GTK_WIDGET(right_bottom_sco_win),-1,200);*/

    g_signal_connect(send_button,"clicked",G_CALLBACK(get_text),GTK_TEXT_VIEW(user_edit_view));
    gtk_widget_show_all(GTK_WIDGET(window));
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),Search_bar);
    gtk_main ();

    return 0;
}
