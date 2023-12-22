#include <iostream>

std::string input_to_string(int input)
{
    if (input == 1)
    {
        return "Schere";
    }

    if (input == 2)
    {
        return "Stein";
    }

    return "Papier";
}

int get_random_computer_input()
{
    std::srand(std::time(nullptr));
    return std::rand() % 3 + 1;
}

int main()
{
    int user_input;
    std::cout << "Bitte wählen:" << std::endl;
    std::cout << " Schere (1)" << std::endl;
    std::cout << " Stein  (2)" << std::endl;
    std::cout << " Papier (3)" << std::endl;
    std::cin >> user_input;
    std::cout << "Spieler wählte " << input_to_string(user_input) << "." << std::endl;

    int computer_input = get_random_computer_input();
    std::cout << "Computer wählte " << input_to_string(computer_input) << "." << std::endl;

    if (computer_input == user_input)
    {
        std::cout << "Keiner gewinnt." << std::endl;
    }
    else if (
        (computer_input == 1 && user_input == 3) || (computer_input == 2 && user_input == 1) || (computer_input == 3 && user_input == 2))
    {
        std::cout << "Computer gewinnt." << std::endl;
    }
    else
    {
        std::cout << "Spieler gewinnt." << std::endl;
    }

    return 0;
}
