class Solution {
public:

int largestRectangleArea(vector<int>&heights){
    stack<int>s;
    int maxArea=0;
    int n=heights.size();

    for(int i=0;i<=n;i++){
        int curr=(i==n)?0:heights[i];

        while(!s.empty() && curr<heights[s.top()]){
            int h=heights[s.top()];
            s.pop();

            int w=s.empty()?i: (i-s.top()-1);

            maxArea=max(maxArea,h*w);
        }
        s.push(i);
    }
    return maxArea;
}

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int>heights(cols,0);
        int maxArea=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    heights[j]+=1;
                }else{
                    heights[j]=0;
                }
            }
            maxArea=max(maxArea, largestRectangleArea(heights));
        }
       return maxArea;
        
    }
};