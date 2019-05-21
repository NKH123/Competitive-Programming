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
    int t;
    cin>>t;
    vi a;
    vi Even,Odd;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);
        REP(i,0,n)cin>>a[i];
        int even=0,odd=0;
        Even.clear();
        Odd.clear();

        for(int i=1;i<n;i=i+2){
            if(a[i]>0){
                even+=a[i];
                Even.push_back(a[i]);
            }
        }
        for(int i=0;i<n;i=i+2){
            if(a[i]>0){
                odd+=a[i];
                Odd.push_back(a[i]);
            }
        }
        ostringstream sss;
        string _odd="",_even="";
        for(int i=Even.size()-1;i>=0;i--){

            sss<<Even[i];
        }
        _even=sss.str();
        sss.str("");
        sss.clear();
        sss.flush();
        for(int i=Odd.size()-1;i>=0;i--){
            sss<<Odd[i];
        }

        _odd=sss.str();
        sss.str("");
        sss.clear();
        // deb(_even);
        // deb(_odd);
        if(even!=odd){
            if(even>odd){
                // for(int i=Even.size()-1;i>=0;i--){
                //     cout<<Even[i];
                // }
                // cout<<"\n";
                // deb("even");
                cout<<_even<<"\n";
            }
            else{
                // for(int i=Odd.size()-1;i>=0;i--){
                //     cout<<Odd[i];
                // }
                // deb("odd");
                cout<<_odd;
                cout<<"\n";
            }
        }
        else{
            // int I=Even.size()-1,J=Odd.size()-1;
            // int f=1;
            // while(I>=0 && J>=0){
            //     if(Even[I]==Odd[J]){
            //         I--;
            //         J--;
            //         continue;
            //     }
            //     else if(Even[I]>Odd[J]){
            //         f=1;
            //         break;
            //     }
            //     else{
            //         f=0;
            //         break;
            //     }
            // }
            int f=1;
            if(_odd.size()>_even.size()){
                f=0;
            }
            int I=0,J=0;
            while(I<_even.size() && J<_odd.size()){
                if(_even[I]==_odd[J]){
                    I++;
                    J++;
                    continue;
                }
                else{
                    if(_even[I]>_odd[J]){
                        f=1;
                        break;
                    }
                    else{
                        f=0;
                        break;
                    }
                }
            }
            if(f==1){
                cout<<_even<<"\n";
            }
            else{
               cout<<_odd<<"\n";
            }
        }

    }



    return 0;
}