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



int32_t main(){
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans=0;
        vi Next(s.size()+1);
        Next.clear();
        Next.resize(s.size()+1);
        Next[s.size()]=1e18;
        
        for(int i=(int)s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                Next[i]=i;
            }
            else{
                Next[i]=Next[i+1];
            }
        }
        for(int i=0;i<(int)s.size();i++){
            if(s[i]=='1'){
                int cost=0;

                for(int j=i;j<min((int)s.size(),i+20);j++){
                    cost=cost*2;
                    if(s[j]=='1'){
                        cost=cost|1;
                    }
                    else{

                    }
                    int len=j-i+1;
                    if(len==(cost)){
                        ans++;
                    }
                }
            }
            else{
                
                
                int j=Next[i];
                if(j==(1e18)){
                    continue;
                }
                else{
                    int cost=0;
                    int J=j;
                    for(;j<min((int)s.size(),J+20);j++){
                        // deb(Next[i]);
                        // deb(min((int)s.size(),j+20));
                        // deb(i);
                        // deb(j);
                        cost=cost*2;
                        // if(cost>100000)
                        // deb(cost);
                        if(s[j]=='1'){
                            cost=cost|1;
                        }
                        else{

                        }
                        int len=(j-i+1);
                        if(len==(cost)){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }


    return 0;
}