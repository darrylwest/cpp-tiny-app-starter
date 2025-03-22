//
// Created by Darryl West on 3/22/25.
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() function

#include <catch2/catch_all.hpp>
#include <app/tiny.hpp>
#include <vendor/ansi_colors.hpp>
#include <spdlog/spdlog.h>

struct MainTestSetup {
    MainTestSetup() {
        using namespace colors;
        spdlog::set_level(spdlog::level::critical);

        // do any config stuff
        // start the perf timer
    }

    ~MainTestSetup() {
        using namespace colors;
        std::println("{} Tests complete...{}", bright::cyan, colors::reset);
    }
};

// put helpers here...

// Tests here
TEST_CASE("Version test", "[version]") {

    const auto vers = app::VERSION;
    REQUIRE(vers == app::VERSION);
}