/*
ID: neerajd3
PROG: beads
LANG: C++11
*/
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    int n;
    fin >> n;

    string str;
    fin >> str;

    int max = 0;

    for (int i = 0; i < n; ++i) {
        string b = str.substr(i) + str.substr(0, i);

        int c = 0, pos = 0;

        char initial = '\0';
        for (int p = 0; p < n; ++p) {
            if (b[p] == 'w') {
                c++;pos++;
            } else {
                if (initial == '\0') {
                    c++;pos++;
                    initial = b[p];
                } else {
                    if (initial == b[p]) {
                        c++;pos++;
                    } else {
                        break;
                    }
                }
            }
        }

        initial = '\0';
        for (int p = n - 1; p >= pos; --p) {
            if (b[p] == 'w') {
                c++;
            } else {
                if (initial == '\0') {
                    c++;
                    initial = b[p];
                } else {
                    if (initial == b[p]) {
                        c++;
                    } else {
                        break;
                    }
                }
            }
        }

        if (c > max) {
            max = c;
        }
    }

    fout << max << endl;

    return 0;
}