#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
public:
    Rectangle(Color color, Rect rect) : Shape(color, rect) {};
    std::vector<std::vector<std::string>>* draw() override;
    std::string get_desc() override;
    void edit(std::string parameters) override;
};

