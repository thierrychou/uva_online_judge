#include<stdio.h>
#include<algorithm>
#include<cstring>

struct team {
  int  team_number;
  int  total_solved;
  int  total_penalty;
  bool solved[10];
  int  incorrect_count[10];
  bool submission;
};

team score[101];

inline bool compare(const team& a, const team& b) {
  if(a.total_solved > b.total_solved) return true;
  if(a.total_solved == b.total_solved) {
    if(a.total_penalty < b.total_penalty) return true;
    if(a.total_penalty == b.total_penalty && a.team_number<b.team_number) return true;
  }
  return false;
}

inline void clear() {
  for(int i=0; i<=100; ++i) {
    score[i].team_number = i;
    score[i].total_solved = 0;
    score[i].total_penalty = 0;
    std::memset(score[i].solved, false, sizeof(score[i].solved));
    std::memset(score[i].incorrect_count, 0, sizeof(score[i].incorrect_count));
    score[i].submission = false;
  }
}

char line[1000], l;
int testcase, cases, c, p, t, x;

int main() {
  scanf("%d", &cases);
  getchar();
  gets(line); //blank line.
  for(testcase=0; testcase<cases; ++testcase) {
    clear();
    while(gets(line) && strlen(line)) {
      sscanf(line, "%d %d %d %c", &c, &p, &t, &l);
      score[c].submission = true;
      switch(l) {
        case 'R': case 'U': case 'E':
	  continue;
	case 'C':
	  if(!score[c].solved[p]) {
	    ++score[c].total_solved;
	    score[c].total_penalty += t + score[c].incorrect_count[p] * 20;
	    score[c].solved[p] = true;
	  }
	  break;
	case 'I':
	  if(!score[c].solved[p]) {
	    ++score[c].incorrect_count[p];
	  }
	  break;
      }
    }

    std::sort(score, score+101, compare);

    if(testcase!=0) printf("\n");
    for(x=0; x<101; ++x) {
      if(score[x].submission)
	printf( "%d %d %d\n", score[x].team_number, score[x].total_solved, score[x].total_penalty);
    }
  }
}
