#include <stdio.h>
#include <stdlib.h>

typedef struct retire_info{
  int months;
  double contribution;
  double rate;
} retire;

int main (){
	   retire w1;
	   w1.months=489;
	   w1.contribution=1000;
	   w1.rate=0.00375;
	   retire r1;
	   r1.months=384;
	   r1.contribution=-4000;
	   r1.rate=0.0008333333333333334;   
	   //retire_info working, //info about working
	   //retire_info retired) //info about being retired
int  startAge = 327;
double initial = 21345;
int Age = startAge;
double savings = initial;
 for (int i=0;i < w1.months ; i++){
   //print Age  27 month  3 you have $21345.00
   printf("Age %3d month %2d you have $%.2f\n",Age/12,Age%12,savings);
   savings=savings*(1+w1.rate)+w1.contribution;
	   Age++;}
 for (int i=0;i < r1.months ; i++){
   //print Age  27 month  3 you have $21345.00
   printf("Age %3d month %2d you have $%.2f\n",Age/12,Age%12,savings);
   savings=savings*(1+r1.rate)+r1.contribution;
   Age++;}
 return EXIT_SUCCESS;
}

