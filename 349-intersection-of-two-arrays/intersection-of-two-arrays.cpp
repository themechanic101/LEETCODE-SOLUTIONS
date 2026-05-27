class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>hash(1001,0);
        vector<int>ans;
        set<int>s;

        for(int i=0;i<nums1.size();i++){
            hash[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){
            if(hash[nums2[i]]>0 && s.find(nums2[i])==s.end()){
                ans.push_back(nums2[i]);
                s.insert(nums2[i]);
            }
        }

        return ans;
    }
};