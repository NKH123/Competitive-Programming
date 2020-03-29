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
    vi a;
    vi b;
    vi ans;
    vi aans;
    while(t--){
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        b.clear();
        int f=0;
        REP(i,0,n){
            cin>>a[i];
            if(i==0){
                b.PB(a[i]);
            }
            else if(a[i]!=a[i-1]){
                b.PB(a[i]);
            }
            else{
                f=1;
            }
        }
        if(b.size()==1){
            cout<<1<<"\n";
            REP(i,0,n){
                cout<<1<<" ";
            }
            cout<<"\n";
            continue;
        }
        aans.clear();
        aans.resize(n);
        REP(i,0,n){
            if(i%2==0){
                aans[i]=1;
            }
            else{
                aans[i]=2;
            }
        }
        if(aans[0]==aans[n-1] && a[0]!=a[n-1]){
            if(f==1){
                // cout<<2<<"\n";
                int I;
                for(int i=1;i<n;i++){
                    if(a[i]==a[i-1]){
                        I=i;

                    }
                }
                for(int i=I;i<n;i++){
                    if(i==I){
                        if(aans[i-1]==2){
                            aans[i]=2;
                        }
                        else{
                            aans[i]=1;
                        }
                    }
                    else{
                        if(aans[i-1]==2){
                            aans[i]=1;
                        }
                        else{
                            aans[i]=2;
                        }
                    }
                }
            }
            else{
                // cout<<3<<"\n";
                aans[n-1]=3;

            }
            int Ans=0;
            REP(i,0,n){
                Ans=max(Ans,aans[i]);
            }
            cout<<Ans<<"\n";
            REP(i,0,n){
                cout<<aans[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<2<<"\n";
            REP(i,0,n){
                cout<<aans[i]<<" ";
            }
            cout<<"\n";
        }

    }

    return 0;
}