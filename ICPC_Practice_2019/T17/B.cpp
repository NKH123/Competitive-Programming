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
    int n;
    cin>>n;
    vi a(n);
    int maxDegree=0;
    REP(i,0,n){
        cin>>a[i];
        maxDegree+=a[i];
    }
    if(maxDegree<(2*n-2)){
        cout<<"NO\n";
        return 0;
    }
    vector<int>ones;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            ones.PB(i);
        }
    }
    int Diameter=n-1-ones.size();
    if(ones.size()>2){
        Diameter+=2;
    }
    else{
        Diameter+=ones.size();
    }
    int I=0;
    vector<int>twos;
    for(int i=0;i<n;i++){
        if(a[i]>=2){
            twos.push_back(i);
        }
    }
    vector<pair<int, int> >edges;
    int first=twos[0];
    int last=twos[0];
    for(int i=1;i<twos.size();i++){
        int A=twos[i-1];
        int B=twos[i];
        a[A]--;
        a[B]--;
        edges.PB({twos[i-1],twos[i]});
        last=twos[i];
    }
    if(ones.size()==0){
        //do nothing
    }
    else if(ones.size()==1){
        edges.PB({twos[0],ones[0]});
        a[twos[0]]--;
        a[ones[0]]--;

    }
    else{
       edges.PB({twos[0],ones[0]});
       a[twos[0]]--;
       a[ones[0]]--;
       edges.PB({last,ones[1]});
       a[ones[1]]--;
       a[last]--;
       int I=2;
       for(int i=0;i<twos.size();i++){
            if(I<ones.size()){
                while(a[twos[i]]>0){
                    edges.PB({twos[i],ones[I]});
                    a[ones[I]]--;
                    a[twos[i]]--;
                    I++;
                    if(I==ones.size()){
                        break;
                    }
                }
            }
       }
   }
   cout<<"YES "<<Diameter<<"\n";
   cout<<edges.size()<<"\n";
   for(int i=0;i<edges.size();i++){
        cout<<edges[i].F+1<<" "<<edges[i].S+1<<"\n";
   }







   return 0;
}