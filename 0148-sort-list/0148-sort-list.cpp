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
    ListNode* Merge(ListNode* lf,ListNode* rf){
        ListNode DNode(-1);
        ListNode* temp = &DNode;
        while(lf and rf){
            if(lf->val < rf->val){
                temp->next = lf;
                lf= lf->next;
            }
            else{
                temp->next = rf;
                rf = rf->next;
            }
            temp = temp->next;
        }
        if(lf == NULL)temp->next = rf;
        if(rf == NULL)temp->next = lf;
        return DNode.next;
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* MergeSort(ListNode* head){
        if(!head or !head->next){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* left_head = head;
         ListNode* right_head = middle->next;
        middle->next = NULL;
        left_head = MergeSort(left_head);
        right_head = MergeSort(right_head);
        return Merge(left_head,right_head);
    }
    ListNode* sortList(ListNode* head) {
        return MergeSort(head);
    }
};