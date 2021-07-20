/*Sum of two linklist represented in a linklist*/

#include<iostream>
#include <math.h>
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
		void sumOfLL(node **head1, node **head2, node*& head3);
		int getNumber(node**& temp);
};
int linkList::getNumber(node**& head) {
	int power=0;
	int base=10;
	int num=0;
	node *temp = *head;
	while(temp!=NULL) {
		num = num+(temp->data*pow(base, power));
		temp=temp->next;
		power++;
	}
	return num;
}
void linkList::sumOfLL(node **head1, node **head2, node*& head3) {
	int num1 = getNumber(head1);
	int num2 = getNumber(head2);
	int res = num1+num2;
	int val;
	while(res>0) {
		val = res%10;
		insert(&head3,val);
		res = res/10;
	}

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
	node *head1=NULL;
	node *head2=NULL;
	node *head3=NULL;
	linkList ll;
	ll.insert(&head1, 7);
	ll.insert(&head1, 1);
	ll.insert(&head1, 6);
	ll.insert(&head2, 5);
	ll.insert(&head2, 9);
	ll.insert(&head2, 2);
	std::cout<<"LinkList is:"<<std::endl;
	ll.display(&head1);
	std::cout<<std::endl;
	ll.display(&head2);
	std::cout<<std::endl;
	ll.sumOfLL(&head1, &head2, head3);
	std::cout<<"result LL is: "<<std::endl;
	ll.display(&head3);
	return 0;
}
