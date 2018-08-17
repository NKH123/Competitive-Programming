#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
int n,k;
vi a;

int main()
{   ios::sync_with_stdio(false);
    cin>>n>>k;
    a.resize(n);
    vi A(n);
    REP(i,0,n){
        cin>>a[i];
        A[i]=a[i];
    }
    sort(A.begin(),A.end());
    /*cout<<"Sorted array\n";
    for(auto g:A){
        cout<<g<<" ";
    }
    cout<<"\n";*/
    int ans=0;
    vi B;
    for (int i=0; i<k;i++){
        ans=ans+A[n-1-i];
        B.PB(A[n-1-i]);
    }
    /*cout<<"Last k largest elements\n";
    for( auto g:B){
        cout<<g<<" ";
    }
    cout<<"\n";*/
    cout<<ans<<"\n";
    vi AA(n);
    //int start=0;
    for(int j=0;j<k;j++){
    for(int i=0; i<a.size();i++){
        if(a[i]==B[j] && AA[i]!=1){
            AA[i]=1;

            //start=i+1;
            break;
        }
    }
    }
   /* cout<<"Break array\n";
    for(auto g: AA){
        cout<<g<<" ";
    }
    cout<<"\n";*/
    int count=0;
    vi C;
    int SUM=0;
    for(int i=0; i<n;i++){
        if(AA[i]==0){
            count++;
        }
        else{
            C.PB(count+1);
            SUM+=count+1;
            count=0;
        }
    }
    C[k-1]=C[k-1]+(n-SUM);
    for(auto g: C){
        cout<<g<<" ";
    }

    return 0;
}