#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

char device[90];
int row,cal,tmp,tmp1,bf=0;
bool gg=false;

void setup(int i){
if(i==1) endwin();
else if(i==2){
initscr();
noecho();
raw();
keypad(stdscr,true);
curs_set(0);
start_color();
}
}

void Help(){
halfdelay(1);
for(int i=0;i<row/2/2;i++){
for(int g=0;g<cal/2;g++) mvprintw(row/2+i,cal/2/2+g,"#");
for(int g=0;g<cal/2-2;g++) mvprintw(row/2-1+i,cal/2/2+1+g," ");
for(int g=0;g<cal/2-2;g++) mvprintw(row/2+1-i,cal/2/2+1+g," ");
for(int g=0;g<cal/2;g++) mvprintw(row/2-i,cal/2/2+g,"#");
getch();
}
raw();
/*for(int i=0;i<row/2;i++){
mvprintw(row/2/2+i,cal/2/2," ");
for(int g=0;g<cal/2-2;g++) printw(" ");
}
for(int i=0;i<row/2;i++){
mvprintw(row/2/2+i,cal/2/2,"#");
mvprintw(row/2/2+i,cal/2+tmp+tmp,"#");
}
for(int i=0;i<cal/2;i++) mvprintw(row/2/2,cal/2/2+i,"#");
for(int i=0;i<cal/2;i++) mvprintw(row/2+tmp1+tmp1,cal/2/2+i,"#");*/
}

void wd(){
halfdelay(1);
mvprintw(row/2,cal/2-10,"wait device");
getch();
system("adb wait-for-device");
raw();
clear();
}

int main(){

//device connect
//system("adb wait-for-device");
system("adb devices");
printf("device: ");
cin >> device;

initscr();
noecho();
raw();
//halfdelay(1);
curs_set(0);
keypad(stdscr,true);
getmaxyx(stdscr,row,cal);
start_color();
init_pair(1,COLOR_GREEN,COLOR_BLACK);
init_pair(2,COLOR_WHITE,COLOR_BLACK);
init_pair(3,COLOR_RED,COLOR_BLACK);

int y[3];
y[0]=0,y[1]=0,y[3]=0;

//Help();

//programm
gg=false;
raw();
while(!gg){
//inpurt
clear();
getmaxyx(stdscr,row,cal);
tmp=cal/2/2/2,tmp1=row/2/2/2;

attron(COLOR_PAIR(2));
for(int i=0;i<row;i++) mvprintw(i,cal/2,"#");
mvprintw(0,0,"");
for(int i=0; i<cal;i++) printw("#");
attron(COLOR_PAIR(1));
//mvprintw(1,0,"y0:%d, y1:%d",y[0],y[1]);
mvprintw(1,(cal-strlen(device))/2-4,"device: %s\n",device);
attron(COLOR_PAIR(2));
for(int i=0;i<cal;i++) printw("#");

if(y[0]==0) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-4,cal/2/2/2,"Device");
if(y[0]==1) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-3,cal/2/2/2,"Shutdown\\reboot");
if(y[0]==2) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-2,cal/2/2/2,"Copy files");
if(y[0]==3) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-1,cal/2/2/2,"Install apk");
if(y[0]==4) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2,cal/2/2/2,"Connect ip");
if(y[0]==5) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+1,cal/2/2/2,"Shell");
if(y[0]==6) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+2,cal/2/2/2,"Flash\\Boot");
if(y[0]==7) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+3,cal/2/2/2,"Exit");

if(y[1]==1){
if(y[2]==0) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-3,cal/2+tmp,"Shutdown");
if(y[2]==1) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-2,cal/2+tmp,"Reboot");
if(y[2]==2) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-1,cal/2+tmp,"Reboot recovery");
if(y[2]==3) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2,cal/2+tmp,"Reboot bootloader");
if(y[2]==4) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+1,cal/2+tmp,"Fastboot reboot");
if(y[2]==5) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+2,cal/2+tmp,"Back");
}

if(y[1]==2){
if(y[2]==0) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-3,cal/2+tmp,"PC -> Device");
if(y[2]==1) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-2,cal/2+tmp,"Device -> PC");
if(y[2]==2) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-1,cal/2+tmp,"Back");
}

if(y[1]==6){
if(y[2]==0) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
if(bf==0) mvprintw(row/2-2,cal/2+tmp,"< Boot >");
else if(bf==1) mvprintw(row/2-4,cal/2+tmp,"< Flash >");
if(bf==0){
if(y[2]==1) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-1,cal/2+tmp,"Recovery");
if(y[2]==2) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2,cal/2+tmp,"Boot");
if(y[2]==3) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+1,cal/2+tmp,"Back");
}
else if(bf==1){
if(y[2]==1) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-3,cal/2+tmp,"Recovery");
if(y[2]==2) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-2,cal/2+tmp,"Boot");
if(y[2]==3) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2-1,cal/2+tmp,"System");
if(y[2]==4) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2,cal/2+tmp,"Userdada");
if(y[2]==5) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+1,cal/2+tmp,"Radio");
if(y[2]==6) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+2,cal/2+tmp,"Update.zip");
if(y[2]==7) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+3,cal/2+tmp,"Back");
}
}

