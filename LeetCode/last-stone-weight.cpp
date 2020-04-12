class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int>S;
        for(auto g:stones){
            S.insert(-g);
        }
        while(S.size()>=2){
            int FF=*(S.begin());
            S.erase(S.begin());
            int SS=*(S.begin());
            S.erase(S.begin());
            int ele=-(-(FF)+SS);
            S.insert(ele);
        }
        int ans=*(S.begin());
        return -ans;
        
    }
};