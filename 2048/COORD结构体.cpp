#include <windows.h>
#include <stdio.h>
#include <conio.h>

void loopout(HANDLE hwnd,COORD coord)
{
    SetConsoleCursorPosition(hwnd, coord);
    printf("hello world");
}

int main()
{
    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;

    coord.X = 25;
    coord.Y = 25;

    SetConsoleCursorPosition(hwnd,coord);
    while (1)
    {
        switch(getch() )
        {
        case 13://按下回车键清屏
            system("cls");
            break;
        case 0xE0:
            switch (getch())
            {
                case 72://上
                    coord.Y--;
                    loopout(hwnd, coord);
                    break;

                case 80://下 
                    coord.Y++;
                    loopout(hwnd, coord);
                    break;
                case 75://左
                    coord.X--;
                    loopout(hwnd, coord);
                    break;
                case 77://右
                    coord.X++;
                    loopout(hwnd, coord);
                    break;
            }
        }
    }
    getchar();
    return 0;
}
