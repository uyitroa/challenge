//80ms
#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

void print(ListNode *lists)
{
	cout << "lists: ";
	while (lists != NULL)
	{
		cout << lists->val << " ";
		lists = lists->next;
	}
	cout << "\n";
}
class Solution {
private:
	ListNode *head = NULL;
	ListNode *tail = NULL;

public:

	void add_one(int min) {
		ListNode *tmp = new ListNode(min);
		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
		//delete tmp;

	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int vectorsize = lists.size();
		for(int x = 0; x < vectorsize; x++) {
			if(lists[x] == NULL) {
				lists[x] = lists[vectorsize - 1];
				vectorsize--;
			} else {
				break;
			}
		}

		while(vectorsize > 0) {
			int min = lists[0]->val;
			int smallestIndexNode = 0;

			for(int x = 0; x < vectorsize; x++) {
				if(lists[x] == NULL) {
					lists[x] = lists[vectorsize - 1];
					vectorsize--;
					x--;
					continue;
				}
				int value = lists[x]->val;
				if(min > lists[x]->val) {
					smallestIndexNode = x;
					min = lists[x]->val;
				}
			}
			if(vectorsize == 0)
				break;
			add_one(min);
			lists[smallestIndexNode] = lists[smallestIndexNode]->next;
			if (lists[smallestIndexNode] == NULL) {
				lists[smallestIndexNode] = lists[vectorsize - 1];
				vectorsize--;
			}
		}
		return head;
	}

};

class Linked_list {
public:
	ListNode *head, *tail;
	Linked_list(int a, int b, int c = -1)
	{
		head = NULL;
		tail = NULL;
		add_one(a);
		add_one(b);
		if(c != -1)
			add_one(c);

	}

	void add_one(int p) {
		ListNode *tmp = new ListNode(p);

		if(head == NULL) {
			head = tmp;
			tail = tmp;
		} else {
			tail->next = tmp;
			tail = tail->next;
		}
	}

	void print()
	{
		cout << head->val << "\n";
	}
};

int main() {
	vector<ListNode*> lists(3);

	Linked_list l1(1,2,3);
	Linked_list l2(69,70,200);
	Linked_list l3(5, 201);
	lists[0] = l1.head;
	lists[1] = l2.head;
	lists[2] = l3.head;
	Solution solution;
	ListNode *list = solution.mergeKLists(lists);
	print(list);
	/* delete l1.head;
	delete l2.head;
	delete l3.head;

	delete list; */
	return 0;
}
