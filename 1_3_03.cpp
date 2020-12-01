/*
ID: harryha7
LANG: C++
TASK: namenum
*/

// todo rewrite use the right way
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

set<string> dict;

void init_dict() {
    FILE *fdict = fopen("dict.txt", "r");
    char word[128];
    while (fscanf(fdict, "%s", word) != EOF) {
        dict.insert(word);
    }
    fclose(fdict);

    cout << "dict size: " << dict.size() << endl;
}

char a[12][4] = {
        "",
        "",
        "ABC",
        "DEF",
        "GHI",
        "JKL",
        "MNO",
        "PRS",
        "TUV",
        "WXY",
};

bool found = false;

void find(FILE *fout, char *prefix, char *dig, int i = 0) {
    if (dig[i] == 0) {
        prefix[i] = 0;
        if (dict.find(prefix) != dict.end()) {
            found = true;
            cout << prefix << endl;
            fprintf(fout,"%s\n",prefix);
        }
        return;
    }
    int d = dig[i] - '0';
    for (int k = 0; k < 3; k++) {
        prefix[i] = a[d][k];
        find(fout,prefix, dig, i + 1);
    }
    return;
}


int main() {
    init_dict();
    FILE *fin = fopen("namenum.in", "r");
    FILE *fout = fopen("namenum.out", "w");
    char dig[16] = {0};
    char prefix[16] = {0};
    fscanf(fin, "%s", dig);
    found = false;
    find(fout, prefix, dig, 0);
    if (!found) {
        cout<<"NONE\n"<<endl;
        fprintf(fout,"%s\n","NONE");
    }
    return 0;
}