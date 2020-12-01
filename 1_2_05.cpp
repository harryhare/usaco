/*
ID: harryha7
LANG: C++
TASK: beads
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

struct P {
    int count;
    char color;
};
P p[1024];
int p_n = 0;

void push(char color, int count) {
    p[p_n].color = color;
    p[p_n].count = count;
    p_n++;
}

void merge() {
    int j = 0;
    p[p_n].color = 'x';
    p[p_n + 1].color = 'x';
    for (int i = 0; i < p_n;) {
        if (p[i + 1].color == 'w' && p[i].color == p[i + 2].color) {
            p[i + 2].count = p[i].count + p[i + 1].count + p[i + 2].count;
            i += 2;
        } else {
            p[j].count = p[i].count;
            p[j].color = p[i].color;
            i++;
            j++;
        }
    }
    p_n = j;
}

int cal() {
    int m_len = 0;
    p[p_n].color = 'x';
    p[p_n + 1].color = 'x';
    p[p_n + 2].color = 'x';
    p[p_n + 3].color = 'x';
    P p2[2];
    p2[0].color = 'x';
    p2[1].color = 'x';
    p2[0].count = 0;
    p2[1].count = 0;
    int m = 0;
    for (int i = 0; i < p_n; i++) {
        if (p[i].color == 'r' || p[i].color == 'b') {
            if (i >= 1 && p[i - 1].color == 'w') {
                m = max(m, p2[0].count + p2[1].count + p[i - 1].count);
                p2[0] = p2[1];
                p2[1] = p[i];
                p2[1].count += p[i - 1].count;
            } else {
                m = max(m, p2[0].count + p2[1].count);
                p2[0] = p2[1];
                p2[1] = p[i];
            }
        }
    }
    return m;
}

int main() {
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    char str[1024];

    fscanf(fin, "%s", str);
    int c_r = 0;
    int c_b = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'r') {
            c_r++;
        } else if (str[i] == 'b') {
            c_b++;
        }
    }
    if (!(c_r && c_b)) {
        fprintf(fout, "%d\n", n);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        str[n + i] = str[i];
    }
    str[2 * n] = 0;

    int t = 0;
    for (int i = 0; i < 2 * n; i++) {
        t++;
        if (str[i] != str[i + 1]) {
            push(str[i], t);
            t = 0;
        }
    }
    merge();
    int r = cal();
    r = min(r, n);
    cout << r << endl;
    fprintf(fout, "%d\n", r);
    return 0;
}