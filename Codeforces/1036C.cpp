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
vector<int>no;
vi N;
map<pair<pair<int, int>,int >,int>DP;
map<int, int>ddp;
int fun(int ct, int small, int pos){
    if(ct==3){
        return 1;
    }
    if(pos==(no.size())){
        if(ct<=3){
            return 1;
        }
    }
    if(DP.count({{ct,small},pos})!=0){
        return DP[{{ct,small},pos}];
    }
    int ans=0;
    if(small==1){
        for(int i=0;i<=9;i++){
            // deb(i);
            if(i!=0){
                N.PB(i);
                ans+=fun(ct+1,1,pos+1);
                N.pop_back();
            }
            else{
                N.PB(0);
                ans+=fun(ct,1,pos+1);
                N.pop_back();
            }
        }
    }
    else{
        // deb(pos);
        // deb(no[pos]);
        for(int i=0;i<=9;i++){
            if(i!=0){
                // deb(i);
                if(i<no[pos]){
                    N.PB(i);
                    // deb(i);
                    ans+=fun(ct+1,1,pos+1);
                    N.pop_back();
                }
                else if(i==no[pos]){
                    N.PB(i);
                    ans+=fun(ct+1,0,pos+1);
                    N.pop_back();
                }
            }
            else{
                N.PB(i);
                if(no[pos]==0)
                ans+=fun(ct,0,pos+1);
                else{
                    ans+=fun(ct,1,pos+1);
                }
                N.pop_back();
            }
        }
    }
    return DP[{{ct,small},pos}]=ans;
}

int Fun(int R){
    if(ddp.count(R)!=0){
        return ddp[R];
    }
    if(R==0){
        return ddp[0]=1;
    }
    DP.clear();
    // deb(R);
    // deb(R);
    no.clear();
    int r=R;
    while(r>0){
        no.push_back((r%10));
        r=r/10;
    }
    reverse(no.begin(),no.end());
    // deb(no);
    // deb(no);
    N.clear();
    return ddp[R]=fun(0,0,0);
}
int32_t main(){
    ios::sync_with_stdio(false);

    int T;
    cin>>T;
    // deb(T);
    while(T--){
        int L, R;
        cin>>L>>R;
        // deb(Fun(1000));
        // deb(Fun(1));
        int ans=Fun(R)-Fun(L-1);
        cout<<ans<<"\n";
    }


    return 0;
}