#include <iostream>
#include <array>

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

void print_board(std::array<int, 9> &board)
{
    for (int i = 0; i < board.size(); i += 3)
    {
        std::cout << i << ": " << get_symbol_for_number(board[i]) << " ";
        std::cout << i + 1 << ": " << get_symbol_for_number(board[i + 1]) << " ";
        std::cout << i + 2 << ": " << get_symbol_for_number(board[i + 2]) << std::endl;
    }

    std::cout << std::endl;
}

bool is_winner(std::array<int, 9> &board, int player)
{
    const std::array<std::array<int, 3>, 8> winning_combinations{{
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6},
    }};

    for (const auto &combination : winning_combinations)
    {
        const int field_1 = board[combination[0]];
        const int field_2 = board[combination[1]];
        const int field_3 = board[combination[2]];
        if (field_1 == player && field_2 == player && field_3 == player)
        {
            return true;
        }
    }

    return false;
}

bool has_empty_field(std::array<int, 9> &board)
{
    for (const auto &field : board)
    {
        if (field == 0)
        {
            return true;
        }
    }

    return false;
}

void await_player_input(std::array<int, 9> &board, int player)
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
    std::array<int, 9> game_board{0};

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
