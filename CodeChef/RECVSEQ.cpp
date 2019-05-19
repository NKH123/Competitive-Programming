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
#define llp 1000000007
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
    vi a;
    // vector<int>s(3);
    // vector<int> AA(3);
    while(t--){

     int n;
     cin>>n;
     a.resize(n);
     REP(i,0,n)cin>>a[i];
     set<int>s;
     s.clear();
     for(int i=1;i<n;i++){
        s.insert(a[i]-a[i-1]);
    }
    vi ff;
    ff.clear();

    for(auto g:s){
        // deb(g);
        ff.clear();
        ff.resize(n,0);
        REP(i,1,n){
            if((a[i]-a[i-1])!=g){
                ff[i]=1;
            }
        }
        int ct=0;
        for(int i=0;i<n;i++){
            if(ff[i]==1){
                ct++;
            }
        }
        // deb(ff);
        // deb(ct);
        if(ct>2){
            continue;
        }
        else{
            if(ct==2){
                int f=1;
                for(int i=1;i<n;i++){
                    if((a[i]-a[i-1])!=g){
                        int temp=a[i-1]+g;
                        if(i!=(n-1) && a[i+1]-temp!=g){
                            f=0;
                            break;
                        }
                        else{
                            a[i]=a[i-1]+g;
                            break;
                        }
                    }
                }
                if(f==0){
                    continue;
                }
            }
        else{
            if((a[1]-a[0])!=g){
                a[0]=a[1]-g;
            }
            else{
                a[n-1]=a[n-2]+g;
            }
        }
        break;
    }

}
REP(i,0,n){
    cout<<a[i]<<" ";
}
cout<<"\n";
}



return 0;
}