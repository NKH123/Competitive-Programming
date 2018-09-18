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
 void p(string s){
     cout<<s<<"\n";
 }
int main()
{   ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        //p("In here t");
        string row,col;
        cin>>row>>col;
        
        vi ro0;
        ro0.clear();
        vi co0;
        co0.clear();
        for(auto g:row){
            if(g=='0'){
                ro0.PB(0);
            }
            else{
                ro0.PB(1);
            }
        }
        for(auto g:col){
            if(g=='0'){
                co0.PB(0);
            }
            else{
                co0.PB(1);
            }
        }
        vi ro1;
        ro1.clear();
        ro1.resize(ro0.size());
        vi co1;
        co1.clear();
        co1.resize(co0.size());
        if(co0[0]==0 || ro0[0]==0){
            co1[0]=ro1[0]=1;
        }
        for(int i=1;i<ro1.size();i++){
            if(ro0[i]==0){
                ro1[i]=1;
            }
            else{
                ro1[i]=1^ro1[i-1];
            }
        }
        for(int i=1;i<co1.size();i++){
            if(co0[i]==0){
                co1[i]=1;
            }
            else{
                co1[i]=1^co1[i-1];
            }
        }
        if(row.size()==1 || col.size()==1){
            if(row.size()==1){
                int q,x,y;
                cin>>q;
                vi ans;
                ans.clear();
                while(q--){
                    cin>>x>>y;
                   // cout<<co1[x-1]<<"\n";
                    ans.PB(co1[x-1]);
                }
                for(auto g:ans){
                    cout<<g;
                }
                cout<<"\n";
            }
            else{
                int q,x,y;
                cin>>q;
                vi ans;
                ans.clear();
                while(q--){
                    cin>>x>>y;
              //      cout<<ro1[y-1]<<"\n";
                    ans.PB(ro1[y-1]);
                }
                for(auto g:ans){
                    cout<<g;
                }
                cout<<"\n";
            }
        }
        else{
        vi ro2,co2;
        ro2.clear();
        co2.clear();
        ro2.resize(ro1.size()-1);
        co2.resize(co1.size()-1);
        if(co1[1]==0 || ro1[1]==0){
            ro2[0]=co2[0]=1;
        }
        else{
            ro2[0]=co2[0]=0;
        }
        for(int i=1;i<ro2.size();i++){
            if(ro1[i+1]==0 || ro2[i-1]==0){
                ro2[i]=1;
            }
            else{
                ro2[i]=0;
            }
        }
        for(int i=1;i<co2.size();i++){
            if(co1[i+1]==0 || co2[i-1]==0){
                co2[i]=1;
            }
            else{
                co2[i]=0;
            }
        }
        /*
        cout<<"rows"<<"\n";
        for(auto g: ro0){
            cout<<g<<" ";
        }
        cout<<"\nrow1\n";
        for(auto g: ro1){
            cout<<g<<" ";
        }
        cout<<"\nrow2\n";
        for(auto g: ro2){
            cout<<g<<" ";
        }
         cout<<"\ncols"<<"\n";
        for(auto g: co0){
            cout<<g<<" ";
        }
        cout<<"\ncol1\n";
        for(auto g: co1){
            cout<<g<<" ";
        }
        cout<<"\ncol2\n";
        for(auto g: co2){
            cout<<g<<" ";
        }
        cout<<"\n";
        */
       int q;
       int x, y;
       cin>>q;
       vi ans;
       ans.clear();
       while(q--){
           //p("In here q=");
           cin>>x>>y;
           
           if(x==1 || y==1){
               if(x==1){
                  // cout<<ro1[y-1]<<"\n";
                   ans.PB(ro1[y-1]);
               }
               else if(y==1){
                  // cout<<co1[x-1]<<"\n";
                   ans.PB(co1[x-1]);
               }
           }
           else{
               int inter=x-y;
               if(inter==0){
                 // cout<<ro2[0]<<"\n";
                   ans.PB(ro2[0]);
               }
               else if(inter>0){
                   //cout<<co2[inter]<<"\n";
                   ans.PB(co2[inter]);
               }
               else if(inter<0){
                 // cout<<ro2[(-1)*inter]<<"\n";
                   ans.PB(ro2[(-1)*inter]);
               }
           }
       }

for(auto g:ans){
    cout<<g;
}
    cout<<"\n";
        }
    }
    return 0;
}