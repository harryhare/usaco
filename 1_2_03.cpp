/*
ID: harryha7
LANG: C++
TASK: gift1
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unordered_map>

using namespace std;

char *go = "GO\n";
char *stay = "STAY\n";

int cal(char *a) {
    int r = 1;
    for (int i = 0; i < 8 && a[i] != 0 && a[i] != '\r'; i++) {
        r = r * (a[i] - 'A' + 1) % 47;
    }
    return r;
}

int main() {
    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");

    char name[10][16];
    int n;
    unordered_map<string, int> m;

    fscanf(fin, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", name[i]);
        m.insert(make_pair(string(name[i]), 0));
    }
    char giver[16];
    char receiver[16];
    int money;
    int receiver_n;
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", giver);
        fscanf(fin, "%d%d", &money, &receiver_n);
        if (money == 0) {
            for (int j = 0; j < receiver_n; j++) {
                fscanf(fin, "%s", receiver);
            }
            continue;
        }
        if (receiver_n == 0) {
            continue;
        }
        m[string(giver)] -= money / receiver_n * receiver_n;
        cout<<m[string(giver)]<<endl;
        for (int j = 0; j < receiver_n; j++) {
            fscanf(fin, "%s", receiver);
            m[string(receiver)] += money / receiver_n;
        }

    }
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%s %d\n", name[i], m[string(name[i])]);
    }

    return 0;
}