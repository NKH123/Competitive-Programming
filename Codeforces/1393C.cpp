#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define sz(x) (int)(x.size())
#define mod 1000000007
#define endl "\n"
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;


vi a;
vi b;
map<int, int>ct;
map<int, int>pos;
set<pair<int, pair<int, int> >  >pq;
int MAXI = 1e18;
map<int, int>M;
map<int, int>fuck;
bool can(int gap){
    deb(gap);
    b.clear();
    set<pair<int, pair<int, int> >  >pqq = pq;
    M.clear();
    int time  =0;
    map<int, int>CT = ct;
    map<int, int>Fuck =fuck;
    while(pqq.size()!=0){
        // deb(pqq);
        // deb(time);
        // deb(CT);
        // deb(b);
        // deb("******************");
        auto ele = *(pqq.begin());
        // pqq.pop();
        // Q.push({ele.S.S, ele.S.F});
        if(M.find(time-gap-1)==M.end()){
            // deb(1);
            b.PB(ele.S.S);
            M[time]=ele.S.S;
            pqq.erase(pqq.begin());
            if(ele.S.F!=(-1) ){
                // deb(2);
                pqq.insert({ele.F+1,{ele.S.F+1,ele.S.S}});
                CT[ele.S.S]--;
                Fuck[ele.S.S]=ele.F+1;
            }
            else{
                CT[ele.S.S]=0;
            }
            // deb(3);
        }
        else{
            // deb(4);
            if(CT[M[time-gap-1]]!=0){
                // deb(5);
                b.PB(M[time-gap-1]);
                M[time]=M[time-gap-1];
                int yoyo=M[time];
                // deb(yoyo);
                auto Ele = (pqq.find({Fuck[yoyo],{-CT[yoyo],yoyo}}));
                auto ele = *(Ele);
                pqq.erase(Ele);
                if(ele.S.F!=(-1) ){
                    // deb(6);
                    pqq.insert({ele.F+1,{ele.S.F+1,ele.S.S}});
                    CT[ele.S.S]--;
                    Fuck[ele.S.S]=ele.F+1;
                }
                else{
                    CT[ele.S.S]=0;
                }
                // deb(7);

            }
            else{
                // deb(8);
                b.PB(ele.S.S);
                M[time]=ele.S.S;
                pqq.erase(pqq.begin());
                if(ele.S.F!=(-1) ){
                    // deb(9);
                    pqq.insert({ele.F+1,{ele.S.F+1,ele.S.S}});
                    CT[ele.S.S]--;
                    Fuck[ele.S.S]=ele.F+1;
                }
                else{
                    CT[ele.S.S]=0;
                }
                // deb(10);
            }
            // deb(11);
        }
        time++;
    }
    // pos.clear();
    // while(Q.size()!=0){
    //     auto ele = Q.front();
    //     Q.pop();
    //     if(pos[ele.F]!=pos.end()){
            
    //     }
    //     b.PB(ele.F);

    //     if(ele.S!=1){
    //         Q.push({ele.F, ele.S-1});
    //     }
    // }
    pos.clear();
    deb(b);
    int ans = 1e18;
    for(int i=0;i<b.size();i++){
            if(pos.find(b[i])!=pos.end()){
                ans=min(ans,i-pos[b[i]]-1);
            }
            pos[b[i]]=i;
    }
    deb(ans);
    return ans>=gap;

}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        MAXI = 1e17;
        a.resize(n);
        ct.clear();
        pos.clear();
        fuck.clear();
        // pq = priority_queue <pair<int, pair<int, int> > >();
        pq.clear();
        REP(i,0,n){
            cin>>a[i];
            ct[a[i]]++;
        }
        for(auto g:ct){
            pq.insert({-MAXI,{-g.S, g.F} });
            fuck[g.F]=-MAXI;
            // MAXI--;
        }
        deb(ct);
        b.clear();
        int ans = 0;
        int l =0, r= n-2;
        while(l<=r){
            MAXI = 1e17;
            int mid = (l+r)/2;
            // deb(mid);
            if(can(mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        cout<<ans<<"\n";
        // // deb(ct);
        // while(pq.size() != 0){
        //     auto ele = pq.top();
        //     pq.pop();
        //     b.PB(ele.S.S);
        //     if(ele.S.F != 1){
        //         pq.push({ele.F-1,{ ele.S.F-1,ele.S.S} });
        //         // MAXI--;
        //     }
        // }
        // int ans = 1e18;
        // // deb(b);
        // for(int i=0;i<n;i++){
        //     if(pos.find(b[i])!=pos.end()){
        //         ans=min(ans,i-pos[b[i]]-1);
        //     }
        //     pos[b[i]]=i;
        // }
        // cout<<ans<<"\n";




    }

    return 0;
}