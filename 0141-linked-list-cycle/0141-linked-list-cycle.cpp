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
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> visited; 
        ListNode* temp = head;

        while (temp) {
            if (visited.find(temp) != visited.end()) {
                return true;
            }
            visited.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};
