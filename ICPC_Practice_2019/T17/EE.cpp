#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
//vector <int>
// push_back
// char ice[n][m]



ll logg(ll num, ll base){
    ll count = 0;
    while(num){
        count++;
        num/=base;
    }

    return count;
}

ll getval(string s){
    ll val=0;
    for(int i=0; i<s.size(); i++){
        val = val*7+(s[i]-'0');
    }

    return val;
}

bool valid(string s, ll n, ll m, ll digh, ll digm){
    string hours = s.substr(0, digh);
    string minutes = s.substr(digh, digm);

    ll h = getval(hours);
    ll mm = getval(minutes);

    if(h<=n-1 && mm<=m-1){
        cout<<s<<" "<<h<<" "<<mm<<"\n";
        return true;
    }

    return false;
}


int main(){
    
    string s;

    cin>>s;
    ll i=0;
    for(i=0; i<s.size();  i++)
    {
        if(s[i]=='M')
            break;
    }
    ll len = s.size();
    s = s.substr(i, len-i);

    ll wait = 0;
    ll man = 0;
    ll total = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='M')
            man++;

        else{
         
            if(s[i-1]=='F')
                wait++;

            else{
                wait = max(wait, wait-man+1);
            }
            cout<<wait<<"^"<<endl;
            man =0;
        }
    }

    for(int i=0; i<s.size(); i++){
        if(s[i]=='M')
            man++;
    }

    for(int i=s.size()-1; i>=0; i--){
        if(s[i]=='M')
            man--;

        else
            break;
    }
    cout<<"M "<<man<<"\n";
    cout<<wait+man<<"\n";

    
}


