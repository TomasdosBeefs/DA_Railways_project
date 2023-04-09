//
// Created by ritac on 09/04/2023.
//

#ifndef RAILWAYS_MENU_H
#define RAILWAYS_MENU_H


#include <string>
#include "Program_data.h"

class Menu {

    void Error(const std::__cxx11::basic_string<char> &erro);

public:
    Menu(Program_data data);
    Menu();

    void backToMainMenu(std::string striBack);

    void backToMainMenu();

    Program_data data_;
};


#endif //RAILWAYS_MENU_H
