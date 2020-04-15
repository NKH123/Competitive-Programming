#include<bits/stdc++.h>
#define int long long
using namespace std;

// #define //deb(x) cerr << #x << " = " << x << endl;

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

// #define //deb(x) cerr << #x << " = " << x << endl;

vector<int> r;
vector<int> g;
vector<int> b;
int ans=4*(1e18);
int getans(vector<int> A, vector<int> B, vector<int> C){
    // ans=min(ans,A[0]*B[0]*C[0]);
    int X, Y, Z;
    X=A[0];
    Y=B[0];
    Z=C[0];


    ans=min(ans,(X-Y)*(X-Y)+(Y-Z)*(Y-Z)+(X-Z)*(X-Z));
    // int ll[3];
    // int rr[3];
    vector<int>ll(3);
    vector<int>rr(3);
    //deb(ans);
    //deb("*******************************");
    //deb(A);
    //deb(B);
    //deb(C);
    for(int i=0;i<B.size();i++){
        //deb("***");
        ll[0]=-1, ll[1]=-1, ll[2]=-1;
         rr[0]=-1, rr[1]=-1, rr[2]=-1;
        ll[0]=lower_bound(A.begin(),A.end(),B[i])-A.begin();
        if(ll[0]==A.size()){
            // ll[0]=-1;
            ll[0]--;
        }
        if(ll[0]==0){
            if(A[0]>B[i]){
                ll[0]=-1;
            }
        }
        else{
            ll[0]--;
        }
        ll[1]=lower_bound(A.begin(),A.end(),B[i])-A.begin();
        if(ll[1]==A.size()){
            // ll[0]=-1;
            ll[1]--;
        }
        ll[2]=upper_bound(A.begin(),A.end(),B[i])-A.begin();
        if(ll[2]==A.size()){
            // ll[0]=-1;
            ll[2]--;
        }
        rr[0]=lower_bound(C.begin(),C.end(),B[i])-C.begin();
        if(rr[0]==C.size()){
            // ll[0]=-1;
            rr[0]--;
        }
        if(rr[0]==0){
            if(C[0]>B[i]){
                rr[0]=-1;
            }
        }
        else{
            rr[0]--;
        }
        rr[1]=lower_bound(C.begin(),C.end(),B[i])-C.begin();
        if(rr[1]==C.size()){
            // ll[0]=-1;
            rr[1]--;
        }
        rr[2]=upper_bound(C.begin(),C.end(),B[i])-C.begin();
        if(rr[2]==C.size()){
            // ll[0]=-1;
            rr[2]--;
        }
        //deb(i);
        //deb(ll);
        //deb(rr);
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(ll[j]!=-1 && rr[k]!=-1){
                    // ans=min(ans,B[i]*A[ll[j]]*C[rr[k]]);
                    X=A[ll[j]];
                    Y=B[i];
                    Z=C[rr[k]];
                    ans=min(ans,(X-Y)*(X-Y)+(Y-Z)*(Y-Z)+(X-Z)*(X-Z));
                }
            }
        }
        //deb(ans);






    }


    return ans;

}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ans=4*(1e18);
        int nr, ng, nb;
        cin>>nr>>ng>>nb;
        r.clear();
        r.resize(nr);
        g.clear();
        g.resize(ng);
        b.clear();
        b.resize(nb);
        for(int i=0;i<nr;i++){
            cin>>r[i];
        }
        for(int i=0;i<ng;i++){
            cin>>g[i];
        }
        for(int i=0;i<nb;i++){
            cin>>b[i];
        }
        sort(r.begin(),r.end());
        sort(g.begin(),g.end());
        sort(b.begin(),b.end());
        int ans=getans(r,g,b);
        ans=min(ans,getans(g,r,b));
        ans=min(ans,getans(g,b,r));
        cout<<ans<<"\n";
    }


    return 0;
}