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
string s;
int n, p;
int cost(char A, char B){
    int ans=abs(A-B);
    ans=min(ans,26-ans);
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);

    
    cin>>n>>p; 
    cin>>s;
    s='0'+s;
    int ans=1e18;
    if(n%2==0){
        //left  
        int mid=(n/2);
        int temp=0;
        if(p>mid){
            p=(n-p+1);
        }
        if(p<=(mid)){
            //left to right
            // temp+=cost(s[p],s[n-p+1]);
            int right_ind=p;
            //find rightmost index that is unequal
            for(int i=p;i<=mid;i++){
                if(s[i]!=s[n-i+1]){
                    right_ind=max(i,right_ind);
                }
            }
            if(right_ind!=p){
                for(int i=p+1;i<=right_ind;i++){
                    temp++;
                    // temp+=cost(s[i],s[n-i+1]);
                }
            }
            //find leftmost index that is unequal
            int left_ind=p;
            for(int i=p;i>=1;i--){
                if(s[i]!=s[n-i+1]){
                    left_ind=min(i,left_ind);
                }
            }
            if(left_ind<p){
                for(int i=right_ind-1;i>=left_ind;i--){
                    temp++;
                    // if(i!=p)
                    // temp+=(cost(s[i],s[n-i+1]));
                }
            }

            int temp1=0;
            //right to left
            // temp1+=cost(s[p],s[n-p+1]);
            if(left_ind<p){
                for(int i=p-1;i>=left_ind;i--){
                    temp1++;
                    // temp1+=(cost(s[i],s[n-i+1]));
                }
            }
            if(right_ind!=p){
                for(int i=left_ind+1;i<=right_ind;i++){
                    temp1++;
                    // temp1+=cost(s[i],s[n-i+1]);
                }
            }
            int Cost=0;
            for(int i=1;i<=mid;i++){
                Cost+=(cost(s[i],s[n-i+1]));
            }


            // deb(temp);
            // deb(temp1);

            ans=Cost+min(temp,temp1);
        }

    }
    else{
        int mid=(n/2);
        int temp=0;
        if(p>mid){
            p=(n-p+1);
        }
        // deb(p);
            //left to right
        mid++;
        // temp+=cost(s[p],s[n-p+1]);
        int right_ind=p;
            //find rightmost index that is unequal
        for(int i=p;i<=mid;i++){
            if(s[i]!=s[n-i+1]){
                right_ind=max(i,right_ind);
            }
        }
        if(right_ind!=p){
            for(int i=p+1;i<=right_ind;i++){
                temp++;
                // temp+=cost(s[i],s[n-i+1]);
            }
        }
            //find leftmost index that is unequal
        int left_ind=p;
        for(int i=p;i>=1;i--){
            if(s[i]!=s[n-i+1]){
                left_ind=min(i,left_ind);
            }
        }
        if(left_ind<p){
            for(int i=right_ind-1;i>=left_ind;i--){
                temp++;
                // temp+=(cost(s[i],s[n-i+1]));
            }
        }

        int temp1=0;
            //right to left
        // temp1+=cost(s[p],s[n-p+1]);
        if(left_ind<p){
            for(int i=p-1;i>=left_ind;i--){
                temp1++;
                // temp1+=(cost(s[i],s[n-i+1]));
            }
        }
        if(right_ind!=p){
            for(int i=left_ind+1;i<=right_ind;i++){
                temp1++;
                // temp1+=cost(s[i],s[n-i+1]);
            }
        }


        int Cost=0;
        for(int i=1;i<=mid;i++){
            Cost+=cost(s[i],s[n-i+1]);
        }
        // deb(temp);
        // deb(temp1);
        ans=Cost+min(temp,temp1);
        
    }
    

    cout<<ans<<"\n";

    return 0;
}