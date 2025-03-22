//
// dpw
//

#include <print>
#include <app/tiny.hpp>

int main() {

    constexpr auto lang = "c++";
    std::println("Hello and welcome to {} tiny application, version: {}", lang, app::VERSION);

    return 0;
}

