#include "engine.h"
#include <string>
#include <iostream>
#include <vector>

Engine::Engine(){
    set_position_from_fen(std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
}

void Engine::set_position_from_fen(std::string fen){
    int pos = 0;
    int horizontal = 8;
    char vertical = 'a';
    char c = fen[pos];
    while (c != ' '){
        switch (c) {
            case '/': vertical = 'a'; horizontal--; break;
            case 'k': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::KING, Color::BLACK)); vertical++; break;
            case 'q': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::QUEEN, Color::BLACK)); vertical++; break;
            case 'r': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::ROCK, Color::BLACK)); vertical++; break;
            case 'b': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::BISHOP, Color::BLACK)); vertical++; break;
            case 'n': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::KNIGHT, Color::BLACK)); vertical++; break;
            case 'p': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::PAWN, Color::BLACK)); vertical++; break;
            case 'K': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::KING, Color::WHITE)); vertical++; break;
            case 'Q': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::QUEEN, Color::WHITE)); vertical++; break;
            case 'R': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::ROCK, Color::WHITE)); vertical++; break;
            case 'B': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::BISHOP, Color::WHITE)); vertical++; break;
            case 'N': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::KNIGHT, Color::WHITE)); vertical++; break;
            case 'P': _board.set(vertical, horizontal, ChessPiece(ChessPieceType::PAWN, Color::WHITE)); vertical++; break;
            //ниже используется свойство языка С++, когда в отсутствие break выполнение переходит к нижележащей ветке
            case '1': 
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8': {
                int blank_fields = c - 48;
                for (int skip_vertical_index = 0; skip_vertical_index < blank_fields; skip_vertical_index++){
                    _board.set(horizontal, vertical, ChessPiece(ChessPieceType::BLANK, Color::WHITE));
                    vertical++;
                }
                break;
            }
        }
        pos++;
        c = fen[pos];
    }
    if (fen[pos] == ' '){
        pos++;
    }
    if (fen[pos] == 'w'){
        _next_move = Color::WHITE;
    } else if (fen[pos] == 'b'){
        _next_move = Color::BLACK;
    }
    pos++;
    if (fen[pos] == ' '){
        pos++;
    }
    if (fen[pos] == '-'){
        pos++;
    } else {
        while (fen[pos] != ' '){
            switch (fen[pos]){
                case 'k': _black_can_short_castling = true; break;
                case 'q': _black_can_long_castling = true; break;
                case 'K': _white_can_short_castling = true; break;
                case 'Q': _white_can_long_castling = true; break;
            }
            pos++;
        }
    }
    if (fen[pos] == ' '){
        pos++;
    }
    if (fen[pos] == '-'){
        pos++;
        _canEnPassant = false;
    } else {
        _canEnPassant = true;
        _enPassantAtackField.vertical = fen[pos];
        _enPassantAtackField.horizontal = fen[pos+1] - 48;
        pos += 2;
    }
    if (fen[pos] == ' '){
        pos++;
    }
    _rule_50_halfmoves_counter = fen[pos] - 48;
    pos++;
    if (fen[pos] == ' '){
        pos++;
    }
    _full_moves_counter = fen[pos] - 48;
}

void Engine::make_move(std::string user_input){

}

void Engine::make_move(Move move){
    
}

void Engine::unmake_move(){

}

void Engine::print_position(){
    for (int horizontal = 8; horizontal >= 1; horizontal--){
        for (char vertical = 'a'; vertical <= 'h'; vertical++){
            std::cout << ' ' << _board.get(vertical, horizontal).get_char_present() << ' ';
            if (vertical != 'h'){
                std::cout << "|";
            }
        }
        std::cout << std::endl << "_______________________________" << std::endl;
    }
}

Move Engine::get_best_move(int depth){

}

std::vector<Move> Engine::get_moves_for_king(char vertical, int horizontal){

}

std::vector<Move> Engine::get_moves_for_queen(char vertical, int horizontal){

}

std::vector<Move> Engine::get_moves_for_rock(char vertical, int horizontal){

}

std::vector<Move> Engine::get_moves_for_bishop(char vertical, int horizontal){

}

std::vector<Move> Engine::get_moves_for_knight(char vertical, int horizontal){

}

std::vector<Move> Engine::get_moves_for_pawn(char vertical, int horizontal, Color color){
    // 1. обычный ход вперед 2. взятие 
    // 3. взятие на проходе 4. превращение
    int increment = 1;
    if (color == Color::BLACK){
        increment = -1;
    }
    // Обычный ход
    if (is_correct_pos(vertical, horizontal + increment) &&
        is_blank_pos(vertical, horizontal + increment)){
        
    }
    
}

std::vector<Move> Engine::get_all_moves(){
    std::vector<Move> all_moves;
    for (int horizontal = 8; horizontal >= 1; horizontal--){
        for (char vertical = 'a'; vertical <= 'h'; vertical++){
            Color piece_color = _board.get(vertical, horizontal).color();
            std::vector<Move> moves;
            switch (_board.get(vertical, horizontal).type()){
                case ChessPieceType::PAWN: moves = get_moves_for_pawn(vertical, horizontal, piece_color); break;
                case ChessPieceType::KNIGHT: moves = get_moves_for_knight(vertical, horizontal); break;
                case ChessPieceType::BISHOP: moves = get_moves_for_bishop(vertical, horizontal); break;
                case ChessPieceType::ROCK: moves = get_moves_for_rock(vertical, horizontal); break;
                case ChessPieceType::QUEEN: moves = get_moves_for_queen(vertical, horizontal); break;
                case ChessPieceType::KING: moves = get_moves_for_king(vertical, horizontal); break;
            }
            for (auto &m:moves){
                all_moves.push_back(m);
            }
        }
    }
    return all_moves;
}

bool Engine::is_king_atacked(Color color){

}

bool Engine::is_correct_pos(char vertical, int horizontal){

}


bool Engine::is_blank_pos(char vertical, int horizontal){

}