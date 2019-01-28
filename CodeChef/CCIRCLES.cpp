#include<bits/stdc++.h>
using namespace std;
#define ll long long
    int Ai[1005];
    int Bi[1005];
   
    double ri[1005];
   
  ll ps[1000005];
 double getDistance(int a,int b,int c,int d){
      double ret=(a-c)*(a-c)+(b-d)*(b-d);
      ret=sqrt(ret);
      return ret;

  }
  void calcRange(int a,int b,int c, int dd,double r, double R){
      
      double d=getDistance(a,b,c,dd);   
     
      if(r>R){
          swap(r,R);
      }
      ll l,rr;
      if(a==c && b==dd && r==R){
          l=0;
          rr=2*r;
      }

      else if(d>=(r+R)){
          //case 1 non overlapping
          
          l=ceil(d-r-R);
          rr=floor(d+r+R);
      }
      else if(d>=(R-r) && d<=(r+R)){
          //case 2 partially overlapping
          
        l=0;
        rr=floor(d+r+R);

      }
      else if(d<=(R-r)){
          //case 3 one circle inside another overlap
           
        l=ceil(R-d-r);
        rr=floor(R+d+r);
      }
      
      ps[l]++;
      rr=min((long long)1000003,rr);
      if(rr!=1000004){
          ps[rr+1]--;
      }
  }

int main(){
    int n,q;
    cin>>n>>q;
    memset(ps,0,sizeof(ps));
   // set<tuple<int,int,double> >ss;
    for(int i=0;i<n;i++){
        cin>>Ai[i]>>Bi[i]>>ri[i];
       // ss.insert({Ai[i],Bi[i],ri[i]});
    }
    int i=0;
    /*for(auto it=ss.begin();it!=ss.end();it++){
       Ai[i]=get<0>(*it);
        Bi[i]=get<1>(*it);
        ri[i]=get<2>(*it);
        i++;
        //cout<<g<<"\n";
    }*/
    //n=ss.size();
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            calcRange(Ai[i],Bi[i],Ai[j],Bi[j],ri[i],ri[j]);
            
        }
    }
    for(int i=1;i<1000005;i++){
        ps[i]=ps[i]+ps[i-1];
    }
    while(q--){
        int k;
        cin>>k;
        cout<<ps[k]<<"\n";
    }

    return 0;
}