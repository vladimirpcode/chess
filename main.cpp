#include <iostream>
#include "engine.h"
#include <string>
#include "move.h"

void test(){
    Engine engine;
    engine.set_position_from_fen(std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
    engine.print_position();
    std::vector<Move> all_moves = engine.get_all_moves();
    for (auto v:all_moves){
        std::cout << v.to_string_present() << std::endl;
    }
}

int main(){
    test();
    return 0;
    Engine engine;
    engine.set_position_from_fen(std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
    engine.print_position();
    std::string user_input;
    std::cout << "введите Ваш ход: ";
    std::cin >> user_input;
    while (user_input != "exit"){
        engine.make_move(user_input);
        engine.make_move(engine.get_best_move(6));
        engine.print_position();
        std::cout << "введите Ваш ход: ";
        std::cin >> user_input;
    }
    return 0;
}