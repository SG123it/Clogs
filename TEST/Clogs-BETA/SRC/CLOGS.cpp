#include <iostream>
#include <chrono>
#include <ctime>
#include <filesystem>

#include <CLOGS.hpp>


void log::get(LOG_TYPE type, std::string MSG) {
    std::string return_text = ""; //Весь текст прежде чем вывести его в консоль (и/или) записать в файл будет записан сюда

    //Шаг 1 : Запись времени в формате [HH] : [MM] : [SS]
    //-------------------------
    if (UseTime){
        std::time_t now = std::time(nullptr);
        std::tm localTime = *std::localtime(&now);

        return_text += std::to_string(localTime.tm_hour) + ":" + std::to_string(localTime.tm_min) + ":" + std::to_string(localTime.tm_sec);

        return_text += " | ";
    }

    //Шаг 2 : Запись типа лога в return_text
    //-------------------------
    return_text += "[ ";

    switch(type) {

        case(LOG_TYPE::INFO):
            return_text += "INFO";
            break;
        case(LOG_TYPE::WARNING):
            return_text += "WARNING";
            break;
        case(LOG_TYPE::ERROR):
            return_text += "ERROR";
            break;
        case(LOG_TYPE::CRITICAL):
            return_text += "CRITICAL";
            break;
        default:
            return_text += "-"; //НА крайний случай, я думаю выкидывать здесь исключение будет не разумно
            break;

    }

    return_text += " ]";

    //Шаг 3 : Запись сообщения
    //-------------------------
    return_text += " : ";

    return_text += MSG;

    //Шаг 4 : Вывод в консоль (и/или) запись в файл
    //-------------------------
    if (!(PrintToConsole || SaveToFile)) PrintToConsole = true; //Оба параметра не могут быть пустыми

    if (PrintToConsole) std::cout << return_text << std::endl;
    if (SaveToFile) {
        if (!std::filesystem::exists(AbsoluteFilePath)) throw std::runtime_error("Unable to exists path to logs");

        std::filesystem::path path = AbsoluteFilePath;
        path /= FileName;

    }
}

//----------------------------------

void log::Set_SaveToFile(bool value)
{
    SaveToFile = value;
}
bool log::Get_SaveToFile()
{
    return SaveToFile;
}

void log::Set_PrintToConsole(bool value)
{
    PrintToConsole = value;
}
bool log::Get_PrintToConsole()
{
    return PrintToConsole;
}

void log::Set_AbsoluteFilePath(std::string value)
{
    if (!std::filesystem::exists(value)) throw std::runtime_error("Unable to exists path to logs");
    AbsoluteFilePath = value;
}
std::string log::Get_AbsoluteFilePath()
{
    return AbsoluteFilePath;
}

void log::Set_FileName(std::string value)
{
    FileName = value;
}
std::string log::Get_FileName()
{
    return FileName;
}

void log::Set_UseTime(bool value)
{
    UseTime = value;
}
bool log::Get_UseTime() 
{
    return UseTime;
}