#include<bits/stdc++.h>
using namespace std;
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


vector<int>Sum(5);
vector<vector<int> >no(3,vector<int>(5));
// vector<vector<int> >ans(3,vector<int>(5));
vector<int>ans(3);
int f=0;
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int solve(int ct){
    // deb(ct);
    if(ct==0){
        //check if prime
        vector<int>a(3,0);
        for(int i=0;i<3;i++){
            for(int j=0;j<5;j++){
                a[i]=a[i]*10+no[i][j];
            }
        }
        // deb(a);
        if(isPrime(a[0]) && isPrime(a[0]) && isPrime(a[0])){
            f=1;
            for(int i=0;i<3;i++){
                ans[i]=a[i];
            }
            return 1;
        }
        else{
            return 0;
        }


    }
    else{
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=9;k++){
                    int sum=i+j+k;
                    // if(sum==14){
                    //     cout<<i<<' '<<j<<' '<<k<<" ";
                    // // int ncar=sum%2;
                    // // if(ct==1 && ncar!=0){
                    //     // continue;
                    // // }
                    // // sum=sum%10;
                    //     deb(sum);
                    // }
                    if(ct==1){
                        if(i==0 || j==0 || k==0){
                            continue;
                        }
                    }
                    if(ct==5){
                        if(i%2==0 || j%2==0 || k%2==0){
                            continue;
                        }
                    }
                    if(sum==Sum[5-ct]){
                        no[0][ct-1]=i;
                        no[1][ct-1]=j;
                        no[2][ct-1]=k;
                        int ff=solve(ct-1);
                        if(ff==1){
                            return 1;
                        }
                        else{
                            return 0;
                        }
                    }
                }
            }
        }
        return 0;
    }
}

class EllysThreePrimes{
public:
    vector <int> getPrimes(vector <int> sums){
        for(int i=0;i<5;i++){
            Sum[i]=sums[i];
        }
        // deb(Sum);
        int ff=solve(5);

        if(ff==0){
            ans.clear();
            return ans;
        }
        else{
            if(ans[0]==ans[1] || ans[1]==ans[2] || ans[0]==ans[2]){
                ans.clear();
            }
            return ans;
        }
    }
    
};
/*
int main(){
    EllysThreePrimes E;
    vector<int> a(5);
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    vector<int> b=E.getPrimes(a);
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
*/