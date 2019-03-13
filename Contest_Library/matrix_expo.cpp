
const int modn = 1e9+7;
inline int add(int a, int b)
{
    int ret=((ll)a+b)%modn;
    if(ret<0) {
        ret=(ret+modn)%modn;
    }
    return ret;
}

inline int mul(int a, int b)
{
    int ret=((ll)a*b)%modn;
    return ret;
}
vector<vector<int>> matmul(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int p=a.size();
    int q=sz(a[0]);
    int r=b.size();
    vector<vector<int>> c(p, vector<int>(r));

    for(int i=0; i<p; i++) {
        for(int j=0; j<r; j++) {
            for(int k=0; k<q; k++) {
                c[i][j]=add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}
vector<vector<int>> power(vector<vector<int>> a, ll k)
{
    int n=a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for(int i=0; i<n; i++) res[i][i]=1;

        while(k>0) {
            if(k&1) {
                res=matmul(res, a);
            }
            a=matmul(a, a);
            k>>=1;
        }
        return res;
    }
