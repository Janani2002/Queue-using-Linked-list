#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Node 
{
  public:
   char company_name[10];
   char buyer_name[10]; 
  	Node * next;

  Node() {
    strcpy(company_name,"NULL");
    strcpy(buyer_name,"NULL");
    next = NULL;
  }
  Node(char k[10], char d[10]) {
    strcpy(company_name,k);
    strcpy(buyer_name,d);
    next = NULL;
  }
};
class Queue 
{
  public:
  	Node *front;
  	Node *rear;
  	
    Queue() 
	 {
      front = NULL;
      rear = NULL;
    }
    
    bool isEmpty()
    {
    	if(front==NULL && rear==NULL)
    	{
    		return true;
		}
		else
		{
			return false;
		}
	 }
	 
	 
	void enqueue(Node *n) 
   {
    if (isEmpty())
      {
        front = n;
        rear = n;
        cout<<"Node  ENQUEUED successfully"<<endl;
      }
    else
    {
      rear->next=n;
      rear=n;
      cout<<"Node  ENQUEUED successfully"<<endl;
    }
   }
	
	Node* dequeue() 
    {
        Node *temp=NULL;
      if (isEmpty()) 
      {
          cout << "Queue is Empty" << endl;
          return NULL;
      } 
      else 
      {
        if(front==rear)
        {
          temp=front;
          front = NULL;
          rear = NULL;  
          return temp;
        }
        else
        {
          temp=front;
          front = front->next;  
          return temp;
        }
       }
    }
	 
	 int count() 
    {
      int count=0;
      Node *temp=front;
      while(temp!=NULL)
      {
        count++;
        temp=temp->next;
    	}
     return count;
    }
	 
	 void display() 
    {
      if(isEmpty())
      {
        cout << "Queue is Empty" << endl;
      }
    else
    {
      cout << "All values in the Queue are :" << endl;
        Node *temp=front;
        while(temp!=NULL)
        {
          cout<<"("<<temp->company_name<<","<<temp->buyer_name<<")"<<" -> ";
          temp=temp->next;
      	}
      cout<<endl;
    }
    }
    
   void find(char c[10])
   {
       Node *temp=front;
       for(int i=0;i<10;i++)
       {
           if(strcmp(temp->company_name,c)==0)
           {
               cout<<"("<<temp->company_name<<","<<temp->buyer_name<<")"<<" -> ";
               cout<<"The given company is present\n";
               break;
           }
           temp=temp->next;
       }
   }

};
 
int main() {
  Queue q;
  int ch;
  char company_name[10];
  char buyer_name[10];
 
  do {
      cout<<"----------------MAIN MENU-----------------"<<endl;
    cout << "What operation do you want to perform?"<< endl;
    cout << "1. INSERT" << endl;
    cout << "2. DELETE" << endl;
    cout << "3. IS EMPTY?" << endl;
    cout << "4. COUNT" << endl;
    cout << "5. DISPLAY" << endl;
    cout << "6. FIND" << endl;
    cout << "7. EXIT" << endl << endl;
 	cin >> ch;
 	 
	 Node * new_node = new Node();
	 
    switch (ch) {
    case 0:
      break;
    case 1:
      cout << "Enter COMPANY NAME to insert in the Queue \n";
      cin>>company_name;
      cout << "Enter BUYER NAME to insert in the Queue \n";
      cin>>buyer_name;
      strcpy(new_node->company_name, company_name);
      strcpy(new_node->buyer_name, buyer_name);
      q.enqueue(new_node);
      break;
      
    case 2:
      new_node = q.dequeue();
      cout<<"Deleted Value is: ("<<new_node->company_name<<"," <<new_node->buyer_name<<")";
      delete new_node;
	  cout<<endl;
      break;
      
    case 3:
    if (q.isEmpty())
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is NOT Empty" << endl;
      break;

    case 4:
      cout << "No. of nodes in the Queue: " <<q.count() <<endl;
      break;
      
    case 5:
      q.display();
      cout << endl;
      break;
      
    case 6:
    cout<<"Enter the Company name to be searched\n";
    char search[10];
    cin>>search;
    q.find(search);
      
    
    }
  } while (ch <7);
  return 0;
}
