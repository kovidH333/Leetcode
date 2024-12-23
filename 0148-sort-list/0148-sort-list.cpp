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
//     ListNode* sortList(ListNode* head) {
//         if (!head || !head->next) return head;

//         vector<int> values;
//         ListNode* temp = head;
//         while (temp) {
//             values.push_back(temp->val);
//             temp = temp->next;
//         }

//         sort(values.begin(), values.end());

//         temp = head;
//         for (int val : values) {
//             temp->val = val;
//             temp = temp->next;
//         }

//         return head;
//     }
// };

class Solution {
public:
    // Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        
        current->next = l1 ? l1 : l2;
        return dummy->next;
    }
    
    // Find the middle node of the list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    // Main sort function using merge sort
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // Base case
        
        // Split the list into two halves
        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        
        // Recursively sort both halves
        ListNode* left = sortList(head);
        right = sortList(right);
        
        // Merge the two sorted halves
        return merge(left, right);
    }
};
