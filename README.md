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

* cmake 3.30
* c++23
* osx, linux
 
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
  └─src
    └── main.cpp
  └─tests
    └── main_unit.cpp
```

## Use

* clone or download this project
* change include path to real name
* remove / replace `.git` and do a `git init`

## Alternate Branches

* develop - the most basic startup with spdlog, catch2, nlohmann json, threads
* kvstore - adds support for quickkv and domainkeys for an in-memory k/v store

###### 2025.03.27 | dpw
