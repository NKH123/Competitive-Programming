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
set<int>ss;
priority_queue<int> us;
set<int>Ans;
int f=0;
void process(int k){
    if(f!=0)
    ss.insert(k);
    else{
        f=1;
    }
    k=k*13*11*7;
    int d[10]={0};
    vi dig;
    while(k>0){
        dig.PB({k%10});
        d[k%10]++;
        k=k/10;
    }
    int ct=0;
    for(int i=0;i<10;i++){
        if(d[i]){
            ct++;
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            for(int k=0;k<6;k++){
                if(i!=j && j!=k && k!=i){
                    if(ss.find(dig[i]*100+dig[j]*10+dig[k])==ss.end()){
                           us.push(dig[i]*100+dig[j]*10+dig[k]);
                           process(dig[i]*100+dig[j]*10+dig[k]);
                       }

                }
            }
        }
    }
}

int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        Ans.clear();
        ss.clear();
        us=priority_queue<int>();
        int k, n;
        cin>>k>>n;
        us.push(k);
        for(int i=0;i<n;i++){
            if(us.size()==0){
                break;
            }
            else{
                k=us.top();
                us.pop();
                process(k);

            }

        }
        cout<<ss.size()<<"\n";
    }




    return 0;
}