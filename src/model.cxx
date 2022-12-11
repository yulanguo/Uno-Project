#include "model.hxx"
//#include "card.hxx"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <algorithm>


Model::Model():
        turn_(1),
        winner_(0),
        reverse_('n'),
        playdone_('n'),
        count_(1),
        a_(0),
        plustwoo_(0)
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            //int x = rand() % 44;
            board_[i][j] = '-';
        }
    }

    std::vector<char> cards;
    //std::srand(std::time(0));

    cards.push_back('a');
    //card r1

    cards.push_back('b');
    // card r2

    cards.push_back('c');
    // card r3

    cards.push_back('d');
    //card r4

    cards.push_back('j');
    //card g1

    cards.push_back('k');
    //card g2

    cards.push_back('l');
    //card g3

    cards.push_back('m');
    //card g4

    cards.push_back('s');
    //card y1

    cards.push_back('t');
    //card y2

    cards.push_back('u');
    //card y3

    cards.push_back('v');
    //card y4

    cards.push_back('1');
    //card b1

    cards.push_back('2');
    //card b2

    cards.push_back('3');
    //card b3

    cards.push_back('4');
    //card b4

    cards.push_back('n');
    //red, reverse

    cards.push_back('e');
    //blue, reverse

    cards.push_back('x');
    //green, plus two

    cards.push_back('5');
    //yellow, plus two



    //
    char b2;
    for (int i = 1; i < 8; i++)
    {
        std::shuffle(cards.begin(), cards.end(), std::random_device());
        b2 = cards[1];
        board_[i][0] = b2;
        board_[i][8] = b2;
        std::shuffle(cards.begin(), cards.end(), std::random_device());
        b2 = cards[1];
        board_[i][1] = b2;
        std::shuffle(cards.begin(), cards.end(),std::random_device());
        b2 = cards[1];
        board_[i][2] = b2;
        std::shuffle(cards.begin(), cards.end(), std::random_device());
        b2 = cards[1];
        board_[i][3] = b2;
    }

    std::shuffle(cards.begin(), cards.end(), std::random_device());
    b2 = cards[1];
    board_[3][4] = b2;
    std::shuffle(cards.begin(), cards.end(), std::random_device());
    b2 = cards[count_];
    board_[5][4] = b2;


}

void Model::change_turn()
{
    // if (reverse_ == 'n'){
        if (turn_ == 1) {
            turn_ = 2;
        }
        else if (turn_ == 2) {
            turn_ = 3;
        }
        else if (turn_ == 3) {
            turn_ = 4;
        }
        else if (turn_ == 4) {
            turn_ = 1;
        }}

    // else  {
    //         if (turn_ == 1) {
    //             turn_ = 4;
    //         } else if (turn_ == 2) {
    //             turn_ = 1;
    //         } else if (turn_ == 3) {
    //             turn_ = 2;
    //         } else if (turn_ == 4) {
    //             turn_ = 3;
    //         }
    //     }
    //
    // else if (reverse_ == 'y'){
    //     if (turn_ == 1) {
    //         turn_ = 4;
    //     }
    //     else if (turn_ == 2) {
    //         turn_ = 3;
    //     }
    //     else if (turn_ == 3) {
    //         turn_ = 2;
    //     }
    //     else if (turn_ == 4) {
    //         turn_ = 1;
    //     }
    //    }
    //}
//}ß

// void Model::change_reverse()
// {
//     if (reverse_ == 'n'){
//         reverse_ = 'y';
//         }
//     else if (reverse_== 'y')
//     {
//         reverse_ = 'n';
//     }
// }
// //
// void Model::change_reverse()
// {
//     char temp;
//     for (int i = 1; i < 8; i++){
//
//         temp = board_[i][0];
//         board_[i][0] = board_[i][3];
//         board_[i][3] = temp;
//         temp = board_[i][1];
//         board_[i][1] = board_[i][2];
//         board_[i][2] = temp;
//
//
//     }
// }

