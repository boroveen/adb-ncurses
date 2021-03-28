#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ios>
using namespace std;
int row,cal,y=1;
bool gg=false;

void DevicesAdb(){
mvprintw(row/2,cal/2-10,"device not connect");
system("adb wait-for-device");
clear();
}

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
attron(COLOR_PAIR(1));
mvprintw(row,0,"beta");
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

void installApkAdb(){
endwin();
char one[90],two[256];
printf("apk directory: ");
cin >> one;
sprintf(two,"adb install %s",one);
initscr();
noecho();
raw();
curs_set(0);
start_color();
}

void StorageAdb(){
y=1;
bool gg1=false;
while(!gg1){
DevicesAdb();
if(y==1) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("PC -> Phone\n");
if(y==2) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("Phone -> PC\n");
if(y==3) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("back");

switch(getch()){
case 259:
case 119:
if(y<1) y=3;
else y--;
break;
case 258:
case 115:
if(y>3) y=1;
else y++;
break;
case 10:
if(y==1){
clear();
yesecho();
char one[90],two[90],tree[256];
printw("PC directory: ");
cin >> one;
printw("Phone directory: ");
getstr(two);
sprintf(tree,"adb push %s %s",one,two);
system(tree);
noecho();
}
if(y==2){
clear();
yesecho();
char one[90],two[90],tree[256];
printw("PC directory: ");
getstr(one);
printf("Phone directory: ");
getstr(two);
sprintf(tree,"adb pull %s %s",two,one);
system(tree);
noecho();
}
if(y==3) gg1=true;
break;
}
}
y=1;
}

void BFAdb(){
clear();
attron(COLOR_PAIR(2));
mvprintw(0,cal/2-10,"~/adb-ncurses/Linux");
mvprintw(1,cal/2,"^");
for(int i=0;i<row-8;i++) mvprintw(2+i,cal/2,"|");
mvprintw(row-6,cal/2-5,"update.zip");
mvprintw(row-5,cal/2-5,"recovery.img");
mvprintw(row-4,cal/2-5,"boot.img");
mvprintw(row-3,cal/2-5,"system.img");
mvprintw(row-2,cal/2-5,"userdata.img");
mvprintw(row-1,cal/2-5,"radio.img");
getch();
}

void FlashAdb(){
BFAdb();
system("adb reboot bootloader");
bool gg1=false;
y=1;
while(!gg1){
clear();
if(y==1) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("recovery.img\n");
if(y==2) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("boot.img\n");
if(y==3) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("system.img\n");
if(y==4) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("userdata.img\n");
if(y==5) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("radio.img\n");
if(y==6) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("update.zip\n");
if(y==7) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("back\n");

attron(COLOR_PAIR(1));
mvprintw(row-1,0,"beta");
switch(getch()){
case 259:
case 119:
if(y<1) y=7;
else y--;
break;
case 258:
case 115:
if(y>7) y=1;
else y++;
break;
case 10:
if(y==1) system("fastboot flash recovery recovery.img");
if(y==2) system("fastboot flash boot boot.img");
if(y==3) system("fastboot flash system system.img");
if(y==4) system("fastboot flash userdata userdata.img");
if(y==5) system("fastboot flash radio radio.img");
if(y==6) system("fastboot update update.zip");
if(y==7){
system("fastboot reboot");
gg1=true;
}
break;
}
}
y=1;
}

void BootAdb(){
BFAdb();
system("adb reboot bootloader");
bool gg1=false;
y=1;
while(!gg1){
clear();
if(y==1) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("recovery.img\n");
if(y==2) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("boot.img\n");
if(y==3) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("back");
attron(COLOR_PAIR(1));
mvprintw(row-1,0,"beta");
switch(getch()){
case 259:
case 119:
if(y<1) y=3;
else y--;
break;
case 258:
case 115:
if(y>3) y=1;
else y++;
break;
case 10:
if(y==1) system("fastboot boot recovery.img");
if(y==2) system("fastboot boot boot.img");
if(y==3){
gg1=true;
system("fastboot reboot");
}
break;
}
}
y=1;
}

void ConnectAdb(){
clear();
bool gg1=false;
y=1;

while(!gg1){
clear();
if(y==1) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("Connect ip\n");
if(y==2) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("Shell\n");
if(y==3) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("back\n");

switch(getch()){
case 259:
case 119:
if(y<1) y=3;
else y--;
break;
case 258:
case 115:
if(y>3) y=1;
else y++;
break;
case 10:
if(y==1){
endwin();
system("adb shell ip addr show | grep inet");
char one[30],two[256];
printf("ip addres: ");
cin >> one;
sprintf(two,"adb connect %s",one);
system("adb tcpip 5555");
system(two);
initscr();
raw();
curs_set(0);
noecho();
start_color();
}
if(y==2){
endwin();
system("adb shell");
initscr();
raw();
curs_set(0);
noecho();
start_color();
}
if(y==3) gg1=true;
break;
}
}
}

int main(){
printf("start server adb\n");
system("adb start-server");
//system("adb wait-for-device");
initscr();
noecho();
curs_set(0);
keypad(stdscr,true);
getmaxyx(stdscr,row,cal);
if(row>7 && cal>55){
mvprintw(row/2-4,cal/2-12,"_______ ______  ______");
mvprintw(row/2-3,cal/2-12,"|_____| |     \\ |_____]");
mvprintw(row/2-2,cal/2-12,"|     | |_____/ |_____]");

mvprintw(row/2,cal/2-3,"___");

mvprintw(row/2+2,cal/2-27,"__   _ _______ _     _  ______ _______ _______ _______");
mvprintw(row/2+3,cal/2-27,"| \\  | |       |     | |_____/ |______ |______ |______");
mvprintw(row/2+4,cal/2-27,"|  \\_| |_____  |_____| |    \\_ ______| |______ ______|");
getch();
}
else{
mvprintw(row/2,cal/2-1,"ADB");
mvprintw(row/2+1,cal/2-15,"click on any button to continue");
mvprintw(row-1,0,"beta");
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
}
raw();
clear();
start_color();
init_pair(1,COLOR_WHITE,COLOR_BLACK);
init_pair(2,COLOR_GREEN,COLOR_BLACK);
while(!gg){
DevicesAdb();

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
printw("boot\n");
if(y==5) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("copy\n");
if(y==6) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("shell\n");
if(y==7) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("install soft\n");
if(y==8) attron(COLOR_PAIR(2));
else attron(COLOR_PAIR(1));
printw("exit");
attron(COLOR_PAIR(1));
mvprintw(row-1,0,"beta");

switch(getch()){
case 259:
case 119:
if(y<1) y=7;
else y--;
break;
case 258:
case 115:
if(y>7) y=1;
else y++;
break;
case 10:
if(y==1) system("adb shell reboot -p");
if(y==2) RebootAdb();
if(y==3) FlashAdb();
if(y==4) BootAdb();
if(y==5) StorageAdb();
if(y==6) ConnectAdb();
if(y==7) installApkAdb();
if(y==8) gg=true;
break;
}
}
endwin();
printf("kill server adb\n");
system("adb kill-server");
return 0;
}

