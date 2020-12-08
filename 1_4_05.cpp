/*
ID: harryha7
LANG: C++
TASK: wormhole
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <cstring>

using namespace std;
const int N = 12;
//int x[N + 1];
//int y[N + 1];
int nexts[N + 1];
int pairs[N + 1] = {0};

int visit[N + 1] = {0};
int parents[N + 1] = {0};
unordered_map<int, int> counter;


int dsp2(int n, int index) {
    if (parents[index] != 0) {
        return true;
    }
    if (index == 0) {
        visit[index] = true;
        return false;
    }
    if (visit[index] == 1) {
        return false;
    }
    int next_node = pairs[nexts[index]];
    parents[index] = true;
    int r = dsp2(n, next_node);
    parents[index] = false;
    if (r == false) {
        visit[index] = true;
    }
    return r;
}

bool checkloop(int n) {

    for (int i = 1; i <= n; i++) {
        cout << i << ";" << pairs[i] << ", ";
    }
    cout << endl;
    memset(visit, 0, sizeof(visit));
    memset(parents, 0, sizeof(parents));
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            if (dsp2(n, i)) {
                cout << "true" << endl;
                return true;
            }
        }
    }

    cout << "false" << endl;
    return false;
}

int dsp(int *pair, int n) {
    int first = 0;
    for (int i = 1; i <= n; i++) {
        if (pair[i] == 0) {
            first = i;
            break;
        }
    }
    if (first == 0) {
        return checkloop(n);
    }
    int second = 0;
    int r = 0;
    for (int j = first + 1; j <= n; j++) {
        if (pair[j] != 0) {
            continue;
        }
        second = j;
        pair[first] = second;
        pair[second] = first;
        r += dsp(pair, n);
        pair[first] = 0;
        pair[second] = 0;
    }
    return r;
}

int solve(int n) {
    return dsp(pairs, n);
}

int main() {
    FILE *fin = fopen("wormhole.in", "r");
    FILE *fout = fopen("wormhole.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        fscanf(fin, "%d%d", &x, &y);
        //fscanf(fin, "%d%d", x + i, y + i);
        auto iter = counter.find(y);
        if (iter != counter.end()) {
            iter->second = iter->second + 1;
        } else {
            counter.insert(make_pair(y, 1));
        }
    }
    int node = 0;
    for (auto iter = counter.begin(); iter != counter.end(); iter++) {
        int n = iter->second;
        cout << iter->second << endl;
        for (int i = 0; i < n - 1; i++) {
            node++;
            nexts[node] = node + 1;
        }
        node++;
        nexts[node] = 0;
    }
    int r = solve(n);
    cout << r << endl;
    fprintf(fout, "%d\n", r);
    return 0;
}