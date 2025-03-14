//worked with my group

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <clocale>
#include "function.h"

int main() {
    

    while (true)
    {
        
        std::vector<Person>myvec = read_file("names.txt");
        std::vector<Person>mytempvec = read_file("names.txt");
        int option;


        std::cout << "-----Hello!-----" << std::endl;
        std::cout << "Enter 1 : Search by name" << std::endl;
        std::cout << "Enter 2 : Search by address" << std::endl;
        std::cout << "Enter 3 : EXIT" << std::endl;
        std::cout << "Enter (1-3): ";
        std::cin >> option;

        switch (option)
        {
            case 1: {
                

                
                std::string namepart;
                std::cout << "Enter : ";
                std::cin.ignore();
                getline(std::cin, namepart);
                //std::cin >> namepart;
                size_t data_count = find_in_names(myvec, namepart);
                std::cout << namepart << " has occurred " << data_count << " times" << std::endl;
                break;
            }
            case 2: {
            
                std::string city;
                std::cout << "Enter : ";
                std::cin.ignore();
                getline(std::cin, city);
                mytempvec = find_person_from_city(myvec, city);
                for (auto it : mytempvec) {
                    std::cout << it.name << std::endl;
                    std::cout << it.id << std::endl;
                    std::cout << it.location.street << ", " << it.location.zip << " " << it.location.city << std::endl;
                    std::cout << " " << std::endl;
                    
                }
                break;
            }

            case 3: {
                exit(1);
                break;
            }
            default:
            {
                std::cout << "Error! Invalid Input! " << std::endl;
            }
        }
    }
    return 0;
}
