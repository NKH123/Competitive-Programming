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
double X1, Y1, R1, X2, Y2, R2;

bool check(){
    double dist=sqrt(((X1 - X2) * (X1 - X2)) + ((Y1 - Y2) * (Y1 - Y2))); 
    if(((dist+R1))<=R2){
        return true;
    }
    else{
        return false;
    }
}
bool check1(double X, double Y){
    double dist=(X-X2)*(X-X2)+(Y-Y2)*(Y-Y2);
    // if(dist)
    double sqrd=R2*R2;
    if(dist<=sqrd){
        return false;
    }
    else{
        return true;
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        
        cin>>X1>>Y1>>R1>>X2>>Y2>>R2;
        if(X1==X2 && Y1==Y2 && R1==R2){
                // cout<<"NO\n";
                printf("NO\n");
                continue;
        }
        //check if circle 1 lies completely inside circle 2
        if(check()){
            printf("NO\n");
            continue;
        }
        else{
            printf("YES\n");
            double Xx1, Xx2, Yy1, Yy2;
            //find the point
            //slope is 0
            if(Y1==Y2){
                Xx1=X1+R1;
                Yy1=Y1;
                Xx2=X1-R1;
                Yy2=Y1;
            }
            //slope is infinity
            else if(X1==X2){
                Xx1=X1;
                Yy1=Y1+R1;
                Xx2=X1;
                Yy2=Y1-R1;
            }

            //normal slope
            else{
                double m=((Y2-Y1)*1.0)/(X2-X1);
                double dx=(R1*1.0)/(sqrt(1+(m*m)));
                double dy=m*dx;
                Xx1=X1+dx;
                Yy1=Y1+dy;
                Xx2=X1-dx;
                Yy2=Y1-dy;
            }

            if(check1(Xx1, Yy1)){
                printf("%0.9lf %0.9lf\n",Xx1, Yy1);
            }
            else{
                printf("%0.9lf %0.9lf\n",Xx2, Yy2);
            }
        }



        
    }



    return 0;
}