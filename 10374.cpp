#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>
#include <string>

int test_cases, n, m, count, max_vote;

int main() {
    scanf("%d", &test_cases);
    while(test_cases--) {
	std::map<std::string, std::string> party;
	std::map<std::string, int> vote;
	std::string winner_party;
	max_vote = 0;
	count = 0;

        scanf("%d\n", &n);
	while(n--) {
	    std::string name, party_name;
	    getline(std::cin, name);
	    getline(std::cin, party_name);
	    party[name] = party_name;
	    vote[name] = 0;
	}
	scanf("%d\n", &m);
	while(m--) {
	    std::string name;
	    getline(std::cin, name);
	    if(vote.find(name)!=vote.end()) {
	        vote[name]++;
		max_vote = std::max(max_vote, vote[name]);
	    }
	}
	for(std::map<std::string, int>::iterator it = vote.begin(); it!=vote.end(); it++) {
	    if(max_vote == it->second) {
	        count++;
		winner_party = party[it->first];
	    }
	}
	if(count>1) {
	    printf("tie\n");
	} else {
	    printf("%s\n", winner_party.c_str());
	}
	if(test_cases)
	    printf("\n");
    }
}