//input
if(y[1]==0)//main
switch(getch()){
case KEY_F(1):
Help();
while(!gg){
attron(COLOR_PAIR(1));
mvprintw(row/2-2,cal/2-7,"w    -    up");
mvprintw(row/2-1,cal/2-7,"s    -    down");
mvprintw(row/2,cal/2-7,"a    -    back");
mvprintw(row/2+1,cal/2-7,"d\\enter - next");
switch(getch()){
case ERR: break;
default: gg=true; break;
}
}
gg=false;
break;
case 119://w
case 259:
if(y[0]<0) y[0]=7;
else y[0]--;
break;
case 115://s
case 258:
if(y[0]>7) y[0]=0;
else y[0]++;
break;
case 10:
case 100:
case 261:
if(y[0]==0){
setup(1);
//system("adb wait-for-device");
system("adb devices");
printf("device: ");
cin >> device;
setup(2);
}
if(y[0]==1) y[1]=1,y[2]=0;
if(y[0]==2) y[1]=2,y[2]=0;
if(y[0]==3){
char command[255],one[90];
echo();
attron(COLOR_PAIR(1));
mvprintw(row/2-1,cal/2+tmp,"Directory");
mvprintw(row/2,cal/2+tmp,"APK: ");
attron(COLOR_PAIR(2));
getstr(one);
sprintf(command,"adb -s %s install %s",device,one);
setup(1);
system(command);
setup(2);
}
if(y[0]==4){
setup(1);
char command[225],one[90];
sprintf(command,"adb -s %s shell ip addr show wlan0 | grep \"inet\\s\" | awk \'{print $2}\' | awk -F\'/\' \'{print $1}\'",device);
system(command);
printf("^\n");
printf("|\n");
printf("Ip: ");
cin >> one;
sprintf(command,"adb -s %s tcpip 5555",device);
system(command);
sprintf(command,"adb connect %s:5555",one);
system(command);
setup(2);
Help();
while(!gg){
attron(COLOR_PAIR(3));
mvprintw(row/2-2,cal/2-8,"Are change device?");
if(y[2]==0) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+1,cal/2-4,"no");
if(y[2]==1) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+1,cal/2+2,"ok");
switch(getch()){
case 10:
if(y[2]==0) gg=true;
if(y[2]==1){
setup(1);
system("adb devices");
printf("device: ");
cin >> device;
setup(2);
gg=true;
}
break;
case 97:
case 260:
if(y[2]==0) y[2]=1;
else y[2]=0;
break;
case 100:
case 261:
if(y[2]==0) y[2]=1;
else y[2]=0;
break;
}
}
gg=false;
}
if(y[0]==5){
setup(1);
char command[255];
sprintf(command,"adb -s %s shell",device);
system(command);
setup(2);
}
if(y[0]==6){
Help();
while(!gg){
attron(COLOR_PAIR(3));
mvprintw(row/2-2,cal/2-3,"WARNING");
mvprintw(row/2-1,cal/2-12,"device reboot in bootloader");
if(y[2]==0) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+1,cal/2-4,"no");
if(y[2]==1) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(row/2+1,cal/2+2,"ok");
switch(getch()){
case 10:
if(y[2]==0) gg=true;
if(y[2]==1){
y[1]=6,y[2]=0;;
char command[255];
setup(1);
sprintf(command,"adb -s %s reboot bootloader",device);
system(command);
setup(2);
gg=true;
}
break;
case 97:
case 260:
if(y[2]==0) y[2]=1;
else y[2]=0;
break;
case 100:
case 261:
if(y[2]==0) y[2]=1;
else y[2]=0;
break;
}
}
gg=false;
}
if(y[0]==7) gg=true;
break;
}

if(y[1]==1)
switch(getch()){
case KEY_F(1):
Help();
while(!gg){
attron(COLOR_PAIR(1));
mvprintw(row/2-2,cal/2-7,"w    -    up");
mvprintw(row/2-1,cal/2-7,"s    -    down");
mvprintw(row/2,cal/2-7,"a    -    back");
mvprintw(row/2+1,cal/2-7,"d\\enter - next");
switch(getch()){
case ERR: break;
default: gg=true; break;
}
}
gg=false;
break;
case 119://w
case 259:
if(y[2]<0) y[2]=5;
else y[2]--;
break;
case 115://s
case 258:
if(y[2]>5) y[2]=0;
else y[2]++;
break;
case 10:
if(y[2]==0){
char command[255];
sprintf(command,"adb -s %s shell reboot -p",device);
system(command);
}
if(y[2]==1){
char command[255];
sprintf(command,"adb -s %s reboot",device);
system(command);
}
if(y[2]==2){
char command[255];
sprintf(command,"adb -s %s reboot recovery",device);
system(command);
}
if(y[2]==3){
char command[255];
sprintf(command,"adb -s %s reboot bootloader",device);
system(command);
}
if(y[2]==4) system("fastboot reboot");
if(y[2]==5) y[1]=0;
break;
case 97:
case 260: y[1]=0; break;
}

