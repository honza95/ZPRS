//libraries
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//time constants (100ms - defines sleep)
#define PREPARATION 15
#define PREWASH 15
#define WASH 30
#define SECOND_WASH 25
#define DRYING 20

//data structures of state
typedef enum {
    STATE_STOP,
    STATE_PREPARATION,
    STATE_PREWASH,
    STATE_WASH,
    STATE_SECOND_WASH,
    STATE_DRYING,
} STATE;

//Global variable
int Timer = 0;  //reset of time
STATE State; //current state
char Program; // it depends on which program is used (Eco, Rinse...)

//prototypes of functions
void Stop ();
void Preparation ();
void Prewash ();
void Wash ();
void SecondWash ();
void Drying ();

//main function of programme
void main () {
    State = STATE_STOP;  //Only when you start the program, sets the state to STOP
    while (1){
        system("cls");
        switch (State){ //selects appropriate case
        case STATE_STOP:
            Stop();
            break;
        case STATE_PREPARATION:
            Preparation();
            break;
        case STATE_PREWASH:
            Prewash();
            break;
        case STATE_WASH:
            Wash();
            break;
        case STATE_SECOND_WASH:
            SecondWash();
            break;
        case STATE_DRYING:
            Drying();
            break;
        default:
            printf("%d \n", State);
            break;
        }
       Sleep(300); // for every cycle waits 200 ms
    }
}

// Definition if functions
void Stop(){
    SetConsoleOutputCP (1252);
    printf("Stopped \n");
    printf("Choose program: \n");
	printf("[1] Rince \n");
	printf("[2] Wash ECO \n");
	printf("[3] Wash 70°C \n");
	printf("[4] Wash 65°C \n");
	fflush(stdin); //ensures loading of character properly
	scanf("%c", &Program);
	if (Program <'1' || Program >'4' ) {
        State = STATE_STOP; // if is lower than 1 or upper than 4, goes back to STOP
	}
	else {
        State = STATE_PREPARATION;
        Timer = 0;
	}
}
void Preparation() {
    if (Timer < PREPARATION){
        printf("Preparation: %d", (PREPARATION - Timer));
        Timer++;
    }
    else {
        if (Program == 4){
            State = STATE_PREWASH;
        }
        else {
            State = STATE_WASH;
        }
        Timer = 0;
    }
}
void Prewash() {
    if (Timer < PREWASH){
        printf("Prewash: %d", (PREWASH - Timer));
        Timer++;
    }
    else {
        State = STATE_WASH;
        Timer = 0;
    }
}
void Wash() {
    if (Timer < WASH){
        printf("Wash: %d", (WASH - Timer));
        Timer++;
    }
    else {
        if (Program == 3 || Program == 4 ){
            State = STATE_SECOND_WASH;
        }
        else {
            if (Program == 2){
                State = STATE_DRYING;
            }
            else {
                State = STATE_STOP;
            }
        }
        Timer = 0;
    }

}
void SecondWash() {
    if (Timer < SECOND_WASH) {
        printf("Second wash: %d", (SECOND_WASH - Timer));
        Timer++;
    }
    else{
        State = STATE_DRYING;
        Timer = 0;
    }
}
void Drying() {
    if  (Timer < DRYING) {
        printf ("Drying: %d", (DRYING - Timer));
        Timer++;
    }
    else {
        State = STATE_STOP;
        Timer = 0;
    }
}




