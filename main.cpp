#include <iostream>
#include <clipp.h>

using namespace clipp;

/*
  Demo: commands may not be optional, thus a global "-v" cannot co-exists with any command
*/
int main(int argc, char* argv[]) {
    enum class mode { find, help, version };
    mode selected = mode::help;

    auto cli = ((
            command("find").set(selected, mode::find) |
            command("help").set(selected, mode::help)
        ).optional(),
        option("-v", "--version").set(selected, mode::version).doc("show version")
    );

    if ( parse(argc, argv, cli) ) {
        switch( selected ) {
            case mode::find: std::cout << "find action" << std::endl; break;
            case mode::help: std::cout << make_man_page(cli, argv[0]) << std::endl; break;
            case mode::version: std::cout << "Version 0.1.0\n\n"; break;
        }

    } else {
        std::cout << make_man_page(cli, argv[0]) << std::endl;
    }

    std::cout << "Hello, world!\n";
}
