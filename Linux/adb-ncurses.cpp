#include <ncurses.h>
#include <stdlib.h>
#include <ios>
using namespace std;
int row,cal,y=1;
bool gg=false;

void RebootAdb(){
bool gg1=false;
y=1;
while(!gg1){
clear();
if(y==1) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("reboot\n");
if(y==2) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("reboot recovery\n");
if(y==3) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("reboot bootloader\n");
if(y==4) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("reboot bootloader normal\n");
if(y==5) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("back");
switch(getch()){
case 259:
case 119:
if(y<1) y=5;
else y--;
break;
case 258:
case 115:
if(y>5) y=1;
else y++;
break;
case 10:
if(y==1) system("adb reboot");
if(y==2) system("adb reboot recovery");
if(y==3) system("adb reboot bootloader");
if(y==4) system("fastboot reboot");
if(y==5) gg1=true;
break;
}
}
y=1;
}

void FlashAdb(){
mvprintw(row/2,cal/2-3,"not work");
getch();
}

void ShellAdb(){
clear();
endwin();
system("adb shell");
initscr();
noecho();
keypad(stdscr,true);
curs_set(0);
raw();
}

int main(){
printf("start server adb\n");
system("adb start-server");
initscr();
noecho();
curs_set(0);
keypad(stdscr,true);
getmaxyx(stdscr,row,cal);
mvprintw(row/2,cal/2-1,"ADB");
mvprintw(row/2+1,cal/2-15,"click on any button to continue");
getch();
halfdelay(1);
for(int i=0;i<3;i++){
mvprintw(row/2,cal/2-1+i,"%d",rand() % 2);
getch();
}
for(int i=0;i<31;i++){
mvprintw(row/2+1,cal/2-15+i,"%d",rand() % 2);
getch();
}
raw();
clear();
start_color();
init_pair(1,COLOR_WHITE,COLOR_BLACK);
init_pair(2,COLOR_GREEN,COLOR_BLACK);
while(!gg){
clear();

if(y==1) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("shutdown\n");
if(y==2) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("reboot\n");
if(y==3) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("flash\n");
if(y==4) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("shell\n");
if(y==5) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("exit");

switch(getch()){
case 259:
case 119:
if(y<1) y=5;
else y--;
break;
case 258:
case 115:
if(y>5) y=1;
else y++;
break;
case 10:
if(y==1) system("adb shell reboot -p");
if(y==2) RebootAdb();
if(y==3) FlashAdb();
if(y==4) ShellAdb();
if(y==5) gg=true;
break;
}
}
endwin();
printf("kill server adb\n");
system("adb kill-server");
return 0;
}
