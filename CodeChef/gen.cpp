#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int t=rand(1,10);
    printf("%d\n", t);
    while(t--){
        int n=rand(1,100);
        printf("%d\n", n);
        set<int> used;
        for(int i = 0; i < n; ++i) {
            int x;
        /*do */{
            x = rand(1, 10000);
        } /*while(used.count(x));*/
            printf("%d ", x);
        /*used.insert(x);*/
        }
        cout<<"\n";

    }
    puts("");
}
