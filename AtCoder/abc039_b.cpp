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
#define MAXN 200005
int getSum(int BITree[], int index) 
{ 
    int sum = 0; // Initialize result 
  
    // Traverse ancestors of BITree[index] 
    while (index > 0) { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates a node in Binary Index Tree (BITree) at 
// given index in BITree.  The given value 'val' is  
// added to BITree[i] and all of its ancestors in  
// tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    // Traverse all ancestors and add 'val' 
    while (index <= n) { 
        // Add 'val' to current node of BI Tree 
        BITree[index] += val; 
  
        // Update index to that of parent  
        // in update View 
        index += index & (-index); 
    } 
} 
  
// Converts an array to an array with values from 1 to n 
// and relative order of smaller and greater elements  
// remains same.  For example, {7, -90, 100, 1} is  
// converted to {3, 1, 4, 2 } 
void convert(vi &arr, int n) 
{ 
    // Create a copy of arrp[] in temp and sort  
    // the temp array in increasing order 
    int temp[n]; 
    for (int i = 0; i < n; i++) 
        temp[i] = arr[i]; 
    sort(temp, temp + n); 
  
    // Traverse all array elements 
    for (int i = 0; i < n; i++) { 
  
        // lower_bound() Returns pointer to 
        //  the first element greater than  
        // or equal to arr[i] 
        arr[i] = lower_bound(temp, temp + n,  
                         arr[i]) - temp + 1; 
    } 
} 
  
// Returns inversion count of all subarray  
// of size k in arr[0..n-1] 
int getInvCount(vi &arr, int k, int n) 
{ 
    int invcount = 0; // Initialize result 
  
    // Convert arr[] to an array with values from  
    // 1 to n and relative order of smaller and  
    // greater elements remains same.  For example,  
    // {7, -90, 100, 1} is converted to {3, 1, 4, 2 } 
    // convert(arr, n); 
  
    // Create a BIT with size equal to maxElement+1  
    // (Extra one is used so that elements can be 
    // directly be used as index) 
    int BIT[n + 1]; 
    for (int i = 0; i <= n; i++) 
        BIT[i] = 0; 
  
    // Get inversion count of first subarray 
    for (int i = k - 1; i >= 0; i--) { 
  
        // Get count of elements smaller than arr[i] 
        invcount += getSum(BIT, arr[i] - 1); 
  
        // Add current element to BIT 
        updateBIT(BIT, n, arr[i], 1); 
    } 
  
    // now calculate the inversion of all other subarrays 
    // int ans = invcount;
    int ans=0;
    if(invcount>0){
        ans=1;
    } 
    int i = 0, j = k, icnt = 0, jcnt = 0; 
    while (j <= n - 1) { 
  
        // calculate value of inversion count of first element 
        // in previous subarray 
         if(jcnt>0 || icnt>0 ){
            ans++;
        }
        icnt = getSum(BIT, arr[i] - 1); 
        updateBIT(BIT, n, arr[i], -1); 
  
        // calculating inversion count of last element in the 
        // current subarray 
        jcnt = getSum(BIT, n) - getSum(BIT, arr[j]); 
        updateBIT(BIT, n, arr[j], 1); 
  
        // calculating inversion count of current subarray 
        invcount = invcount - icnt + jcnt; 
  
        // adding current inversion to the answer 
        // ans = ans + invcount;  
        // if((jcnt-icnt)>0){
        //     ans++;
        // }
        deb(i);
        deb(j);
        deb(icnt);
        deb(jcnt);
        deb("**************");
       
        i++, j++; 
    } 
     if(jcnt>0 || icnt>0 ){
            ans++;
        }
    return ans; 
} 


int32_t main(){
    ios::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    vi p(n);
    REP(i,0,n){
        cin>>p[i];
        p[i]++;
    }
    // int ans=0;
    vi arr=p;
    int ans=getInvCount(arr,k,n);
    if(ans==0)
    ans++;

    cout<<ans<<"\n";


    return 0;
}