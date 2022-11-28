#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
//#include "listaC.h"

bool load(char* direction);
void players(char* screen);
char* pegar(char* direction, char* palabra);
int lenP(char* direction);
void comienzo(char* screen);

int main(){
	//listaC *n = listaC_init ();
	char ini[3];
	int flag = 0;
	char* screen = "==================================================\n|\t\t\t\t\t\t |\n|\t\tJuego de Trivia\t\t\t |\n|\t\t\t\t\t\t |\n==================================================\n";
	
	do {
		puts(screen);
		puts("1. Comenzar\n2. Salir\nElija una opcion: ");
		fgets(ini, 3, stdin);
		fflush(stdin);
		if (atoi(ini) == 1){
			flag++;
		}
		if (atoi(ini) == 2){
			return 1;
		} else {
			system("clear");
		}
	} while(flag != 1);
	comienzo(screen);			
}

void comienzo(char* screen){
	char direction[100];
	int flag = 0;
	int jugadores;
	char* iniS = "";
	do {
		puts(screen);
		puts("Ingrese la direccion del directorio: ");		
		fflush(stdin);
		scanf("%s", direction);
		fflush(stdin);
		if (load(direction)){
			flag++;
		} else {
			system("clear");
		}
	} while (flag != 1);
	players(screen);
}

void players(char* screen){
	char cantPlayers[3];
	int flag = 0;
	do {
		puts(screen);
		puts("Ingrese la cantidad de jugadores (1-6): ");
		fgets(cantPlayers, 3, stdin);
		fflush(stdin);
		if (atoi(cantPlayers) <= 6 && atoi(cantPlayers) > 0){
			flag++;
		} else {
			system("clear");
		}
	} while (flag != 1);
	//return cantPlayers[0]-'0';
}

bool load(char* direction){
	char* palabra;
	DIR *dir;
	struct dirent *ent;
	if (dir = opendir(direction)){
		while (ent = readdir(dir)){
			//palabra = pegar(ent->d_name, palabra);
			//insertCategory(n, palabra);
			puts(ent->d_name);	
		}
		closedir(dir);
		return true;
	}
	return false;
}

char* pegar(char* direction, char* palabra){
	int large = lenP(direction);
	int cont = 0;
	while (cont != large-1){
		palabra[cont] = direction[cont];
		cont++;
	}
	return palabra;
}

int lenP(char* direction){
	int large = 0;
	while (direction[large] != '.'){
		large++;
	}
	return large;
}

