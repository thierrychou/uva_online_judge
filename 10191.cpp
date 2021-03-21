#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<utility>

using namespace std;

int day, s, lastEndTime, nap, startTime;
int tempNap;
char *time1, *time2, line[256];
map<int, int> schedule;
map<int, int>::const_iterator it;

int getDuration(char* time){
  int hh, mm;
  hh = atoi(strtok(time, ":"));
  mm = atoi(strtok(NULL, ":"));
  return hh * 60 + mm;
}

int main() {
  day = 1;
  while(gets(line)!=NULL) {
    schedule.clear();
    s = atoi(line);
    for(; s>0; --s) {
      gets(line);
      time1 = strtok(line, " ");
      time2 = strtok(NULL, " ");
      schedule[getDuration(time1)] = getDuration(time2);
    }

    nap = 0;
    lastEndTime = 10*60;
    for(it=schedule.begin(); it!=schedule.end() ; ++it) {
        tempNap = it->first - lastEndTime;
        if(tempNap > nap) {
          nap = tempNap;
          startTime = lastEndTime;
        }
        lastEndTime = it->second;
    }
    tempNap = 18*60 - lastEndTime;
    if(tempNap>nap) {
      nap = tempNap;
      startTime = lastEndTime;
    }

    printf("Day #%d: the longest nap starts at %02d:%02d and will last for", day++, startTime/60,  startTime%60);
    if(nap/60>0) {
      printf(" %d hours and %d minutes.\n", nap/60, nap%60);
    }else{
      printf(" %d minutes.\n", nap);
    }
  }
}
