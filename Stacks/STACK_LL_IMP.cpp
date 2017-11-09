#include <bits/stdc++.h>

using namespace std;

class Node{
private:
		int val;
		Node *next;
public:
	Node(){

	}
	void set_value(int value){
		val = value;
		next = NULL;
	}
	void set_next(Node *temp){
		next = temp;
	}
	int get_value(){
		return val;
	}
	Node* get_next(){
		return next;
	}
	};

class STACK_LL_MP{
private:
	Node *head;
	int sz;

public:
	STACK_LL_MP(){
		head = NULL;
		sz = 0;
	} 
	void push(int value){
		Node *temp = head;
		Node *new_node = new Node();
		new_node->set_value(value);
		new_node->set_next(temp);
		head = new_node;
		sz++;
	}

	int pop(){
		int res;
		if(!head){
			cout<<"Already empty"<<endl;
			res = -1;
		}
		else{
			res = head->get_value();
			head = head->get_next();
			sz--;
		}
		return res;
	}

	int size()
	{
		return sz;
	}

	bool empty(){
		if(!head)
			return true;
		else
			return false;
	}

	int top(){
		if(!head){
			cout<<"Empty..."<<endl;
			return -1;
		}
		return head->get_value();
	}
};

int main(){

	STACK_LL_MP s;
	int t;
	cout<<"Enter the no. of queries: ";
	cin>>t;

	cout<<"\n\tPush: 1 val\n\tPop: 2\n\tIsEmpty: 3\n\tSize: 4\n\tTop: 5"<<endl;
	int type,val;
	while(t--){
		cin>>type;
		switch(type){
			case 1:
				cin>>val;
				s.push(val);
				cout<<"Pushed"<<endl;
				cout<<"Current Top: "<<s.top()<<endl;
				break;
			case 2:
				int val = s.pop();
				cout<<"Popped "<<val<<endl;
				cout<<"Current Top: "<<s.top()<<endl;
				break;
			case 3:
				if(s.empty())
					cout<<"Stack is Empty"<<endl;
				else
					cout<<"Stack is not Empty"<<endl;
				break;
			case 4:
				cout<<"Stack size is: "<<s.size()<<endl;
				break;
			case 5:
				cout<<"Current top element: "<<s.top()<<endl;
				break;
		}
		 
	}
	return 0;
}