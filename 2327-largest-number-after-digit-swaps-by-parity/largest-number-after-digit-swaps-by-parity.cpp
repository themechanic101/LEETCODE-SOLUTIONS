class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> odd, even;

        // Separate digits
        for (char c : s) {
            int d = c - '0';
            if (d % 2 == 0) even.push_back(d);
            else odd.push_back(d);
        }

    
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());

        int oi = 0, ei = 0;
        string ans = "";

        
        for (char c : s) {
            int d = c - '0';
            if (d % 2 == 0) {
                ans += char('0' + even[ei++]);
            } else {
                ans += char('0' + odd[oi++]);
            }
        }

        return stoi(ans);
    }
};