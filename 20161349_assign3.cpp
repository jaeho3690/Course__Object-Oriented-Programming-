#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
	private:
		int data;
	public:
		Node* prev;
		Node* next;
		Node(int);
		int get_data();
	};

class NodeList{
	private:
		Node* head;
		Node* tail;
		int list_size;
	public:
		NodeList();
		void initList(int);
		void printList();
		Node* findNode(int);
		void append(Node*);
		void remove(Node*);
		void changeTypeA(Node*, Node*);
		void changeTypeB(Node*, Node*);
		void ascending_order();
		void descending_order();
};


Node::Node(int data){
	this-> data = data;
}

int Node:: get_data(){
	return this->data;
}

NodeList::NodeList(){
	this->head =NULL;
	this->tail =NULL;
	this->list_size=0;
}

void NodeList::initList(int n){
	for(int i =1; i<=n;i++)
	{
		this->append(new Node(i));
	}
}

void NodeList::printList(){
	Node* temp=this->head;
	while(temp !=NULL){
		std::cout << temp->get_data() <<" ";
		temp = temp->next;
	}
	std::cout<<std::endl;
}
Node* NodeList::findNode(int n){
	Node* temp = this->head;
	while(temp){
		if(temp->get_data() ==n){
			return temp;
		}
		temp = temp->next;
	}
}

//append new node on tail
void NodeList::append(Node* new_node){
	if(new_node->get_data()==1)
	{
		head = new_node;
		tail = new_node;
		new_node->prev=NULL;
		new_node->next=NULL;
	}
	else
	{
		tail->next = new_node;
		new_node->prev= tail;
		tail= new_node;
		new_node->next= NULL;
	}
		
}

//remove specific node
void NodeList:: remove(Node* node){

	if(head==NULL || node==NULL)
	return;

	//if node to be deleted is head node
	if(head==node)	
	head = node->next;
	
	if(tail==node)
	tail = node->prev;
	
	if(node->next !=NULL)
	node->next->prev = node->prev;
	
	if(node->prev !=NULL)
	node->prev->next= node->next;

	free(node);
	return;
	
}

//do A operation
void NodeList:: changeTypeA(Node* node1,Node* node2){
	Node *temp;
	temp = new Node(node1->get_data());
	this->remove(node1);

	if(node2 ==head)
	{
		temp->next = head;
		temp->prev = head->prev;
		head->prev =temp;
		head =temp;
	}
	else if( node2 == tail)
	{
		temp->prev = tail->prev;
		tail->prev->next =temp;
		temp->next = tail;
		tail->prev = temp;

	}
	
	else
	{
		temp->next = node2;
		temp->prev = temp->next->prev;
		temp->prev->next = temp;
		temp->next->prev = temp;		
	}
}	
//do B operation
void NodeList:: changeTypeB(Node* node1,Node* node2){
	Node *temp;
	temp = new Node(node1->get_data());
	this->remove(node1);

	if(node2 == head)
	{
		temp->prev = node2;
		temp->next = node2->next;
		node2->next =temp;
		temp->next->prev= temp;
	}
	else if(node2 == tail)
	{
		temp->prev = tail;
		temp->next = tail->next;
		tail->next =temp;
		tail = temp;
		
	}
	else
	{
		temp->prev = node2;
		temp->next= node2->next;
		temp->prev->next=temp;
		temp->next->prev=temp;
	}
	

}
//sort list ascending
void NodeList::ascending_order(){

	Node *count = this->head;
	Node *min_ptr= this->head;
	Node *iterator = count->next;

	do
	{
		

		while(iterator !=NULL)
		{
			if(iterator->get_data() <min_ptr->get_data())
			{
				min_ptr =iterator;
			}
			iterator = iterator ->next;
			
		}
		if(min_ptr !=count)
		{
			this->changeTypeA(min_ptr,count);
			min_ptr = count;
		}
		else
		{
			count = count->next;
			min_ptr = count;
		}
		
		iterator= count->next;
		

	}while(count !=tail);

	return;		
}
//sort list descending order
void NodeList:: descending_order(){
	Node *count = this->head;
	Node *max_ptr = this->head;
	Node *iterator = count->next;

	do
	{
		while(iterator !=NULL)
		{
			if(iterator->get_data() > max_ptr->get_data())
			{
				max_ptr = iterator;
			}
			iterator= iterator ->next;
		}
		if(max_ptr !=count)
		{
			this->changeTypeA(max_ptr,count);
			max_ptr =count;
		}
		else
		{
			count= count->next;
			max_ptr=count;
		}
		iterator =count->next;
	}while(count !=tail);

	return;
	
}




int main()
{

	
}


