#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

//Declare your rectangle structure here!
typedef struct rect_t {
  int x;
  int y;
  int width;
  int height;
} rectangle;


rectangle canonicalize(rectangle r) {
  
  if (r.width < 0) {
    r.width = 0 - r.width;
	r.x = r.x - r.width;}
  if (r.height < 0) {
      r.height = 0 - r.height;
	   r.y = r.y - r.height;}
  return r;
}
rectangle intersection(rectangle r1, rectangle r2) {
  rectangle i;

  r1 = canonicalize(r1);
  
  r2 = canonicalize(r2);
  
  i.x=0;
  i.y=0;
  i.width=0;
  i.height=0;
  
  if (r1.x <= r2.x) {
    i.x = r2.x; //
    if (( r2.x - r1.x ) <= r1.width) {
      if (r2.width >= ( r1.width - (r2.x - r1.x))){
	i.width = r1.width - ( r2.x - r1.x );}
      else {i.width = r2.width; }}
      else { i.width = 0; }}  //no hay interseccion
  else {//r1.x>r2.x lo mismo de ariba invirtiendo r1 y r2
    i.x = r1.x;//
    if (( r1.x - r2.x ) <= r2.width) {
      if (r1.width >= ( r2.width - (r1.x - r2.x))){
	i.width = r2.width - ( r1.x - r2.x );}
      else {i.width = r1.width; }}
    else { i.width = 0; }}
  //hago lo mismo con la altura remplazo x por y, width por height
     if (r1.y <= r2.y) {
       i.y = r2.y; //  
      if (( r2.y - r1.y ) <= r1.height) {
      if (r2.height >= ( r1.height - (r2.y - r1.y))){
	i.height = r1.height - ( r2.y - r1.y );}
      else {i.height = r2.height; }}
      else { i.height = 0; }}  //no hay interseccion
     else {//r1.y>r2.y lo mismo de ariba invirtiendo r1 y r2
    i.y=r1.y;//
    if (( r1.y - r2.y ) <= r2.height) {
      if (r1.height >= ( r2.height - (r1.y - r2.y))){
	i.height = r2.height - ( r1.y - r2.y );}
      else {i.height = r1.height; }}
    else { i.height = 0; }}
 
    return i;
}

//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 || r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                           r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;
  r2.y = 5;
  r2.width = -5;
  r2.height = -7;
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}
