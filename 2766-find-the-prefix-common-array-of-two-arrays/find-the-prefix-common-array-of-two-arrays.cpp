class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        vector<int> res(n);
        vector<int> seen(51,0);

        for (int i = 0; i < n; i++) {
            count += seen[A[i]];
            seen[A[i]]=1;

            count += seen[B[i]];
            seen[B[i]]=1;

            res[i] = count;
        }

        return res;
    }
};