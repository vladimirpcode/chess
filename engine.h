#pragma once

#include <string>
#include "chess_piece.h"
#include "move.h"
#include "board.h"

class Engine{
public:
    Engine();
    void set_position_from_fen(std::string);
    void make_move(Move);
    void print_position();
private:
    Board _board;
    Color _next_move;
    bool _black_can_short_castling;
    bool _black_can_long_castling;
    bool _white_can_short_castling;
    bool _white_can_long_castling;
    bool _canEnPassant;
    int32_t _rule_50_halfmoves_counter;
    int32_t _full_moves_counter;
};