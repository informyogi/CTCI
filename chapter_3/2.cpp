#include <iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
};

class minNode {		//abstract class
	public:
		struct nodeMin {
			int data;
			struct nodeMin *next;
		};
		nodeMin *topMin=NULL;
		virtual void updateMin(int minVal) = 0;	//pure virtual function
};

class stack: public minNode {
	public:
		int minVal;
		node *top = NULL;
		void push(int n);
		void pop();
		void updateMin(int minVal);
		void min();
};

void stack::updateMin(int minVal) {
	nodeMin *newnode = new nodeMin();
	if(newnode==NULL) {
		std::cout<<"out of memory in update"<<std::endl;
		return;
	}
	newnode->data = minVal;
	newnode->next = NULL;
	if(topMin==NULL) {
		topMin = newnode;
	}
	else {
		newnode->next = topMin;
		topMin = newnode;
	}
}

void stack::push(int n) {
	//std::cout<<"inside push"<<std::endl;
	struct node *newnode = new node();
	if(newnode==NULL) {
		std::cout<<"out of memory in push"<<std::endl;
		return;
	}

	newnode->data = n;
	newnode->next = NULL;
	if(top==NULL) {
		top = newnode;
		minVal = top->data;
	}
	else {
		newnode->next = top;
		top = newnode;
	}
	//update minNode stack
	if(top->data <= minVal) {
		minVal = top->data;
		updateMin(minVal);
	}
}

void stack::pop() {
	if(top==NULL) {
		std::cout<<"stack is empty"<<std::endl;
		return;
	}
	struct node *tmp = top;
	top = top->next;
	if(tmp->data == topMin->data) {
	    struct nodeMin *minTemp = topMin;
	    topMin = topMin->next;
	    delete(minTemp);
	}
	delete(tmp);
}

void stack::min() {
    if(topMin==NULL) {
        std::cout<<"empty"<<std::endl;
        return;
    }
    
    std::cout<<"min value is:"<<topMin->data<<std::endl;
}

int main() {
	stack s;
	s.push(10);
	s.push(7);
	s.push(12);
	s.push(5);
	s.min();
	s.pop();
	s.min();
	s.push(2);
	s.min();

	return 0;
}
