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
string s;
vi a;
bool check(){
    for(int i=0;i<n;i++){
        if(i==0){
            if(s[i]=='o'){
                if(a[i]==0){
                    if(a[1]!=a[n-1]){
                        return false;
                    }
                }
                else{
                    if(a[1]==a[n-1]){
                        return false;
                    }
                }
            }
            else{
                if(a[i]==0){
                    if(a[1]==a[n-1]){
                        return false;
                    }
                }
                else{
                    if(a[1]!=a[n-1]){
                        return false;
                    }
                }
            }
        }
        else if(i==(n-1)){
            if(s[i]=='o'){
                if(a[i]==0){
                    if(a[0]!=a[n-2]){
                        return false;
                    }
                }
                else{
                    if(a[0]==a[n-2]){
                        return false;
                    }
                }
            }
            else{
                if(a[i]==0){
                    if(a[0]==a[n-2]){
                        return false;
                    }
                }
                else{
                    if(a[0]!=a[n-2]){
                        return false;
                    }
                }
            }
        }
        else{
            if(s[i]=='o'){
                if(a[i]==0){
                    if(a[i-1]!=a[i+1]){
                        return false;
                    }
                }
                else{
                    if(a[i-1]==a[i+1]){
                        return false;
                    }
                }
            }
            else{
                if(a[i]==0){
                    if(a[i-1]==a[i+1]){
                        return false;
                    }
                }
                else{
                    if(a[i-1]!=a[i+1]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int32_t main(){
	ios::sync_with_stdio(false);
    // int n;
    cin>>n;
    // string s;
    cin>>s;
    // vi a(n);
    a.resize(n);
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            a[0]=i;
            a[1]=j;
            for(int J=1;J<(n-1);J++){
                if(a[J]==0){
                    if(s[J]=='o'){
                        a[J+1]=a[J-1];
                    }
                    else{
                        if(a[J-1]==0){
                            a[J+1]=1;
                        }
                        else{
                            a[J+1]=0;
                        }
                    }
                }
                else{
                    if(s[J]=='o'){

                        if(a[J-1]==0){
                            a[J+1]=1;
                        }
                        else{
                            a[J+1]=0;
                        }
                    }
                    else{
                       a[J+1]=a[J-1];
                   }
               }
           }
           // deb(i);
           // deb(j);
           // deb(a);
           if(check()){
               for(int I=0;I<n;I++){
                if(a[I]==1){
                    cout<<"W";
                }
                else{
                    cout<<"S";
                }
            }
            cout<<"\n";
            return 0;
        }
    }
}
cout<<-1<<"\n";


return 0;
}