#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int x, col, length, i, j;
char c, dealer[2], deal[27];

int translateSuit(char suit) {
  switch(suit) {
    case 'C':
      return 1;
    case 'D':
      return 2;
    case 'S':
      return 3;
    case 'H':
      return 4;
  }
}

char translateSuitBack(int suit) {
  switch(suit) {
    case 1:
      return 'C';
    case 2:
      return 'D';
    case 3:
      return 'S';
    case 4:
      return 'H';
  }  
}

int translateCard(char card) {
  switch(card) {
    case 'T':
      return 9;
    case 'J':
      return 10;
    case 'Q':
      return 11;
    case 'K':
      return 12;
    case 'A':
      return 13;
    default:
      return card - '1';
  }
}

char translateCardBack(int card) {
  switch(card) {
    case 9:
      return 'T';
    case 10:
      return 'J';
    case 11:
      return 'Q';
    case 12:
      return 'K';
    case 13:
      return 'A';
    default:
      return card + '1';
  }
}

int main() {
  vector<int> hand[4];
  for(x=0; x<4; ++x){
    hand[x].resize(13);
  }

  while(scanf("%s", dealer) && dealer[0]!='#') {
    switch(dealer[0]) {
      case 'S':
	      j = 0;
	      break;
      case 'W':
	      j = 1;
	      break;
      case 'N':
	      j = 2;
	      break;
      case 'E':
	      j = 3;
	      break;
    }
    
    col = 0;
    for(x=0; x<2; ++x) {
      scanf("%s", deal);
      length = strlen(deal);

      for(i=0; i<length; i+=2) {
        ++j;
        j %= 4;
	hand[j][col/4] = translateSuit(deal[i])*14 + translateCard(deal[i+1]);
	++col;
      }
    }

    for(x=0; x<4; ++x) {
      sort(hand[x].begin(), hand[x].end());

      switch(x) {
        case 0: c='S'; break;
        case 1: c='W'; break;
	case 2: c='N'; break;
	case 3: c='E'; break;
      }
      printf("%c:", c);
      for(vector<int>::const_iterator it=hand[x].begin(); it!=hand[x].end(); ++it) {
        printf( " %c%c", translateSuitBack(*it/14), translateCardBack(*it%14));
      }
      printf("\n");
    }
  }
}
