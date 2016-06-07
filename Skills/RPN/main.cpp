#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

stack <long long> st;
char Opt[4] = {'+', '-', '*', '/'};
string T;
char RPN[1000000];

bool InOpt(char x) {
	for (int p = 0; p < 4; p++)
		if (x == Opt[p]) return true;
	return false;
}

long long cover(string x) {
	long long p = 0;
	for (int j = 0; j < x.size(); j++)
		p = p*10 + (x[j] - 48);
	return p;
}

void Process(string T) {
	if (!InOpt(T[0])) { st.push(cover(T)); }
	else {
		long long y = st.top();	st.pop();
		long long x = st.top();	st.pop();
		cout << T << " " << x << " " << y << endl;
		if (T == "+") x = x + y;
		if (T == "-") x = x - y;
		if (T == "*") x = x * y;
		if (T == "/") x = x / y;
		st.push(x);
	}
}

int main() {
    freopen("in.txt", "r", stdin);
	gets(RPN);  RPN[strlen(RPN)] = ' ';
	for (int i = 0; i < strlen(RPN); i++)
		if (RPN[i] != ' ') T = T + RPN[i];
		else {
			Process(T);
			T = "";
		}
	cout << "RPN = " << st.top() << endl;
	return 0;
}

