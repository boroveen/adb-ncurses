#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ncurses.h>
using namespace std;
int gg1=false,refiles=false;;
fstream filesD;
string filesDS,filesDS1,filesDS2;
char filesDC[90],directory[90]=" ",command[200];
char filesDC1[90],filesDC2[90];
int y,x,filesI=1,filesI1=0;
bool Getch=false;

void filesV(){
	sprintf(directory,"%s/%s",directory,filesDS.c_str());
	sprintf(command,"adb shell ls %s > files.txt",directory);
	system(command);
	filesD.open("files.txt");
	filesI1=0;
	bool timebool=false;
	while(!timebool){
		filesD >> filesDS;
		filesI1++;
		if(filesD.eof()) timebool=true;
	}
	filesI1--;
	filesD.close();
	refiles=true;
}

void logic(){
	if(!refiles) filesV();
	filesD.open("files.txt");
	for(int i=0;i<filesI;i++){
		filesD >> filesDS;
		//if(i==filesI-1) filesD >> filesDS1;
		//if(i==filesI-2) filesD >> filesDS2;
	}
	filesD.close();
	filesD.open("files.txt");
	for(int i=0;i<filesI-1;i++){
		filesD >> filesDS1;
	}
	filesD.close();
	filesD.open("files.txt");
	for(int i=0;i<filesI+1;i++){
		filesD >> filesDS2;
	}
	sprintf(filesDC1,"%s",filesDS1.c_str());
	sprintf(filesDC2,"%s",filesDS2.c_str());
	sprintf(filesDC,"%s",filesDS.c_str());
	filesD.close();
}

void inpurt(){
	if(!Getch) halfdelay(1);
	switch(getch()){
		case 'q': gg1=true; break;
		case 'a':
		case 260:
		if(filesI==1) filesI=filesI1; 
		else filesI--;
		break;
		case 'd':
		case 261:
		if(filesI==filesI1) filesI=1;
		else filesI++;
		break;
		case 410: getmaxyx(stdscr,y,x); break;
		case 10:
		filesI=1;
		mvprintw(y/2-2,x/2-3,"loading");
		refiles=false;
		break;
		case 27:
		filesI=1;
		sprintf(directory,"");
		filesDS="";
		refiles=false;
		break;
		case 32:
		gg1=true;
		sprintf(command,"echo %s > directory.txt",directory);
		system(command);
		break;
	}
	if(!Getch){
		raw();
		Getch=true;
	}
}

void draw(){
	clear();
	attron(COLOR_PAIR(2));
	mvprintw(y/2-6,x/2-20,"esc: refresh  space: copy  enter: next directory");
	mvprintw(y/2-2,x/2-10,"number file:%d files all:%d",filesI,filesI1);
	mvprintw(y/2-3,(x-strlen(directory))/2,"%s",directory);
	for(int i=0;i<x;i++){
		mvprintw(y/2-4,i,"#");
		mvprintw(y/2+4,i,"#");
	}
	int x1=x/2/2;
	if(filesI>1) mvprintw(y/2,(x-strlen(filesDC1))/2/2,"%s",filesDC1);
	if(filesI<filesI1) mvprintw(y/2,(x-strlen(filesDC2))/2+x1,"%s",filesDC2);
	attron(COLOR_PAIR(1));
	if(filesDC!=directory) mvprintw(y/2,(x-strlen(filesDC))/2,"%s",filesDC);
}

void filesmanager(){
	gg1=false;
	initscr();
	keypad(stdscr,true);
	noecho();
	curs_set(0);
	getmaxyx(stdscr,y,x);
	start_color();
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	mvprintw(y/2,x/2-6,"loading");
	while(!gg1){
		inpurt();
		logic();
		draw();
	}
	//system("rm directory.txt");
	system("rm files.txt");
	//delete [] filesDC,directory,command,filesDC1,filesDC2;
	sprintf(filesDC,filesDC1,filesDC2,directory,command,"");
	filesDS="",filesDS1="",filesDS2="";
	endwin();
}

/*
char filesDC[90],directory[90]=" ",command[200];
char filesDC1[90],filesDC2[90];
string filesDS,filesDS1,filesDS2;
*/
