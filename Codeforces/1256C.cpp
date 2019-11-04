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



int32_t main(){
    ios::sync_with_stdio(false);
    int n, m, d;
    cin>>n>>m>>d;
    vi c;
    c.resize(m);
    REP(i,0,m){
        cin>>c[i];
    }
    int f=1;
    int cur=0;
    vi pref(m);
    pref[m-1]=c[m-1];
    for(int i=m-2;i>=0;i--){
        pref[i]=pref[i+1]+c[i];
    }
    pref.PB(0);
    // deb(c);
    // deb(pref);
    int I=0;
    vi pp(m);
    while(I<m){
        // deb(I);
        // deb(cur);
        int canr=cur+d;
        //extreme right
        int sum=pref[I+1];
        int rend=n+1-sum;
        int lend=rend-c[I];
        // deb(sum);
        // deb(rend);
        // deb(lend);
        // deb(canr);
        // deb(lend);
        int put=min(canr,lend);

        pp[I]=put;
        cur=put;
        cur+=(c[I]-1);
        I++;

        
    }
    // deb(pp);
    int canl=cur;
    int canr=cur+d;
    pp.PB(1e18);
    // deb(cur);
    if((n+1)>=canl && (n+1)<=canr){
        cout<<"YES\n";
        int next=0;
        for(int i=1;i<=(n);i++){
            // deb(i);
            if(i==pp[next]){
                int temp=0;
                for(int j=0;j<c[next];j++){
                    cout<<(next+1)<<" ";
                    temp=i+j;
                }
                i=temp;


                //update next
                next++;
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<"\n";
    }
    else{
        cout<<"NO\n";
    }

return 0;
}