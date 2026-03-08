#include <iostream>
#include "CLOGS.hpp"
int main() {

    log::Set_SaveToFile(true);
    log::get(log::LOG_TYPE::INFO, "TEST INFO MESSAGE");

    return 0;
}