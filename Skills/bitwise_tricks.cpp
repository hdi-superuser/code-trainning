/*
 * Jun 10, 2016
 * Demo bitwise tricks
 */
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// return true if x is power of 2, and otherwise
bool is_power_of_2(ull x) {
    if (x & (x-1) == 0) return true;
    return false;
}
bool is_diff_signA(int x, int y) {
    return (x ^ y) < 0;
}

// return true if x and y are different sign
bool is_diff_signB(int x, int y) {
    return ((unsigned) (x ^ y)) >> 31;
}

// return absolute of x
// m = x >> 31 -> the sign mask
int abs_a(int x) {
    int m = x >> 31;
    return x - ((2 * x) & m);
}
int abs_b(int x) {
    int m = x >> 31;
    return (x ^ m) - m;
}
int abs_c(int x) {
    int m = x >> 31;
    return (x + m) ^ m;
}

// sign extended
int sign_ext_A(int x, int b) {
    return (x << (32 - b)) >> (32 - b);
}
int sign_ext_B(int x, int b) {
    int m = 1 << (b - 1);   // the signed bit
    x = x & ((1 << b) - 1); // clear k-b leading bits
    return (x ^ m) - m;
}
int sign_ext_C(int x, int b) {
    int m = 1 << (b-1);
    x = x & ((1 << b) - 1); // clear k-b leading bits
    return (x ^ m) - m;
}

// swap two integer
void swap_a(int &x, int &y) {
    x = x + y;
    y = x - y;
    x = x - y;
}
void swap_b(int &x, int &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

// return max(integer, integer), min(integer, integer)
int min_A(int x, int y) {
    int m = -(x < y);
    return y ^ ((x ^ y) & m);
}
int min_B(int x, int y) {
    int m = -(x < y);
    return y + ((x - y) & m);
}

int main() {
    freopen("in.txt", "r", stdin);
    int a = 2, b = 4;
    swap_b(a, b);
    printf("%d %d", a, b);
    return 0;
}
