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
int n,m;
int t;
vector< pair<ll, ll> >times;
vector<ll> Start;
vector<ll> End;

int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>m;
        //times.clear)();
        Start.clear();
        End.clear();
        while(n--){
            ll l, r;
            cin>>l>>r;
            Start.PB(l);
            End.PB(r);
        }
        sort(Start.begin(),Start.end());
        sort(End.begin(),End.end());
        while(m--){
            ll time;
            cin>>time;
            int N=Start.size();
            auto slot=upper_bound(End.begin(),End.end(),time);
            if(slot==End.end()){
                cout<<-1<<"\n";
            }
            else{
                int pos=slot-End.begin();
                if(time>=Start[pos]){
                    //if(time<End[pos])
                    cout<<0<<"\n";
                }
                else{
                    cout<<Start[pos]-time<<"\n";
                }

            }



            /*if(End[pos]>time){
                cout<<0<<"\n";
            }
            else{
                pos++;
                if(pos==N){
                    cout<<-1<<"\n";
                }
                else{
                    
                cout<<(Start[pos]-time)<<"\n";
            
                }
            }*/
        }
    }
    return 0;
}