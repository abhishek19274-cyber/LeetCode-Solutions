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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* p1 = head;
        ListNode* result = head;
        if(p1 == NULL or p1->next == NULL){
            return head;
        }
        ListNode* p2 = head->next;
        ListNode* temp = p2;
        while(p1 and temp){
            if(temp->next == NULL)break;
            p1->next = temp->next;
            p1 = p1->next;
            temp->next = p1->next;
            temp = temp->next;

        }
        p1->next = p2;
        return result;
    }
};