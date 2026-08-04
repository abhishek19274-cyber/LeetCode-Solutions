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
    ListNode* get_KthNode(ListNode* head,int k){
        k-=1;
        while(head!= NULL and k > 0){
            head = head->next;
            k--;
        }
        return head;
    }
    ListNode* reversell(ListNode* head){
        ListNode* curr = head;
        ListNode* previous = nullptr;
        while(curr!=nullptr){
            ListNode* forw = curr->next;
            curr->next = previous;
            previous = curr;
            curr = forw;
        }
        return previous;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* previous = NULL;
        while(temp!=NULL){
            ListNode* kthnode = get_KthNode(temp,k);
            if(kthnode == NULL){
                if(previous)previous->next = temp;
                break;
            }
            ListNode* newnode = kthnode->next;
            kthnode->next =nullptr;
            reversell(temp);
            if(temp == head){
                head = kthnode;
            }
            else{
                previous->next = kthnode;
            }
            previous = temp;
            temp = newnode;
        }
        return head;
    }
};