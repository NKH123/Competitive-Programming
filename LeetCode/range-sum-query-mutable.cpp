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
    vector<int>T;
    vector<int>nums;

    int build(int v, int l, int r){
        cout<<"---"<<" "<<v<<" "<<l<<" "<<r<<"\n";
        if(l>r){
            return 0;
        }
        else if(l==r){
            T[v]=nums[l];
        }
        else{
            int mid=(l+r)/2;
            T[v]=build(2*v,l,mid)+build(2*v+1,mid+1,r);
            deb(v);
            deb(T[v]);
            return T[v];
        }
        return T[v];
    }
    void Update(int v, int l, int r, int ind, int val){
        if(l>r){
            return;
        }
        else{
            if(l==r){
                nums[l]=val;
                T[v]=nums[l];
            }
            else{
                int mid=(l+r)/2;
                if(ind<=mid){
                    Update(2*v,l,mid,ind,val);
                }
                else{
                    Update(2*v+1,mid+1,r,ind,val);
                }
                T[v]=T[2*v]+T[2*v+1];
            }
        }
    }
    int query(int v, int sl, int sr, int l, int r){
        cout<<v<<" "<<sl<<" "<<sr<<" "<<l<<" "<<r<<"\n";
        if(sl>sr || l>r){
            return 0;
        }
        else if(sl>=l && sr<=r){
            return T[v];
        }
        else if(sl>r || sr<l){
            return 0;
        }
        else{
            int mid=(sl+sr)/2;
            int ans=query(2*v,sl,mid,l,min(r,mid))+query(2*v+1,mid+1,sr,max(mid+1,l),r);
            return ans;
        }
    }
    NumArray(vector<int>& A) {
        nums=A;
        deb(nums);
        T.clear();
        T.resize(4*nums.size()+5);
        build(1,0,nums.size()-1);
        deb(T);
    }
    
    void update(int i, int val) {
        Update(1,0,nums.size()-1,i,val);
        deb(T);
    }
    
    int sumRange(int i, int j) {
        deb(T);
        return query(1,0,nums.size()-1,i,j);
    }
};


int32_t main(){
    ios::sync_with_stdio(false);
    vi a={0,9,5,7,3};
    NumArray* obj=new NumArray(a);
    deb(obj->sumRange(4,4));
    deb(obj->sumRange(2,4));
    deb(obj->sumRange(3,3));
    // obj->update(0,3);
    // deb(obj->sumRange(1,1));
    // deb(obj->sumRange(0,1));
    // deb(obj->sumRange(0,2)); 

    return 0;
}