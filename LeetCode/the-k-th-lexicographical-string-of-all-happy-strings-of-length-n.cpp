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

#define //deb(x) cerr << #x << " = " << x << endl;

class Solution {
public:
    vector<string>S;
    int N;
    string s;
    void gen(int i){
        if(i>10){
            exit(0);
        }
        //deb(N);
        //deb(i);
        //deb(s);
        if(i==N){
                S.push_back(s);
                // s=s.substr(0,s.size()-1);
        }
        else {
                if(s.size()==0){
                    s=s+'a';
                    gen(1);
                    s=s.substr(0,s.size()-1);
                    s=s+'b';
                    gen(1);
                    s=s.substr(0,s.size()-1);
                    s=s+'c';
                    gen(1);
                    s=s.substr(0,s.size()-1);
                }
            else{
                if(s[s.size()-1]=='a'){
                    s+='b';
                    gen(i+1);
                    s=s.substr(0,s.size()-1);
                    s+='c';
                    gen(i+1);
                    s=s.substr(0,s.size()-1);
                }
                else if(s[s.size()-1]=='b'){
                    s+='a';
                    gen(i+1);
                    s=s.substr(0,s.size()-1);
                    s+='c';
                    gen(i+1);
                    s=s.substr(0,s.size()-1);
                }
                else if(s[s.size()-1]=='c'){
                    s+='a';
                    gen(i+1);
                    s=s.substr(0,s.size()-1);
                    s+='b';
                    gen(i+1);
                    s=s.substr(0,s.size()-1);
                }
            }
        }
    }
    
    string getHappyString(int n, int k) {
        N=n;
        string ans="";
        s="";
        gen(0);
        sort(S.begin(),S.end());
        //deb(S);
        if(k>S.size()){
            return ans;
        }
        else{
            return S[k-1];
        }
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    Solution S;
    int n, k;
    cin>>n>>k;
    //deb(S.getHappyString(n,k));

    return 0;
}