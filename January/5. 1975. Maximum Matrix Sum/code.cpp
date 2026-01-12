class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int negative_count=0;
        int minAbsSum=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int val=matrix[i][j];

                if(val<0){
                    negative_count++;
                }

                ans+=abs(val);

                minAbsSum=min(minAbsSum,abs(val));
            }
        }

        if(negative_count%2==1){
            ans-=2*minAbsSum;
        }
        return  ans;
        
    }
};