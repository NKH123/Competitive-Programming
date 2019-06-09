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
int n;
vi b;
const int MAX=3000000;
map<int,int>pos;
vector<bool>prime(MAX+1,true);
int mm[MAX];
void pre(){
    prime[1]=false;
    prime[0]=true;
    int ct=1;
    for(int i=2;i<=MAX;i++){
        if(prime[i]==true){
            pos[i]=ct;
            ct++;
            for(int j=i*i;j<=MAX;j+=i){
                prime[j]=false;
            }
        }
    }
}
bool comp (int A, int B){
    return A>B;
}

int32_t main(){
	ios::sync_with_stdio(false);
    memset(mm,0,sizeof(mm));
    cin>>n;  
    b.resize(2*n);
    REP(i,0,2*n){
        cin>>b[i];
        mm[b[i]]++;
    }
    pre();
    vi a;
    sort(b.begin(),b.end(),comp);
    for(int i=0;i<2*n;i++){
        if(prime[b[i]]){
            if(mm[b[i]]==0)continue;
            int poss=pos[b[i]];
            if(prime[poss]){
                if(mm[poss]>0){
                    a.PB(poss);
                    mm[poss]--;
                    mm[b[i]]--;
                }

            }
        }
        else{
            if(mm[b[i]]==0)continue;
            int gd=0;
            for(auto g:pos){
                if((b[i]%(g.F))==0){
                    gd=b[i]/g.F;
                    break;
                }
            }
            if(mm[gd]>0){
                a.PB(b[i]);
                mm[b[i]]--;
                mm[gd]--;
            }
        }
    }
    REP(i,0,a.size()){
        cout<<a[i]<<" ";
    }
    cout<<"\n";

    return 0;
}