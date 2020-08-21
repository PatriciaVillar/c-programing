#include <stdio.h>
#include <stdlib.h>

typedef struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
} retire_info;

int main (){
	   retire_info working;
	   working.months=489;
	   working.contribution=1000;
	   working.rate_of_return=0.00375;
	   retire_info retired;
	   retired.months=384;
	   retired.contribution=-4000;
	   retired.rate_of_return=0.0008333333333333334;   
	   //retire_info working, //info about working
	   //retire_info retired) //info about being retired
int  startAge = 327;
double initial = 21345;
int Age = startAge;
double savings = initial;
 for (int i=0;i < working.months ; i++){
   //print Age  27 month  3 you have $21345.00
   printf("Age %3d month %2d you have $%.2f\n",Age/12,Age%12,savings);
   savings=savings*(1+working.rate_of_return)+working.contribution;
	   Age++;}
 for (int i=0;i < retired.months ; i++){
   //print Age  27 month  3 you have $21345.00
   printf("Age %3d month %2d you have $%.2f\n",Age/12,Age%12,savings);
   savings=savings*(1+retired.rate_of_return)+retired.contribution;
   Age++;}
 return EXIT_SUCCESS;
}

