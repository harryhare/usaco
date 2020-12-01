/*
ID: harryha7
LANG: C++
TASK: dualpal
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

bool check_sym(const int *a, int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (a[i] != a[j]) {
            return false;
        }
    }
    return true;
}


bool check(int x, int base) {
    int a[20];
    int i = 0;
    int xx = x;
    while (xx) {
        a[i] = xx % base;
        xx = xx / base;
        i++;
    }
    return check_sym(a, i);
}


int main() {
    FILE *fin = fopen("dualpal.in", "r");
    FILE *fout = fopen("dualpal.out", "w");
    int n, s;
    fscanf(fin, "%d%d", &n, &s);
    for (int i = s + 1, c = 0; c < n; i++) {
        int counter = 0;
        for (int base = 2; base <= 10; base++) {
            counter += check(i, base);
            if (counter >= 2) {
                c++;
                fprintf(fout, "%d\n", i);
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}