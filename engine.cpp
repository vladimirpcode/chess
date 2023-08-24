#include "engine.h"
#include <string>

Engine::Engine(){
    set_position_from_fen(std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
}

void Engine::set_position_from_fen(std::string fen){
    int pos = 0;
    int vertical = 8;
    int horizontal = 'a';
    for (int horizontal_count = 0; horizontal_count < 8; horizontal_count++){
        char c = fen[pos];
        switch (c) {
            case '/': vertical = 'a'; horizontal--; break;
            case 'k': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::KING, Color::BLACK)); break;
            case 'q': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::QUEEN, Color::BLACK)); break;
            case 'r': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::ROCK, Color::BLACK)); break;
            case 'b': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::BISHOP, Color::BLACK)); break;
            case 'n': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::KNIGHT, Color::BLACK)); break;
            case 'p': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::PAWN, Color::BLACK)); break;
            case 'K': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::KING, Color::WHITE)); break;
            case 'Q': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::QUEEN, Color::WHITE)); break;
            case 'R': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::ROCK, Color::WHITE)); break;
            case 'B': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::BISHOP, Color::WHITE)); break;
            case 'N': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::KNIGHT, Color::WHITE)); break;
            case 'P': _board.set(horizontal, vertical, ChessPiece(ChessPieceType::PAWN, Color::WHITE)); break;
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
    }
    if (fen[pos] == ' '){
        pos++;
    }
}

void Engine::make_move(Move){

}

void Engine::print_position(){

}