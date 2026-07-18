class Solution {
public:
double rad,xc,yc;
    Solution(double radius, double x_center, double y_center) {
        rad=radius;
        xc=x_center;
        yc=y_center;
    }
    
    vector<double> randPoint() {
        double angle=(double)rand()/RAND_MAX*2*M_PI;
        double hyp=sqrt((double)rand()/RAND_MAX)*rad;
        double adj=cos(angle)*hyp;
        double opp=sin(angle)*hyp;

        return vector<double>{xc+adj,yc+opp};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */