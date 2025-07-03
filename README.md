# Tiny Application Starter

```
 _______ __                _______ __               __                _______              
|_     _|__|.-----.--.--. |     __|  |_.---.-.----.|  |_.-----.----. |   _   |.-----.-----.
  |   | |  ||     |  |  | |__     |   _|  _  |   _||   _|  -__|   _| |       ||  _  |  _  |
  |___| |__||__|__|___  | |_______|____|___._|__|  |____|_____|__|   |___|___||   __|   __|
                  |_____|                                                     |__|  |__|   
```

Minimal application startup.

## Features

* cmake 3.30.0
* c++23
* osx clang-17.0
* linux gcc-14.2.0
 
## Includes

* spdlog
* Catch2

## File Structure

```
tiny-app
  | 
  └─include
    ├── app
    │   └── tiny.hpp
    └── vendor
        ├── ansi_colors.hpp
        └── cxxopts.hpp
        └── perftimer.hpp
  └─src
    └── main.cpp
  └─tests
    └── main_unit.cpp
```

There is also a GEMINI.md file with minimal rules.

## Use

* clone or download this project
* change include path to real name
* remove / replace `.git` and do a `git init`
* have gemini (or claude code) refactor the `tiny` file names and namespaces to `your-project` including the CMakeLists.txt and target

## Alternate Branches

* develop - the most basic startup with spdlog, catch2, nlohmann json, threads
* kvstore - adds support for quickkv and domainkeys for an in-memory k/v store

###### dpw | 2025-07-03

<!-- txkey for last update -->
<p style="font-size: 5px;">81MzL7oHYRG9</p>
