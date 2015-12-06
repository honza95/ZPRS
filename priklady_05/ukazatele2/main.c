#include <stdio.h>
#include <ctype.h>
#include <math.h>

int set(int in, int *out)
{
    int ret_val;
if (isalpha(in)) {
ret_val = 1;
if (isupper(in)) {
*out = tolower(in);
} else {
*out = toupper(in);
}
} else {
ret_val = 0;
}
return ret_val;
}
int quad(double a, double b, double c, double *res1, double *res2)
{
int ret_val;
double disc;
disc = b * b - 4 * a * c;
if (disc > 0) {
*res1 = (-b + sqrt(disc)) / (2 * a);
*res2 = (-b - sqrt(disc)) / (2 * a);
ret_val = 1;
} else {
ret_val = 0;
}
return ret_val;//knihovny
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
}
void main(void)
{
int result, output;
double x1, x2;
int (*fce_ptr)(double, double, double, double *, double *);
//exercise 1
printf("\nexercise 1\n");
printf("sizeof(char) is %d\n", sizeof(char));
printf("sizeof(short) is %d\n", sizeof(short));
printf("sizeof(int) is %d\n", sizeof(int));
printf("sizeof(long) is %d\n", sizeof(long));
printf("sizeof(long long) is %d\n", sizeof(long long));
printf("sizeof(float) is %d\n", sizeof(float));
printf("sizeof(double) is %d\n", sizeof(double));
printf("sizeof(long double) is %d\n", sizeof(long double));
//exercise 2
printf("\nexercise 2\n");
result = set(’1’, &output);
printf("navratova hodnota: %d, znak: %c\n", result, output);
result = set(’A’, &output);
printf("navratova hodnota: %d, znak: %c\n", result, output);
result = set(’a’, &output);
printf("navratova hodnota: %d, znak: %c\n", result, output);
//exercise 3
printf("\nexercise 3\n");
result = quad(3.1, 15.6, 1.8, &x1, &x2);
if (result) {
printf("Rovnice ma nasledujici koreny: %f %f\n", x1, x2);
} else {
printf("Rovnice nema realne koreny.\n");
}
//exercise 4
printf("\nexercise 4\n");
fce_ptr = &quad;
result = (*fce_ptr)(2.2, 0.1, 8.6, &x1, &x2);
if (result) {
printf("Rovnice ma nasledujici koreny: %f %f\n", x1, x2);
} else {
printf("Rovnice nema realne koreny.\n");
}
}
