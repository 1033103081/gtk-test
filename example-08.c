#include <gtk/gtk.h>

static void print_hello (GtkWidget *widget, gpointer   data)
{
    g_print ("Hello World\n");
}

static void activate (GtkApplication *app,gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *frame;
    GtkWidget *button;
    GtkWidget *button_box;
    GtkWidget *layout;
    GtkWidget *layout1;
    GtkWidget *grid;
    GtkAdjustment *hAdjustment=NULL;
    GtkAdjustment *vAdjustment=NULL;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 800, 560);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    frame=gtk_fixed_new();
    /*hAdjustment = gtk_adjustment_new(1,1,1,0.1,1,20);*/
    /*vAdjustment = gtk_adjustment_new(1,1,1,0.1,1,20);*/
    layout = gtk_layout_new(hAdjustment,vAdjustment);
    layout1 = gtk_layout_new(hAdjustment,vAdjustment);
    
    grid = gtk_grid_new();

    button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    gtk_layout_set_size(GTK_LAYOUT(layout),200,200);
    gtk_layout_set_size(GTK_LAYOUT(layout1),200,200);

    gtk_container_add(GTK_CONTAINER(window),grid);
    gtk_grid_attach(GTK_GRID(grid),layout,0,0,200,200);
    gtk_grid_attach(GTK_GRID(grid),layout1,201,0,200,200);

    gtk_container_add(GTK_CONTAINER(layout),frame);
    button = gtk_button_new_with_label ("Hello World");

    gtk_fixed_put(GTK_FIXED(frame),button_box,1,1);
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    /*gtk_container_add (GTK_CONTAINER (button_box), button);*/
    gtk_grid_attach(GTK_GRID(grid),button,401,200,2,1);

    gtk_widget_show_all (window);
}

int main (int argc,char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}

