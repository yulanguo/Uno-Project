#pragma once

#include <ge211.hxx>
//#include "card.hxx"

class Model
{
public:
    Model();

    char xy(int i, int j) const {
        return board_[i][j];
    }

    void change_turn();

    int next_turn();

    bool check_valid_move(char x, int i, int j);

    void play_move(int x, int y);
    void end_turn();
    void plustwo();
    bool gameover();
    int count() const
    { return count_; }
    bool is_game_over() const
    { return count() ==  1000;}
    int turn() const
    { return turn_; }
    int a() const
    { return a_; }
    char boardd(int i, int j) const
    { return board_[i][j]; }
    void boardd2(int i, int j);
    void change_reverse();
    void set_board(int i, int j, char x);



private:
    char board_[9][9];

    int turn_;

    int winner_;
    int a_;

    char reverse_;

    char playdone_;
    int count_;
    int plustwoo_;

    std::vector <char> cards;

    std::vector <int> vector_;


};

