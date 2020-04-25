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
class ValueDivision{
public:
    map<int, int>M;
    vector<int>A;
    bool oned(int x){
        if(M[x]==1){
            return true;
        }
        return false;
    }
    bool one(){
        //deb(M);
        int f=1;
        for(auto g:M){
            if(g.first==1){
                continue;
            }
            if(g.second>1){
                f=0;
            }
        }
        return f==1;
    }
    vector <int> getArray(vector <int> a){
        vector<int>ans;
        ans=a;
        A=a;
        M.clear();
        int n=a.size();
        //deb(1);
        for(auto g:a){
            M[g]++;
        }
        while(!one())
        for(int i=0;i<n;i++){
            //deb(i);
            //deb(a);
            if(a[i]==1){
                continue;
            }
            while(!oned(a[i])){
                //deb(M);
                //deb(a);
                int ct=M[a[i]];
                int lim=ct/2;
                int c=0;
                // //deb(ct);
                // //deb(c);
                // //deb(lim);
                int temp=a[i];
                for(int j=0;j<n;j++){
                    //deb(i);
                    //deb(j);
                    if(a[j]==temp){
                        a[j]--;
                        M[a[j]+1]--;
                        M[a[j]]++;
                        c++;
                    }
                    if(c==lim){
                        break;
                    }
                }
            }
        }



        return a;
    }
};


int32_t main(){
    ios::sync_with_stdio(false);
    vi a;
    int n;
    cin>>n;
    REP(i,0,n){
        int A;
        cin>>A;
        a.PB(A);
    }
    ValueDivision V;
    //deb(V.getArray(a));

    return 0;
}