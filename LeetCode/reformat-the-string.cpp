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

class Solution {
public:
    string reformat(string s) {
        int cc=0, nn=0;
        string C="", N="";
        string ans="";
        for(auto g:s){
            if(g>='0' && g<='9'){
                nn++;
                N+=g;
            }
            else{
                cc++;
                C+=g;
            }
        }
        deb(C);
        deb(N);
        deb(cc);
        deb(nn);
        if(abs(nn-cc)>1){
            string ans="";
            return ans;
        }
        else{
            if(nn==cc){
                int I=0, J=0;
                for(int i=0;i<s.size();i++){
                    if(i%2==0){
                        ans+=N[I];
                        I++;
                    }
                    else{
                        ans+=C[J];
                        J++;
                    }
                }
            }
            else{
                if(nn>cc){
                    int I=0, J=0;
                for(int i=0;i<s.size();i++){
                    if(i%2==0){
                        ans+=N[I];
                        I++;
                    }
                    else{
                        ans+=C[J];
                        J++;
                    }
                }
                }
                else{
                    int I=0, J=0;
                for(int i=0;i<s.size();i++){
                    if(i%2==0){
                        ans+=C[I];
                        I++;
                    }
                    else{
                        ans+=N[J];
                        J++;
                    }
                }
                }
            }
            
        }
        return ans;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    Solution S;
    deb(S.reformat("ab123"));

    return 0;
}