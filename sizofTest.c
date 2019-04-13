#include <stdio.h>

void main(){

char variable[3];

printf("sizeof(variable) = %u\n",sizeof(variable));

variable[0]=' ';
printf("sizeof(variable) = %u\n",sizeof(variable));

variable[1]=' ';
printf("sizeof(variable) = %u\n",sizeof(variable));

}
