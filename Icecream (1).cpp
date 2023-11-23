
#include <iostream>

using namespace std;
struct Node {
	int data;
	Node * next;
	Node *Butter,*Vanilla,*temp,*cur;
	void addLast1 (int);
	void addLast2 (int);
	void display1 ();
	void display2 ();
	void intersection();
	void onlyB();
	void uni();
	
	
}ob;


void Node::addLast1 (int data) 
{
	cur =new Node;
	cur=Butter;
	Node *ptr = new Node();
	ptr -> data = data;
	ptr -> next = NULL;
	if(Butter==NULL)
		Butter=ptr;
	else{

		while(cur->next!=NULL) 
		{
			cur=cur->next;
		}
		cur->next=ptr;
	}
}

void Node:: addLast2 (int data) {
	Node *cur =new Node;
	cur=Vanilla;
	Node *ptr = new	Node();
	ptr -> data = data;
	ptr -> next = NULL;
	if(Vanilla==NULL)
		Vanilla=ptr;
	else{

		while(cur->next!=NULL) {
			cur=cur->next;
		}
		cur->next=ptr;
	}
}

void Node:: display1 () {
	Node *cur = Butter;
	while(cur) {
		if ( cur -> next == NULL) {
			cout << cur -> data;
		}
		else
			cout << cur -> data << ",";
		cur = cur -> next;
	}
	cout << endl; cout << endl;
}
void Node::display2 () {
	Node *cur = Vanilla;
	while(cur) {
		if ( cur -> next == NULL) {
			cout << cur -> data;
		}
		else
			cout << cur -> data << ",";
		cur = cur -> next;
	}
	cout << endl; cout << endl;
}
void Node:: intersection()
{
	Node *cur1=Butter;
	Node *cur2=Vanilla;

	int found=0;
	while(cur1)
	{
		while(cur2)
		{
			if(cur1->data==cur2->data){
				found=1;
				break;
			}
			else
				cur2=cur2->next;
		}
		if(found==1){
			cout<<cur1->data<<" ";
			cur1=cur1->next;
			found=0;
		}
		else
			cur1=cur1->next;
		cur2=Vanilla;
	}

}
void Node:: onlyB(){
	Node *cur1=Butter;
	Node *cur2=Vanilla;
	int found=0;
	while(cur1)
	{
		while(cur2){
			if(cur1->data==cur2->data){
				found=1;
				break;
			}
			else{
				cur2=cur2->next;
			}
		}
		if(found==1){
			cur1=cur1->next;
			found=0;
		}
		else{
			cout<<cur1->data<<" ";
			cur1=cur1->next;
		}
		cur2=Vanilla;
	}
}
void Node:: onlyV(){
	Node *cur1=Butter;
	Node *cur2=Vanilla;
	int found=0;
	while(cur2){
		while(cur1){
			if(cur2->data==cur1->data){
				found=1;
				break;
			}
			else{
				cur1=cur1->next;
			}
		}
		if(found==1){
			cur2=cur2->next;
			found=0;
		}
		else{
			cout<<cur2->data<<" ";
			cur2=cur2->next;
		}
		cur1=Butter;
	}
}
void Node:: uni(){
	onlyB();
	intersection();
	onlyV();
}
int main()
{
	int ch,no;
	Node ob;


	do{
		cout<<"\n1)Add students who like ButterScotch\n"
				"2)Add students who like Vanilla\n"
				"3)Display students who like ButterScotch\n"
				"4)Display students who like Vanilla\n"
				"5)Students who like Both ButterScotch n Vanilla\n"
				"6)Set of students who like  only vanilla not ButterScotch \n"
				"7)Set of students who like only ButterScotch not vanilla\n"
				"8)Set of students who like icecream(UNION)\n"
				"9) Exit :( :( \n > ";
		cin>>ch;
		switch(ch){
		case 1:

			cout<<"\nEnter the roll no. of students >>";
			cin>>no;

			ob.addLast1(no);
			break;
		case 2:
			cout<<"\nEnter the roll no. of students >>";
			cin>>no;
			ob.addLast2(no);
			break;
		case 3:
			ob.display1();
			break;
		case 4:
			ob.display2();
			break;
		case 5:
			ob.intersection();
			break;
		case 6:
			ob.onlyV();
			break;
		case 7:
			ob.onlyB();
			break;
		case 8:
			ob.uni();
			break;
		case 9:
			return 0;
			break;

		}

	}while(1);
}



















