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
    int q;
    cin>>q;
    vi a;
    map<int, int>Ct;
    vi b;
    while(q--){
        int n;
        cin>>n;
        a.clear();
        a.resize(4*n);
        Ct.clear();
        int small=1e18;
        int large=-1;
        REP(i,0,4*n){
            cin>>a[i];
            Ct[a[i]]++;
            small=min(small,a[i]);
            large=max(large, a[i]);
        }
        int area=small*large;
        int f=1;
        for(auto g:Ct){
            if((g.S%2)==1){
                f=0;
                break;
            }
            else{
                Ct[g.F]=g.S/2;
            }
        }
        if(f==0){
            cout<<"NO\n";
            continue;
        }
    //     else{
    //         b.clear();
    //         for(auto g:Ct){
    //             b.PB(g.F);
    //         }
    //         for(int i=0;i<b.size();i++){
    //             int l=b[i];
    //             int b=area/b[i];
    //             if((area%b[i]!=0)){
    //                f=0;
    //                break;
    //            }
    //            if(l==b){
    //             if(Ct[l]%2==1){

    //             }
    //            }
    //            else{

    //            }
    //        }
    //        if(f==0){
    //             cout<<"No\n";
    //             continue;
    //         }

    // }
        b.clear();
        for(auto g:Ct){
            for(int i=0;i<g.S;i++){
                b.PB(g.F);
            }
        }
        int l=0, r=b.size()-1;
        while(l<r){
            if((b[l]*b[r])==area){
                l++;
                r--;
            }
            else{
                f=0;
                break;
            }
        }
        if(f==0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }


}




return 0;
}