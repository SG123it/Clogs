<B> <h3>
Clogs - pet project that helps you to add a logging to your project<br><br>
If you want to include this lib to your project please go to TEST/cmakelists.txt and copy this file to your project

<br><br><br>


Code Example

    #include <iostream>
    #include "CLOGS.hpp"
    int main() {

        log::Set_SaveToFile(true);
        log::get(log::LOG_TYPE::INFO, "TEST INFO MESSAGE");
        log::get(log::LOG_TYPE::WARNING, "TEST WARN MESSAGE");
        log::get(log::LOG_TYPE::ERROR, "TEST ERR MESSAGE");
        log::get(log::LOG_TYPE::CRITICAL, "TEST CRITICAL MESSAGE");

        Return 0;
    }

Cmakelists Example

    #--------
    set(p_name CLOGS_TEST)
    set(p_ver 1.0)
    #--------

    cmake_minimum_required(VERSION 3.10...3.30)

    add_subdirectory(Clogs-BETA)

    project(${p_name} VERSION ${p_ver})

    set(SRC
        main.cpp
    )

    add_executable(${p_name} ${SRC})
    target_include_directories(${p_name} PUBLIC Clogs-BETA/header)
    target_link_libraries(${p_name} PUBLIC CLOGS)


</h3> </b>
