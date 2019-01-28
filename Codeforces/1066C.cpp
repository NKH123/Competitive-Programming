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
//freopen("a.in", "r", stdin);
//freopen("b.in", "r", stdin);
//freopen("c.in", "r", stdin);
//freopen("d.in", "r", stdin);
    int q;
    vector<int> L,R;
    cin>>q;
    map<int,int> ml,mr;
    int first;
    int ans;
     int ln=0,rn=0;
    while(q--){
        char op;
        int n;
        cin>>op>>n;
        //cout<<"q="<<q<<" ln="<<ln<<" rn="<<rn<<"\n";
       
        if(ln==0 && rn==0){
            L.push_back(n);
            R.push_back(n);
            ml[n]=ln;
            mr[n]=rn;
            ln++;
            rn++;
            first=n;
        }
        else if(op=='L'){
             L.push_back(n);
           
            ml[n]=ln;
            
            ln++;
           
        }
        else if(op=='R'){
            R.push_back(n);
            mr[n]=rn;
            rn++;
        }
        else{
           if(first==n){
               ans=   min(L.size(),R.size());
               ans--;
           }
           else{
               if(ml.find(n)!=ml.end()){
                   ans=L.size()-ml[n]-1;

                   ans=min(ans,int(ml[n]+R.size()-1));
               }
               else{
                   //cout<<"in right\n";
                   //cout<<"mr[2]="<<mr[2]<<"\n";
                   ans=R.size()-mr[n]-1;
                   ans=min(ans,int(mr[n]+L.size()-1));
               }
           }
           cout<<ans<<"\n";
        }
    }

    return 0;
}