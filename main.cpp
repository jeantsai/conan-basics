#include <iostream>
#include <clipp.h>

using namespace clipp;

/*
  Demo: commands may not be optional, thus a global "-v" cannot co-exists with any command
*/
int main(int argc, char* argv[]) {
    enum class mode { find, version, help };
    mode selected = mode::help;
    std::string pattern = "";
    std::string glob = "";

    auto cli = (
        (
            opt_value("pattern", pattern).set(selected, mode::find) % "searching pattern"
            & opt_value("path") % "searching path"
        ),
        option("-v", "--version").set(selected, mode::version) % "show version",
        option("-h", "--help").set(selected, mode::help) % "show help information"
    );

    if ( !parse(argc, argv, cli) ) {
        std::cout << make_man_page(cli, argv[0]) << std::endl;
        exit(1);
    }

    switch( selected ) {
        case mode::find: std::cout << "find action" << std::endl; break;
        case mode::help: std::cout << make_man_page(cli, "mygrep") << std::endl; break;
        case mode::version: std::cout << "Version 0.1.0\n\n"; break;
    }

}
