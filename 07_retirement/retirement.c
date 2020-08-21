#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

int retirement(retire_info working,retire_info retired){
  int  startage = 327;
  double initial = 21345;
  int age = startage;
  double savings = initial;
  for (int i=0;i < working.months ; i++){
    //print age  27 month  3 you have $21345.00
    printf("Age %3d month %2d you have $%.2f\n",age/12,age%12,savings);
    savings=savings*(1+working.rate_of_return)+working.contribution;
    age++;}
  for (int i=0;i < retired.months ; i++){
    //print age  27 month  3 you have $21345.00
    printf("Age %3d month %2d you have $%.2f\n",age/12,age%12,savings);
    savings=savings*(1+retired.rate_of_return)+retired.contribution;
    age++;}
  return EXIT_SUCCESS;
}
int main (){
	   retire_info working;
	   working.months=489;
	   working.contribution=1000;
	   working.rate_of_return=0.00375;
	   retire_info retired;
	   retired.months=384;
	   retired.contribution=-4000;
	   retired.rate_of_return=0.0008333333333333334;   
	   retirement(  working,retired);
}


