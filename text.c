#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkWidget *view;
    GtkTextBuffer *buffer;
    GtkTextIter start, end;
    /*PangoFontDescription *font_desc;*/
    /*GdkRGBA rgba;*/
    GtkTextTag *tag;
    GtkCssProvider *provider;
    GtkStyleContext *context;

    view = gtk_text_view_new ();

    buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));

    gtk_text_buffer_set_text (buffer, "Hello, this is some text", -1);

    /* Change default font and color throughout the widget */
    provider = gtk_css_provider_new ();
    gtk_css_provider_load_from_data (provider,
            "textview {"
            " font: 15 serif;"
            "  color: green;"
            "}",
            -1,
            NULL);
    context = gtk_widget_get_style_context (view);
    gtk_style_context_add_provider (context,
            GTK_STYLE_PROVIDER (provider),
            GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    /* Change left margin throughout the widget */
    gtk_text_view_set_left_margin (GTK_TEXT_VIEW (view), 30);

    /* Use a tag to change the color for just one part of the widget */
    tag = gtk_text_buffer_create_tag (buffer, "blue_foreground",
            "foreground", "blue", NULL);  
    gtk_text_buffer_get_iter_at_offset (buffer, &start, 7);
    gtk_text_buffer_get_iter_at_offset (buffer, &end, 12);
    gtk_text_buffer_apply_tag (buffer, tag, &start, &end);   
    return 0;
}

