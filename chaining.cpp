#include<iostream>
#include<list>
using namespace std;
class chaining{
	public:
	int size;
	protected:
	list<int> *table;
	
	public:
		chaining(int);
		void insert(int);
		int search(int);
		void deleted(int key);
		void print();
		~chaining();
	
};

chaining::chaining(int size){
	
	this->size=size;
	table=new list<int>[size];
}

void chaining::insert(int key){
	
	int pos=key%size;
	table[pos].push_back(key);
}

int chaining::search(int key){
	
	int pos=key%size;
	list<int>::iterator it;
	for(it=table[pos].begin();it!=table[pos].end();it++){
		
		if(*it==key)
		return 1;
	}
	
	return 0;
}

void chaining::deleted(int key){
	
	int flag;
	int pos=key%size;
	list<int>::iterator it;
	for(it=table[pos].begin();it!=table[pos].end();it++){
		
		if(*it==key){
			flag=1;
			break;
		}
	
		else
		flag=0;
	}
	
	if(flag)
	table[pos].remove(key);
	
	else
	cout<<"Not found"<<endl;
}

void chaining::print(){
	
	int i;
	list<int>::iterator it;
	for(i=0;i<size;i++){
		if(table[i].empty())
		continue;
		
		else{
			
			for(it=table[i].begin();it!=table[i].end();it++)
			
			cout<<*it<<"->";
		}
		
		cout<<endl;
	}
}

chaining::~chaining(){
	
int i;
for(i=0;i<size;i++)
table[i].clear();
}
int main(){
	
	cout<<"Enter the size of the table"<<endl;
	int s;
	cin>>s;
	chaining obj(s);
	cout<<"Enter the number of elements"<<endl;
	int no;
	cin>>no;
	cout<<"Enter the elements"<<endl;
	int j,temp;
	for(j=0;j<no;j++){
		
		cin>>temp;
		obj.insert(temp);
	}
	j=1;
	while(j){
		
		cout<<"Enter the choice you want"<<endl;
		int choice,key;
		cout<<"1.Delete"<<endl;
		cout<<"2.Print"<<endl;
		cout<<"3.Search"<<endl;
		cin>>choice;
		switch(choice){
			
			case 1:	cout<<"Enter the key"<<endl;
		     cin>>key;
			obj.deleted(key);
			break;
			
			case 2:obj.print();
			break;
			
			case 3:	cout<<"Enter the key"<<endl;
		    cin>>key;
			obj.search(key);
			break;
		}
		
		cout<<"Do you want to proceed?"<<endl;
		char ch;
		cin>>ch;
		if(ch=='y'||ch=='Y')
		j=1;
		
		else if(ch=='n'||ch=='N')
		j=0;
	}
	
	obj.~chaining();
}

