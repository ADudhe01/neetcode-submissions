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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;
        ListNode *curr = head;
        while (curr) {
            curr = curr->next;
            num++;
        }

        ListNode dummy(-1);
        dummy.next = head;
        curr = &dummy;

        int idx = 0;
        while (idx < num - n) {
            curr = curr->next;
            idx++;
        }

        curr->next = curr->next->next;
        return dummy.next;
    }
};
