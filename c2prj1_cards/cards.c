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
  assert (2<=value_let||value_let<=14);
  assert (suit_let=='s'||suit_let=='d'||suit_let=='h'||suit_let=='c');
  card_t temp;
  temp.value=value_let;
  temp.suit=suit_let;
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
temp.suit = c / 13;
temp.value = c % 13;
 return temp;
}
