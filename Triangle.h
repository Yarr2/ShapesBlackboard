#pragma once
#include "Shape.h"
class Triangle :
    public Shape
{
    int _x_point1 = 0;
    int _y_point1 = 0;
    int _x_point2 = 0;
    int _y_point2 = 0;
    int _x_point3 = 0;
    int _y_point3 = 0;
    static void draw_side(Color color, int x1, int y1, int x2, int y2,
        std::vector<std::vector<std::string>>* board
    );
    static Rect get_rect(
        int x_point1, int y_point1, 
        int x_point2, int y_point2,
        int x_point3, int y_point3);
public:
    Triangle(bool filled, Color color, 
        int x_point1, int y_point1,
        int x_point2, int y_point2,
        int x_point3, int y_point3);
    
    std::vector<std::vector<std::string>>* draw() override;
    std::string get_desc() override;
    void edit(std::string parameters) override;
    std::string serialise() override;
    void change_while_move(int new_x, int new_y);
};

