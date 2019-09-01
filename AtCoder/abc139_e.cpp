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


int a[1005][1005];
map<int,int>Now;
map<int,set<int> >inter;
set<pair<int, int> >used;
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int ini=0;
    int f=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){

            cin>>a[i][j];
            if(j==1){
                Now[i]=1;
                inter[a[i][j]].insert(i);
                if(inter[i].find(a[i][j])!=inter[i].end()){
                    f=1;
                    if(used.find({min(i,a[i][j]),max(i,a[i][j])})==used.end()){
                        ini++;
                        used.insert({min(i,a[i][j]),max(i,a[i][j])});
                    }
                }
            }
        }
    }
    int day=0;
    int Limit=n*(n-1)/2;
    set< pair<int, int > >Used;
    int ct=0;
    while(1){
        if(used.size()==0){
            break;
        }
        else{
            day++;
            for(auto g:used){
                int I=g.F;
                int J=g.S;
                Now[I]++;
                Now[J]++;
                ct++;
                if(Now[I]<(n)){
                    inter[a[I][Now[I]] ].insert(I);
                    if(inter[I].find(a[I][Now[I]])!=inter[I].end()){
                        if(Used.find({min(I,a[I][Now[I]]),max(I,a[I][Now[I]])})==Used.end()){
                            Used.insert({min(I,a[I][Now[I]]),max(I,a[I][Now[I]])});
                        }
                    }
                }
                if(Now[J]<n){
                    inter[a[J][Now[J]] ].insert(J);
                    if(inter[J].find(a[J][Now[J]])!=inter[J].end()){
                        if(Used.find({min(J,a[J][Now[J]]),max(J,a[J][Now[J]])})==Used.end()){
                            Used.insert({min(J,a[J][Now[J]]),max(J,a[J][Now[J]])});
                        }
                    }
                }

            }
            used.clear();
            used=Used;
            Used.clear();
        }
    }
    if(ct==(Limit))
        cout<<day<<"\n";
    else{
        cout<<-1<<"\n";
    }





    return 0;
}