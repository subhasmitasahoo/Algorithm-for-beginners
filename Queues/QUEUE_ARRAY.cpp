#include <bits/stdc++.h>

using namespace std;

class QUEUE_ARRAY{
private:
	int arr[1000];
	int sz;
	int maxi;

public:
	QUEUE_ARRAY(){
		sz = 0;
		maxi = 1000;
	}

	void push(int val){
		if(sz >= maxi){
			cout<<"Queue Overflowing..."<<endl;
			return;
		}
		arr[sz] = val;
		sz++;
		cout<<"Pushed..."<<endl;
	}

	int pop(){
		if(sz == 0){
			cout<<"Queue underflowing..."<<endl;
			return -1;
		}
		sz--;
		return arr[0];
	}

	bool empty(){
		if(sz == 0)
			return true;
		return false;
	}

	int size(){
		return sz;
	}

	int top(){
		if(sz == 0){
			cout<<"Queue underflowing..."<<endl;
			return -1;
		}
		return arr[0];
	}
};

int main(){

	QUEUE_ARRAY s;
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
				int ele = s.pop();
				cout<<"Popped "<<ele<<endl;
				cout<<"Current Top: "<<s.top()<<endl;
				break;
			case 3:
				if(s.empty())
					cout<<"Queue is Empty"<<endl;
				else
					cout<<"Queue is not Empty"<<endl;
				break;
			case 4:
				cout<<"Queue size is: "<<s.size()<<endl;
				break;
			case 5:
				cout<<"Current top element: "<<s.top()<<endl;
				break;
		}
		 
	}
	return 0;
}