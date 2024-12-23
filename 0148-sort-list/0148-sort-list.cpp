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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<int> values;
        ListNode* temp = head;
        while (temp) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        sort(values.begin(), values.end());

        temp = head;
        for (int val : values) {
            temp->val = val;
            temp = temp->next;
        }

        return head;
    }
};