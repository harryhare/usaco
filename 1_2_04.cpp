/*
ID: harryha7
LANG: C++
TASK: friday
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int m_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nonleap_c[7] = {0};
int leap_c[7] = {0};

void init() {
    int s = 0;
    nonleap_c[s] += 1;
    for (int i = 0; i < 11; i++) {
        s = (s + m_day[i]) % 7;
        nonleap_c[s] += 1;
    }
    m_day[1] += 1;
    s = 0;
    leap_c[s] += 1;
    for (int i = 0; i < 11; i++) {
        s = (s + m_day[i]) % 7;
        leap_c[s] += 1;
    }
}

int main() {
    init();
    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    int s = (2 + 13 - 1) % 7;
    int c[7] = {0};
    for (int i = 0; i < n; i++) {
        int y = 1900 + i;
        bool leap = (y % 100 != 0) && (y % 4 == 0) || (y % 400 == 0);
        if (leap) {
            for (int j = 0; j < 7; j++) {
                c[(j + s) % 7] += leap_c[j % 7];
            }
        } else {
            for (int j = 0; j < 7; j++) {
                c[(j + s) % 7] += nonleap_c[j % 7];
            }
        }

        s = (s + 365 + leap) % 7;
    }
    for (int j = 0; j < 7; j++) {
        cout << c[j] << endl;
        fprintf(fout, "%d", c[j]);
        if (j != 6) {
            fprintf(fout, " ");
        }
    }
    fprintf(fout, "\n");

    return 0;
}