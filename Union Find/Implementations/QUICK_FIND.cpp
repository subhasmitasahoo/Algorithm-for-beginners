//This is also called as Eager Approach to algorithm design
//Initialization: O(N)
//Union : O(N)
//Find : O(1)

#include <bits/stdc++.h>

using namespace std;


class QUICK_FIND{

private:
	std::vector<int> id;
	int sz;

public:

	QUICK_FIND(int n){
		for(int i=0;i<n;i++)
			id.push_back(i);
		sz = n;
	}

	bool connected(int p, int q){
		if(id[p] == id[q])
			return true;
		return false;
	}

	void unions(int p, int q){
		int pid = id[p];
		if(id[p]!=id[q])
		{
			for(int i=0;i<sz;i++)
			{
				if(id[i]==pid)
					id[i] = id[q];
			}
		}
	}
};


int main()
{
	int n;
	cout<<"Enter the value of Object size: ";
	cin>>n;

	QUICK_FIND qf = QUICK_FIND(n);

	cout<<"Enter the queries in the following format:"<<endl;
	cout<<"\t1. For union: U p q\n\t2. For find: C p q"<<endl;

	char type;
	int p,q;

	int t;
	cout<<"Enter the number of queries: ";
	cin>>t;

	while(t--)
	{
		cin>>type>>p>>q;

		if(tolower(type) == 'u'){
			qf.unions(p,q);
			cout<<"united..."<<endl;
		}
		else if(tolower(type) == 'c'){
			if(qf.connected(p,q))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else{
			cout<<"INVALID..."<<endl;
		}
	}
	return 0;
}

