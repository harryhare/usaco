/*
ID: harryha7
LANG: C++
TASK: combo
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

bool check(int a, int b, int n) {
    int x = (a - b + n) % n;
    int y = (b - a + n) % n;
    if (x >= 0 && x <= 2 || y >= 0 && y <= 2) {
        return true;
    }
    return false;
}

int main() {
    FILE *fin = fopen("combo.in", "r");
    FILE *fout = fopen("combo.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    if (n <= 5) {
        fprintf(fout, "%d\n", n * n * n);
        return 0;
    }
    int a[3];
    int b[3];
    for (int i = 0; i < 3; i++) {
        fscanf(fin, "%d", a + i);
    }
    for (int i = 0; i < 3; i++) {
        fscanf(fin, "%d", b + i);
    }

    int s = 1;
    for (int i = 0; i < 3; i++) {
        int x = min(a[i], b[i]);
        int y = max(a[i], b[i]);
        int t = 1;
        if (y - x < 5) {
            t = 5 - (y - x);
        } else if (x + n - y < 5) {
            t = 5 - (x + n - y);
        } else {
            s *= 0;
        }
        s *= t;
    }
    int r = 250 - s;
    cout << r << endl;
    fprintf(fout, "%d\n", r);
    return 0;
}