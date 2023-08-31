#pragma once

#include <string>
#include "engine.h"

// координаты поля на шахматной доске
struct Point{
    char vertical;
    int horizontal;
};

class Move{
    friend class Engine;
public:
    Move();
    Move(std::string user_input);
    Move(Point start, Point end);
    std::string to_string_present();
private:
    Point _start;
    Point _end;
};