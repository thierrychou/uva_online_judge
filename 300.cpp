#include <cstdio>
#include <map>
#include <string>

int  n, dd, yy;
int tyy, tname, tnumber;
int total, rest;
char mm[100];

const std::string haab_month[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

const std::string tzolkin[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int main() {
    std::map<std::string, int> haab_month_map;
    for(int i=0; i<19; ++i) {
        haab_month_map[haab_month[i]] = i;
    }

    scanf("%d", &n);
    printf("%d\n", n);
    while(n--) {
	scanf("%d. %s %d", &dd, &mm, &yy);
        std::string s(mm);
	total = dd + haab_month_map[s]*20 + yy*365;

        tyy = total/260;
        rest = total%260;
        tname = rest%20;
        tnumber = rest%13 + 1; 
        printf("%d %s %d\n", tnumber, tzolkin[tname].c_str(), tyy);
    }
}
