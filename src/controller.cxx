#include "controller.hxx"
#include <algorithm>

Controller::Controller()
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}
void
Controller::on_mouse_up(ge211::Mouse_button, ge211::Posn<int> position)
{
    View::Position board_pos = view_.screen_to_board(position);
    model_.play_move(board_pos.x, board_pos.y);
}