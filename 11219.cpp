#include <cstdio>

int main() {
    int d1, m1, y1, d2, m2, y2, T, total = 0, age;
    scanf("%d", &T);
    while(T--){
        scanf("%d/%d/%d", &d1, &m1, &y1);
        scanf("%d/%d/%d", &d2, &m2, &y2);
        if(y1 < y2) {
	    printf("Case #%d: Invalid birth date\n", ++total);
	    continue;
	}
        age=y1-y2;
	if(age==0) {
            if(m1 < m2 || (m1 == m2 && d1 < d2)) {
                printf("Case #%d: Invalid birth date\n", ++total);
		continue;
	    }
        } else{
            if(m1 < m2 || (m1 == m2 && d1 < d2)) age--;
        }

        if(age > 130) printf("Case #%d: Check birth date\n", ++total);
        else          printf("Case #%d: %d\n", ++total, age);
    }
    return 0;
}

