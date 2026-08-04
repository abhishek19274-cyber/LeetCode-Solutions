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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next)return head;
        ListNode* temp = head;
        int llsize =1;
        while(temp->next){
            llsize++;
            temp= temp->next;
        }
        k = k % llsize;
        if (k == 0) {
            temp->next = nullptr;
            return head;
        }
        temp->next = head;
        int correct_node = llsize -k;
        temp = head;
        ListNode* newhead = nullptr;
        for(int i=1;i<correct_node;i++){
            temp = temp->next;
        }
        newhead = temp->next;
        temp->next = nullptr;
        return newhead;
    }
};