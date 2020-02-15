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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		ListNode *index = head->next, *result = new ListNode(head->val);
		while (index != NULL) {
			ListNode *cur = result, *pre;
			while (cur != NULL) {
				if (cur == result && cur->val >= index->val) {
					ListNode *temp = new ListNode(index->val);
					temp->next = result;
					result = temp;
					break;
				}
				if (cur->val >= index->val) {
					ListNode *temp = new ListNode(index->val);
					temp->next = cur;
					pre->next = temp;
					break;
				}
				pre = cur;
				cur = cur->next;
			}
			if (cur == NULL) {
				ListNode *temp = new ListNode(index->val);
				pre->next = temp;
			}
			index = index->next;
		}

		return result;
	}
};