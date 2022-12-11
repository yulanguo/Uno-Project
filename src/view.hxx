#pragma once

#include "model.hxx"
#include <string>
#include <algorithm>

class View
{
public:
    using Dimensions = ge211::Dims<int>;

    /// View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    /// View rectangles will use `int` coordinates.
    using Rectangle = ge211::Rect<int>;
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    Dimensions initial_window_dimensions() const;

    Position
    screen_to_board(Position screen_pos) const;

private:
    Model const& model_;
    ge211::Rectangle_sprite backdsprite;
    ge211::Rectangle_sprite redcard;
    ge211::Rectangle_sprite bluecard;
    ge211::Rectangle_sprite yellowcard;
    ge211::Rectangle_sprite deck;
    ge211::Rectangle_sprite greencard;
    ge211::Rectangle_sprite endturn;
    ge211::Font sans30;
    ge211::Font sans40;
    ge211::Text_sprite one;
    ge211::Text_sprite two;
    ge211::Text_sprite three;
    ge211::Text_sprite four;
    ge211::Text_sprite five;
    ge211::Text_sprite six;
    ge211::Text_sprite seven;
    ge211::Text_sprite eight;
    ge211::Text_sprite nine;
    ge211::Text_sprite reverseslash;
    ge211::Text_sprite plustwo;
    ge211::Text_sprite endturntext;
    ge211::Text_sprite endturntext2;
    ge211::Rectangle_sprite sheet;
    ge211::Text_sprite turn1;
    ge211::Text_sprite turn2;
    ge211::Text_sprite turn3;
    ge211::Text_sprite turn4;
    ge211::Image_sprite img;
};