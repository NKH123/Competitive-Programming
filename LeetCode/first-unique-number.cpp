class FirstUnique {
public:
    int I=0;
    map<int, int>M;
    map<int, int>Present;
    set<pair<int, int> >S;
    FirstUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(Present[nums[i]]==0){
                S.insert({I,nums[i]});
                M[nums[i]]=I;
                I++;
                Present[nums[i]]=1;
            }
            else{
                if(S.find({M[nums[i]],nums[i]})!=S.end())
                S.erase(S.find({M[nums[i]],nums[i]}));
            }
        }
    }
    
    int showFirstUnique() {
        if(S.size()==0)return -1;
        auto g=*(S.begin());
        return g.second;
    }
    
    void add(int value) {
        if(Present[value]==0){
                S.insert({I,value});
                M[value]=I;
                I++;
                Present[value]=1;
        }
        else{
                if(S.find({M[value],value})!=S.end())
                S.erase(S.find({M[value],value}));
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */