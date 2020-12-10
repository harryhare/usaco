/*
ID: harryha7
LANG: C++
TASK: pprime
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// todo: 备忘: 偶数回文数可以被 11 整除，除了11 以外都不是质数，所以只要生产 奇回文数就可以了


const int maxp = 10000;
int notprime[maxp + 1];
vector<int> primes;
FILE *fin;
FILE *fout;
int a, b;

void init() {
    for (int i = 2; i <= maxp; i++) {
        if (notprime[i] == 0) {//is prime
            primes.push_back(i);
            for (int j = i * i; j <= maxp; j += i) {
                notprime[j] = 1;
            }
        }
    }
//    cout << primes.size() << endl;
//    for (int prime : primes) {
//        cout << prime << endl;
//    }
}

bool is_prime(int n) {
    int upbound = sqrt(n) + 2;
    for (int x:primes) {
        if (x > upbound) {
            return true;
        }
        if (n % x == 0) {
            return false;
        }
    }
    return true;
}

bool is_palindromic(int n) {
    int c[10];
    int i = 0;
    for (; n; n = n / 10, i++) {
        c[i] = n % 10;
    }
    for (int a = 0, b = i - 1; a < b; a++, b--) {
        if (c[a] != c[b]) {
            return false;
        }
    }
    return true;
}

int create_odd(int x) {
    int y = 0;
    int m = 1;

    for (int xx = x / 10; xx; xx = xx / 10, m *= 10) {
        y = y * 10 + xx % 10;
    }
    return x * m + y;

}

int create_even(int x) {
    int y = 0;
    int m = 1;
    for (int xx = x; xx; xx = xx / 10, m *= 10) {
        y = y * 10 + xx % 10;
    }
    return x * m + y;
}

void check(int x) {
    if (x < a || x > b) {
        return;
    }
    if (is_prime(x)) {
        cout << x << endl;
        fprintf(fout, "%d\n", x);
    }
}

void process_odd(int i) {
    int j = i / 2 + 1;
    int x=1;
    for (int k = 0; k < j; k++) {
        x *= 10;
    }
    for (int y = x / 10; y < x; y++) {
        int yy = create_odd(y);
        check(yy);
    }
}

void process_even(int i) {
    int j = i / 2;
    int x=1;
    for (int k = 0; k < j; k++) {
        x *= 10;
    }
    for (int y = x / 10; y < x; y++) {
        int yy = create_even(y);
        check(yy);
    }
}

int main() {
    fin = fopen("pprime.in", "r");
    fout = fopen("pprime.out", "w");
    fscanf(fin, "%d%d", &a, &b);
    init();
    for (int i = 0; i < 8; i++) {
        if (i % 2) {
            process_odd(i);
        } else {
            process_even(i);
        }
    }
    return 0;
}