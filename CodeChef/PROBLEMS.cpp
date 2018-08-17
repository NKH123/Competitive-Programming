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
int p,s;
vector<vector<pair<int,int> > >prob;
//prob[i]=(k,{score,no. of people})
bool COMP(const pair<int,int>  &a, const pair<int,int>  &b){
    if(a.F<b.F){
        return true;
    }
    else if(a.F==b.F){
        return a.S<b.S;
    }
    else{
        return false;
    }
}
bool COMP1(const pair<int,int> &a, const pair<int,int> &b){
    if(a.F<b.F){
        return true;
    }
    else if(a.F==b.F){
        return a.S<b.S;
    }
    else{
        return false;
    }
}
 
int main()
{   ios::sync_with_stdio(false);
    cin>>p>>s;
    int sc,ns;
    prob.resize(p, vector<pair<int,int> >(s));
    /*cout<<"debug\n";
    for(int i=0; i<p;i++){
        for(auto g:prob[i]){
            cout<<"{"<<g.F<<","<<g.S<<"} ";
        }
        cout<<"\n";
    }*/
    REP(i,0,2*p){
        if(i%2==0){
            /*REP(j,0,s){
                prob[i][j].F=j;
                cin>>sc;
                prob[i][j].S.F=sc;
            }*/
            for(int j=0;j<s;j++){
                cin>>sc;
                prob[i/2][j].F=sc;
            }
        }
        else{
            for(int j=0;j<s;j++){
 
                cin>>ns;
                prob[i/2][j].S=ns;
            }
        }
        /*for(int i=0; i<p;i++){
        for(auto g:prob[i]){
            cout<<"{"<<g.F<<","<<g.S<<"} ";
        }
        cout<<"\n";
    }*/
    }
    REP(i,0,p){
        sort(prob[i].begin(),prob[i].end(),COMP);
    }
    vector<pair<int,int> >diff(p);
    //prob[i]=(k,{score,no. of people})
    for(int i=0; i<p; i++){
        int N=0;
        for(int j=0; j<s-1;j++){
            if(prob[i][j].S>prob[i][j+1].S){
                N++;
            }
        }
        diff[i]={N,i};
    }
    sort(diff.begin(),diff.end(),COMP1);
    REP(i,0,p){
        cout<<diff[i].S+1<<"\n";
    }
    return 0;
}
 