#include <cstdio>

int n, one, two;
char word[6];

int main() {
    scanf("%d", &n);
    while(n--) {
	one = two = 0;
        scanf("%s", &word);
	if((word[0]-'o')!=0) one++;
	if((word[1]-'n')!=0) one++;
	if((word[2]-'e')!=0) one++;
	if((word[0]-'t')!=0) two++;
	if((word[1]-'w')!=0) two++;
	if((word[2]-'o')!=0) two++;
        if(one<=1) printf("1\n");
	else if(two<=1) printf("2\n");
	else printf("3\n");
    }
}
