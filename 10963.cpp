#include <cstdio>

int test_cases, w, y1, y2, gap, overall_gap;
bool closable, first, first_case;

int main() {
    first_case = true;
    scanf("%d", &test_cases);
    while(test_cases--) {
        scanf("%d", &w);
	closable = true;
	first = true;
	while(w--) {
	    scanf("%d %d", &y1, &y2);
	    if(closable) {
		gap = y1 - y2;
	        if(first) {
	            overall_gap = gap;
		    first = false;
	        } else {
	            if(overall_gap!=gap) {
		        closable = false;
	    	   }
	        }  
	    }
	}
	if(!first_case) printf("\n");
	printf( closable ? "yes\n" : "no\n" );
	first_case = false;
    }
}
