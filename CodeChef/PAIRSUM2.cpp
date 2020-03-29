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



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi b;
    vi pref;
    vi B;
    while(t--){
        int n, Q;
        cin>>n>>Q;
        b.clear();
        B.clear();
        pref.clear();
        b.resize(n-1);
        B.resize(n-1);
        pref.resize(n-1);
        REP(i,0,n-1){
            cin>>b[i];
            if(i%2==0){
                B[i]=b[i];
            }
            else{
                B[i]=-b[i];
            }
        }
        // pref[0]=b[0];
        // for(int i=1)
        for(int i=0;i<(n-1);i++){
            if(i==0){
                pref[i]=B[i];
            }
            else{
                pref[i]=B[i]+pref[i-1];
            }
        }
        while(Q--){
            int p, q;
            cin>>p>>q;

            int diff=abs(p-q);
            if(diff%2==0){
                cout<<"UNKNOWN\n";
            }
            else{
                if(diff==1){
                    int ind=min(p,q);
                    ind--;
                    cout<<b[ind]<<"\n";
                }
                else{
                    if(p>q){
                        swap(p,q);
                    }
                    int start=p-1;
                    int end=q-2;
                    int ans=b[start]+b[end];
                    //now subtract
                    int sub=pref[end-1]-pref[start];
                    if((start+1)%2==1){

                    }
                    else{
                        sub=-sub;
                    }
                    ans+=sub;
                    cout<<ans<<"\n";
                }
            }
        }
    }



    return 0;
}