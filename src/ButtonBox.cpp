#include <cstdlib>
#include <gtkmm.h>
#include <gtkmm/grid.h>
#include <gtkmm/button.h>
#include <utility>
#include <iostream>

#include "ButtonBox.h"

ButtonBox::ButtonBox(std::string title_string, std::vector<std::pair<std::string, std::string>> button_list)
{
    title = title_string;
    set_title(title);
    set_border_width(12);
    set_default_size(400, -1);

    grid.set_column_homogeneous(true);
    grid.set_row_spacing(12);
    add(grid);

    for (int i = 0; i < button_list.size(); i++)
    {
        button.push_back(Gtk::Button());
        button[i].set_label((button_list[i].first).c_str());

        if (i == 0)
            grid.add(button[i]);
        else 
            grid.attach_next_to(button[i], button[i-1], Gtk::POS_BOTTOM, 1, 1);
    }
    for (int i = 0; i < button_list.size(); i++)
    {
        button[i].signal_clicked().connect(
            sigc::bind<Glib::ustring>(sigc::mem_fun(*this,
                                                    &ButtonBox::on_button),
                                      button_list[i].second));
    }
    grid.show_all();
}

ButtonBox::~ButtonBox()
{
    std::cout << "Closing " << title << std::endl;
}

void ButtonBox::on_button(const Glib::ustring &data)
{
    std::cout << "Running `" << data << "`" << std::endl;
    system(data.c_str());
    return;
}
