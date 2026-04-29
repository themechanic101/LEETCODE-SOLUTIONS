/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         ListNode *curr=head;
        unordered_map<ListNode *,int>mp;
        while(curr){
            if(mp.find(curr)!=mp.end()){
                return true;
            }
            mp[curr]=curr->val;
            curr=curr->next;
        }
        return false;
    }
};