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

bool comp(pi A, pi B){
    return A.F>B.F;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int n, v;
    cin>>n>>v;
    vector<pair<int, int> > ones, twos;
    for(int i=0;i<n;i++){
        int t, A;
        cin>>t>>A;
        if(t==1){
            ones.PB({A,i+1});
        }
        else{
            twos.PB({A,i+1});
        }
    }
    if(ones.size()!=0)
    sort(ones.begin(),ones.end(),comp);
    if(twos.size()!=0)
    sort(twos.begin(),twos.end(),comp);
    vi one_pre(ones.size(),0);
    vi two_pre(twos.size(),0);
    for(int i=0;i<ones.size();i++){
        if(i==0){
            one_pre[i]=ones[i].F;
        }
        else{
            one_pre[i]=one_pre[i-1]+ones[i].F;
        }
    }
    for(int i=0;i<twos.size();i++){
        if(i==0){
            two_pre[i]=twos[i].F;
        }   
        else{
            two_pre[i]=twos[i].F+two_pre[i-1];
        }
    }
    int ans=0;
    int Limit=min(v,(int)ones.size());
    if(Limit!=0)
    ans=one_pre[Limit-1];
    int cut=-1;
    for(int i=0;i<twos.size();i++){
        int take=i+1;
        int temp=two_pre[i];
        int rem=v-(take*2);
        if(rem<0)continue;
        int Limit=min(rem,(int)ones.size());
        if(Limit!=0)
        temp=temp+one_pre[Limit-1];
        if(temp>ans){
            cut=i;
        }
        ans=max(ans,temp);
    }
    cout<<ans<<"\n";
    // deb(cut);
    if(cut==-1){
        int Limit=min(v,(int)ones.size());
        if(Limit!=0)
        for(int i=0;i<Limit;i++){
            cout<<ones[i].S<<" ";
        }
        cout<<"\n";

    }
    else{
        for(int i=0;i<=cut;i++){
            cout<<twos[i].S<<" ";
        }
        int rem=v-((cut+1)*2);
        int Limit=0;
        if(rem>0)
        Limit=min(rem,(int)ones.size());
        if(Limit>0){
            for(int i=0;i<Limit;i++){
                cout<<ones[i].S<<" ";
            }
            
        }
        cout<<"\n";
    }
    return 0;
}

