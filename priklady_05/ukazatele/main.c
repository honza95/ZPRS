#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int set(int vstup, int *out)
{
int ret_val;
if (isalpha(vstup)) {
    ret_val = 1;
    if (isupper(vstup)) {
        *out = tolower(vstup);
    } else {
        *out = toupper(vstup);
        }
} else {
    *out = vstup;
    ret_val = 0;
    }
return ret_val;
}

int kvad(float druha, float prvni, float nulta, float *result1, float *result2)
{
    int ret_val;
    double D;

    D = prvni * prvni - 4 * druha * nulta;

    if (D>0) {
        *result1=(-prvni + sqrt (D))/(2 * druha);
        *result2=(-prvni - sqrt (D))/(2 * druha);
        ret_val=1;
    }   else {
        ret_val=0;
    }
}


void main(void)
{
    int result;
    int output;
    float x1;
    float x2;

//exercise 1
  printf("\nexercise 1\n");
  printf("sizeof(char) is %dB\n", sizeof(char));
  printf("sizeof(short) is %dB\n", sizeof(short));
  printf("sizeof(int) is %dB\n", sizeof(int));
  printf("sizeof(long) is %dB\n", sizeof(long));
  printf("sizeof(long long) is %dB\n", sizeof(long long));
  printf("sizeof(float) is %dB\n", sizeof(float));
  printf("sizeof(double) is %dB\n", sizeof(double));
  printf("sizeof(long double) is %dB\n", sizeof(long double));

  //exercise 2
  printf("\nexercise 2\n");
  result = set('1', &output);
  printf("navratova hodnota: %d, znak: %c\n", result, output);

  result = set('€', &output);
  printf("navratova hodnota: %d, znak: %c\n", result, output);

  result = set('a', &output);
  printf("navratova hodnota: %d, znak: %c\n", result, output);

  //exercise 3
  printf("\nexercise 3\n");
  result = kvad(1, 2, 1, &x1, &x2);
  if (result) {
    printf("Rovnice ma nasledujici koreny: x1=%f x2=%f\n", x1, x2);
  } else {
    printf("Rovnice nema realne koreny.\n");
}

}
