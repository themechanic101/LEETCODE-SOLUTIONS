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

    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
       vector<int> arr;
        ListNode *curr=head;
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        int n=arr.size();
        int maxSum=0;
        int i=0,j=arr.size()-1;
        while(i<j){
            int sum=0;
            sum+=arr[i]+arr[n-i-1];
            maxSum=max(maxSum,sum);
            i++;j--;
        }
        return maxSum;
    }
};