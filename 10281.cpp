#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int hh,mm,ss,h,m,s;
double d, sp, speed;
char line[100], *time, *ptr;
bool reset;

int main() {
  d = 0;
  hh = 0;
  mm = 0;
  ss = 0;
  speed = 0;
  while(gets(line)!=NULL) {
    if(strlen(line)==0) return 0;
    reset = false;

    time = strtok(line, " ");
    sscanf(time, "%d:%d:%d", &h, &m, &s);

    ptr = strtok(NULL, " ");
    if(ptr!=NULL) {
      sp = atof(ptr);
      reset = true;
    }

    if(reset) {
      d +=  ((double)h-(double)hh + ((double)m-(double)mm)/60.0 + ((double)s-(double)ss)/(60.0*60.0))*speed;
      hh = h;
      mm = m;
      ss = s;
      speed = sp;
    } else {
      printf("%02d:%02d:%02d %.2lf km\n", h, m, s, d + ((double)h-(double)hh + ((double)m-(double)mm)/60.0 + ((double)s-(double)ss)/(60.0*60.0))*speed);
    }

  }
}
