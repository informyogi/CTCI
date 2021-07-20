/*Check if LinkList is a palindrom*/

#include <iostream>
#include <stack>
using namespace std;

class node {
	public:
		int data;
		node *next;
};
class linkList : public node{
	public:
		void insert(node **head, int n);
		void display(node **head);
		bool isPalindrome(node **head);
};

bool linkList::isPalindrome(node **head) {
	stack<int> stack;
	node *f=NULL;
	node *s=NULL;
	s = *head;
	f = s->next;
	while(f!=NULL) {
		stack.push(s->data);
		s = s->next;
		f= f->next->next;
	}
	stack.push(s->data);
	while(s!=NULL) {
		if(s->data != stack.top())
			return false;	
		stack.pop();
		s = s->next;

	}
	return true;
}

void linkList::insert(node **head, int n) {
	node *newnode = new node();
	newnode->data = n;
	newnode->next = NULL;
	if(*head==NULL) {
		*head = newnode;
	}
	else {
		node *temp = *head;
		while(temp->next!=NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}
void linkList::display(node **head) {
	node *tmp=NULL;
	tmp = *head;
	while(tmp!=NULL) {
		std::cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
}

int main() {
	node *head=NULL;
	linkList ll;
	ll.insert(&head, 1);
	ll.insert(&head, 2);
	ll.insert(&head, 3);
	ll.insert(&head, 3);
	ll.insert(&head, 2);
	ll.insert(&head, 1);
	std::cout<<"LinkList is:"<<std::endl;
	ll.display(&head);
	std::cout<<std::endl;
	bool res = ll.isPalindrome(&head);
	if(res)
		std::cout<<"LL is palindrome"<<std::endl;
	else
		std::cout<<"LL is not palindrome"<<std::endl;
	
	return 0;
}
