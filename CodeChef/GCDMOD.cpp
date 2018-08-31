    #include<bits/stdc++.h>
    using namespace std;
    #define F first
    #define S second
    #define PB push_back
    #define REP(i,a,b) for (int i = a; i <b; i++)
    typedef long long ll;
    typedef vector<int> vi;
    typedef pair<int,int> pi;
    #define llp 1000000007
    long long a,b,n;

    long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

    long long power(long long a, long long b)
    {   //cout<<"a="<<a<<" powr b="<<b<<"==";

        if(b==0)
        return 1;
        if(b==1)
        {
            return a;
        }
        long long ret=1;
        while(b!=0)
        {
            if(b%2)
            {
                ret=((ret%llp)*(a%llp))%llp;
            }
            a=((a%llp)*(a%llp))%llp;
            b/=2;
        }
        //cout<<ret<<"\n";
        return ret;

    }
    long long mult(ll a,ll b, ll mod){
        ret=0;
        while(b!=0){
            if(b%2){
                ret=(ret+a)%mod;
            }
            a=(2*((a)%mod))%mod;
            b=b/2;
        }
        return ret;
    }
    long long power1(long long a, long long b,long long G)
    {   //cout<<"a="<<a<<" powr b="<<b<<"==";

        if(b==0)
        return 1;
        if(b==1)
        {
            return a;
        }
        long long ret=1;
        while(b!=0)
        {
            if(b%2)
            {
                ret=mult(ret,a,G)%G;
            } 
            a=mult(a,a,G)%G;
            b/=2;
        }
        //cout<<ret<<"\n";
        return ret;

    }


    int main()
    {   ios::sync_with_stdio(false);
        int t;
        cin>>t;
        while(t--){
            cin>>a>>b>>n;
            long long G=abs(a-b);
            if(b>a){
                swap(a,b);
            }

            //a=a%llp;
            //b=b%llp;
            //n=n%(llp-1);
            //long long A=power(a%llp,n%(llp-1));
            //long long B=power(b%llp,n%(llp-1));
            if(G==0){
                cout<<(2*power(b,n))%llp<<"\n";
            }
            else{
                //long long AA=power1(a,n,G);
                long long BB=power1(b,n,G);

                cout<<gcd(min(2*BB,G),max(2*BB,G))%llp<<"\n";
            }
            //long long AA=A+B;
            //if(G!=0)
            //AA=(A+B)%G;
            //cout<<gcd(G,AA)%llp<<"\n";


        }
        return 0;
    }
