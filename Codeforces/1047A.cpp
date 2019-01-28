#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
int n;
int a,b,c;
int main()
{   ios::sync_with_stdio(false);
    cin>>n;
    if(n%3==0){
        if(n==3){
            a=b=c=1;
        }
        else{
            a=b=2;
            c=n-4;
        }   
    }
    else{
        a=1;
        b=2;
        c=n-3;
    }
    //cin>>a>>b>>c;
    /*int k=n/3;
    if(k%3==0){
        a=k-2;
        b=k+1;
        c=n-a-b;
        if(c%3==0){
            a++;
            c--;
        }
    }
    else{
        a=k;
        b=k;
        c=n-a-b;
        if(c%3==0){
            c--;
            b++;
        }
    }*/
    cout<<a<<" "<<b<<" "<<c<<"\n";
    return 0;
}