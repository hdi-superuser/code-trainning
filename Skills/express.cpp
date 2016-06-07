#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int N;
char opt[6] = {'(', ')', '+', '-', '*', '/'};
char infix[251];
string T, rpn;
 
bool inOpt(char x) {
	for (int j = 0; j < 6; j++) 
		if (x == opt[j]) return true;
	return false;
}

void cover(char* infix) {
	cout << infix;	
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> N;
	while (N--) {
		gets(infix);	cover(infix);		
	}	
}
