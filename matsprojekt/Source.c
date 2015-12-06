//knihovny
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//casove konstanty (ve 100ms-definuje sleep())
#define PRIPRAVA 20
#define PREDMYTI 20
#define MYTI 30
#define DRUHE_MYTI 20
#define SUSENI 25

//datova struktura stavu
typedef enum {
	SEM_STATES_PRIPRAVA,
	SEM_STATES_PREDMYTI,
	SEM_STATES_MYTI,
	SEM_STATES_DRUHE_MYTI,
	SEM_STATES_SUSENI,
	SEM_STATES_STOP
} SEM_STATES;

//Globalni promenne
int Timer = 0; //vynulovany casovac
SEM_STATES SemStates; //aktualni stav (v jakem stavu se nachazi-Predmyti, myti, druhe myti..)
char program; //aktualni program (jaky vykonava program-ECO, Oplach..)

//prototypy funkci (s temi funkcemi se bude dale pracovat)
void StopState();
void PripravaState();
void PredmytiState();
void MytiState();
void DruheMytiState();
void SuseniState();

//hlavni funkce programu
void main()
{
	SemStates = SEM_STATES_STOP; //Pouze pri spusteni programu nastavi stav na STOP
	while (1){
		system("cls");
		switch (SemStates) //vybira prislusny case(blok)
		{
		case SEM_STATES_STOP:
			StopState();
			break;
		case SEM_STATES_PRIPRAVA:
			PripravaState();
			break;
		case SEM_STATES_PREDMYTI:
			PredmytiState();
			break;
		case SEM_STATES_MYTI:
			MytiState();
			break;
		case SEM_STATES_DRUHE_MYTI:
			DruheMytiState();
			break;
		case SEM_STATES_SUSENI:
			SuseniState();
			break;
		default:
			break;
		}
		Sleep(100);//v kazdem cyklu pocka 100ms
	}
}
// ---DEFINICE FUNKCI---
void StopState(){
	printf("Zastaveno\n");
	printf("Zvolte program:\n");
	printf("[1] Oplach\n");
	printf("[2] Myti ECO\n");
	printf("[3] Myti 65%c \n", 248);
	printf("[4] Myti 70%c \n", 248);
	fflush(stdin); //zajisti spravne nacitani znaku
	scanf_s("%c", &program); //nacte znank z klavesnice a ulozi na adresu promenne programu
	if (program < '1' || program > '4'){
		SemStates = SEM_STATES_STOP; //pokud je mensi nez 1 nebo vetsi nez 4 tak jde zpet na STOP
	}
	else
		SemStates = SEM_STATES_PRIPRAVA; //jinak to jde na pripravu
	Timer = 0; //vynuluje casovac
}

void PripravaState(){
	if (Timer < PRIPRAVA){
		printf("Priprava: %f", (PRIPRAVA - Timer) / 10.0);
		Timer++;
	}
	else{
		if (program == '1' || program == '4'){
			SemStates = SEM_STATES_MYTI;
		}
		else{
			SemStates = SEM_STATES_PREDMYTI;
		}
		Timer = 0;
	}
}

void PredmytiState(){
	if (Timer < PREDMYTI){
		printf("Predmyti: %f", (PREDMYTI - Timer) / 10.0);
		Timer++;
	}
	else{
		SemStates = SEM_STATES_MYTI;
		Timer = 0;
	}
}

void MytiState(){
	if (Timer < MYTI){
		printf("Myti: %f", (MYTI - Timer) / 10.0);
		Timer++;
	}
	else{
		if (program == '2'){
			SemStates = SEM_STATES_SUSENI;
		}
		else if (program == '1'){
			SemStates = SEM_STATES_STOP;
		}
		else{
			SemStates = SEM_STATES_DRUHE_MYTI;
		}
		Timer = 0;
	}
}

void DruheMytiState(){
	if (Timer < DRUHE_MYTI){
		printf("Druhe myti: %f", (DRUHE_MYTI - Timer) / 10.0);
		Timer++;
	}
	else{
		SemStates = SEM_STATES_SUSENI;
		Timer = 0;
	}
}

void SuseniState(){
	if (Timer < SUSENI){
		printf("Suseni: %f", (SUSENI - Timer) / 10.0);
		Timer++;
	}
	else{
		SemStates = SEM_STATES_STOP;
		Timer = 0;
	}
}