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
    #define endl "\n"
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
            int x1, y1, x2, y2;
            int n, m;
            cin>>n>>m;
            cin>>x1>>y1>>x2>>y2;
            //whilte is below black
            if(y1<y2){
                //if on the same column
                if(x1==x2){
                    cout<<"Draw\n";
                }
                //if adjacent
                else if(abs(x1-x2)==1){
                    if(abs(y1-y2)%2==1){
                        cout<<"Aunty\n";
                    }
                    else{
                        cout<<"Bunty\n";
                    }
                }
                //not adjacent
                else{
                    //simulate queening
                    int white_dist=m-y1;
                    int black_dist=abs(y2-1);
                    if(abs(white_dist-black_dist)>=2){
                        if(white_dist<black_dist){
                            cout<<"Aunty\n";
                        }
                        else{
                            cout<<"Bunty\n";
                        }
                    }
                    else if(abs(white_dist-black_dist)==1){
                        if(white_dist<black_dist){
                            cout<<"Aunty\n";
                        }
                        else{
                            //check the corner case for black
                            //same column
                            if(x1==x2){
                                cout<<"Bunty\n";
                            }

                            //same diagonal
                            // else if((x1+n)==(x2+1) || (x1-n)==(x2-1)){
                            else if(abs(x1-x2)==abs(m-1)){
                                cout<<"Bunty\n";
                            
                            }

                            //knight
                            else if((m-1)==2 && (x1==(x2+1)|| x1==(x2-1))){
                            
                                    cout<<"Bunty\n";
                                
                            }
                            else if((m-1)==1 && (x1==(x2+2)|| x1==(x2-2))){
                            cout<<"Bunty\n";
                            }
                            else{
                                cout<<"Draw\n";
                            }
                        }
                    }
                    else{
                        //check corner case for white
                        //same column
                                                    //same column
                            if(x1==x2){
                                cout<<"Aunty\n";
                            }

                            //same diagonal
                            // else if((x1+n)==(x2+1) || (x1-n)==(x2-1)){
                            else if(abs(x1-x2)==abs(m-1)){
                                cout<<"Aunty\n";
                            
                            }

                            //knight
                            else if((m-1)==2 && (x1==(x2+1)|| x1==(x2-1))){
                            
                                    cout<<"Aunty\n";
                                
                            }
                            else if((m-1)==1 && (x1==(x2+2)|| x1==(x2-2))){
                            cout<<"Aunty\n";
                            }
                            else{
                                cout<<"Draw\n";
                            }
                    }
                }
                

            }
            //white is above or equal to black
            else{
                //y1>=y2
                //no need to consider apparently
            }

        }

        return 0;
    }