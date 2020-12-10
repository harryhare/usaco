/*
ID: harryha7
LANG: C++
TASK: sprime
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


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
}

bool is_prime(int n) {
    if(n==1){
        return false;
    }
    if(n==2){
        return true;
    }

    int upbound = sqrt(n+1) ;
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

void print(int x) {
        cout << x << endl;
        fprintf(fout, "%d\n", x);
}

void process(int n, int prefix) {
    if (prefix!=0 && !is_prime(prefix)){
        return;
    }
    if (n == 0) {
        print(prefix);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        process(n-1, prefix * 10 + i);
    }

}

int main() {
    fin = fopen("sprime.in", "r");
    fout = fopen("sprime.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    init();
    process(n, 0);
    return 0;
}