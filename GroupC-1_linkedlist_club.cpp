/* Group C-1
Department of Computer Engineering has student's club named 'Pinnacle Club'.
Students of Second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club.First node is reserved for president of club and last node
is reserved for secretary of club. Write C++ program to maintain club members information
using singly linked list. Store student PRN and Name.
Write functions to
a)	Add and delete the members as well as president or even secretary.
b)	Compute total number of members of club
c)	Display members
d)	Two linked lists exists for two divisions. Concatenate two lists.
*/


#include<iostream>
using namespace std;

struct NODE
{
    int prn;
    char name[10];
    struct NODE *next;
};
typedef struct NODE node;

class Pinnacle_club
{
 private:
        node *president;
        node *secretary;

 public:
         Pinnacle_club();
         ~Pinnacle_club();
         void add_member();
         void delete_member();
         void display_members();
         void display_total_members();
         void concatinate(Pinnacle_club &);
};

Pinnacle_club :: Pinnacle_club()
{
    president=NULL;
    secretary=NULL;
}


Pinnacle_club ::~Pinnacle_club()
		  {

		    node *temp,*n;
	        temp = president;
            while(temp != NULL)
            {
                n = temp;
                temp = temp->next;
                delete n;
            }
            cout<<"destructor called";
		  }


void Pinnacle_club::add_member()
{
    //Define new Node for member
    node *temp;
    node *member=new node;
    cout<<"\n\t\t Enter PRN of member : ";
    cin>>member->prn;
    cout<<"\n\t\t Enter Name of member : ";
    cin>>member->name;
    member->next=NULL;

    if(president==NULL)                    // adding first node
    {
        president=member;
        cout<<"\n\t\t President added !!!";
    }
    else
    {
        if(secretary==NULL || president->next==NULL)               //adding secretary
        {
            secretary=member;
            president->next=secretary;
            cout<<"\n\t\t Secretary added !!!";
        }
        else
        {
            temp=president;
            while(temp->next!=secretary)    //traversing list till secretary
                temp=temp->next;
            temp->next=member;   // adding node to last
            member->next=secretary;
            cout<<"\n\t\t Member added !!!";
        }
    }
}

void Pinnacle_club::display_members()
{
    if(president==NULL)
         cout<<"\n No members added to Pinnacle club !!!";
    else
    {
        node *temp;
        temp=president;
        cout<<"\n\t\t Pinnacle Club Members : \n";
        cout<<"\n\t\t"<<"PRN"<<"  " <<"MEMBER NAME";
        while(temp!=NULL)
        {
          cout<<"\n\t\t"<<temp->prn<<"  " <<temp->name;
          if(temp==president)
            cout<<" - President";
          if(temp==secretary)
            cout<<" - Secretary";
          temp=temp->next;
        }
    }

}


void Pinnacle_club::display_total_members()
{
    node *temp;
    int cnt=0;
    for(temp=president; temp!=NULL; temp=temp->next)
    {
        cnt++;
    }
    cout<<"\n Total members of Pinnacle club : "<<cnt;
}

void Pinnacle_club::concatinate(Pinnacle_club &A2)
{
    secretary->next=A2.president;
    secretary=A2.secretary;
    A2.president=NULL;
    A2.secretary=NULL;
}


void Pinnacle_club::delete_member()
{
    node *temp,*prev;
    int prn;
    cout<<"\n Enter PRN of member to be delete : ";
    cin>>prn;
    for(temp=president; temp!=NULL; temp=temp->next)    // search node to be delete and locate temp i.e node to delete
    {
        if(temp->prn == prn)
            break;
        prev=temp;                              //locate previous node of temp
    }

    if(temp==NULL)
        cout<<"\n Member to delete id not found!!";
    else
    {
        if( temp == president)        //deleting front
        {
            president=president->next;
            if(president==NULL)
                secretary==NULL;
            cout<<"\n President deleted!!";
        }
        else
        {
            if(temp->next == NULL)     //deleting last node
            {
                prev->next=NULL;
                secretary=prev;
                cout<<"\n Secretary Deleted!!";
            }
            else                        //deleting intermediate node
            {
                prev->next=temp->next;
                cout<<"\n Member deleted!!";

            }

        }
    }
    delete temp;
}


int main()
{
    Pinnacle_club A1,A2;   //constructor invoked
    int ch;
    do
    {
        cout<<"\n\n";
        cout<<"\n\t\t 1. Add Member ";
        cout<<"\n\t\t 2. Display Members ";
        cout<<"\n\t\t 3. Display Total Members ";
        cout<<"\n\t\t 4. Delete Member";
        cout<<"\n\t\t 5. Concatenate Two Lists ";
        cout<<"\n\t\t 6. Exit ";
        cout<<"\n\t\t Enter your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1: A1.add_member();
                break;
        case 2: A1.display_members();
                break;
        case 3: A1.display_total_members();
                break;
        case 4: A1.delete_member();
                break;
        case 5: cout<<"\n Enter member details of division A2 :";
                char ans;
                do{
                  A2.add_member();
                  cout<<"\n Do you want to add more members : ";
                  cin>>ans;
                }while(ans=='y'||ans=='Y');
                A1.concatinate(A2);
                A1.display_members();

        case 6: cout<<"\n End of program ";
                break;
        default:cout<<"\n Invalid Choice !!";
        }

    }while(ch!=6);
}











