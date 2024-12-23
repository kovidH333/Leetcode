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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int len = 0;
//         ListNode* temp = head;
//         while (temp) {
//             len++;
//             temp = temp->next;
//         }

//         int pos = len - n + 1;
//         if (pos == 1) return head->next;

//         temp = head;
//         for (int i = 1; i < pos - 1; i++) {
//             temp = temp->next;
//         }

//         temp->next = temp->next->next;

//         return head;
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head); // Dummy to handle edge cases
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;

        return dummy->next;
    }
};
