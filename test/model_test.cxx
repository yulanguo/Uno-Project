#include "model.hxx"
#include <catch.hxx>

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

TEST_CASE("check valid move")
{
    Model m;
    // assuming the value at these locations is the same as the middle
    CHECK(m.check_valid_move(m.boardd(3, 4), 1, 2));
    CHECK(m.check_valid_move(m.boardd(3, 4), 0, 1));
    CHECK(m.check_valid_move(m.boardd(3, 4), 3, 1));

    //checks false with the middle
    CHECK_FALSE(m.check_valid_move(m.boardd(3, 4), 3, 4));

}

TEST_CASE("end turn button")
{
    Model m;
    // assuming the value at these locations is the same as the middle
    if (m.turn() == 1){
        m.end_turn();
        CHECK(m.turn() == 2);
    }

    if (m.turn() == 2){
        m.end_turn();
        CHECK(m.turn() == 3);
    }

    if (m.turn() == 3){
        m.end_turn();
        CHECK(m.turn() == 4);
    }

    if (m.turn() == 4){
        m.end_turn();
        CHECK(m.turn() == 1);
    }

}

TEST_CASE("game over")
{
    // check to see game is not over
    Model m;
    CHECK_FALSE(m.gameover());


    //check to see if game is over
    m.boardd2(0, 8);
    m.boardd2(1, 8);
    m.boardd2(2, 8);
    m.boardd2(3, 8);
    m.boardd2(4, 8);
    m.boardd2(5, 8);
    m.boardd2(6, 8);
    m.boardd2(7, 8);
    m.boardd2(8, 8);
    CHECK(m.gameover());

}


TEST_CASE("play move")
{
    // check the pile reflects the card you put down
    Model m;
    char x = 'k';
    m.set_board(1, 8, 'k');
    m.set_board(3, 4, 'k');
    x = m.boardd(1, 8);
    printf("%c", x);
    m.play_move(1, 8);
    // check if valid move
    CHECK(m.boardd(3, 4) == 'k');

    // check that the pile didn't change if they're not compatible
    Model k;
    k.set_board(1, 8, 'k');
    k.set_board(3, 4, 's');
    k.play_move(1, 8);
    // check if valid move
    CHECK(k.boardd(3, 4) == 's');

}


TEST_CASE("3")
{
    // check to see if card is  in hand
    Model m;
    char x = 'k';
    m.set_board(1, 8, 'k');
    m.set_board(3, 4, 'k');
    x = m.boardd(1, 8);
    printf("%c", x);
    m.play_move(1, 8);
    // check if valid move
    CHECK(m.boardd(3, 4) == 'k');
    CHECK(m.boardd(7, 8) == '-');

    // check to see that card is not in hand
    Model k;
    k.set_board(1, 8, 'k');
    k.set_board(3, 4, 's');
    k.play_move(1, 8);
    // check if valid move
    CHECK(k.boardd(3, 4) == 's');
    CHECK(k.boardd(1, 8) == 'k');
}










//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate your functional requirements.
//
