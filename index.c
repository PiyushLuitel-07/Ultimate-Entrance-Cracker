#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <windows.h>

void rank();
void help();
void login();
void developer();
void start();
void coordn(int x, int y);
void delaying();
int main();


COORD c = {0, 0};
pthread_t thread;


struct question{
    char question[300];
    char a[30], b[30], c[30], d[30];
    char correct;
};
typedef struct question que;

struct student{
    char name[25];
    int marks;
};
typedef struct student std;

void delaying(char texty[45]) {
    for(int vale = 0; vale < strlen(texty); vale++){
        printf("%c", texty[vale]);
        Sleep(5);
    }
}

void coordn(int x, int y){
	c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


#include "countdowntimer.c"
#include "start.c"
#include "developer.c"
#include "rank.c"
#include "login.c"
#include "help.c"

int main(){
    system("cls");
    printf("\n\n");
    char select;
    char texty[45] = " ";
    b = 'a';
    //// home page display
    coordn(42, 3);
    delaying("Ultimate Entrance Cracker");
    for(int vale = 0; vale < strlen(texty); vale++){
        printf("%c", texty[vale]);
        Sleep(5);
    }
    coordn(15, 8);
    printf(" _____________________________________________________________________________\n");
    coordn(15, 25);
    printf("______________________________________________________________________________\n");

    time_t currenttime;
    char *currenttimeinstring;
    currenttime = time(NULL);
    currenttimeinstring = ctime(&currenttime);
    coordn(69, 9);
    printf("%s", currenttimeinstring);

    coordn(25, 15);
    delaying("--> Press S to start.");

    coordn(25, 16);
    delaying("--> Press R to see top ranks.");

    coordn(25, 17);
    delaying("--> Press H for help.");

    coordn(25, 18);
    delaying("--> Press D for developer options.");

    coordn(25, 19);
    delaying("--> Press Q to Quit.");
    coordn(35, 20);
    ///////////////User interaction
    top:
    select = getche();

    switch (select){

    case 's':
        start();
        break;
    case 'r':
        rank();
        break;
    case 'h':
        help();
        break;
    case 'd':
        login();
        break;
    case 'q':
        exit(1);
        break;
    default:
        printf("Sorry! invalid input \n please select again: ");
        goto top;
        break;
    }

    return 0;
}