#pragma once

#include <string>
#include "chess_piece.h"
#include "move.h"
#include "board.h"
#include <vector>

class Engine{
public:
    Engine();
    void set_position_from_fen(std::string);
    void make_move(std::string);
    void make_move(Move move);
    void print_position();
    Move get_best_move(int depth);
    std::vector<Move> get_all_moves();
    void make_move(Move move);
    void unmake_move();
private:
    Board _board;
    Color _next_move;
    bool _black_can_short_castling;
    bool _black_can_long_castling;
    bool _white_can_short_castling;
    bool _white_can_long_castling;
    bool _canEnPassant;
    Point _enPassantAtackField;
    int32_t _rule_50_halfmoves_counter;
    int32_t _full_moves_counter;
    std::vector<Move> maked_moves;

    std::vector<Move> get_moves_for_king(char vertical, int horizontal);
    std::vector<Move> get_moves_for_queen(char vertical, int horizontal);
    std::vector<Move> get_moves_for_rock(char vertical, int horizontal);
    std::vector<Move> get_moves_for_bishop(char vertical, int horizontal);
    std::vector<Move> get_moves_for_knight(char vertical, int horizontal);
    std::vector<Move> get_moves_for_pawn(char vertical, int horizontal, Color color);
};