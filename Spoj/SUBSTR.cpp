/*
 * An implementation of Z algorithm for this problem: http://vn.spoj.com/problems/SUBSTR/
 *
 *  Created on: Jul 21, 2015
 *      Author: hunglv
 */

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<string.h>

using namespace std;
#define max(x, y) (((x) < (y)) ? (y) : (x))
#define MAX 1000005
string T, P;
int  Z[2*MAX];

void compute_Z_function(int n);

int main() {
	cin >> T >> P;
	int n=T.size(), m=P.size();
	T = " " + P + "{" + T;
	compute_Z_function(n+m+1);
	for(int i = m + 2; i <= n+m+1; i++){
		if(Z[i] == m)printf("%d ",i-m-1);
	}
}

void compute_Z_function(int n){
	Z[1] = 0;
	int R = 0, L = 0;
	int i = 0, j = 0, k = 0, next = 0;
	for(i = 2; i <=n; i++){
		next  = 0;
		if(i >= R){
			k = i; j = 1;
			next = 1;
		} else {
			int al = i - L + 1;
			int be = R - L + 1;
			if(i + Z[al] -1 < R){
				Z[i] = Z[al];
			} else{ // i + Z[al] -1 = R[i-1]
				k = R + 1;
				j = be - al + 2;
				next = 1;
			}

		}
		if(next == 1){
			while(k <= n && T[k] == T[j]){
				k++; j++;
			}
			Z[i] = j-1;
			L = i; R = L + Z[i] - 1;
		}
	}
}






