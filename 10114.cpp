#include <cstdio>

int i, n, m, depreciation_size;
double d, down_payment, loan, depreciation[101];
double monthly_payment, car_value;

int main() {
    while(scanf("%d %lf %lf %d", &n, &down_payment, &loan, &depreciation_size)!=EOF) {
        if(n<0) break;
        while(depreciation_size--) {
	    scanf("%d %lf", &m, &d);
	    for(i=m; i<=100; ++i) depreciation[i] = d;
	}
	monthly_payment = loan / n;
	car_value       = (down_payment + loan) * (1-depreciation[0]);
	i=0;

        while(car_value<loan) {
	    loan      -= monthly_payment;
	    car_value *= 1-depreciation[++i];
	}
	if(i==1) printf("1 month\n");
	else printf("%d months\n", i);
    }
}
