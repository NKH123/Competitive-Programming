#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(time(NULL)); // atoi(s) converts an array of chars to int
    int n = rand(2, 10);
    printf("%d\n", n);
    set<int> used;
    for(int i = 0; i < n; ++i) {
        int x;
        x = rand(1, 10);
        // do {
            
        // } while(used.count(x));
        printf("%d ", x);
        // used.insert(x);
    }
    int p=rand(0,n);
    if(p==n){
        p--;
    }
    printf("\n%d\n",p);
    puts("");
}
