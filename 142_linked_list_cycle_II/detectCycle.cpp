#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode *detectCycle(ListNode *head) {
            ListNode* slow = head, *fast = head;
            while(slow && fast && fast->next) {
                slow = slow -> next;
                fast = fast -> next -> next;
                if(slow == fast) break;
            }
            if(!fast || !fast->next) return NULL;
            fast = head;
            while(slow != fast) {
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow; 
    	}
};
