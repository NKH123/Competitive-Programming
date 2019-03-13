#include <bits/stdc++.h>
#define ll long long
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}
bool valid(ll x){
    string s;
    ll B=x;
    while(B>0){
        int d=B%10;
        s.push_back('0'+d);
        B=B/10;
    }
    reverse(s.begin(),s.end());
    //cout<<s<<"\n";
    int f=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            f=1;
            break;
        }
    }
    if(f)return false;
    else return true;
}
int main(int argc, char* argv[]) {
    srand(time(NULL)); // atoi(s) converts an array of chars to int
    ll n = 1;//rand(2, 10);
    printf("%d\n", n);

    set<int> used;
    for(ll i = 0; i < n; ++i) {
        ll x;
        ll y;
        do {
            x = rand(1L, 1000000000000000000L);
            y=rand(1,9);
        } while(used.count(x) || !valid(x));
        printf("%d %d", x,y);
        used.insert(x);
    }
    puts("");
}