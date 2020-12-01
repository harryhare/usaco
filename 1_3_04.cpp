/*
ID: harryha7
LANG: C++
TASK: palsquare
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

bool check(int *a, int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (a[i] != a[j]) {
            return false;
        }
    }
    return true;
}

void print(FILE *fout, int *a, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= 9) {
            fputc(a[i] + '0', fout);
        } else {
            fputc(a[i] - 10 + 'A', fout);
        }
    }
}

bool check(FILE *fout, int x, int base) {
    cout << "check " << x << endl;
    int a[20];
    int b[20];
    int i = 0;
    int j = 0;
    int xx = x * x;
    while (xx) {
        a[i] = xx % base;
        xx = xx / base;
        i++;
    }
    while (x) {
        b[j] = x % base;
        x = x / base;
        j++;
    }
    if (check(a, i)) {
        cout << "find" << endl;
        print(fout, b, j);
        fputc(' ', fout);
        print(fout, a, i);
        fputc('\n', fout);
    }
    return true;
}


int main() {
    FILE *fin = fopen("palsquare.in", "r");
    FILE *fout = fopen("palsquare.out", "w");
    int base = 0;
    fscanf(fin, "%d", &base);
    for (int i = 1; i <= 300; i++) {
        check(fout, i, base);
    }
    return 0;
}