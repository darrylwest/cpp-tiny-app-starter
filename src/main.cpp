//
// dpw
//

#include <spdlog/spdlog.h>
#include <app/tiny.hpp>

int main() {

    constexpr auto lang = "c++";
    spdlog::info("Hello and welcome to {} tiny application, version: {}", lang, app::VERSION);

    return 0;
}

