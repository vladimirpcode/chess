#pragma once

#include <string>

// координаты поля на шахматной доске
struct Point{
    char vertical;
    int horizontal;
};

class Move{
public:
    Move();
    Move(std::string user_input);
    std::string to_string_present();
private:
    Point _start;
    Point _end;
};