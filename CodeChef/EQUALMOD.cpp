#include<bits/stdc++.h>
using namespace std;
#define int long long 

#define pp pair<int,int> 

bool cmp(pp a,pp b){
    return a.first%a.second<b.first%b.second;
}

int find_ind(vector<pp> &v,int m){
    int si=0,ei=v.size()-1;
    int ans=ei+1;
    while(si<=ei){
        int mid=(si+ei)/2;
        if(v[mid].first%v[mid].second > m){
            ans=mid;
            ei=mid-1;
        }
        else{
            si=mid+1;
        }
    }
    return ans;
}

int find_ind1(vector<pp> &v,int m){
    int si=0,ei=v.size()-1;
    int ans=ei+1;
    while(si<=ei){
        int mid=(si+ei)/2;
        if(v[mid].first%v[mid].second <m){
            ans=mid;
            si=mid+1;
        }
        else{
            ei=mid-1;
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>v[i].first;
        }
        for(int i=0;i<n;i++){
            cin>>v[i].second;
            m[v[i].first%v[i].second]++;
        }
        sort(v.begin(),v.end(),cmp);
        int premod[n]{0},suf[n]{0};
        premod[0]=v[0].first%v[0].second;
        for(int i=1;i<n;i++){
            premod[i]=v[i].first%v[i].second + premod[i-1];
        }
        
        suf[n-1]=v[n-1].second;
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+v[i].second;   
        }
        int sufmod[n]{0};
        sufmod[n-1]=v[n-1].first%v[n-1].second;
        for(int i=n-2;i>=0;i--){
            sufmod[i]+=sufmod[i+1]+v[i].first%v[i].second;
        }
        int ans=1e17;
        for(auto i:m){
            int j=find_ind(v,i.first);
            int ans1=0;
            if(j!=n){
                ans1+=(n-j)*i.first+suf[j]-sufmod[j];
            }
            int left=find_ind1(v,i.first);
            if(left!=n)
                ans1+=(left+1)*i.first-premod[left];
            ans=min(ans,ans1);
        }
        cout<<ans<<endl;
    }
}


