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

int a[505][505];
int32_t main(){
	ios::sync_with_stdio(false);
    int n , m ;
    cin>>n>>m;
    memset(a,0,sizeof(a));
    vector<vector<int> >ct[2];
    ct[0].resize(n);
    ct[1].resize(n);
    REP(i,0,n){
        ct[0][i].resize(11);
        ct[1][i].resize(11);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<=10;k++)
            for(int j=0;j<m;j++){
                if((a[i][j])&(1L<<k)){
                    ct[1][i][k]++;
                }
                else{
                    ct[0][i][k]++;
                }
            }
        }
        for(int k=0;k<=10;k++){
            int odd=0,eve=0, eveodd=0;
            for(int i=0;i<n;i++){
                if(ct[1][i][k]!=0 && ct[0][i][k]==0){
                    odd++;
                }
                if(ct[1][i][k]==0 && ct[0][i][k]!=0){
                    eve++;
                }
                if(ct[1][i][k]!=0 && ct[0][i][k]!=0){
                    eveodd++;
                }
            }
            if(odd%2!=0){
                cout<<"TAK\n";
                for(int i=0;i<n;i++){
                    if(ct[1][i][k]!=0 && ct[0][i][k]==0){
                        for(int j=0;j<m;j++){
                            if((a[i][j])&(1L<<k)){
                                // ct[1][i][k]++;
                                cout<<(j+1)<<" ";
                                break;
                            }
                        }

                    }
                    else{
                        for(int j=0;j<m;j++){
                            if((a[i][j])&(1L<<k)){

                            }
                            else{
                                cout<<(j+1)<<" ";
                                break;
                            }
                        }
                    }
                }
                cout<<"\n";

                return 0;
            }
            else{
                if(eveodd!=0){
                    int f=0;
                    cout<<"TAK\n";
                    for(int i=0;i<n;i++){
                        if(ct[1][i][k]!=0 && ct[0][i][k]==0){
                            for(int j=0;j<m;j++){
                                if((a[i][j])&(1L<<k)){
                                // ct[1][i][k]++;
                                    cout<<(j+1)<<" ";
                                    break;
                                }
                            }
                        }
                        if(ct[1][i][k]==0 && ct[0][i][k]!=0){
                            cout<<1<<" "; 

                        }
                        if(ct[1][i][k]!=0 && ct[0][i][k]!=0){
                            // eveodd++;
                            if(f==1){

                                for(int j=0;j<m;j++){
                                    if((a[i][j])&(1L<<k)){
                                // ct[1][i][k]++;
                                        // cout<<(j+1)<<" ";
                                    }
                                    else{
                                        cout<<(j+1)<<" ";
                                        break;
                                    }
                                }

                            }
                            else{

                                for(int j=0;j<m;j++){
                                    if((a[i][j])&(1L<<k)){
                                // ct[1][i][k]++;
                                        cout<<(j+1)<<" ";
                                        break;
                                    }
                                }

                                f=1;
                            }
                        }
                    }
                    return 0;
                }
            }
        }


        cout<<"NIE\n";




        return 0;
    }