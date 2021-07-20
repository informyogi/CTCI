/*Program to find Kth element to the last in a linklist*/

#include<iostream>
using namespace std;

class index {
	public: int count;
};
class node {
	public:
		int data;
		node *next;
};
class linkList : public node{
	node *head;
	public:
		linkList() {head=NULL;}
		void insert(int n);
		void display();
		node* kthElement(node *head, int k, index& ind);
		int FindkthElements(int k);
};
int linkList::FindkthElements(int k) {
	index ind;
	ind.count=0;
	node *res = kthElement(head, k, ind);
	return res->data;
}

node* linkList::kthElement(node *head, int k, index& ind) {
	if(head==NULL)
		return NULL;
	node *n = kthElement(head->next, k, ind);
	if(ind.count==k) {
		ind.count++;
		return head;
	}
	ind.count = ind.count+1;
	return n;
}

void linkList::insert(int n) {
	node *newnode = new node();
	newnode->data = n;
	newnode->next = NULL;
	if(head==NULL) {
		head = newnode;
	}
	else {
		node *tmp = head;
		while(tmp->next!=NULL) {
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}
}
void linkList::display() {
	node *tmp=NULL;
	tmp = head;
	while(tmp!=NULL) {
		std::cout<<tmp->data<<std::endl;
		tmp=tmp->next;
	}
}

int main() {
	linkList ll;
	ll.insert(1);
	ll.insert(2);
	ll.insert(3);
	ll.insert(4);
	ll.insert(5);
	ll.insert(6);
	std::cout<<"LinkList is:"<<std::endl;
	ll.display();
	std::cout<<"Kth element to last:"<<ll.FindkthElements(5)<<std::endl;

	return 0;
}
