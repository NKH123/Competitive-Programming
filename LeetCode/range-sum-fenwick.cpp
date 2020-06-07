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
class NumArray {
public:
    vector<int>nums;
    vector<int>T;
    void add(int ind,int val){
        for(int i=ind;i<n;i=(i|()i+1)){
            T[i]+=val;
        }
    }
    int sum(int r){
        if(r<0){
            return 0;
        }
        else{
            int ret=r;
            int ans=0;
            while(ret>=0){
                ans+=T[ret];
                ret=(ret&(ret+1))-1;
            }
            return ans;
        }
    }
    NumArray(vector<int>& A) {
        nums=A;
        T.clear();
        T.resize(nums.size());
        // build(1,0,nums.size()-1,nums);
        for(int i=0;i<A.size();i++){
            nums[i]=A[i];
            add(i,A[i]);
        }
    }
    
    void update(int i, int val) {
        add(i,-nums[i]);
        nums[i]=val;
        add(i,val);
    }
    
    int sumRange(int i, int j) {
        // return query(1,0,nums.size()-1,i,j);
        return sum(r)-sum(l-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */


int32_t main(){
    ios::sync_with_stdio(false);


    return 0;
}