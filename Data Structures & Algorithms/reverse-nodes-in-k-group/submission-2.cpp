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

 /*
    -> reverse nodes in k groups: 1st k nodes, then next k;
    -> store pointers to the nodes in a vector
    -> for every block of k nodes, reverse the order in that block
        -> leaving the elements with less that k nodes at the end alone
    -> iterate through the vector and do nodes[i]->next = nodes[i + 1];
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }

        int n = nodes.size();

        for (int i = 0; i + k <= n; i += k) {
            reverse(nodes.begin() + i, nodes.begin() + i + k);
        }

        for (int i = 0; i < n - 1; i++) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes[n - 1]->next = nullptr;

        return nodes[0];
    }
};
