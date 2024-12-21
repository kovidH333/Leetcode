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
//     bool isPalindrome(ListNode* head) {
//         vector<int> arr;
//         ListNode* temp = head;
//         while(temp){
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         int n = arr.size();
//         int i = 0;
//         int j = n-1;
//         while(i<=j){
//             if(arr[i]!=arr[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow;
        ListNode* prev = nullptr;
        ListNode* front = nullptr;
        while(temp){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = prev;
        while(temp2){
            if(temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};