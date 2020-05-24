#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
//vector <int>
// push_back
// char ice[n][m]

ll max(ll a, ll b){
    if(a>=b)
        return a;

    return b;
}



int main(){
    ll q;
    cin>>q;
    

    while(q--){
        ll n, r, temp;
        cin>>n>>r;
        vector<ll> f(100005);
        vector<ll> v;
        for(ll i=0; i<n; i++){
            cin>>temp;
            f[temp]=1;
        }

        for(ll i=0; i<f.size(); i++){
            if(f[i]==1)
                v.push_back(i);
        }

        ll start = 0;
        ll startv = 0;
        ll end = v.size()-1;
        ll count = 0;
        while(startv<=end){
            count++ ;
         
            start+= r;
         
            for(ll j=startv; j<=end; j++){
                //cout<<j<<" J\n";
                if(v[j]>start){
                    //startv++;
                    //cout<<"he"<<startv<<" "<<j<<endl;
                    startv = j;
                    break;
                }

                else{
                    startv = j;
                }
            }
         
            end--;
            // if(start>end)
            //  break;

            //cout<<start<<" "<<startv<<" "<<end<<endl;
         
        }

        cout<<count<<"\n";
    }

}
