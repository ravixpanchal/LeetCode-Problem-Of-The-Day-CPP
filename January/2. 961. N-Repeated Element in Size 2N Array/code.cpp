class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>m; //number,frequency
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])){
                m[nums[i]]++;
            }else{
                m[nums[i]]=1;
            }
        }

        for(auto &i:m){
            if(i.second==nums.size()/2){
                ans=i.first;
             
            }
        }
        return ans;

        
    }
};