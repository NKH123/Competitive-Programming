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

int n;
vi a;
map<int, int>Ct;
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n;
    a.resize(n);
    vi b;
    b.resize(n);
    REP(i,0,n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b.begin(),b.end());
    set<int>cd;
    for(int i=1;i<n;i++){
        cd.insert(b[i]-b[i-1]);
        Ct[b[i]-b[i-1]]++;
    }
    deb(cd);
    deb(b);
    // if(cd.size()>3){
    //     cout<<"-1\n";
    //     return 0;
    // }
    int f=0;
    for(auto g:Ct){
        if(g>1 && f==2){
            cout<<"-1\n";
            return 0;
        }
        if(g>1 && f==1){
            f=2;
            // cout<<"-1\n";
            // return 0;
        }
        if(g>1 && f==0){
            f=1;
        }

    }
    if(cd.size()==1){
        for(int i=0;i<n;i++){
            if(a[i]==b[0]){
                cout<<i+1<<"\n";
                return 0;
            }
        }
    }
    else if(cd.size()==2){
        int CD=b[2]-b[1];
        int f=0;
        for(int i=2;i<n;i++){
            if(CD!=(b[i]-b[i-1])){

            }
        }



    }
    else if(cd.size()==3){
        vi CD;
        for(auto g:cd){
            CD.PB(g);
        }
        map<int, int>M;
        for(int i=1;i<n;i++){
            M[b[i]-b[i-1]]++;
        }
        int J=-1;
        for(int i=0;i<3;i++){
            if(M[CD[i]]==1){
                J=i;
                break;
            }
        }
        int ind=-1;
        for(int i=1;i<n-1;i++){
            if(((b[i]-b[i-1])==(b[i+1]-b[i]))==CD[J]){
                ind=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]==b[ind]){
                cout<<i+1<<"\n";
                return 0;
            }
        }
    }




    return 0;
}