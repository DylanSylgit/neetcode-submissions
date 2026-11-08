class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // index number
        if(nums.size() == 0) return 0;
        std::unordered_map<int,int> m;
        if (nums.size() == 1) {return 1;}
        int ret = 1;

        for (int i = 0; i < nums.size(); i ++){
            m[nums[i]] = i;
        }
        for (const auto& [key,value] : m ){
            if (m.contains(key-1)){continue;}
            int maybe = 0;
            int i = key;
            while(m.contains(i)){
                maybe ++;
                i++;
            }
            ret = max(ret,maybe);
        }
        return ret;

    }
};
