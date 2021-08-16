#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

void scan(){
	fstream ipD,portD,foundD;
	string ipDS,portDS,foundDS;
	int list;
	bool timebool=false;
	char command[255];
	printf("scan ip\n");
	sprintf(command,"ip addr show | grep \"inet\\s\" | awk \'{print $2}\' > ip.txt");
	system(command);
	ipD.open("ip.txt");
	ipD >> ipDS;
	ipD >> ipDS;
	sprintf(command,"nmap -sn %s | grep for | awk \'{print $5}\' > list.txt",ipDS.c_str());
	system(command);
	ipD.close();
	printf("search port 5555\n");
	ipD.open("list.txt");
	while(!timebool){
		ipD >> ipDS;
		list++;
		if(ipD.eof()) timebool=true;
	}
	ipD.close();
	ipD.open("list.txt");
	system("touch found.txt search.txt");
	foundD.open("found.txt");
	ipD >> ipDS;
	for(int i=0;i<list;i++){
		ipD >> ipDS;
		//printf("scan %s\n",ipDS.c_str());
		sprintf(command,"nmap -Rn %s | grep freeciv | awk -F \'/\' \'{print $1}\' > search.txt ",ipDS.c_str());
		system(command);
		portD.open("search.txt");
		portD >> portDS;
		//printf("%s\n",portDS.c_str());
		portD.close();
		if(portDS == "5555"){
			printf("\e[32mfound\e[0m\n");
			foundD << ipDS << "\n";
		}
		else{
			printf("\e[34mnot found\e[0m\n");
		}
		portDS="";
	}
	portD.close();
	ipD.close();
	foundD.close();
	//printf("\e[5mip open port in 5555\e[0m\n");
	system("cat found.txt");
	system("rm search.txt ip.txt list.txt");
	//return 0;
}
