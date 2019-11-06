#include <stdio.h>
#include <gtk/gtk.h>

/* 创建一个"信息"列表 */

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

GtkWidget *create_list( void )
{

    GtkWidget *scrolled_window;
    GtkWidget *tree_view;
    /*GtkListStore *model;*/
    /*GtkTreeIter iter;*/
    GtkCellRenderer *cell;
    GtkTreeViewColumn *column;

    /* 创建一个新的滚动窗口(scrolled window)，只有需要时，滚动条才出现 */
    scrolled_window = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
            GTK_POLICY_AUTOMATIC, 
            GTK_POLICY_AUTOMATIC);

    /*model = gtk_list_store_new (1,G_TYPE_STRING); */
    tree_view = gtk_tree_view_new ();
    /*gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (scrolled_window), */
            /*tree_view);*/
    /*GtkWidget* paned = gtk_paned_new(GTK_ORIENTATION_VERTICAL);*/
    
    /*GtkWidget * box =    gtk_box_new(GTK_ORIENTATION_VERTICAL,1);*/
    gtk_container_add(GTK_CONTAINER(scrolled_window),tree_view);
    /*gtk_tree_view_set_model (GTK_TREE_VIEW (tree_view), GTK_TREE_MODEL (model));*/
    gtk_widget_show (tree_view);

    /* 在窗口中添加一些消息 */
    for (int i = 0; i < 100; i++ ) {
        /*gchar *msg = g_strdup_printf ("Message #%d", i);*/
        /*gtk_list_store_append (GTK_LIST_STORE (model), &iter);*/
        /*gtk_list_store_set (GTK_LIST_STORE (model), &iter,0, msg, -1);*/
        /*g_free (msg);*/
    }

    cell = gtk_cell_renderer_text_new ();

    column = gtk_tree_view_column_new_with_attributes ("即时通信",
            cell,
            "text", 0,
            NULL);

    gtk_tree_view_append_column (GTK_TREE_VIEW (tree_view),
            GTK_TREE_VIEW_COLUMN (column));

    return scrolled_window;
}

int main( int argc,char *argv[] )
{
    GtkWidget *window;
    GtkWidget *vpaned;
    GtkWidget *vpaned1;// 暂时没有使用
    GtkWidget *vpaned2; //
    GtkWidget *vpaned3;
    GtkWidget *list;
    GtkWidget *list1;
    GtkWidget *button;
    GtkWidget *scrolled_window;
    GtkWidget *view;
    /*GtkTextBuffer *buffer;*/

    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Free Like A Bird");

    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    /* 在顶级窗口上添加一个垂直分栏窗口构件 */

    /*vpaned = gtk_vpaned_new ();*/
    vpaned= gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    vpaned1 = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
    vpaned2 = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
    vpaned3 = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
    gtk_container_add (GTK_CONTAINER (window), vpaned);
    gtk_widget_show (vpaned);

    /* 在分栏窗口的两部分各添加一些构件 */

    list = create_list ();
    gtk_paned_pack1 (GTK_PANED (vpaned), list,1,0);
    gtk_widget_show (list);

    view = gtk_text_view_new ();
    /*buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));*/
    scrolled_window = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
    gtk_container_add (GTK_CONTAINER (scrolled_window), view);
    gtk_widget_show_all (scrolled_window);

    list1 = create_list ();
    gtk_paned_pack1 (GTK_PANED (vpaned1), list1,1,0);
    gtk_widget_show (list1);



    /*gtk_paned_add2 (GTK_PANED (vpaned), vpaned1);*/
    gtk_paned_pack2 (GTK_PANED (vpaned), vpaned2,1,1);
    gtk_widget_show (vpaned2);
    
    /*gtk_paned_add1(GTK_PANED(vpaned1),text);*/
    gtk_paned_pack1(GTK_PANED(vpaned2),vpaned1,1,0);
    gtk_paned_pack2(GTK_PANED(vpaned2),vpaned3,1,0);
    gtk_paned_pack1(GTK_PANED(vpaned3),scrolled_window,1,0);
    gtk_widget_show (scrolled_window);

    button = gtk_button_new_with_label("发送");
    /*gtk_paned_add2(GTK_PANED(vpaned1),button);*/
    gtk_paned_pack2(GTK_PANED(vpaned3),button,0,1);
    gtk_widget_show (vpaned1);
    gtk_widget_show (vpaned2);
    gtk_widget_show (vpaned3);
    gtk_widget_show(button);
    gtk_widget_show (window);

    g_signal_connect(button, "clicked", G_CALLBACK(get_text), GTK_TEXT_VIEW(view));
    g_signal_connect(window, "destroy",G_CALLBACK (gtk_main_quit), NULL);
    gtk_main ();

    return 0;
}
