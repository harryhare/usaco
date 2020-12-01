/*
ID: harryha7
LANG: C++
TASK: transform
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
const int N = 16;
char t[N][N];
char m1[4][N][N];
char m2[4][N][N];

bool cmp(char m1[N][N], char m2[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m1[i][j] != m2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void rotate(char out[N][N], char in[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out[i][j] = in[n-1-j][i];
        }
    }
}

void reflect(char out[N][N], char in[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < n; j++, k--) {
            out[i][j] = in[i][k];
        }
    }
}

void make_matrix(int n) {
    reflect(m2[0], m1[0], n);
    for (int i = 1; i < 4; i++) {
        rotate(m1[i], m1[i - 1], n);
    }
    for (int i = 1; i < 4; i++) {
        rotate(m2[i], m2[i - 1], n);
    }
}

int cmp_matrix(int n) {
    for (int i = 1; i < 4; i++) {
        if (cmp(t, m1[i], n)) {
            return i;
        }
    }

    if (cmp(t, m2[0], n)) {
        return 4;
    }
    for (int i = 1; i < 4; i++) {
        if (cmp(t, m2[i], n)) {
            return 5;
        }
    }
    if (cmp(t, m1[0], n)) {
        return 6;
    }
    return 7;
}

int main() {
    FILE *fin = fopen("transform.in", "r");
    FILE *fout = fopen("transform.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", m1[0][i]);
    }
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", t[i]);
    }
    make_matrix(n);
    int r = cmp_matrix(n);
    cout << r << endl;
    fprintf(fout, "%d\n", r);

    return 0;
}