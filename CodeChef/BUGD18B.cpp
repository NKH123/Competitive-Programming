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
 int main()
{   ios::sync_with_stdio(false);
    int t;
    cin>>t;
     while(t--){
        int l,r;
        cin >> l>>r;
        int count=0;
         if(l==r){
            cout << "0\n";
        }else if(l>r){
            cout << l-r<<"\n";
        }else{
            /*while(r>l){
                r=r/3;
                count++;
            }
            count+=l-r;
            cout << count << "\n";*/
            while(l<r){
                   // cout<<"l="<<l<<" r="<<r<<"\n";
                if(r%3!=0){
                    count=count+3-(r%3);
                    r=r+3-(r%3);
                   // cout<<"Inter r="<<r<<"\n";
                }
                r=r/3;
                //cout<<"final r="<<r<<"\n";
                count++;
            }
            //cout<<"count="<<count<<"\n";
            if(l!=r){
                count=count+l-r;
            }
            cout<<count<<"\n";
        }
    }
    return 0;
}