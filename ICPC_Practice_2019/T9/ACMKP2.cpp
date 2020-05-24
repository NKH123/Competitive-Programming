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
vi arr;
vi temp;

int merge(int left, 
  int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 

            /* this is tricky -- see above  
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 

    /* Copy the remaining elements of left subarray  
(if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 

    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 

    return inv_count; 
} 

int _mergeSort(int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 
        /* Divide the array into two parts and  
        call _mergeSortAndCountInv()  
        for each of the parts */
        mid = (right + left) / 2; 

        /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
        inv_count = _mergeSort( left, mid); 
        inv_count += _mergeSort( mid + 1, right); 

        /*Merge the two parts*/
        inv_count += merge(left, mid + 1, right); 
    } 
    return inv_count; 
} 
int mergeSort( int array_size) 
{ 
    // int temp[array_size]; 
    temp.clear();
    temp.resize(array_size);
    return _mergeSort(0, array_size - 1); 
} 




int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n;
    int k;
    int T=t;
    while(t--){
        cin>>n>>k;
        int ans=0;
        arr.clear();
        arr.resize(n);
        REP(i,0,n){
            cin>>arr[i];
        }
        int no=mergeSort(n);
        // deb(no);
        if(k<no){
            ans=(no-k);
        }
        else{
            int rem=(k-no);
            // int ans=0;
            ans=0;
            int f=0;
            for(int i=1;i<n;i++){
                if(arr[i]==arr[i-1]){
                    f=1;
                }
            }
            if(rem%2==0){

            }
            else{
                // if(f==0){
                    ans++;
                // }
            }
        }

        cout<<"Case "<<(T-t)<<": "<<ans<<"\n";
    }



    return 0;
}