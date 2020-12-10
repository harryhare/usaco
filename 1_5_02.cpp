/*
ID: harryha7
LANG: C++
TASK: milk3
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

int reached[21 * 21 * 21];
int reached_c[21];
int a0;
int b0;
int c0;
int cap[3];

void dsp(int a, int b, int c) {
    int state = a * 21 * 21 + b * 21 + c;
    if (a == 0) {
        reached_c[c] = 1;
    }
    if (reached[state] == 1) {
        return;
    }
    reached[state] = 1;
    int cur[3];
    cur[0] = a;
    cur[1] = b;
    cur[2] = c;

//    if (a < a0) {
//        int space = a0 - a;
//        if (b >= space) {
//            dsp(a0, b - space, c);
//        } else {
//            dsp(a0 + b, 0, c);
//        }
//
//        if (c >= space) {
//            dsp(a0, b, c - space);
//        } else {
//            dsp(a0 + c, b, 0);
//        }
//    }
    for (int i = 0; i < 3; i++) {
        if (cur[i] == cap[i]) {
            continue;
        }
        int space = cap[i] - cur[i];
        for (int j = 1; j <= 2; j++) {
            int k = (i + j) % 3;
            int x = min(cur[k], space);
            cur[i] += x;
            cur[k] -= x;
            dsp(cur[0], cur[1], cur[2]);
            cur[i] -= x;
            cur[k] += x;
        }
    }

}


int main() {
    FILE *fin = fopen("milk3.in", "r");
    FILE *fout = fopen("milk3.out", "w");

    fscanf(fin, "%d%d%d", &a0, &b0, &c0);
    cap[0] = a0;
    cap[1] = b0;
    cap[2] = c0;
    dsp(0, 0, c0);
    int count = 0;
    int first = true;
    for (int i = 0; i <= 20; i++) {
        if (reached_c[i] != 0) {
            cout << i << endl;
            if (first) {
                first = false;
            } else {
                fprintf(fout, " ");
            }
            fprintf(fout, "%d", i);
        }
    }
    fprintf(fout, "\n");

    return 0;
}