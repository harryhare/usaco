/*
ID: harryha7
LANG: C++
TASK: crypt1
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
vector<int> numbers;
int flag[10];

bool check(int x, int maxx) {
    if (x > maxx) {
        return false;
    }
    while (x) {
        if (flag[x % 10] == 0) {
            return false;
        }
        x = x / 10;
    }
    return true;
}

int main() {
    FILE *fin = fopen("crypt1.in", "r");
    FILE *fout = fopen("crypt1.out", "w");
    int n;
    fscanf(fin, "%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        fscanf(fin, "%d", &x);
        numbers.push_back(x);
        flag[x] = 1;
    }
    int count = 0;
    for (int a = 0; a < numbers.size(); a++) {
        for (int b = 0; b < numbers.size(); b++) {
            for (int c = 0; c < numbers.size(); c++) {
                int x = numbers[a] * 100 + numbers[b] * 10 + numbers[c];
                for (int d = 0; d < numbers.size(); d++) {
                    if (!check(x * numbers[d],999)) {
                        continue;
                    }
                    for (int e = 0; e < numbers.size(); e++) {
                        if (!check(x * numbers[e],999)) {
                            continue;
                        }
                        int y = numbers[d] * 10 + numbers[e];
                        if (!check(x * y,9999)) {
                            continue;
                        } else {
                            cout << x << "," << y << endl;
                            count++;
                        }
                    }

                }
            }
        }
    }
    cout << count << endl;
    fprintf(fout, "%d\n", count);

    return 0;
}