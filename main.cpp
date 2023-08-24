#include <iostream>
#include "engine.h"

int main(){
    Engine engine;
    engine.set_position_from_fen(std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
    engine.print_position();
    return 0;
}