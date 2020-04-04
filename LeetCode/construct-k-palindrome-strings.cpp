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
    bool canConstruct(string s, int k) {
        int ans=0;
        // int a[26];
        vector<int>a(26);
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        if(s.size()==k){
            return true;
        }
        else if(s.size()<k){
            return false;
        }
        deb(a);
            int f=0;
            for(int i=0;i<26;i++){
                if(a[i]%2==0){
                    
                }
                else{
                    f++;
                }
            }
            deb(f);
            if(f==0){
                return true;
            }
            else{
                return k>=f;
            }
        
        
    }
};
int32_t main(){
    ios::sync_with_stdio(false);
    Solution S;
    deb(S.canConstruct("annabelle",2));

    return 0;
}