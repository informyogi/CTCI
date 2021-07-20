/*Program to remove duplictes from linklist*/

#include<iostream>
using namespace std;

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
		void removeDuplicate();
};

void linkList::removeDuplicate() {
	node *current = head;
	node *prev = NULL;
	while(current!=NULL) {
		node *tmp = current->next;
		while(tmp!=NULL) {
			if(tmp->data==current->data) {
				prev->next = tmp->next;
				node *del = tmp;
				delete(del);
				tmp=tmp->next;
			}
			else {
				prev = tmp;
				tmp = tmp->next;
			}

		}
		current = current->next;

	}
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
	ll.insert(4);
	ll.insert(3);
	ll.insert(4);
	ll.insert(5);
	ll.insert(3);
	std::cout<<"before removing duplictes:"<<std::endl;
	ll.display();
	std::cout<<"after removing duplicates:"<<std::endl;
	ll.removeDuplicate();
	ll.display();

	return 0;
}
