#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>


char ch[3];
bool firstCase;

int main() {
    firstCase = true;
    std::string v1, v2, root;

    while(std::cin >> v1 >> v2) {
	if(firstCase) {
	    firstCase = false;
	} else {
	    printf("\n");
	}
        printf("%s (to %s)\n", v1.c_str(), v2.c_str());
	
	ch[0] = v1[v1.size()-2];
	ch[1] = v1[v1.size()-1];
	ch[2] = 0;

	const char* root = v1.substr(0, v1.size()-2).c_str();

	if(strcmp(ch, "ar")==0) {
	    printf("%-10s%so\n", "eu", root);
	    printf("%-10s%sas\n", "tu", root);
	    printf("%-10s%sa\n", "ele/ela", root);
	    printf("%-10s%samos\n", "nós", root);
	    printf("%-10s%sais\n", "vós", root);
	    printf("%-10s%sam\n", "eles/elas", root);
	} else if(strcmp(ch, "er")==0) {
	    printf("%-10s%so\n", "eu", root);
	    printf("%-10s%ses\n", "tu", root);
	    printf("%-10s%se\n", "ele/ela", root);
	    printf("%-10s%semos\n", "nós", root);
	    printf("%-10s%seis\n", "vós", root);
	    printf("%-10s%sem\n", "eles/elas", root);
	} else if(strcmp(ch, "ir")==0) {
	    printf("%-10s%so\n", "eu", root);
	    printf("%-10s%ses\n", "tu", root);
	    printf("%-10s%se\n", "ele/ela", root);
	    printf("%-10s%simos\n", "nós", root);
	    printf("%-10s%sis\n", "vós", root);
	    printf("%-10s%sem\n", "eles/elas", root);
	} else {
	    printf("Unknown conjugation\n");
	}
    }
}
