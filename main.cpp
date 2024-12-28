#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cmath>

//so if we have a typical cmd window ROWS would be like height and COLLUMNS like width

#define ROWS 30
#define COLLUMNS 120

//for resizing console
void resize_console(int width, int height) { 
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD bufferSize = { width, height }; 
    SetConsoleScreenBufferSize(hOut, bufferSize);  
    SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 }; 
    SetConsoleWindowInfo(hOut, TRUE, &windowSize); 
}

int main(){
    //map[x * y]
    char* map = new char[COLLUMNS * ROWS];

    //aspect = screen ratio * symbol ratio
    float aspect = 2.0f;
    //for sin in cycles
    float coef = 0;

    resize_console(COLLUMNS, ROWS-1);

    while (true) {
        for (int y = 0; y < ROWS; ++y) {
            for (int x = 0; x < COLLUMNS; ++x) {
                float dx = (float)x / COLLUMNS * 2.0f - 1.0f;
                float dy = (float)y / ROWS * 2.0f - 1.0f;

                //so basically to print a circle correctly we have to multiply x coord by aspect
                map[y * COLLUMNS + x] = ' ';
                if (pow((dx * aspect) - sin(coef), 2) + pow(dy, 2) < 0.5) {
                    map[y * COLLUMNS + x] = '@';
                }
                if (pow((dx * aspect) + sin(coef), 2) + pow(dy, 2) < 0.5) {
                    map[y * COLLUMNS + x] = '@';
                }
                if (((pow((dx * aspect) - sin(coef), 2) + pow(dy, 2) < 0.5) == (pow((dx * aspect) + sin(coef), 2) + pow(dy, 2) < 0.5)) && (((pow((dx * aspect) + sin(coef), 2) + pow(dy, 2) < 0.5) == true) && ((pow((dx * aspect) - sin(coef), 2) + pow(dy, 2))))) {
                    map[y * COLLUMNS + x] = '%';
                }
            }
        }
        coef-=0.01f;
        std::cout << map;
    }

    return 0;
}