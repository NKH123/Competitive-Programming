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
int n,k;
string s;
int a[26];
int part[26];
int b[26];
int main()
{   ios::sync_with_stdio(false);
    cin>>n>>k;
    cin>>s;
    REP(i,0,26){
        a[i]=0;
        b[i]=0;
        part[i]=0;
    }
    for(auto g:s){
        a[g-'a']++;
    }
    for(int i=0;i<26;i++){
        if(i==0){
            part[i]=a[i];
        }
        else{
            part[i]=part[i-1]+a[i];
        }
    }
    int f=1;
 //   cout<<"n="<<n<<"\n";
    REP(i,0,26){
   //     cout<<"i="<<i<<"\n";
        if(f==0){
     //           cout<<"breaked\n";
            break;
        }
        if(part[i]<=k){
      //      cout<<"in if\n";
            b[i]=a[i];
        }
        else{
        //    cout<<"in else\n";
                if(i==0){
                    b[i]=k;
                }
                else{
            b[i]=k-part[i-1];}
            f=0;
        }
    }
    //REP(i,0,26){
   // cout<<a[i]<<" "<<part[i]<<" "<<b[i]<<"   ";
    //}
  //  cout<<"\n";
    for(int i=0; i<s.size();i++){
    //        cout<<"i="<<i<<"\n";
        if(b[int(s[i])-'a']>0){

      //      cout<<"Set it\n";
            b[int(s[i])-'a']--;
      //      int some=int(s[i])-'a';
        //    cout<<"b["<<some<<"]="<<b[int(s[i])-'a']<<"\n";
            s[i]='1';

        }
    }
    for(int i=0;i<s.size();i++){
    if(s[i]!='1'){
        cout<<s[i];
    }
   }




    return 0;
}
