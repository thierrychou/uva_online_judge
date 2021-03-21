#include <cstdio>
#include <map>
#include <iostream>
#include <limits>
#include <string>

int tc;
char output[10000];

int main() {
    std::cin >> tc;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while(tc--) {
	std::string plaintext, substitution;
	std::string input;
	std::map<char, char> m;

	std::getline(std::cin, plaintext);
	std::getline(std::cin, substitution);

	std::cout << substitution << std::endl;
	std::cout << plaintext    << std::endl;

	for(int i=0; i<plaintext.size(); ++i) {
	    m[plaintext[i]] = substitution[i];
	}

	
	while(true) {
	    std::getline(std::cin, input);
	    if(input.size()==0) break;
	    for(int i=0; i<input.size(); ++i) {
	        if(m.find(input[i]) != m.end()) {
	            output[i] = m[input[i]];
	        } else {
	            output[i] = input[i];
	        }
	    }
	    output[input.size()] = 0;
	    std::cout << output << std::endl;
	}
	if(tc) std::cout << std::endl;
    }
}
