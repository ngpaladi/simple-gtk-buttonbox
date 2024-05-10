#ifndef BUTTONBOX_H
#define BUTTONBOX_H

#include <cstdlib>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <utility> 



class ButtonBox : public Gtk::Window
{
public:
    ButtonBox(std::string title_string, std::vector<std::pair<std::string, std::string>> button_map);
    ~ButtonBox();

private:
    std::string title;

    void on_button(const Glib::ustring &data);

    Gtk::Grid grid;
    std::vector<Gtk::Button> button;
};

#endif