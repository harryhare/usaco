/*
ID: harryha7
LANG: C++
TASK: ariprog
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int biquares[125001] = {0};
vector<int> a;

void init(int m) {
    for (int i = 0; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            biquares[i * i + j * j] = 1;
        }
    }
    for (int i = 0; i <= 2 * m * m; i++) {
        if (biquares[i]) {
            a.push_back(i);
            //cout << i << endl;
        }
    }
    cout << a.size() << endl;
}

void solute(int m, int n, FILE *fout) {
    int max = 2 * m * m;
    bool found = false;
    for (int i = 1; i <= max; i++) {
        for (int j : a) {
            bool error = false;
            if (j + i * (n - 1) > max) {
                break;
            }
            for (int k = 1, x = j + i; k < n && x <= max; k++, x += i) {
                if (biquares[x] == 0) {
                    error = true;
                    break;
                }
            }
            if (!error) {
                found = true;
                printf("%d %d\n", j, i);
                fprintf(fout, "%d %d\n", j, i);
            }

        }
    }
    if (!found) {
        fprintf(fout, "NONE\n");
    }
}


int main() {
    FILE *fin = fopen("ariprog.in", "r");
    FILE *fout = fopen("ariprog.out", "w");
    int n, m;
    fscanf(fin, "%d%d", &n, &m);
    init(m);
    solute(m, n, fout);
    return 0;
}