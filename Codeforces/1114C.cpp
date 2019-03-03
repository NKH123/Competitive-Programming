#include <bits/stdc++.h>
#define int long long  
using namespace std; 

  
// To find the power of a prime p in 
// factorial N 
int findPowerOfP(int N, int p) 
{ 
    int count = 0; 
    int r = p; 
    while (r <= N) { 
  
        // calculating floor(n/r) 
        // and adding to the count 
        count += (N / r); 
  
        // increasing the power of p 
        // from 1 to 2 to 3 and so on 
        r = r * p; 
    } 
    return count; 
} 
  
// returns all the prime factors of k 
vector<pair<long long, long long> > primeFactorsofB(long long  B) 
{ 
    // vector to store all the prime factors 
    // along with their number of occurrence 
    // in factorization of B 
    vector<pair<int, int> > ans; 
    int ct=0;
    while(B%2==0){
        B=B/2;
        ct++;
    }
    if(ct!=0){
        ans.push_back({2,ct});
    }
  
    for (int i = 3; i<=sqrt(B); i=i+2) { 
        if (B % i == 0) { 
            int count = 0; 
            while (B % i == 0) { 
                B = B / i; 
                count++; 
            } 
  
            ans.push_back(make_pair(i, count)); 
        } 
    } 
    if(B>2){
        ans.push_back({B,1});
    }
    return ans; 
} 
  
// Returns largest power of B that 
// divides N! 
int largestPowerOfB(int N, int B) 
{ 
    vector<pair<int, int> > vec; 
    vec = primeFactorsofB(B); 
    int ans = 1e18; 
    for (int i = 0; i < vec.size(); i++) 
  
        // calculating minimum power of all 
        // the prime factors of B 
        ans = min(ans, findPowerOfP(N, 
                                    vec[i].first) 
                           / vec[i].second); 
  
    return ans; 
} 
  
// Driver code 
int32_t main() 
{   long long n,b;
    cin>>n>>b;
    cout << largestPowerOfB(n, b) << endl; 
    //cout << largestPowerOfB(6, 9) << endl; 
    return 0; 
} 