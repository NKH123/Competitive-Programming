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
int t;
int n;
vi a;
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        if(n%2){
            cout<<"NO\n";
        }
        else{
            int f=1;
            for(int i=0; i<n/2;i++){
                int j=i+n/2;
                if(a[i]==a[j]){
                    if(a[i]==-1){
                        a[i]=a[j]=1;
                    }
                }
                else{
                    if(a[i]==-1 || a[j]==-1){
                        if(a[i]==-1){
                            a[i]=a[j];
                        }
                        else{
                            a[j]=a[i];
                        }
                    }
                    else{
                        f=0;
                        cout<<"NO\n";
                        break;
                    }

                }
                
            }
            if(f==1){
                cout<<"YES\n";
                for(int i=0;i<n;i++){
                    cout<<a[i]<<" ";
                }
                cout<<"\n";
            }
            

        }
    }
    return 0;
}