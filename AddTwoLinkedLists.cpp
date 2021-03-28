// https://leetcode.com/problems/add-two-numbers/

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
private:
    int tempsum;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return linkedSum(l1, l2);
    }
    
    ListNode* linkedSum(ListNode* l1, ListNode* l2, int carry = 0) {
        if (l1 == nullptr && l2 == nullptr) {
            return (carry > 0) ? new ListNode(carry, nullptr) : nullptr;
        }
        
        tempsum = carry;
        if (l1) {
            tempsum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            tempsum += l2->val;
            l2 = l2->next;
        }
        
        carry = (tempsum > 9) ? 1 : 0; // can't be greater than 1
        
        return new ListNode(tempsum % 10, linkedSum(l1, l2, carry));
    }
};
