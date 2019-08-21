#include<bits/stdc++.h>
using namespace std;

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
    vector<int>a;
    int fun(int N){
        if(N==0){
            return 0;
        }
        else{
            int ans=1e9;
            for(int i=0;i<a.size();i++){
                if(a[i]>N)continue;
                int temp=fun(N-a[i]);
                if(temp==-1)continue;
                ans=min(1+temp,ans);
                
                
            }
            if(ans==1e9){
                return -1;
            }
            else{
                return ans;
            }
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        // a=coins;
        a.resize(coins.size());
        for(int i=0;i<coins.size();i++){
            a[i]=coins[i];
        }
        deb(a);
        int ans=fun(amount);
        return ans; 
        
    }
};
int main(){
    Solution S;
    vector<int>a={2};
deb(a);
    int ans=S.coinChange(a,3);
    deb(ans);
    return 0;
}