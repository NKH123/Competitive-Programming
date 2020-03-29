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
    int t;
    cin>>t;
    vector<pair<int, int> >ab;
    vector<char>ss;
    vi used;
    while(t--){
        int n;
        cin>>n;
        ab.clear();
        ab.resize(n);
        int X=0, Y=0;
        used.clear();
        REP(i,0,n){
            cin>>ab[i].F>>ab[i].S;
        }
        used.resize(n,0);
        int f=1;
        int ct=n;
        // string s="";
        ss.clear();
        int tempx=0, tempy=0;
        while(ct--){
            // deb("heree");
            // deb(ct);
            // deb(used);
            int smallX=1e18, smallY=1e18;
            int cur=1e18;
            int I;
            // deb(used);
            for(int i=0;i<n;i++){
                if(used[i]==1){
                    continue;
                }
                int manx=ab[i].F-X;
                int many=ab[i].S-Y;

                if(manx<0 || many<0){
                    f=0;
                }
                else{
                    if(cur>(manx+many)){
                        cur=(manx+many);
                        tempx=ab[i].F;
                        tempy=ab[i].S;
                        smallX=manx;
                        smallY=many;
                        I=i;
                    }
                    // }
                }
            }
            // deb(ct);
            // deb(used);
            if(f==0){
                break;
            }
            else{
                X=tempx;
                Y=tempy;
                used[I]=1;
                // deb(smallX);
                // deb(smallY);
                for(int i=0;i<smallX;i++){
                    ss.PB('R');
                }
                for(int i=0;i<smallY;i++){
                    // cout<<"U";
                    ss.PB('U');
                }
                // cout<<"\n";
            }
            // deb(ct);
            // ct++;
        }
        if(f==0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            REP(i,0,(int)ss.size()){
                // deb("yo");
                cout<<ss[i];
            }
            cout<<"\n";
        }

    }

    return 0;
}