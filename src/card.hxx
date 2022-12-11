#pragma once

class Card
{
private:
    char color;
    int value;
    char special_thing;

public:

    Card(char colorin, int valuein, char special_thingin) : color(colorin),value(valuein), special_thing(special_thingin)
    {}

    const char get_color()
    {
        return color;
    }

    const char get_type()
    {
        return value;
    }

    const char get_special_thing()
    {
        return special_thing;
    }


};
