#include <iostream>

char get_symbol_for_number(int player)
{
    if (player == 1)
    {
        return 'X';
    }

    if (player == 2)
    {
        return 'O';
    }

    return '_';
}

void print_board(int board[9])
{
    for (int i = 0; i < 9; i += 3)
    {
        std::cout << i << ": " << get_symbol_for_number(board[i]) << " ";
        std::cout << i + 1 << ": " << get_symbol_for_number(board[i + 1]) << " ";
        std::cout << i + 2 << ": " << get_symbol_for_number(board[i + 2]) << std::endl;
    }

    std::cout << std::endl;
}

bool is_winner(int board[9], int player)
{
    int winning_combinations[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6},
    };

    for (int i = 0; i < 8; i++)
    {
        int field_1 = winning_combinations[i][0];
        int field_2 = winning_combinations[i][1];
        int field_3 = winning_combinations[i][2];

        if (board[field_1] == player && board[field_2] == player && board[field_3] == player)
        {
            return true;
        }
    }

    return false;
}

bool has_empty_field(int board[9])
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
        {
            return true;
        }
    }

    return false;
}

void await_player_input(int board[9], int player)
{
    int input;
    std::cout << "Player " << get_symbol_for_number(player) << ", ";
    std::cout << "please select a field [0-8]: ";
    std::cin >> input;
    while (board[input] != 0)
    {
        std::cout << "Field " << input << " is already blocked. Please select another one: ";
        std::cin >> input;
    }
    board[input] = player;
}

int main()
{
    // 0 = empty
    // 1 = X
    // 2 = O
    int game_board[9] = {0};
    int input;

    print_board(game_board);

    while (true)
    {
        if (!has_empty_field(game_board))
        {
            std::cout << "Board is full. The game is a draw." << std::endl;
            break;
        }

        await_player_input(game_board, 1);
        print_board(game_board);
        if (is_winner(game_board, 1))
        {
            std::cout << "Player X wins." << std::endl;
            break;
        }

        await_player_input(game_board, 2);
        print_board(game_board);
        if (is_winner(game_board, 2))
        {
            std::cout << "Player O wins." << std::endl;
            break;
        }
    }

    return 0;
}
