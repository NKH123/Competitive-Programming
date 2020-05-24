#include<bits/stdc++.h>
using namespace std;
#define int long long 

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

int power(int a,int b){
    if(b==0)return 1LL;
    int s=power(a,b/2);
    s*=s;
    if(b&1)
        return (s*a);
    return s;
}


signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    int ans=0;
    vector<int> a(n);
    // int max_sm=-1e15;
    for(int i=0;i<n;i++){
        cin>>a[i];
        // max_sm=max(max_sm+a[i],a[i]);
    }

    map<int,int> m;
    int s=0;
    for(int i=0;i<n;i++){
        s+=a[i];
        int val=1;
        if(k!=1 && k!=-1){
            while(abs(val)<=(1e18)){
                if(val==(s))ans++;
                ans+=m[s-val];
                val=val*k;
            }
        }
        else{
            if(k==1){
                val=1;
                if(val==(s))ans++;
                ans+=m[s-val];
            }
            else{
                val=1;
                if(val==(s))ans++;
                ans+=m[s-val];
                val=-1;
                if(val==(s))ans++;
                ans+=m[s-val];
            }
        }
        m[s]++;
    }
    cout<<ans<<"\n";

}


