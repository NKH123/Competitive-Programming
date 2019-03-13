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

const int MOD = 1e9 + 7;
const long long MOD2 = static_cast<long long>(MOD) * MOD;
const int MAX_K = 50;

int ttt,nnn,aaa,bbb,ccc,ddd,eee;

struct Matrix
{
    vector< vector<int> > mat;
    int n_rows, n_cols;

    Matrix() {}

    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
    n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n)
    {
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const 
    {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                long long tmp = 0;
                for(int k = 0; k < n_cols; k++) {

                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    //if(i==0 && j==)
                    while(tmp >= MOD)
                        tmp -= MOD;
                }
                result[i][j] = tmp % MOD;
            }

            return move(Matrix(move(result)));
        }

        inline bool is_square() const
        {
            return n_rows == n_cols;
        }
    };

// M_powers[i] is M, raised to 2^i-th power
    Matrix M_powers[55];

    void precalc_powers(Matrix M)
    {
        assert(M.is_square());
        M_powers[0] = M;

        for(int i = 1; i < 55; i++)
            M_powers[i] = M_powers[i - 1] * M_powers[i - 1];
    }

    Matrix fast_exponentiation_with_precalc(int power)
    {
        Matrix result = Matrix::identity_matrix(M_powers[0].mat.size());
        int pointer = 0;
        while(power) {
            if(power & 1)
                result = result * M_powers[pointer];
            pointer++;
            power >>= 1;
        }
        return result;
    }

    inline int get_int()
    {
        char c;
        int ret = 0;
        while(isdigit(c = getchar()))
            ret = ret * 10 + c - '0';
        return ret;
    }

    int32_t main()
    {
        int t;



        int ttt;
        cin>>ttt;
        while(t--){
            cin>>aaa>>bbb>>ccc>>ddd>>eee>>nnn;
            Matrix M({ 
                {1, 0, 0,ddd,eee*4}, 
                {1, 0, 0,0,0}, 
                {0, 1, 0,0,0},{0,0,1,0,0},{0,0,0,0,eee*4} });
            precalc_powers(M);

            Matrix initial({ {0, 1, 2} });
            t = get_int();
            for(int i = 0; i < t; i++) {
                int n = get_int();
                cout << (initial * fast_exponentiation_with_precalc(n - 1)).mat[0][0] << "\n";
            }
        }
    }




    int32_t main(){
     ios::sync_with_stdio(false);




     return 0;
 }