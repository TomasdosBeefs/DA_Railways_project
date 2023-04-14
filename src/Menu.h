//
// Created by ritac on 09/04/2023.
//

#ifndef RAILWAYS_MENU_H
#define RAILWAYS_MENU_H


#include <string>
#include "Program_data.h"

/**
 * @class Menu
 * @brief Class for handling the menu functionality of a railways program.
 *
 * This class provides functionality for displaying and handling the menu of a railways program. It includes methods for
 * displaying error messages, navigating back to the main menu, and storing program data.
 */

class Menu {

    /**
     * @brief Displays an error message.
     *
     * This private function displays an error message.
     *
     * @param erro The error message to display.
     */

    void Error(const std::__cxx11::basic_string<char> &erro);

public:
    /**
     * @brief Constructor for Menu class.
     *
     * Constructs a Menu object with the specified Program_data object.
     *
     * @param data The Program_data object to store in the Menu object.
     */
    Menu(Program_data data);

    /**
     * @brief Default constructor for Menu class.
     *
     * Constructs a Menu object without initializing the Program_data object.
     */
    Menu();

    /**
    * @brief Navigates back to the main menu with a custom back string.
    *
    * This function displays a custom back string and navigates back to the main menu.
    *
    * @param striBack The custom back string to display.
    */
    void backToMainMenu(std::string striBack);

    /**
     * @brief Navigates back to the main menu.
     *
     * This function navigates back to the main menu without displaying a custom back string.
     */
    void backToMainMenu();

    /**
     * @brief The Program_data object stored in the Menu object.
     */
    Program_data data_;
};


#endif //RAILWAYS_MENU_H
