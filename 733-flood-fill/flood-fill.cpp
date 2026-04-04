class Solution {
public:
int m,n;

void dfs(vector<vector<int>>& image,int &m,int &n,int row,int col,int c,int &color){
    if(row>=m || col>=n ||row<0 || col<0)return ;
    if(image[row][col]!=c || image[row][col]==color)return ;


    
    image[row][col]=color;
    

    dfs(image,m,n,row+1,col,c,color);
    dfs(image,m,n,row-1,col,c,color);
    dfs(image,m,n,row,col+1,c,color);
    dfs(image,m,n,row,col-1,c,color);
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         m=image.size();
         n=image[0].size();
        if(sr>=m  || sc>=n)return image;

        int c=image[sr][sc];

        dfs(image,m,n,sr,sc,c,color);

        return image;
    }
};