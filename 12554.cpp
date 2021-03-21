#include <cstdio>

int i,w,n;
char names[100][101];
const char song[16][9]= {"Happy", "birthday", "to", "you", 
                         "Happy", "birthday", "to", "you",
                         "Happy", "birthday", "to", "Rujia", 
                         "Happy", "birthday", "to", "you"};

int main() {
    scanf("%d", &n);
    for(i=0, w=0; i<n; ++i, w=(w+1)%16) {
        scanf("%s", &names[i]);
        printf("%s: %s\n", names[i], song[w]);
    }
    i=0;
    while(w!=0) {
        printf("%s: %s\n", names[i], song[w]);
	i = (i+1) % n;
	w = (w+1) % 16;
    }
}
