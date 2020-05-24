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
    for( it = v.begin(); it != v.end();  it++ ) {
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


struct comp{
    bool operator()(const pair<int, int> A,const pair<int, int> B)const{
        int gap1=A.S-A.F;
        int gap2=B.S-B.F;
        if(gap1>gap2){
            return true;
        }
        else if(gap2>gap1){
            return false;
        }
        else{
            if(A.F<B.F){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
void print(set<pair<int, int>, comp >intervals){
    cout<<"[ \n";
    for(auto g:intervals){
        cout<<g.F<<" "<<g.S<<"\n";
    }
    cout<<" ]\n";
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int q;
    cin>>q;
    set<pair<int, int>, comp >intervals;
    map<int, int> Left;
    map<int, int> Right;
    map<int, int>place;
    intervals.insert({1,n});
    int cur=0;
    Right[1]=n;
    Left[n]=1;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            cur++;
            auto Int=*(intervals.begin());
            int A=Int.F;
            int B=Int.S;
            int gap=Int.S-Int.F;
            int pos=Int.F+(gap)/2;
            if(A==0){
                pos=1;
            }
            if(B==(n+1)){
                pos=n;
            }
            place[cur]=pos;
            cout<<pos<<"\n";
            intervals.erase(intervals.begin());
            intervals.insert({A,pos});
            intervals.insert({pos,B});
            Right[A]=pos;
            Left[B]=pos;
            Left[pos]=A;
            Right[pos]=B;
        }       
        else{
            int X;
            cin>>X;
            int x=place[X];
            int xr=Right[x];
            int xl=Left[x];
            if(intervals.find({x,xr})!=intervals.end())
                intervals.erase(intervals.find({x,xr}));
            if(intervals.find({xl,x})!=intervals.end())
                intervals.erase(intervals.find({xl,x}));
            intervals.insert({xl,xr});
            place[X]=0;
            Right[x]=0;
            Left[x]=0;
            Right[xl]=xr;
            Left[xr]=xl;
        }
    }
    return 0;
}