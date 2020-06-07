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



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	int a, b;
    	cin>>a>>b;
    	int A=a;
    	while(A%2==0){
    		A=A/2;
    	}
    	int B=b;
    	while(B%2==0){
    		B=B/2;
    	}
    	if(A!=B){
    		cout<<-1<<"\n";
    	}
    	else{
    		if(a==b){
    			cout<<0<<"\n";
    		}
    		else if(a>b){
    			if(a%b==0){
    				// if(a/b==1){
    				// 	cout<<0<<"\n";
    				// }
    				// else if(a/b==2){
    				// 	cout<<1<<"\n";
    				// }
    				// else if(a/b==4){
    				// 	cout<<1<<"\n";
    				// }
    				// else if(a/b==8){
    				// 	cout<<1<<"\n";
    				// }
    				int div=a/b;
    				// deb(div);
    				int ans=0;
    				// ans+=(div/8);
    				int mul=1;
    				while(mul<=div){
    					ans++;
    					div=div/8;
    					mul=mul*8;
    				}
    				// div=div%8;
    				// ans+=(div/4);
    				mul=1;
    				while(mul<=div){
    					ans++;
    					div=div/4;
    					mul=mul*4;
    				}

    				// div=div%4;
    				// ans+=(div/2);
    				// div=div%2;
    				mul=1;
    				while(mul<=div){
    					ans++;
    					div=div/2;
    					mul=mul*2;
    				}
    				
    				cout<<ans<<"\n";
    			}
    		}
    		else{
    			swap(a,b);
    			int div=a/b;
    				// deb(div);
    				int ans=0;
    				// ans+=(div/8);
    				int mul=1;
    				while(mul<=div){
    					ans++;
    					div=div/8;
    					mul=mul*8;
    				}
    				// div=div%8;
    				// ans+=(div/4);
    				mul=1;
    				while(mul<=div){
    					ans++;
    					div=div/4;
    					mul=mul*4;
    				}

    				// div=div%4;
    				// ans+=(div/2);
    				// div=div%2;
    				mul=1;
    				while(mul<=div){
    					ans++;
    					div=div/2;
    					mul=mul*2;
    				}
    				
    				cout<<ans<<"\n";
    		}
    	}
    }

    return 0;
}