// int Model::next_turn()
// {
//     if (reverse_ == 0){
//         if (turn_ == 1) {
//             return 2;
//         }
//         if (turn_ == 2) {
//             return 3;
//         }
//         if (turn_ == 3) {
//             return 4;
//         }
//         if (turn_ == 4) {
//             return 1;
//         }}
//     if (reverse_ == 1){
//         if (turn_ == 1) {
//             return 4;
//         }
//         if (turn_ == 2) {
//             return 1;
//         }
//         if (turn_ == 3) {
//             return 2;
//         }
//         if (turn_ == 4) {
//             return 3;
//         }
//     }
//     return 0;
// }

bool Model::check_valid_move(char x, int i, int j)
{
    char t = board_[3][4];
    if (i == 3 && j == 4){
        return false;
    }
    if (x == 'a'){
        if (t=='b' or t=='c' or t=='d' or t=='1' or t=='s' or t=='j' or
        t=='n' or t==x) {
            return true;
        }}
    if (x == 'b'){
        if (t=='a' or t=='c' or t=='d' or t=='2' or t=='t' or t=='k' or
        t=='n' or t == x){
            return true;
        }}
    if (x == 'c'){
        if (t=='b' or t=='a' or t=='d' or t=='3' or t=='u' or t=='l' or
        t=='n' or t == x){
            return true;
        }}
    if (x == 'd'){
        if (t=='b' or t=='c' or t=='a' or t=='4' or t=='v' or t=='m' or
        t=='n' or t == x){
            return true;
        }}
    if (x == 'j'){
        if (t=='k' or t=='l' or t=='m' or t=='1' or t=='s' or t=='a' or
        t=='x' or t == x){
            return true;
        }}
    if (x == 'k'){
        if (t=='j' or t=='l' or t=='m' or t=='2' or t=='t' or t=='b' or
        t=='x' or t == x){
            return true;
        }}
    if (x == 'l'){
        if (t=='j' or t=='k' or t=='m' or t=='3' or t=='u' or t=='c' or
        t=='x' or t == x){
            return true;
        }}
    if (x == 'm'){
        if (t=='j' or t=='k' or t=='l' or t=='4' or t=='v' or t=='d' or
        t=='x' or t == x){
            return true;
        }}
    if (x == 's'){
        if (t=='t' or t=='u' or t=='v' or t=='1' or t=='a' or t=='j' or
        t=='5' or t == x){
            return true;
        }}
    if (x == 't'){
        if (t=='s' or t=='u' or t=='v' or t=='2' or t=='b' or t=='k' or
        t=='5' or t == x){
            return true;
        }}
    if (x == 'u'){
        if (t=='s' or t=='t' or t=='v' or t=='3' or t=='c' or t=='l' or
        t=='5' or t == x){
            return true;
        }}
    if (x == 'v'){
        if (t=='s' or t=='t' or t=='u' or t=='4' or t=='d' or t=='m' or
        t=='5' or t == x){
            return true;
        }}
    if (x == '1'){
        if (t=='2' or t=='3' or t=='4' or t=='a' or t=='s' or t=='j' or
        t=='e' or t == x){
            return true;
        }}
    if (x == '2'){
        if (t=='3' or t=='4' or t=='1' or t=='b' or t=='t' or t=='k' or
        t=='e' or t == x){
            return true;
        }}
    if (x == '3'){
        if (t=='1' or t=='2' or t=='4' or t=='c' or t=='u' or t=='l' or
        t=='e' or t == x){
            return true;
        }}
    if (x == '4'){
        if (t=='1' or t=='2' or t=='3' or t=='d' or t=='v' or t=='m' or
        t=='e' or t == x){
            return true;
        }}
    if (x == 'n'){
        if (t=='e' or t=='a' or t=='b' or t=='c' or t=='d' or t == x){
            return true;
        }}
    if (x == 'e'){
        if (t=='n' or t=='1' or t=='2' or t=='3' or t=='4' or t == x){
            return true;
        }}
    if (x == 'x'){
        if (t=='j' or t=='k' or t=='l' or t=='m' or t=='5' or t == x){
            return true;
        }}
    if (x == '5'){
        if (t=='s' or t=='t' or t=='u' or t=='v' or t=='x' or t == x){
            return true;
        }}
    return false;
}

