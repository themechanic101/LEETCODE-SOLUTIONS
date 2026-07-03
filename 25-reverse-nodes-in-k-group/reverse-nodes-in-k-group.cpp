/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>arr;
         ListNode* temp=head;

         while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
         }


         for(int i=0;i<arr.size();i+=k){
            if(i+k<=arr.size()){
                reverse(arr.begin()+i,arr.begin()+i+k);
            }
         }
        ListNode *head1=new ListNode(arr[0]);
        ListNode *tail=head1;

        for(int i=1;i<arr.size();i++){
            tail->next=new ListNode(arr[i]);
            tail=tail->next;
        }

        return head1;

    }
};