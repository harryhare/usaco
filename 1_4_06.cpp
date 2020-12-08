/*
ID: harryha7
LANG: C++
TASK: skidesign
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    FILE *fin = fopen("skidesign.in", "r");
    FILE *fout = fopen("skidesign.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    int count[101] = {0};
    int x;
    int max_h = 0;
    int min_h = 100;
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &x);
        count[x]++;
        min_h = min(min_h, x);
        max_h = max(max_h, x);
    }
    int min_sum = INT32_MAX;
    for (int i = 0; i < 87; i++) {
        int low = i;
        int high = i + 17;
        int sum = 0;
        for (int j = min_h; j <= low; j++) {
            if (count[j]) {
                sum += count[j] * (j - low) * (j - low);
            }
        }
        for (int j = high; j <= max_h; j++) {
            if (count[j]) {
                sum += count[j] * (j - high) * (j - high);
            }
        }
        min_sum = min(min_sum, sum);
    }
    cout << min_sum << endl;
    fprintf(fout, "%d\n", min_sum);
    return 0;
}