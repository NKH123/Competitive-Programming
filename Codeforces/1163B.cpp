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
#define llp 1000000007
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


int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n)cin>>a[i];
    vector<vector<int> >b(11);
    REP(i,1,11){
        b[i].resize(n+1);
    }
    REP(i,0,n){
        b[a[i]][i+1]=b[a[i]][i]+1;
        for(int j=1;j<=10;j++){
            if(j==a[i])continue;
            b[j][i+1]=b[j][i];
        }
    }
    // for(int i=1;i<=10;i++){
    //     deb(b[i]);
    // }
    for(int i=n;i>=1;i--){
        // deb(i);
        int f=1;
        int gt=b[1][i];
        int sum=0;
        for(int j=1;j<=10;j++){
            if(b[j][i])
            sum+=1;
            if(gt<b[j][i]){
                gt=b[j][i];
            }
        }
        int ct=0;
        // deb(gt);
        if(gt==1){
            cout<<i<<"\n";
            break;
        }
        //gt--;
        for(int j=1;j<=10;j++){
            // if(b[j][i]%gt==1){
            //     ct++;
            // }
            // else if(b[j][i]%gt!=0){
            //     f=0;
            //     break;
            // }
            if(b[j][i]==0)continue;
            if(gt-b[j][i]>1){
                f=0;
                // break;
            }
            else if(gt-b[j][i]==1){
               
            }
            else if(gt-b[j][i]==0){
                 ct++;
            }
        }
         if(ct!=1){
            f=0;
        }
        if(f==0 && ct==(sum-1)){
            // deb("here");
            int ff=0;
            for(int j=1;j<=10;j++){
                
              if(b[j][i]==1 && ff==0){
                    ff=1;
                    break;
                }
                

            }
            if(ff){
                f=1;
            }
        }

       
        if(f){
            cout<<i<<"\n";
            break;
        }
    }



	return 0;
}