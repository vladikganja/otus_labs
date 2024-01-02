#include "../lib/lib.h"

#include <boost/program_options.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main (int argc, char** argv) 
try {
    opt::options_description desc;
    opt::variables_map vm;

    bool dryRun;

    desc.add_options()(
        "dry-run", opt::value<bool>(&dryRun)->default_value(false), "Skip printing of version"
    );
    opt::store(opt::parse_command_line(argc, argv, desc), vm);
    opt::notify(vm);

    if (!dryRun) {
        std::cout << "Version: " << version() << std::endl;
    }

    std::cout << "Hello, world!" << std::endl;
    return EXIT_SUCCESS;
} catch (std::exception& ex) {
    std::cerr << ex.what();
    return EXIT_FAILURE;
}
