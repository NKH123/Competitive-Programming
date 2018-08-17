#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007

int main()
{   ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string a[n];
    REP(i,0,n)
    {
        cin>>a[i];
    }
    set <string> s;
    REP(i,0,n)
    {   string sr;
        //cout<<"In outer loop i="<<i<<"\n";
        sr.clear();
        sort(a[i].begin(),a[i].end());
        for(int j=0;j<a[i].size();j++)
        {  // cout<<"In inner loop j="<<j<<"\n";
            char A=a[i][j];
            if(j!=0)
            {

                char B=a[i][j-1];
            }
            if(j==0)
            {
                sr.push_back( A);
                //cout<<"Appened first letter sr="<<sr<<"\n";
            }
            else{
                if(a[i][j]!=a[i][j-1])
                sr.push_back(A);
                // cout<<"Appened next letter sr="<<sr<<"\n";
            }

        }
        s.insert(sr);
    }
    cout<<s.size()<<"\n";
    return 0;
}