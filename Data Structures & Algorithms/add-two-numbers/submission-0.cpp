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
    // given: two non-empty lls
    // digits stored in reverse order: 1 -> 2 -> 3 -> NULL : 321
    // two pointers: which run till one of the two lists is exhausted
    // add two numbers: 
    // if currNode->val = sum % 10 + carry, carry = sum / 10;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;

        int carry = 0;
        ListNode dummy(-1);
        ListNode *curr = &dummy;
        while (curr1 && curr2) {
            int sum = curr1->val + curr2->val;
            curr->next = new ListNode((sum + carry) % 10);
            carry = (sum + carry) / 10;
            curr = curr->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while (curr1) {
            int sum = curr1->val;
            curr->next = new ListNode((sum + carry) % 10);
            carry = (sum + carry) / 10;
            curr = curr->next;
            curr1 = curr1->next;
        }

        while (curr2) {
            int sum = curr2->val;
            curr->next = new ListNode((sum + carry) % 10);
            carry = (sum + carry) / 10;
            curr = curr->next;
            curr2 = curr2->next;
        } 

        if (carry) {
            curr->next = new ListNode(carry);
        }
        
        return dummy.next;
    }
};
