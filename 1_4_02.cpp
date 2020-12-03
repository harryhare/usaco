/*
ID: harryha7
LANG: C++
TASK: barn1
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    FILE *fin = fopen("barn1.in", "r");
    FILE *fout = fopen("barn1.out", "w");
    int m, s, c;
    fscanf(fin, "%d%d%d", &m, &s, &c);
    vector<int> len;
    int stalls[200];
    for (int i = 0; i < c; i++) {
        fscanf(fin, "%d", stalls + i);
    }
    sort(stalls, stalls + c);
    for (int i = 1; i < c; i++) {
        int l = stalls[i] - stalls[i - 1] - 1;
        len.push_back(l);
    }
    sort(len.begin(), len.end());
    int sum = 0;
    for (int i = 0; i < m - 1 && i < len.size(); i++) {
        sum += len[len.size() - 1 - i];
    }
    int r = (stalls[c - 1] - stalls[0] + 1) - sum;
    cout << r << endl;
    fprintf(fout, "%d\n", r);
    return 0;
}