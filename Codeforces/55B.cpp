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
long long ans=1LL<<62;
long long calc(long long a, long long b, char c)
{
    if(c=='+')
        return a+b;
    if(c=='*')
        return a*b;
}
void fun(deque<long long>A,deque<char>B)
{   long long temp,t1,t2; char t;
    if(A.size()==1)
    {
        ans=min(ans,A[0]);
        return;
    }
    else{
        do{
              temp=calc(A[0],A[A.size()-1],B[0]);
               t1=A[0];
               t2=A[A.size()-1];
               t=B[0];
               A.pop_front();
               A.pop_back();
               B.pop_front();
               A.push_back(temp);
               fun(A,B);
               A.pop_back();
               A.push_front(t1);
               A.push_back(t2);
               B.push_front(t);
            }while(next_permutation(A.begin(),A.end()));
        }
}
int main()
{   ios::sync_with_stdio(false);
    deque<long long>a(4);
    deque<char>b(3);
    REP(i,0,4)
    cin>>a[i];
    REP(i,0,3)
    cin>>b[i];
    sort(a.begin(), a.end());
    fun(a,b);
    cout<<ans<<"\n";
    return 0;
}
