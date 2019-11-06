#include <gtk/gtk.h>
#include <single_user.h>

GObject * right_top_dialog_box;

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

static int testfunc(void * test){

    g_print("test ...\n");
    return 0;

}
static void change_display(GtkWidget *widget,gpointer   data[])
{
    /*gtk_widget_set_size_request(GTK_WIDGET(data[0]),-1,0);*/
    gtk_widget_hide(data[0]);
    gtk_widget_set_size_request(GTK_WIDGET(data[1]),-1,640);
    gtk_widget_hide(data[2]);
    /*gtk_widget_set_size_request(GTK_WIDGET(data[2]),-1,0);*/
    gtk_search_bar_set_search_mode(GTK_SEARCH_BAR(data[3]),1);
}

static void default_display(GtkWidget *widget,gpointer   data[])
{
    /*gtk_widget_set_size_request(GTK_WIDGET(data[0]),-1,0);*/
    gtk_widget_show(data[0]);
    /*gtk_widget_set_size_request(GTK_WIDGET(data[1]),-1,600);*/
    gtk_widget_set_size_request(GTK_WIDGET(data[1]),-1,400);
    gtk_widget_show(data[2]);
    gtk_search_bar_set_search_mode(GTK_SEARCH_BAR(data[3]),0);
}




int main (int   argc,char *argv[])
{

    gtk_init (&argc, &argv);

    /* Construct a GtkBuilder instance and load our UI description */
    GtkBuilder *builder = gtk_builder_new ();

    GError *error = NULL;
    if (gtk_builder_add_from_file (builder, "testMainWindow.ui", &error) == 0)
    {
        g_printerr ("Error loading file: %s\n", error->message);
        g_clear_error (&error);
        return 1;
    }

    /* Connect signal handlers to the constructed widgets. */
    GObject *window = gtk_builder_get_object (builder, "window");
    
    right_top_dialog_box = gtk_builder_get_object(builder,"right_top_dialog_box");

    /*GObject * left_pane_box = gtk_builder_get_object(builder,"left_pane_box");*/
    /*gtk_widget_set_size_request(GTK_WIDGET(left_pane_box_sco_win),240,600);*/
    /*GObject * left_pane = gtk_builder_get_object(builder,"left_pane");*/
    /*gtk_widget_set_size_request(GTK_WIDGET(left_pane),200,600);*/

    GObject * left_pane_box= gtk_builder_get_object(builder,"left_pane_box");

    
    GtkWidget * search_bar = gtk_search_bar_new();
    GtkWidget * search_bar_entry = gtk_entry_new();
    //
    //真的有作用
    gtk_widget_set_size_request(GTK_WIDGET(search_bar_entry),180,10);
    /*gtk_search_bar_connect_entry(GTK_SEARCH_BAR(search_bar),GTK_ENTRY(search_bar_entry));*/
    gtk_container_add(GTK_CONTAINER(search_bar),search_bar_entry);
    gtk_list_box_insert(GTK_LIST_BOX(left_pane_box),GTK_WIDGET(search_bar),0);

    GtkWidget * single_user_name = gtk_button_new();
    gtk_list_box_insert(GTK_LIST_BOX(left_pane_box),GTK_WIDGET(single_user_name),1);
    //下面这一觉改变窗口的没有用
    /*gtk_widget_set_size_request(GTK_WIDGET(single_user_name),240,20);*/
    gtk_button_set_label(GTK_BUTTON(single_user_name),"点我进入搜索");
    /*GObject * single_user_image = gtk_builder_get_object(builder,"single_user_image");*/
    /*gtk_image_set_from_file(GTK_IMAGE(single_user_image),"./chromium.svg");*/

    /*GObject * left_pane_box_pan1 = gtk_builder_get_object(builder,"left_pane_box_pan1");*/
    /*gtk_widget_set_size_request(GTK_WIDGET(left_pane_box_pan1),240,4);*/
    GtkWidget * single_user_name1 = gtk_button_new();
    gtk_list_box_insert(GTK_LIST_BOX(left_pane_box),GTK_WIDGET(single_user_name1),2);
    //下面这一觉改变窗口的没有用
    /*gtk_widget_set_size_request(GTK_WIDGET(single_user_name),240,10);*/
    gtk_button_set_label(GTK_BUTTON(single_user_name1),"点我退出搜索");
    /*GObject * single_user_image1 = gtk_builder_get_object(builder,"single_user_image1");*/
    /*gtk_image_set_from_file(GTK_IMAGE(single_user_image1),"./acrobat.svg");*/

    /*gtk_search_bar_set_search_mode(GTK_SEARCH_BAR(search_bar),1);*/
    gtk_search_bar_set_show_close_button (GTK_SEARCH_BAR(search_bar),1);

    Load_all_user_to_widget(GTK_WIDGET(left_pane_box));
    /*printf("是这里错了吗\n");*/

    GObject * test_right_top_dialog_box = gtk_builder_get_object(builder,"right_top_dialog_box");

    Load_all_user_to_widget2(GTK_WIDGET(test_right_top_dialog_box));

    /*GObject *right_top_pane =gtk_builder_get_object(builder,"right_top_pane");*/
    /*gtk_widget_set_size_request(GTK_WIDGET(right_top_pane),150,100);*/
    /*button = gtk_builder_get_object (builder, "button2");*/
    /*g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);*/

    GObject *right_top_pane_sco =gtk_builder_get_object(builder,"right_top_pane_sco");
    gtk_widget_set_size_request(GTK_WIDGET(right_top_pane_sco),-1,400);

    
    /*gtk_list_box_select_row(GTK_LIST_BOX(right_top_dialog_box),GTK_LIST_BOX_ROW(33));*/
    /*printf("是这里错了吗1\n");*/
    GObject *right_bottom_sco_win =gtk_builder_get_object(builder,"right_bottom_sco_win");
    gtk_widget_set_size_request(GTK_WIDGET(right_bottom_sco_win),-1,200);


    GObject *send_button =gtk_builder_get_object(builder,"send_button");
    GObject *user_edit_view=gtk_builder_get_object(builder,"user_edit_view");
    /*gtk_widget_set_size_request(GTK_WIDGET(right_bottom_sco_win),-1,200);*/

    GObject * change_list[] = {send_button,right_top_pane_sco,right_bottom_sco_win,(GObject *)search_bar};
    /*g_signal_connect_swapped(button,"clicked",G_CALLBACK(change_display),GTK_WIDGET(right_top_pane_sco));*/

    //就执行一次　一秒后执行
    g_timeout_add(1000,testfunc,0);
    g_signal_connect (single_user_name, "clicked", G_CALLBACK (change_display), change_list);
    g_signal_connect (single_user_name1, "clicked", G_CALLBACK (default_display), change_list);
    g_signal_connect(send_button,"clicked",G_CALLBACK(get_text),GTK_TEXT_VIEW(user_edit_view));
    gtk_widget_show_all(GTK_WIDGET(window));
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_main ();

    return 0;
}
