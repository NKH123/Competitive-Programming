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
    string add(string s){
        string ans;
        ans=s;
        int car=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1' && car==1){
                ans[i]='0';
                car=1;
            }
            else if(s[i]=='1' && car==0){
                ans[i]='1';
            }
            else if(s[i]=='0' && car==0){
                ans[i]='0';
            }
            else if(s[i]=='0' && car==1){
                ans[i]='1';
                car=0;
            }
            
        }
        if(car==1){
            ans="1"+ans;
        }
        return ans;
    }
    
    int numSteps(string s) {
        int st=0;
        while(s!="1"){
            deb(s);
            if(s[s.size()-1]==0){
                string ans="";
                for(int i=0;i<s.size()-1;i++){
                    ans+=s[i];
                }
                s=ans;
            }
            else{
                s=add(s);
            }
                 st++;   
        }
        return st;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    Solution S;
    cout<<S.numSteps("10")<<"\n";

    return 0;
}