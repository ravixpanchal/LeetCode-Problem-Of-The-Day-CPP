class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

// If s2 is empty, delete all remaining characters of s1
        for(int i=n-1;i>=0;i--){
        dp[i][m]=dp[i+1][m]+int(s1[i]);
        }

// If s1 is empty, delete all remaining characters of s2
        for(int j=m-1;j>=0;j--){
        dp[n][j]=dp[n][j+1]+int(s2[j]);
        }

        //Fill the DP
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }else{
                    dp[i][j]=min((dp[i+1][j]+int(s1[i])),dp[i][j+1]+int(s2[j]));
                }
            }
        }
        return dp[0][0];
    }
};