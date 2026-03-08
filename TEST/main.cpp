#include <iostream>
#include "CLOGS.hpp"
int main() {

    log::Set_SaveToFile(true);
    log::get(log::LOG_TYPE::INFO, "TEST INFO MESSAGE");
    log::get(log::LOG_TYPE::WARNING, "TEST WARN MESSAGE");
    log::get(log::LOG_TYPE::ERROR, "TEST ERR MESSAGE");
    log::get(log::LOG_TYPE::CRITICAL, "TEST CRITICAL MESSAGE");

    std::cout << "\n\n";

    //2 Флага выключены, сработает условие и PrintToConsole всё равно включится
    log::Set_SaveToFile(false);
    log::Set_PrintToConsole(false);

    log::get(log::LOG_TYPE::INFO, "TEST INFO MESSAGE");
    log::get(log::LOG_TYPE::WARNING, "TEST WARN MESSAGE");
    log::get(log::LOG_TYPE::ERROR, "TEST ERR MESSAGE");
    log::get(log::LOG_TYPE::CRITICAL, "TEST CRITICAL MESSAGE");

    std::cout << "\n\n";

    //Без времени
    log::Set_UseTime(false);

    log::get(log::LOG_TYPE::INFO, "TEST INFO MESSAGE");
    log::get(log::LOG_TYPE::WARNING, "TEST WARN MESSAGE");
    log::get(log::LOG_TYPE::ERROR, "TEST ERR MESSAGE");
    log::get(log::LOG_TYPE::CRITICAL, "TEST CRITICAL MESSAGE");

    std::cin.get();

    return 0;
}