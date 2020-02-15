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
	void reorderList(ListNode* head) {
		if (head == NULL) {
			return;
		}

		ListNode *index = head;
		int count = 0;
		while (index->next != NULL) {
			index = index->next;
			count += 1;
		}
		int num_move = count / 2;
		int time = 1;
		while (num_move--) {
			ListNode *cur = head, *pre;
			while (cur->next != NULL) {
				pre = cur;
				cur = cur->next;
			}
			pre->next = NULL;

			int time2 = time;
			ListNode *temp_cur = head, *temp_pre;
			while (time2--) {
				temp_pre = temp_cur;
				temp_cur = temp_cur->next;
			}
			cur->next = temp_cur;
			temp_pre->next = cur;

			time += 2;
			/***********
			cout <<"-----";
			ListNode *index2 = head;
			while(index2 != NULL){
			cout<<index2->val;
			index2 = index2->next;
			}
			***********/
		}


	}
};