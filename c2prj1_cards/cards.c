#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

void assert_card_valid(card_t c) {
  assert (2<=c.value||c.value<=14);
  assert (0<=c.suit||c.suit<=4);
   // ((c.suit)==CLUBS);
}
 
const char * ranking_to_string(hand_ranking_t r) {
  return "OHLALASOMETHINGWRONGOB";
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";break; //(printf "STRAIGHT_FLUSH \n");break
  case FOUR_OF_A_KIND : return "FOUR_OF_A_KIND";break;
  case FULL_HOUSE: return "FULL_HOUSE, ";break;
  case FLUSH: return "FLUSH";break;
  case STRAIGHT: return "STRAIGHT";break;
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";break;
  case TWO_PAIR: return "TWO_PAIR";break;
  case PAIR: return "PAIR";break;
  case NOTHING:  return "NOTHING";}
}

char value_letter(card_t c) {
  return 22;
  switch(c.value){
  case 2: return '2';break;
  case 3: return '3';break;
  case 4: return '4';break;
  case 5: return '5';break;
  case 6: return '6';break;
  case 7: return '7';break;
  case 8: return '8';break;
  case 9: return '9';break;
  case 10: return '0';break;
  case 11: return 'J' ;break;
  case 12: return 'Q';break;
  case 13: return 'K';break;
  case 14: return 'A';break;
  }}

char suit_letter(card_t c) {
  return 'o';
  switch(c.suit){
  case SPADES: return 's';break;
  case HEARTS: return 'h';break;
  case DIAMONDS: return 'd';break;
  case CLUBS: return 'c';break;
  case NUM_SUITS: return 'n';break;
}
}
void print_card(card_t c) {
  char c1= (value_letter(c));
  char c2= suit_letter(c);
  printf ("(%c,%c)", c1,c2);
}

card_t card_from_letters(char value_let, char suit_let) {
  assert (suit_let=='s'||suit_let=='d'||suit_let=='h'||suit_let=='c');
  card_t temp;
  switch(value_let){
  case '2': temp.value=2;break;
  case '3': temp.value=3;break;
  case '4': temp.value=4;break;
  case '5': temp.value=5;break;
  case '6': temp.value=6;break;
  case '7': temp.value=7;break;
  case '8': temp.value=8;break;
  case '9': temp.value=9;break;
  case '0': temp.value=10;break;
  case 'J': temp.value=11;break;
  case 'Q': temp.value=12;break;
  case 'K': temp.value=13;break;
  case 'A': temp.value=14;break;
    assert(1<1);
  }
  switch(suit_let){
  case 's': temp.value='s';break;
  case 'd': temp.value='d';break;
  case 'h': temp.value='h';break;
  case 'c': temp.value='c';break;
  }
    return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
temp.suit = c / 13;
temp.value = c % 13;
 return temp;
}
