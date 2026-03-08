#include <iostream>

#pragma once
/*
Это класс который выполняет роль управления логами
Этот класс работает по принципу ООП инкапсуляции, а именно:
В публичном поле всё то, с чем разработчику можно взаймодействовать
В приватном поле поля, с которыми либо никак нельзя взаймодействовать, либо можно взаймодействовать через Set...() | Get...();

Если в логах записывается время, запись происходит в формате:
[HH] : [MM] : [SS]

------
Эта библиотека распространяется под лицензией Apache License 2.0
Подробности можете найти на: https://github.com/SG123it/Clogs
------
This library is distributed under the Apache License 2.0
You can find the details at: https://github.com/SG123it/Clogs
------

*/
class log {
private:

    //Данная переменная должна содержать в себе путь для создания файла, без имени файла
    inline static std::string AbsoluteFilePath = ".";

    //Данная переменная должна содержать в себе имя файла для записи конфигурации
    inline static std::string FileName = "LOG.txt";

    inline static bool SaveToFile = false;
    inline static bool PrintToConsole = true;

    /*Данная переменная должна содержать в себе булевое значение определяющее, будет ли программа в логи добавлять время
    В формате: [HH] : [MM] : [SS], [MS(setprecision(2))]*/
    inline static bool UseTime = true;

public:
    enum LOG_TYPE {
            INFO,
            WARNING,
            ERROR,
            CRITICAL
    };

    //Это функция нужна для вывода сообщения (и / или) запись сообщения в файл
    static void get(LOG_TYPE type, std::string MSG);

    static void Set_SaveToFile(bool value);
    static bool Get_SaveToFile();

    static void Set_PrintToConsole(bool value);
    static bool Get_PrintToConsole();

    static void Set_AbsoluteFilePath(std::string value);
    static std::string Get_AbsoluteFilePath();

    static void Set_FileName(std::string value);
    static std::string Get_FileName();

    static void Set_UseTime(bool value);
    static bool Get_UseTime();
};