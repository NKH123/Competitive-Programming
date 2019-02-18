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

    int t;
    cin>>t;
    set<int>ss;
    vi a;
    while(t--){
        ss.clear();
        a.clear();
        int n;
        cin>>n;
        string s;
        cin>>s;
        char fir=s[0];
        ll ct=0;
        REP(i,0,n){
            if(s[i]==s[0]){
                ct++;
                if(1){
                    ss.insert(i);
                    a.PB(i);
                }
            }
        }
        if(ct==1) {
            cout<<s<<"\n";
        }
        else if( s[n-1]==fir || ct==n){
            cout<<fir<<"\n";
        }
        else{

            /*int minj=n;
         
            int f=0;
            for(auto g:ss){
                int ff=1;
                for(int i=g;i<n;i++){

                   
                    if(s[i]!=s[i-g]){
                        ff=0;
                    }
                    if(ff==0){
                        minj=min(minj,i-g);
                    }


                }
                if(ff==1){
                    minj=min(minj,n-g);
                }

            }
            REP(i,0,minj){
                cout<<s[i];
            }
            /*if(f){
                cout<<s[minj];
            }*/
            /*cout<<"\n";*/
            //deb(s);
            int maxlen=n-a[a.size()-1];
            //deb(maxlen);
            for(int i=0;i<a.size();i++){
                if(a[i]==0)continue;
               // deb(i);
             //   deb(a[i]);
                for(int j=a[i];j<maxlen+a[i];j++){
                 /*   deb(j);
                    deb(a[j]);
                    deb(a[j-a[i]]);*/
                    if(s[j]!=s[j-a[i]]){
                        //deb("Not equal");
                        maxlen=j-a[i];
                       // deb(maxlen);
                        break;
                    }
                }
            }
           // deb(maxlen);
            for(int i=0;i<maxlen;i++){
                cout<<s[i];
            }
            cout<<"\n";

        }
        
    }

    return 0;
}