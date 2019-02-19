#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
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


int main(){
	ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vl a(n*n);
    vl aa(1001);
    unordered_set<int>e1,e2,e4;
    REP(i,0,n*n){
        cin>>a[i];
        aa[a[i]]++;
    }
    int mat[100][100];
    if(n==1){
        cout<<"YES\n";
        cout<<a[0]<<"\n";
    }
    else{
        REP(i,1,1001){
            if(aa[i]%2){
                e1.insert(aa[i]);
            }
            else if(aa[i]%4==0){
                e4.insert(aa[i]);
            }
            else if(aa[i]%2==0){
                e2.insert(aa[i]);
            }
            else{
                cout<<"NO"<<"\n";
                return 0;   
            }
        }
        if(n%2){
              REP(i,1,1001){

                    REP(j,0,aa[i]/4){
                        aaa.PB(aa[i]);
                    }
                    if(aa[i]%4 !=0){
                        if(aa[i]%2!=0){
                            
                        }
                        else{
                            
                        }
                    }

                }
        }
        else{
            if(e1.size()>0 || e2.size()>0){
                cout<<"NO\n";
                return 0;
            }
            else{
                vi aaa;
                REP(i,1,1001){
                    REP(j,0,aa[i]/4){
                        aaa.PB(aa[i]);
                    }
                }
                int I=0;
                REP(i,0,n/2){
                    REP(j,0,n/2){
                        mat[i][j]=aaa[I];
                        I++;
                    }

                }
                I=0;
                REP(i,0,n/2){
                    for(int j=n-1,j>(n/2);j--){
                        mat[i][j]=aaa[I];
                        I++;
                    }
                }
                I=0;
                for(int i=(n-1);i>(n/2);i--){
                    REP(i,0,n/2){
                          mat[i][j]=aaa[I];
                        I++;
                    }
                }
                I=0;
                for(int i=(n-1);i>(n/2);i--){
                    for(int j=n-1,j>(n/2);j--){
                        mat[i][j]=aaa[I];
                        I++;
                    }
                }

            }
            cout<<"YES\n";
            REP(i,0,n){
                REP(j,0,n){
                    cout<<mat[i][j]<<" ";
                }
                cout<<"\n";
            }

        }

    }



	return 0;
}