if(y[1]==2)
switch(getch()){
case KEY_F(1):
Help();
while(!gg){
attron(COLOR_PAIR(1));
mvprintw(row/2-2,cal/2-7,"w    -    up");
mvprintw(row/2-1,cal/2-7,"s    -    down");
mvprintw(row/2,cal/2-7,"a    -    back");
mvprintw(row/2+1,cal/2-7,"d\\enter - next");
switch(getch()){
case ERR: break;
default: gg=true; break;
}
}
gg=false;
break;
case 97:
case 260: y[1]=0; break;
case 119://w
case 259:
if(y[2]<0) y[2]=3;
else y[2]--;
break;
case 115://s
case 258:
if(y[2]>3) y[2]=0;
else y[2]++;
break;
case 10:
if(y[2]==0){
char command[225],one[50],two[50];
echo();
mvprintw(row/2-1,cal/2+tmp,"Directory");
mvprintw(row/2,cal/2+tmp,"PC: ");
getstr(one);
mvprintw(row/2+1,cal/2+tmp,"Device: ");
getstr(two);
sprintf(command,"adb -s %s push %s %s",device,one,two);
setup(1);
system(command);
setup(2);
}
if(y[2]==1){
char command[225],one[50],two[50];
echo();
mvprintw(row/2-1,cal/2+tmp,"Directory");
mvprintw(row/2,cal/2+tmp,"Device: ");
getstr(one);
mvprintw(row/2+1,cal/2+tmp,"PC: ");
getstr(two);
sprintf(command,"adb -s %s pull %s %s",device,one,two);
setup(1);
system(command);
setup(2);
}
if(y[2]==2) y[1]=0;
break;
}

if(y[1]==6){
if(bf==0){
switch(getch()){
case KEY_F(1):
Help();
while(!gg){
attron(COLOR_PAIR(1));
mvprintw(row/2-2,cal/2-7,"w    -    up");
mvprintw(row/2-1,cal/2-7,"s    -    down");
mvprintw(row/2,cal/2-7,"a    -    back");
mvprintw(row/2+1,cal/2-7,"d\\enter - next");
switch(getch()){
case ERR: break;
default: gg=true; break;
}
}
gg=false;
break;
case 97:
case 260: y[1]=0; break;
case 119://w
case 259:
if(y[2]<0) y[2]=3;
else y[2]--;
break;
case 115://s
case 258:
if(y[2]>3) y[2]=0;
else y[2]++;
break;
case 10:
if(y[2]==0) bf=1,y[2]=0;
if(y[2]==1 || y[2]==2){
echo();
char command[255],one[90];
attron(COLOR_PAIR(2));
mvprintw(row/2+2,cal/2+tmp,"img: ");
getstr(one);
sprintf(command,"fastboot boot %s",one);
setup(1);
system(command);
setup(2);
}
if(y[2]==3) y[1]=0;
break;
}
}
else if(bf==1){
switch(getch()){
case KEY_F(1):
Help();
while(!gg){
attron(COLOR_PAIR(1));
mvprintw(row/2-2,cal/2-7,"w    -    up");
mvprintw(row/2-1,cal/2-7,"s    -    down");
mvprintw(row/2,cal/2-7,"a    -    back");
mvprintw(row/2+1,cal/2-7,"d\\enter - next");
switch(getch()){
case ERR: break;
default: gg=true; break;
}
}
gg=false;
break;
case 97:
case 260: y[1]=0; break;
case 119://w
case 259:
if(y[2]<0) y[2]=7;
else y[2]--;
break;
case 115://s
case 258:
if(y[2]>7) y[2]=0;
else y[2]++;
break;
case 10:
if(y[2]==0) bf=0,y[2]=0;
else if(y[2]==7){
y[1]=0;
system("fastboot reboot");
}
else{
echo();
char command[255],one[90];
attron(COLOR_PAIR(2));
mvprintw(row/2+4,cal/2+tmp,"img: ");
getstr(one);
if(y[2]==1) sprintf(command,"fastboot flash recovery %s",one);
if(y[2]==2) sprintf(command,"fastboot flash boot %s",one);
if(y[2]==3) sprintf(command,"fastboot flash system %s",one);
if(y[2]==4) sprintf(command,"fastboot flash userdata %s",one);
if(y[2]==5) sprintf(command,"fastboot flash radio %s",one);
if(y[2]==6) sprintf(command,"fastboot update %s",one);
setup(1);
system(command);
setup(2);
}
break;
}
}
}

}//while
endwin();
return 0;
}
/*main
#######################################
          device: number
#######################################
                 # Device -> PC
 device          # PC -> Device
 shutdown\reboot # Directory:
 copy files      # PC: ~/tmp/file.apk
 install apk     # Device: /sdcard
 connect ip      #
 shell           #
 flash\boot      #
 exit            #
                 #
#######################################
*/
