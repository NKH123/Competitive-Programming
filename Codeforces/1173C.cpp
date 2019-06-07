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
int n;
vi a;
vi b;
vi pos;
bool check(){
    if(pos[1]==-1){
        for(int i=2;i<=n;i++){
            int rem;
            if(pos[i]==-1){
                rem=1;
            }
            else{
                rem=pos[i]+2;
            }
            if(rem<=(i)){

            }
            else{
                return false;
            }
        }
    }
    else{
        int las=b[n-1];
        for(int i=b[n-1]+1;i<=n;i++){
            int rem;
            if(pos[i]==-1){
                rem=1;
            }
            else{
                rem=pos[i]+2;
            }
            if(rem<=(i-(b[n-1]))){

            }
            else{
                return false;
            }
        }
    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    cin>>n;
    a.resize(n);
    b.resize(n);
    pos.resize(n+1);
    REP(i,0,n){
        cin>>a[i];
        if(a[i]!=0){
            pos[a[i]]=-1;
        }
    }
    REP(i,0,n){
        cin>>b[i];
        if(b[i]!=0){
            pos[b[i]]=i;
        }

    }
    int mvs=0;
    int f=0;
    for(int i=0;i<n;i++){
        if(b[i]==i+1){

        }
        else{
            f=1;
        }
    }
    if(f==0){
        cout<<mvs<<"\n";
        return 0;
    }
    if(pos[1]!=-1){
        int f=1;
        for(int i=pos[1]+1;i<n;i++){
            if(b[i]!=i-pos[1]+1){
                f=0;
            }
        }
        if(f==1){
            if(check()){
                if(pos[1]==-1){
                    cout<<n<<"\n";
                }
                else{
                    cout<<(n-b[n-1])<<"\n";
                }
            }
            else{

                if(pos[1]!=-1){
                    int I;
                    for(int i=0;i<n;i++){
                        if(b[i]==1){
                            pos[1]=-1;
                            mvs++;
                            I=i;
                            break;
                        }
                        else{
                            if(b[i]!=0){
                                pos[b[i]]=-1;
                                mvs++;
                            }
                            else{
                                mvs++;
                            }
                        }
                    }
                    int ct=0;
                    for(int i=I+1;i<n;i++){
                        if(b[i]!=0){
                            pos[b[i]]=ct;
                            ct++;
                        }
                        else{
                            ct++;
                        }
                    }
                }
                if(check()){
                    cout<<(mvs+n)<<"\n";
                }
                else{
                    int I;
                    int req=-1;
                    for(int i=n-1;i>=0;i--){
                        if(b[i]!=0){
                            int rem=i+2;
                            if(rem>b[i]){
                                I=i;
                                req=max(req,rem-b[i]);
                            }
                        }
                    }
                    cout<<(mvs+req+n)<<"\n";
                }
            }
        }
        else{
                //fill this it's not in ascending order
            if(pos[1]!=-1){
                int I;
                    for(int i=0;i<n;i++){
                        if(b[i]==1){
                            pos[1]=-1;
                            mvs++;
                            I=i;
                            break;
                        }
                        else{
                            if(b[i]!=0){
                                pos[b[i]]=-1;
                                mvs++;
                            }
                            else{
                                mvs++;
                            }
                        }
                    }
                    int ct=0;
                    for(int i=I+1;i<n;i++){
                        if(b[i]!=0){
                            pos[b[i]]=ct;
                            ct++;
                        }
                        else{
                            ct++;
                        }
                    }
                }
                // deb(pos);
                // deb(mvs);
                int I;
        int req=0;
        for(int i=n-1;i>=0;i--){
            if(b[i]!=0){
                int rem=pos[b[i]]+2;
                if(rem>b[i]){
                    I=i;
                    req=max(req,rem-b[i]);
                }
            }
        }
        // deb(req);
        cout<<(mvs+n+req)<<"\n";


        }
    }
    else{
        int I;
        int req=0;
        for(int i=n-1;i>=0;i--){
            if(b[i]!=0){
                int rem=pos[b[i]]+2;
                if(rem>b[i]){
                    I=i;
                    req=max(req,rem-b[i]);
                }
            }
        }
        cout<<(n+req)<<"\n";
    }


    return 0;
}