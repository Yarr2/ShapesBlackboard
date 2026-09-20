#pragma once
#include "Shape.h"
class Line :
    public Shape
{
    int _x_point1 = 0;
    int _y_point1 = 0;
    int _x_point2 = 0;
    int _y_point2 = 0;
    static Rect get_rect(int x_point1, int y_point1, int x_point2, int y_point2);
public:
    Line(Color color, int x_point1, int y_point1, int x_point2, int y_point2);
    std::vector<std::vector<std::string>>* draw() override;
    std::string get_desc() override;
    void edit(std::string parameters) override;

};

