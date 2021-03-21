#include <cstdio>
#include <cstring>

bool loop;
int tc,mm,ff,mf;
char *ptr, line[10000];

int main() {
    scanf("%d", &tc);
    getchar();
    while(tc--) {
        mm = ff = mf = 0;
        gets(line);
        ptr = strtok(line, " ");
        while(ptr!=NULL) {
            if((ptr[0]=='M' && ptr[1]=='F') ||
               (ptr[0]=='F' && ptr[1]=='M')) {
                ++mf;
            } else if(ptr[0]=='M' && ptr[1]=='M') {
                ++mm;
            } else {
                ++ff;
            }
            ptr = strtok(NULL, " ");
        }
        if((mm+ff+mf)==1) loop = false;
        else if(mm==ff && mf%2==0) loop = true;
        else loop = false;
        printf(loop ? "LOOP\n" : "NO LOOP\n");
    }
}
