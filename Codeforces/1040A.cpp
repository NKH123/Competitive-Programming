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
int a,b;
vi A;

int main()
{   ios::sync_with_stdio(false);
    cin>>n>>a>>b;
    A.resize(n);
    REP(i,0,n){
        cin>>A[i];
    }
    int l=0; r=A.size()-1;
    int price=0;
    while(l<=r){
        if(A[l]==A[r]){
            if(A[l]==2){
                price+=2*min(a,b);
            }
        }
        if(A[l]!=A[r]){
            if(A[l]==2){
                if(A[r]==0){
                    price+=a;
                }
                if(A[r]==1){
                    price+=b;
                }
            }
            else if(A[r]==2){
                if(A[l]==0){
                    price+=a;
                }
                if(A[l]==1){
                    price+=b;
                }
            }
            else{
                price=-1;
                break;
            }
        }



        l++;
        r--;
    }
    cout<<price<<"\n";
    return 0;
}