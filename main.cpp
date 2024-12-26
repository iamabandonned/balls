#include <iostream>
#include <string>

#define ROWS 100
#define COLLUMNS 100

void init(char map[ROWS][COLLUMNS], char background) {
    for(int i = 0; i < ROWS; ++i){
        for(int j = 0; j < COLLUMNS; ++j){
            map[i][j] = background;
        }
    }
}

void update(char map[ROWS][COLLUMNS]){
    for(int i = 0; i < ROWS-1; ++i){
        for(int j = 0; j < COLLUMNS-1; ++j){
            std::cout << map[i][j];
        }
        std::cout << "\n";
    }
} 

void draw_rect(int x1, int x2, int y1, int y2, char map[ROWS][COLLUMNS]){
    for(int i = y1; i < y2; ++i){
        for(int j = x1; j < x2; ++j){
            map[i][j]='#';
        }
    }
}

int main(){
    char map[ROWS][COLLUMNS];
    int x1 = 10, y1 = 10, x2 = 20, y2 = 20;

    init(map, '\0');

    while(true){
        /*for(int i = 0; i < ROWS; ++i){
            for(int j = 0; j < COLLUMNS; ++j){
                map[i][j] = '#';
                update(map);
            }
        }*/
        draw_rect(x1,x2,y1,y2, map);
        update(map);
    }

    return 0;
}