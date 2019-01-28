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
int t;
string s;
long long n,i,j,z,b,m,z1,b1,m1;
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>s;
        int z=0;
        int b=0;
        int m=0;
        for(j=0; j<s.size(); j++)
        {
            if(isdigit(s[j]))
            {
                z++;
                z1=j;
            }
            if(isupper(s[j]))
            {
                b++;
                b1=j;
            }
            if(islower(s[j]))
            {
                m++;
                m1=j;
            }
            if(z>0 && b>0 && m>0)break;
        }
        if(z==0 && b==0)
        {
            s[0]='1';
            s[1]='A';
        }
        else
        {
            if(z==0 && m==0)
            {
                s[0]='1';
                s[1]='a';
            }
            else
            {
                if(b==0 && m==0)
                {
                    s[0]='A';
                    s[1]='a';
                }
                else
                {
                    if(z==0 && b>1)
                    {
                        s[b1]='1';
                    }
                    else
                    {
                        if(z==0 && m>1)
                        {
                            s[m1]='1';
                        }
                        else
                        {
                            if(b==0 && m>1)
                            {
                                s[m1]='A';
                            }
                            else
                            {
                                if(b==0 && z>1)
                                {
                                    s[z1]='A';
                                }
                                else
                                {
                                    if(m==0 && z>1)
                                    {
                                        s[z1]='a';
                                    }
                                    else
                                    {
                                        if(m==0 && b>1)
                                        {
                                            s[b1]='a';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
        cout<<s<<endl;
    }
    return 0;
}
        
    
