class Solution {
public:
int largestRectangleArea(vector<int> heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;

 
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
          if(st.empty())left[i]=-1;
          else left[i]=st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty())right[i] =  n;
            else right[i]=st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxarea=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>temp(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')temp[j]++;
                else temp[j]=0;
            }
            int area=largestRectangleArea(temp);
            maxarea=max(area,maxarea);
        }

        return maxarea;
    }
};