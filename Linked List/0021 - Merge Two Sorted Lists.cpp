//Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/submissions/
//Time Complexity: O(max(n, m))
//Space Complexity: O(1) -> Constant

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *head = NULL;
        
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        int x = list1->val;
        int y = list2->val;
        
        if(x < y){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        
        ListNode *finalAns = head;
        
        while(list1 && list2){
            int x = list1->val;
            int y = list2->val;
            
            if(x < y){
                finalAns->next = list1;
                list1 = list1->next;
            }
            else{
                finalAns->next = list2;
                list2 = list2->next;
            }
            
            finalAns = finalAns->next;
            
        }
        
        while(list1){
            finalAns->next = list1;
            list1 = list1->next;
            finalAns = finalAns->next;
        }
        
        while(list2){
            finalAns->next = list2;
            list2 = list2->next;
            finalAns = finalAns->next;
        }
        
        return head;
        
    }
};