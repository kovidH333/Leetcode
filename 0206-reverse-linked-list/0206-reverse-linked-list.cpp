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
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp = head;
//         ListNode* prev = NULL;
//         ListNode* front = NULL;

//         while(temp){
//             front = temp->next;
//             temp->next = prev;
//             prev = temp;
//             temp = front;
//         }
//         return prev;
//     }
// };

class Solution {
public:
    ListNode* reverse(ListNode* temp, ListNode* prev){
        if(temp == nullptr) return prev;
        ListNode* front = temp-> next;
        temp->next = prev;
        return reverse(front,temp);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head,nullptr);
    }
};