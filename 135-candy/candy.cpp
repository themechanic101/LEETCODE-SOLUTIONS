class Solution {
public:
    int candy(vector<int>& ratings) {
       int n=ratings.size();


       int i=1,candies=n;


       while(i<n){
        if(ratings[i]==ratings[i-1]){
            i++;
            continue;
        }


        int peak=0;

        while(i<n && ratings[i]>ratings[i-1]){
            peak++;
            candies+=peak;
            i++;
        }


        int down=0;

        while(i<n && ratings[i]<ratings[i-1]){
            down++;
            candies+=down;
            i++;
        }

        candies-=min(down,peak);
       }


       return candies;

    }
};