#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
public:
    Rectangle(bool filled, Color color, Rect rect) : Shape(filled, color, rect) {};
    std::vector<std::vector<std::string>>* draw() override;
    std::string get_desc() override;
    void edit(std::string parameters) override;
    std::string serialise() override;
};

