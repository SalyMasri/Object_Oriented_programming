



#include "function.h"

void print_list(linked_list l);
linked_list merge(linked_list&, linked_list&);
bool isInOrder(linked_list& list);

int main()
{
  linked_list list1, list2, list3, list4;
   srand(time(NULL));
  //------------Test 1------------
    std::cout << "Test 1: Filling two lists with 50 random numbers" << std::endl;
    double rand_num;
    srand (time(NULL));
    for (size_t i = 0; i < 50; i++) {
        if (i == 0){
            list1.push_back(0);
            list2.push_back(0);
        }
        else{
            list1.push_back(list1.back() +rand()%5);
            list2.push_back(list1.back() +rand()%5);
        } 
        

    }
   
    list1.print();
   list2.print();
   
//------------Test 2------------
    std::cout << std::endl;
    std::cout << "Test 2: Remove the largerst 25th element of both lists, if equal, remove from list 2" << std::endl;
    double num1 = list1.at(24);
    double num2 = list2.at(24);
    if (num1 > num2){
        std::cout << "Comparing " << num1 << " & " << num2 << " then removing: " << num1 << " in list 1 " << std::endl;
        list1.remove(24);
    }
    else if (num1 < num2){
        std::cout << "Comparing " << num1 << " & " << num2 << " then removing: " << num2 << " in list 2 " << std::endl;

        list2.remove(24);
    }
    else{
        list2.remove(24);
    }
    list1.print();
    list2.print();
  
//------------Test 3------------
    std::cout << std::endl;
    std::cout << "Test 3: The now smallest list in reverse: " << std::endl;
    std::cout<<"list1: " <<list1.size()<<"list2: " <<list2.size()<<"\n";
    if (list1.size() < list2.size()) list3 = list1;
    else list3 = list2;
    list3.print();
 
//------------Test 4------------
    std::cout << std::endl;
    std::cout << "Test 4: Removing every other element from list with 50 elements " << std::endl;
    if(list1.size() == 50) {
        std::cout << "Before: ";
        list1.print();
        for(size_t i = 0; i < 25; i++){
            list1.pop_back();
            list1.push_front(list1.pop_back());
        }
        std::cout << "After: ";
        list1.print();
    }
    else{
        std::cout << "Before: ";
        list2.print();
        for(size_t i = 0; i < 25; i++){
            list2.pop_back();
            list2.push_front(list2.pop_back());
        }
        std::cout << "After: ";
        list2.print();
    }
 
 
//------------Test 5------------
    std::cout << std::endl;
    std::cout << "Test 5: Printing the halved down list using the \"print_list()\" function " << std::endl;
    if(list1.size() == 25) print_list(list1);
    else print_list(list2);
    
//---------------Test6-------------
    std::cout<<"merged list \n";
    list4 =merge(list1, list2);
    list4.print();
    


    //------------Test 7------------
    if (isInOrder(list4))
		std::cout << "The merged list is in order" << std::endl;
	else std::cout << "The merged list is NOT in order" << std::endl;

    return 0;
}



//Prints the given list
void print_list(linked_list l){
    l.print();
}

//Merges the two lists and returns the newly merged list
linked_list merge(linked_list& lista1, linked_list& lista2){

    linked_list merged;
		while (!lista1.is_empty() && !lista2.is_empty())
		{
			if (lista1.back() >= lista2.back()) //start from back of both sides and push front each value until one of the lists is empty
				merged.push_front(lista1.pop_back());
			else if (lista1.back() <= lista2.back())
				merged.push_front(lista2.pop_back());
		}
        //push front the values of the list that still contains data
		while (!lista1.is_empty()) 
			merged.push_front(lista1.pop_back());
		while (!lista2.is_empty())
			merged.push_front(lista2.pop_back());
	return merged;
}


bool isInOrder(linked_list& list)
{
	double prev = list.front();
    //as long as the value of current is larger than or equal to prev set them equal to each other until the end of container if not ordered then false 
	for (size_t i = 0; i < list.size(); i++)
	{
		auto current = list.at(i);
        
		if (current >= prev){

            current = prev;

        }

		else
			return false;
	}

	return true;
}