void Model::play_move(int i, int j)
{

    if (winner_ != 0) {
        return;
    }
    if (i == 5 && j == 4) {
        if(playdone_ != 'y'){
            for (int rr = 1; rr < 8; rr++){
                if(board_[rr][8] == '-'){
                    board_[rr][8] = board_[5][4];
                    rr = 8;
                    playdone_ = 'n';
                }
            }
        }
    }
    if (i == 6 && j == 6) {
        end_turn();
        playdone_ = 'n';
    } else {
        bool valid_move = check_valid_move(board_[i][j], i, j);
        if (valid_move) {
            if(playdone_ != 'y'){
            board_[3][4] = board_[i][j];
            //     if (board_[i][j]== 'n' or board_[i][j] == 'e')
            //     {
            //         //a_ = 0;
            //         change_reverse();
            //         printf("%d", reverse_);
            //         printf("%d", turn_);
            //         printf("%d", reverse_);
            //         //a_ = 1;
            //     }
            //
            if (board_[i][j]== '5' or 'x')
            {
               //plustwoo_ = 1;
            }

            board_[i][j] = '-';
            int aa = 0;
            while (board_[i + 1 + aa][j] != '-') {
                board_[i + aa][j] = board_[i + 1 + aa][j];
                board_[i + 1 + aa][j] = '-';
                aa += 1;
            }
            playdone_ = 'y';


            if (gameover()){
                winner_ = turn_;
                return;
            }
        }}


    }


    //if(board_[i][j] == board[])
    //check person's turn
    //corresponds to row

    // for loop
    // push cards to cover gap

    // char temp;
    // for(int k = 1; k < 8; k++){
    //     temp = board_[k][8];
    //     board_[k][8] = board_[k + 1][8];
    //
    // }

    //else draw a card


}

