#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <string>
#include <iostream>
#include <utility>

#include "ButtonBox.h"

static int on_cmd(const Glib::RefPtr<Gio::ApplicationCommandLine> &, Glib::RefPtr<Gtk::Application> &app)
{
    app->activate();
    return 0;
}

int main(int argc, char *argv[])
{

    auto app = Gtk::Application::create(argc, argv, "org.noahpaladino.simple-gtk-buttonbox", Gio::APPLICATION_HANDLES_COMMAND_LINE);
    app->signal_command_line().connect(sigc::bind(sigc::ptr_fun(on_cmd), app), false);

    std::vector<std::pair<std::string, std::string>> buttons;
    std::string title;
    if (argc > 1 && argc % 2 == 0)
    {
        title = argv[1];
        for (int i = 2; i < argc; i += 2)
        {
            buttons.push_back(std::pair<std::string, std::string>(std::string(argv[i]), std::string(argv[i + 1])));
        }
    }
    else
    {
        std::cerr << "Requires an odd number of arguments (title + n*(name + action))!" << std::endl;
        return 1;
    }

    ButtonBox window(title, buttons);

    return app->run(window);
}