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
		while(lists.size() > 0) {

			int min = 2147483647;
			int smallestIndexNode = 0;

			for(int x = 0; x < lists.size(); x++) {
				if(lists[x] == NULL) {
					lists.erase(lists.begin() + x);
					x--;
				} else {
					int value = lists[x]->val;
					if(min > lists[x]->val) {
						smallestIndexNode = x;
						min = lists[x]->val;
					}
				}
			}
			if(lists.size() == 0)
				break;
			add_one(min);
			lists[smallestIndexNode] = lists[smallestIndexNode]->next;
			if (lists[smallestIndexNode] == NULL)
				lists.erase(lists.begin() + smallestIndexNode);
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