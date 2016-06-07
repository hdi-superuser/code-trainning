#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

stack <long long> st;
char Opt[4] = {'+', '-', '*', '/'};
string T, RPN;

bool InOpt(char x) {
	for (int p = 0; p < 4; p++)
		if (x == Opt[p]) return true;
	return false;
}

long long cover(string x) {
	int p = 0;
	for (int j = 0; j < x.size(); j++)
		p = p*10 + (x[j] - 48);
	return p;
}

void Process(string T) {
	if (!InOpt(T[1])) { st.push(cover(T)); }
	else {
		long long y = st.top();	st.pop();
		long long x = st.top();	st.pop();
		switch (T[1]) {
			case '+': x = x + y;
			case '-': x = x - y;
			case '*': x = x * y;
			case '/': x = x / y;
		}
		st.push(x);
	}
}

int main() {
	cout << "Enter RPN Expression: ";	cin >> RPN;
	for (int i = 0; i < RPN.size(); i++)
		if (RPN[i] != ' ') T += RPN[i];
		else {
			Process(T);
			T = "";
		}
	cout << "RPN = " << st.top() << endl;
	return 0;
}
