//Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/submissions/
//Space Complexity: O(1)
//Time Complexity: O(K * (N)) -> N = Maximum length of a linked list

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
private:
    void merge(ListNode *list1, ListNode *&list2){
        
        if(list1 == NULL){
            return;
        }
        
        if(list2 == NULL){
            list2 = list1;
            return;
        }
        
        ListNode *head = NULL;
        
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
        
        list2 = head;
        
    }
    
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = NULL;
        if(lists.size() == 0)
            return ans;
        int i = 0, n = lists.size();
        for(i = 0; i < n-1; i++){
            merge(lists[i], lists[i+1]);
        }
        return lists[n-1];
    }
};