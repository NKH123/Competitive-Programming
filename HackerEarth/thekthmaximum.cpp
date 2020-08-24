#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<vector<int> > a;
    vector<vector<int> > pref;
    vector<pair<int, pair<int, int> > >values;
    while(t--){
        int n, m;
        cin>>n>>m;
        a.clear();
        pref.clear();
        values.clear();
        a.resize(n, vector<int>(m,0));
        pref.resize(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>a[i][j];
                pref[i][j]=0;
            }
        }
        pref[0][0]=a[0][0];
        values.push_back({a[0][0],{0,0}});
        for(int i=1; i<m;i++){
            pref[0][i]=a[0][i]^pref[0][i-1];
            values.push_back({pref[0][i],{0,i}});
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<m;j++){
                pref[i][j]=a[i][j]^pref[i-1][j];
                if(j!=0){
                    pref[i][j]=pref[i][j]^pref[i][j-1]^pref[i-1][j-1];
                }

                values.push_back({pref[i][j],{i,j}});
            }
        }
        sort(values.begin(), values.end());
        int k;
        cin>>k;
        auto ans = values[n*m-1-(k-1)];
        cout<<(ans.second.first+1)<<" "<<(ans.second.second+1)<<"\n";
    }

    return 0;
}