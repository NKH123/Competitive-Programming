class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> >ans;
        int ct[26];
        int ct1[26];
        ans.resize(1);
        ans[0].push_back(strs[0]);
        for(int i=1;i<strs.size();i++){
        	deb(i);
        	deb(ans);
            int f=0;
            memset(ct,0,sizeof(ct));
            for(int j=0;j<strs[i].size();j++){
                ct[strs[i][j]-'a']++;
            }
            for(int j=0;j<ans.size();j++){
                f=0;
                memset(ct1,0,sizeof(ct1));
                for(int k=0;k<ans[j][0].size();k++){
                    ct1[ans[j][0][k]-'a']++;
                }
                for(int k=0;k<26;k++){
                    if(ct[k]==ct1[k]){
                        
                    }
                    
                    else{
                        f=1;
                    }
                }
                if(f==0){
                    ans[j].push_back(strs[i]);
                    break;
                }
                
            }
            if(f==1){
                vector<string>S;
                S.clear();
                S.push_back(strs[i]);
                ans.push_back(S);
            }
        }
        return ans;
    }
};