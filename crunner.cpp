/*CRunner v.1 Copyright (c) 2017 JJ Posti <techtimejourney.net> 
#This program comes with ABSOLUTELY NO WARRANTY; 
#for details see: http://www.gnu.org/copyleft/gpl.html. 
#This is free software, and you are welcome to redistribute it under 
#GPL Version 2, June 1991")*/
#include <iostream> 
#include <gtk/gtk.h>
#include <string>
#include <cstdlib>
using namespace std;
//The above includes the stuff that the program needs.

//Constructing a static function, so it will be available only for this file.
static void enter_callback(GtkWidget *entry)
{
	const gchar *entry_text; // Const: stays constant cannot be overwritten by others.
	entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
	printf ("Run: %s\n", entry_text); //Printing what we got.
	system(entry_text); //Getting the text and opening it as a program (or program + arguments.)
	exit(0); //Quit the program. No need to keep it running.
}

//Main Function begins.
int main(int argc, char *argv[]) 
{
	GtkWidget *window; //Here we declare some pointers. Making the work easier. Notice that a "widget" is a base class. Almost everything originates from the widget.
	GtkWidget *button;
	GtkWidget *box1;
	GtkWidget *entry;
//init
	gtk_init(&argc, &argv);

//Window definitions. The style of declaring is very close to Gtk2... my personal opinion only.
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "CRunner");
	gtk_widget_set_size_request(window, 500, 50);
	gtk_window_set_resizable (GTK_WINDOW(window), FALSE);	
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 3);

//Box + Entry
	box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, TRUE);
    entry = gtk_entry_new();
    gtk_entry_set_max_length (GTK_ENTRY (entry), 50);
    
//Connecting to function once enter is pressed (activate is the signal).    
    g_signal_connect (entry, "activate",
		      G_CALLBACK (enter_callback),
		      entry);
//First we add our box to the gtk_container and then we pack our stuff inside the box.    
	gtk_container_add(GTK_CONTAINER(window), box1);
	gtk_box_pack_start(GTK_BOX(box1), entry, FALSE, TRUE, 0);

//Show the window.
	gtk_widget_show_all(window);

//Destroy the window callback. Window needs to get destroyed upon exit. Otherwise it might run forever and this is bad for the memory.  
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}
