// Flappy Bird c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <list>

using namespace std;

#define arriba 72
#define izquierda 75
#define derecha 77
#define abajo 80
#define ENTER 13

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void eliminarCosito() {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100; //tamaño del cursor
    cci.bVisible = FALSE; //hace lo que dice su nombre
    SetConsoleCursorInfo(hCon, &cci); //hay que usar un & antes del parametro del cursor
}

void pintar_bordes() {
    for (int i = 1; i < 120; i++) {
        gotoxy(i, 1); printf("%c", 205);
        gotoxy(i, 30); printf("%c", 205);
    };
    for (int i = 1; i < 30; i++) {
        gotoxy(1, i); printf("%c", 186);
        gotoxy(119, i); printf("%c", 186);
    };
    gotoxy(1, 1); printf("%c", 201);
    gotoxy(1, 30); printf("%c", 200);
    gotoxy(119, 1); printf("%c", 187);
    gotoxy(119, 30); printf("%c", 188);
};

class pajaro {
    int x, y;
public:
    pajaro(int X_, int Y_) :x(X_), y(Y_) {};
    int ypp() { return y; }
    int xpp() { return x; }
    void dibujar();
    void borrar();
    void subir();
    void bajar();

};
void pajaro::dibujar() {
    gotoxy(x, y);     cout << "    __";
    gotoxy(x, y + 1); cout << "___( o)>";
    gotoxy(x, y + 2); cout << "  <_. )";
    gotoxy(x, y + 2); printf("%c",92);
    gotoxy(x, y + 3); cout << " `---' ";
}
void pajaro::borrar() {
    gotoxy(x, y);     cout << "      ";
    gotoxy(x, y + 1); cout << "        ";
    gotoxy(x, y + 2); cout << "       ";
    gotoxy(x, y + 3); cout << "       ";
}
void pajaro::subir() {
    if (_kbhit()) {
            char tecla = _getch();
for (int i = 0; i < 5; i++)
    {
            borrar();
            if ((tecla == 115 || tecla == arriba)&& y>0 ){ y--; };
            dibujar();
    }
        };
    
}
void pajaro::bajar() {
    if (y<26)
    {
        borrar();
        y++;
        dibujar();
    }
    
}
class tubo {
    int x, altura, espacioTubos;
public:
    tubo(int X_, int _altura,int _espacioTubos) :x(X_), altura(_altura),espacioTubos(_espacioTubos) {};
    int ypp() { return altura; }
    int xpp() { return x; }
    void dibujar();
    void borrar();
    void mover();
    bool chocar(class pajaro pajarito);
};
void tubo::dibujar() {
    SetColor(2);
    gotoxy(x, altura); printf("%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178);
    for (int w = 30; w > altura; w--) {
        //gotoxy(x,w); cout << "|****|";
        for (int i = x; i <= x + 5; i++)
        {
            gotoxy(i, w); printf("%c", 178);
        }
    }
    gotoxy(x, altura - espacioTubos);printf( "%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178);
    for (int w = 0; w < altura-espacioTubos; w++) {
        //gotoxy(x, w); cout << "|****|";
        for (int i = x; i <= x + 5; i++)
        {
            gotoxy(i, w); printf("%c", 178);
        }
    }
    SetColor(15);
}
void tubo::borrar() {
    gotoxy(x, altura);     cout << "      ";
    for (int w = 30; w > altura; w--) {
        gotoxy(x, w); cout << "      ";
    }
    gotoxy(x, altura - espacioTubos);     cout << "      ";
    for (int w = 0; w < altura - espacioTubos; w++) {
        gotoxy(x, w); cout << "      ";
    }
}
void tubo::mover() {
    
    borrar();
    x--;
    dibujar();
    
}

bool tubo::chocar(class pajaro pajarito) {
    if ((pajarito.ypp() <= altura - espacioTubos || pajarito.ypp() >= altura-4) && pajarito.xpp()>x-8 && pajarito.xpp() < x+6) {
        return true;
    }
    return false;
}

int main()
{
    eliminarCosito();
    int x=0, y=0;
    int espacioTubos = 10;
    bool juegoTerminado = false;
    pajaro pajarito(30,12);
    pajarito.dibujar();
    int xprimerostubos = 30;
    list<tubo*>tubitos;
    list<tubo*>::iterator itTubos;
    for (int j = 0; j < 4; j++) {
        tubitos.push_back(new tubo(xprimerostubos, 25,20));
        xprimerostubos += 30;
    }
    int contador = 0;
    while (!juegoTerminado)
    {
        contador++;
        for (itTubos=tubitos.begin(); itTubos != tubitos.end(); itTubos++)
        {
            (*itTubos)->mover();
            if ((*itTubos)->chocar(pajarito))
            {
                system("cls");
                pintar_bordes();
                gotoxy(15, 14); cout << "Perdiste";
                gotoxy(15, 16); cout << "Gracias por jugar";
                gotoxy(2, 28); system("pause");
                juegoTerminado = true;
                system("cls");
            }
            Sleep(30);
        }
        for (itTubos = tubitos.begin(); itTubos != tubitos.end(); itTubos++)
        {
            if ((*itTubos)->xpp() ==0) {
                (*itTubos)->borrar();
                delete(*itTubos);
                itTubos = tubitos.erase(itTubos);
                tubitos.push_back(new tubo(120, rand() % 20 + 15,15));
            }
        }
        if (contador==1)
        {
            contador = 0;
            pajarito.bajar();

        }
        pajarito.subir();
    }


    return 0;
}
