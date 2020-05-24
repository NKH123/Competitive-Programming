#include <bits/stdc++.h>
using namespace std;
#define int long long 

string lcs(string &X, string &Y) 
{ 
    int m = X.length(); 
    int n = Y.length(); 
  
    int L[m+1][n+1]; 
  
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
            else if (X[i-1] == Y[j-1]) 
                L[i][j] = L[i-1][j-1] + 1; 
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]); 
        } 
    } 
    int index = L[m][n]; 
  
    string lcs(index+1, '\0'); 
    int i = m, j = n; 
    while (i > 0 && j > 0) 
    { 
        if (X[i-1] == Y[j-1]) 
        { 
            lcs[index-1] = X[i-1]; 
            i--; 
            j--; 
  
            index--; 
        } 
        else if (L[i-1][j] > L[i][j-1]) 
            i--; 
        else
            j--; 
    } 
  
    return lcs; 
} 
string longestPalSubseq(string &str) 
{ 
    string rev = str; 
    reverse(rev.begin(), rev.end()); 
  
    return lcs(str, rev); 
} 



signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    unordered_map<char,int> m;
    bool flag=false;
    char c;
    
    for(int i=0;s[i];i++){
        m[s[i]]++;
        if(m[s[i]]>=100){
            flag=true;
            c=s[i];
        }
    }
    if(flag){
        for(int i=0;i<100;i++){
            cout<<c;
        }
        cout<<"\n";
        return 0;
    }
    string ans=longestPalSubseq(s);
    if(ans.length()<=100){
        // cout<<ans<<"\n";
        for(int i=0;i<ans.size()-1;i++){
            cout<<ans[i]<<"";
        }
        cout<<"\n";
        return 0;
    }
    if(1){
        int cnt=0;
        int l=0,r=ans.length()-1;
        string final1,final2;
        while(l<=r){
            final1.push_back(ans[l]);
            final2.push_back(ans[r]);
            l++;
            r--;
            cnt+=2;
            if(cnt==100){
                break;
            }
        }
        cout<<final1<<final2<<"\n";
    }
    return 0;
}
