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
    int q;
    cin>>q;
    while(q--){
        int b, w;
        cin>>b>>w;
        if(w>=b){
            int a=w;
            int rema=a;
            int remb=b;
            int curx=1;
            int maxix;
            int f=0;
            while(rema>3){
                f=1;
                cout<<(curx)<<" "<<3<<"\n";
                cout<<(curx+1)<<" "<<3<<"\n";
                cout<<(curx+1)<<" "<<2<<"\n";
                cout<<(curx+1)<<" "<<4<<"\n";
                maxix=curx+1;
                rema-=3;
                remb-=1;
                curx+=2;
            }
            // if(f==0){
            //     curx=2;
            // }
            if(rema==1){
                cout<<curx<<" "<<3<<"\n";
                cout<<(curx+1)<<" "<<3<<"\n";
                rema-=1;
                remb-=1;   

            }
            else if(rema==2){
                cout<<curx<<" "<<3<<"\n";
                cout<<(curx+1)<<" "<<3<<"\n";
                rema-=1;
                remb-=1;
                cout<<(curx+1)<<" "<<2<<"\n";  
                rema-=1;
            }
            if(remb<0){
                cout<<"NO\n";
            }
            else{
                int X=1;
                while(remb>0){
                    if(remb!=1){
                        cout<<X<<" "<<2<<"\n";
                        cout<<X<<" "<<4<<"\n";
                        remb-=2;
                        X+=2;
                    }
                    else{
                        cout<<X<<" "<<2<<"\n";
                        remb-=1;
                        X+=2;
                    }
                }
            }   
        }
        else{
            int a=b;
            int rema=b;
            int remb=a;
            int curx=2;
            int maxix;
            int f=0;
            while(rema>3){
                f=1;
                cout<<(curx)<<" "<<2<<"\n";
                cout<<(curx+1)<<" "<<2<<"\n";
                cout<<(curx+1)<<" "<<1<<"\n";
                cout<<(curx+1)<<" "<<3<<"\n";
                maxix=curx+1;
                rema-=3;
                remb-=1;
                curx+=2;
            }
            if(f==0){
                curx=2;
            }
            if(rema==1){
                cout<<curx<<" "<<2<<"\n";
                cout<<(curx+1)<<" "<<2<<"\n";
                rema-=1;
                remb-=1;   

            }
            else if(rema==2){
                cout<<curx<<" "<<2<<"\n";
                cout<<(curx+1)<<" "<<2<<"\n";
                rema-=1;
                remb-=1;
                cout<<(curx+1)<<" "<<1<<"\n";  
                rema-=1;
            }
            if(remb<0){
                cout<<"NO\n";
            }
            else{
                int X=1;
                while(remb>0){
                    if(remb!=1){
                        cout<<X<<" "<<1<<"\n";
                        cout<<X<<" "<<3<<"\n";
                        remb-=2;
                        X+=2;
                    }
                    else{
                        cout<<X<<" "<<1<<"\n";
                        remb-=1;
                        X+=2;
                    }
                }
            }   
        }
    }



    return 0;
}