void Model::end_turn()
{
    std::vector<char> cards;
    //std::srand(std::time(0));

    cards.push_back('a');
    //card r1

    cards.push_back('b');
    // card r2

    cards.push_back('c');
    // card r3

    cards.push_back('d');
    //card r4

    cards.push_back('j');
    //card g1

    cards.push_back('k');
    //card g2

    cards.push_back('l');
    //card g3

    cards.push_back('m');
    //card g4

    cards.push_back('s');
    //card y1

    cards.push_back('t');
    //card y2

    cards.push_back('u');
    //card y3

    cards.push_back('v');
    //card y4

    cards.push_back('1');
    //card b1

    cards.push_back('2');
    //card b2

    cards.push_back('3');
    //card b3

    cards.push_back('4');
    //card b4

    cards.push_back('n');
    //red, reverse

    cards.push_back('e');
    //blue, reverse

    cards.push_back('x');
    //green, plus two

    cards.push_back('5');
    //yellow, plus two


    if (turn_ == 1) {
        board_[1][0] = board_[1][8];
        board_[2][0] = board_[2][8];
        board_[3][0] = board_[3][8];
        board_[4][0] = board_[4][8];
        board_[5][0] = board_[5][8];
        board_[6][0] = board_[6][8];
        board_[7][0] = board_[7][8];
    } else if (turn_ == 2) {
        board_[1][1] = board_[1][8];
        board_[2][1] = board_[2][8];
        board_[3][1] = board_[3][8];
        board_[4][1] = board_[4][8];
        board_[5][1] = board_[5][8];
        board_[6][1] = board_[6][8];
        board_[7][1] = board_[7][8];
    } else if (turn_ == 3) {
        board_[1][2] = board_[1][8];
        board_[2][2] = board_[2][8];
        board_[3][2] = board_[3][8];
        board_[4][2] = board_[4][8];
        board_[5][2] = board_[5][8];
        board_[6][2] = board_[6][8];
        board_[7][2] = board_[7][8];
    } else if (turn_ == 4) {
        board_[1][3] = board_[1][8];
        board_[2][3] = board_[2][8];
        board_[3][3] = board_[3][8];
        board_[4][3] = board_[4][8];
        board_[5][3] = board_[5][8];
        board_[6][3] = board_[6][8];
        board_[7][3] = board_[7][8];
    }
    board_[1][8] = '-';
    board_[2][8] = '-';
    board_[3][8] = '-';
    board_[4][8] = '-';
    board_[5][8] = '-';
    board_[6][8] = '-';
    board_[7][8] = '-';
    a_ = 9;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    a_ = 0;
    board_[1][8] = '-';
    board_[2][8] = '-';
    board_[3][8] = '-';
    board_[4][8] = '-';
    board_[5][8] = '-';
    board_[6][8] = '-';
    board_[7][8] = '-';
    std::this_thread::sleep_for(std::chrono::seconds(2));

    change_turn();

    if (turn_ == 1) {
        board_[1][8] = board_[1][0];
        board_[2][8] = board_[2][0];
        board_[3][8] = board_[3][0];
        board_[4][8] = board_[4][0];
        board_[5][8] = board_[5][0];
        board_[6][8] = board_[6][0];
        board_[7][8] = board_[7][0];
        std::shuffle(cards.begin(), cards.end(), std::random_device());
        board_[5][4] = cards[0];
    } else if (turn_ == 2) {
        board_[1][8] = board_[1][1];
        board_[2][8] = board_[2][1];
        board_[3][8] = board_[3][1];
        board_[4][8] = board_[4][1];
        board_[5][8] = board_[5][1];
        board_[6][8] = board_[6][1];
        board_[7][8] = board_[7][1];
        std::shuffle(cards.begin(), cards.end(), std::random_device());
        board_[5][4] = cards[0];
    } else if (turn_ == 3) {
        board_[1][8] = board_[1][2];
        board_[2][8] = board_[2][2];
        board_[3][8] = board_[3][2];
        board_[4][8] = board_[4][2];
        board_[5][8] = board_[5][2];
        board_[6][8] = board_[6][2];
        board_[7][8] = board_[7][2];
        std::shuffle(cards.begin(), cards.end(), std::random_device());
        board_[5][4] = cards[0];
    } else if (turn_ == 4) {
        board_[1][8] = board_[1][3];
        board_[2][8] = board_[2][3];
        board_[3][8] = board_[3][3];
        board_[4][8] = board_[4][3];
        board_[5][8] = board_[5][3];
        board_[6][8] = board_[6][3];
        board_[7][8] = board_[7][3];
        std::shuffle(cards.begin(), cards.end(), std::random_device());
        board_[5][4] = cards[0];
        }
    if(plustwoo_ == 1){
        plustwo();
        plustwoo_ = 0;
    }





    }



// void Model::plustwo()
// {
//     int i = 0;
//     int count = 1;
//     int x2;
//     while (i < 2 or count < 9) {
//
//         if (board_[count][next_turn() - 1] == '-') {
//             x2 = rand() % 20;
//             board_[count][next_turn() - 1] = cards[x2];
//             i = i + 1;
//         }
//         count = count + 1;
//     }
// }

void Model::boardd2(int i, int j){
    board_[i][j] = '-';
}


void Model::set_board(int i, int j, char x){
    board_[i][j] = x;
}

bool Model::gameover()
{
    for (int ee = 0; ee < 9; ee++) {
        if (board_[ee][8] != '-') {
            return false;
        }}
    count_ = 1000;
    return true;

}

void Model::plustwo()
{
        for (int rr = 1; rr < 8; rr++){
            if(board_[rr][8] == '-'){
                board_[rr][8] = board_[5][4];
                if(rr+1<8){
                    board_[rr+1][8] = board_[5][4];
                }
            }}
    }



