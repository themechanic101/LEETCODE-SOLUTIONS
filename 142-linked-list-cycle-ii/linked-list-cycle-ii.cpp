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
    ListNode *detectCycle(ListNode *head) {
         ListNode* left = head;
        ListNode* right = head;
        while (right != NULL && right->next != NULL) {
            left = left->next;
            right = right->next->next;

            if (left == right) {
                break;
            }
        }
        
        if (right == NULL || right->next == NULL) {
            return NULL;
        }
        left = head;
        while (left != right) {
            left = left->next;
            right = right->next;
        }
        

        return left;
    }
};