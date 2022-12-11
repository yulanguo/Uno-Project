#include "view.hxx"
#include "model.hxx"
//using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

static int const a = 80;

static ge211::Color const white {20, 20, 0};
static ge211::Color const black {255, 255, 255};
static ge211::Color const tilegreen {0, 200, 60};
static ge211::Color const tilered {220,30,40};
static ge211::Color const sdf {5,0,255};
//int spacing = a - 4;
View::View(Model const& model)
        : model_(model),
          redcard({a,a},{255,0,0}),
          bluecard({a,a},{0,0,255}),
          greencard({a,a},{0,255,0}),
          yellowcard({a,a},{230,230,0}),
          backdsprite({a,a}, {180,205,130}),
          sans30("sans.ttf",50),
          sans40("sans.ttf",16),
          one(" 1",sans30),
          two(" 2",sans30),
          three(" 3",sans30),
          four(" 4",sans30),
          five(" 5",sans30),
          six(" 6",sans30),
          seven(" 7",sans30),
          eight(" 8",sans30),
          nine(" 9",sans30),
          endturntext(" End Turn.",sans40),
          reverseslash(" //",sans30),
          plustwo("+2",sans30),
          deck({a,a},{0,0,0}),
          sheet({1000,1000},{0,0,0}),
          endturn({a,a},{170,165,205}),
          turn1("The First Player Has Won!", sans30),
          turn2("The Second Player Has Won!", sans30),
          turn3("The Third Player Has Won!", sans30),
          turn4("The Fourth Player Has Won!", sans30),
          img("uno-icon-square.jpg")
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
    int count = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            count++;
            set.add_sprite(backdsprite,{a*i,a*j},0);
            set.add_sprite(img,{a*5,a*4},500);
            set.add_sprite(endturn,{a*6,a*6},1);
            set.add_sprite(endturntext,{a*6,a*6+25},2);
            set.add_sprite(backdsprite,{a*i,a*j},0);
            set.add_sprite(img,{a*0,a*1},500);
            set.add_sprite(img,{a*0,a*2},500);
            set.add_sprite(img,{a*0,a*3},500);
            set.add_sprite(img,{a*0,a*4},500);
            set.add_sprite(img,{a*0,a*5},500);
            set.add_sprite(img,{a*0,a*6},500);
            set.add_sprite(img,{a*0,a*7},500);
            set.add_sprite(img,{a*8,a*1},500);
            set.add_sprite(img,{a*8,a*2},500);
            set.add_sprite(img,{a*8,a*3},500);
            set.add_sprite(img,{a*8,a*4},500);
            set.add_sprite(img,{a*8,a*5},500);
            set.add_sprite(img,{a*8,a*6},500);
            set.add_sprite(img,{a*8,a*7},500);
            set.add_sprite(img,{a*1,a*0},500);
            set.add_sprite(img,{a*2,a*0},500);
            set.add_sprite(img,{a*3,a*0},500);
            set.add_sprite(img,{a*4,a*0},500);
            set.add_sprite(img,{a*5,a*0},500);
            set.add_sprite(img,{a*6,a*0},500);
            set.add_sprite(img,{a*7,a*0},500);
            set.add_sprite(backdsprite,{a*1,a*1},700);
            set.add_sprite(backdsprite,{a*2,a*1},700);
            set.add_sprite(backdsprite,{a*3,a*1},700);
            set.add_sprite(backdsprite,{a*4,a*1},700);
            set.add_sprite(backdsprite,{a*5,a*1},700);
            set.add_sprite(backdsprite,{a*6,a*1},700);
            set.add_sprite(backdsprite,{a*7,a*1},700);
            set.add_sprite(backdsprite,{a*1,a*2},700);
            set.add_sprite(backdsprite,{a*2,a*2},700);
            set.add_sprite(backdsprite,{a*3,a*2},700);
            set.add_sprite(backdsprite,{a*4,a*2},700);
            set.add_sprite(backdsprite,{a*5,a*2},700);
            set.add_sprite(backdsprite,{a*6,a*2},700);
            set.add_sprite(backdsprite,{a*7,a*2},700);
            set.add_sprite(backdsprite,{a*1,a*3},700);
            set.add_sprite(backdsprite,{a*2,a*3},700);
            set.add_sprite(backdsprite,{a*3,a*3},700);
            set.add_sprite(backdsprite,{a*4,a*3},700);
            set.add_sprite(backdsprite,{a*5,a*3},700);
            set.add_sprite(backdsprite,{a*6,a*3},700);
            set.add_sprite(backdsprite,{a*7,a*3},700);


            if(model_.xy(i,j) == 'a'){
                    set.add_sprite(redcard,{a*i,a*j},count);
                    set.add_sprite(one,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'b'){
                    set.add_sprite(redcard,{a*i,a*j},count);
                    set.add_sprite(two,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'c'){
                    set.add_sprite(redcard,{a*i,a*j},count);
                    set.add_sprite(three,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'd'){
                    set.add_sprite(redcard,{a*i,a*j},count);
                    set.add_sprite(four,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'j'){
                    set.add_sprite(greencard,{a*i,a*j},count);
                    set.add_sprite(one,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'k'){
                    set.add_sprite(greencard,{a*i,a*j},count);
                    set.add_sprite(two,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'l'){
                    set.add_sprite(greencard,{a*i,a*j},count);
                    set.add_sprite(three,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'm'){
                    set.add_sprite(greencard,{a*i,a*j},count);
                    set.add_sprite(four,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 's'){
                    set.add_sprite(yellowcard,{a*i,a*j},count);
                    set.add_sprite(one,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 't'){
                    set.add_sprite(yellowcard,{a*i,a*j},count);
                    set.add_sprite(two,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'u'){
                    set.add_sprite(yellowcard,{a*i,a*j},count);
                    set.add_sprite(three,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'v'){
                    set.add_sprite(yellowcard,{a*i,a*j},count);
                    set.add_sprite(four,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == '1'){
                    set.add_sprite(bluecard,{a*i,a*j},count);
                    set.add_sprite(one,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == '2'){
                    set.add_sprite(bluecard,{a*i,a*j},count);
                    set.add_sprite(two,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == '3'){
                    set.add_sprite(bluecard,{a*i,a*j},count);
                    set.add_sprite(three,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == '4'){
                    set.add_sprite(bluecard,{a*i,a*j},count);
                    set.add_sprite(four,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'n'){
                    set.add_sprite(redcard,{a*i,a*j},count);
                    set.add_sprite(reverseslash,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'e'){
                    set.add_sprite(bluecard,{a*i,a*j},count);
                    set.add_sprite(reverseslash,{i*a,j*a},count+1);
                }if(model_.xy(i,j) == 'x') {
                    set.add_sprite(greencard, {a * i, a * j}, count);
                    set.add_sprite(plustwo, {i * a, j * a}, count + 1);
                }if(model_.xy(i,j) == '5'){
                    set.add_sprite(yellowcard,{i*a,j*a},count);
                    set.add_sprite(plustwo, {i * a, j * a}, count + 1);
                }
}
        }
    if(model_.a() == 9){
        set.add_sprite(backdsprite,{a*1,a*8},700);
        set.add_sprite(backdsprite,{a*2,a*8},700);
        set.add_sprite(backdsprite,{a*3,a*8},700);
        set.add_sprite(backdsprite,{a*4,a*8},700);
        set.add_sprite(backdsprite,{a*5,a*8},700);
        set.add_sprite(backdsprite,{a*6,a*8},700);
        set.add_sprite(backdsprite,{a*7,a*8},700);
    }
    if(model_.is_game_over()){
        set.add_sprite(sheet,{0,0},1000);
        if(model_.turn() == 1){
            set.add_sprite(turn1,{50,a*4},1020);
        }
        if(model_.turn() == 2){
            set.add_sprite(turn2,{50,a*4},1020);
        }
        if(model_.turn() == 3){
            set.add_sprite(turn3,{50,a*4},1020);
        }
        if(model_.turn() == 4){
            set.add_sprite(turn4,{50,a*4},1020);
        }
    }





    }
View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    return a * Dimensions{9, 9};
}

View::Position
View::screen_to_board(View::Position pos) const
{
    return {pos.x / a, pos.y / a};
}
