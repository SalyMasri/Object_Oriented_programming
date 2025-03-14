
#include "function.h"

//Constructor
linked_list::linked_list(){ //default constructor is a constructor with empty arguments 
    head = nullptr;
    tail = nullptr;
}
linked_list::linked_list(const linked_list &src){
   
    
   	head = nullptr;
	tail = nullptr;
    //copy constructor to push back all values of const list until it reaches nullptr
	for (node *ptr = src.head; ptr != nullptr; ptr = ptr->prev ) push_back(ptr->value); 

}

//Destructor
linked_list::~linked_list(){    
   if(!is_empty()){ //destructor used as the memory is allocated dynamically and memory need to be deallocated
        
        for( node* it = head;it != nullptr; it = it->prev)  delete it;
        
    }
 
}


linked_list::node::node(double value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
}


linked_list &linked_list::operator=(const linked_list &rhs)
{
	if (this == &rhs)
        return *this;

    while(!is_empty()) pop_front(); //decrease the size of the container one by one until the whole list is empty
        
	for (node* tmp = rhs.head; tmp != nullptr; tmp = tmp->prev) push_back(tmp->value); //then push back the rhs list to the lhs list
	
	return *this;
}

linked_list &linked_list::operator+=(const linked_list &rhs){
    //push back the rhs list to the lhs list whithout emptying the lhs list
	for (node* tmp = rhs.head; tmp != nullptr; tmp = tmp->prev) push_back(tmp->value); 
	
	return *this;
}





void linked_list::insert(double value, size_t pos)
{
	node *temp = new node(value);
	if (0 == size())
	{
		push_front(value);
	}
	else if (pos > size())
	{
		std::cout << "can not found the" << pos << "you are looking for" << std::endl;
	}
	else if (pos == 0)
	{
		push_front(value);
	}
	else
	{
		node *cerrunt = new node(value);
		temp = head;
		for (int i = 0; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		if (temp->next == nullptr)
		{
			push_back(value);
		}
		else
		{
			temp->next = cerrunt->next;
			temp->next->prev = temp;
			cerrunt->next = temp;
			temp->prev = cerrunt;
		}
	}

}
//Push back code
void linked_list::push_back(double val){
    node* N = new node(val);
    if(is_empty()){ 
        head = tail= N;
    }
    else {  //to make the new node the tail of the container; by resetting prev and next of previous tail
        tail->prev = nullptr;
        N->next = tail;
        tail->prev = N;
        tail = N;
    }
}


void linked_list::push_front(double value){
    node* N = new node(value);
    if(is_empty()){
        head = tail= N;
    }
    else {//to make the new node the head of the container; by resetting prev and next of previous head
        
        N->prev = head;
        head->next = N;
        head = N;
        head->next = nullptr;
        
    }
}

void linked_list::print() const
{
    int n=0;             
    node* current=head;  
    if (current==nullptr)
        std::cout<<"This is empty linked list."<<std::endl;

    while(current!=nullptr) //until current reach to null, cout data of node current
    {
        std::cout<</*"The node data number "<<n++<<" is "<<*/current->value<<" " ;
        current=current->prev;
    }
    std::cout<<std::endl;
}



void linked_list::print_reverse() const
{
    int n=0;             
    node* current=tail;  
    if (current==nullptr)
        std::cout<<"This is empty linked list."<<std::endl;
    else
    {
        while(current!=nullptr) //until current reach to null, cout data of node current
    {
        std::cout<</*"The node data number "<<n++<<" is "<<*/current->value<<" " ;
        current=current->next;
    }
    std::cout<<std::endl;
    }
    
    
}

double  linked_list:: at(size_t pos) const{
   node *element = head;
	if (is_empty()) return 0; 
	else //at position that matches with i until it reaches the last value of size of the container
	{
		for (size_t i = 0; i <= size(); ++i)
		{
            
			if (pos == i)
			{
                
                return element->value;
                
			}
			element = element->prev;
		}
	}
	return pos; 
  
}

double linked_list::pop_front()
{
	double val;
    node* N = head;
    if (is_empty()){
        std::cout << "Cannot pop front, there are no elements in the list" << std::endl;
        exit(1);
    }
    else if (size() == 1){  //if size is on then there is only one data to be returned 
        val = head->value;
        head = nullptr;
        tail = nullptr;
       delete N;
        return val;

    }
    else {
        val = head->value; //set the previous of head to be the new head, delete the pointer of current head
        head = head->prev;
        head->next = nullptr;
        delete N;
        return val;
    }

}
double linked_list::pop_back()
{
	double val;
    node* N = tail;
    if (is_empty()){
        std::cout << "Cannot pop back, there are no elements in the list" << std::endl;
        exit(1);
    }
    else if (size() == 1){  
        val = tail->value;
        head = nullptr;
        tail = nullptr;
        delete N;
        return val;
    }
    else {
        val = tail->value;
        tail = N->next;
        tail->prev = nullptr;
        delete N;
        return val;
    }
   
	
}
void linked_list::remove(size_t pos) {


    node *temp;

	if (size()==0)
	{
		std::cout << "the list is empty" << std::endl;
	}
	else if (pos  >= size())
	{
		std::cout << "invalid postion enter value: " <<size() <<" or less" << std::endl;
	}
	else if (pos == 0)
	{
		pop_front();
	}
	else
	{
		node *current = head; //if pos is valid then start to check if the value of data at edges to pop back
		for (int i = 0; i < pos; i++)
		{
			current = current->prev;
		}
		if (current->prev == nullptr)
		{
			pop_back();
		}
		else
		{//else set the new node to be the node of the pos and delete the current value
			temp = current->prev; 
			temp->next = current->next;
			current->next->prev = temp;
			delete current;
		}
	}
}


 // check if the list is empty
 bool linked_list::is_empty() const{
    if(head == nullptr && tail == nullptr){
        return true;
    }
    else {
        return false;
    }
}
double linked_list::front() const{


	if (size() == 0)return 0;


    return head->value;

}


double linked_list::back() const{

	if (size() == 0) return 0;
	

    return tail->value;
}

size_t linked_list::size() const
{

    size_t size  = 0;
	node* current = head;

		while(current) //head pointer and add one to size along with the pointer 
		{
			current = current->prev;
			size++;
		}

		return size;

}
