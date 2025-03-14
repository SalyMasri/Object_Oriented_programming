//worked with my group 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <clocale>
#include "function.h"

//struct Address adresss;
//struct Person person;

std::istream& operator>>(std::istream& in, Person& p) {
    std::string Name, Id, Addres;
    std::string Street, City, Zip;
    char comma = ',';
    char blank = ' ';

    std::getline(in, Name); //get the whole line 
    std::getline(in, Id);
    std::getline(in, Addres);
    if (!Name.empty()) {

        p.name = Name;
        p.id = Id;


        Street = Addres.substr(0, Addres.find(comma)); //until find comma
        p.location.street = Street;
        Addres.erase(0, Addres.find(comma) + 2); //after comma there is two whitespace that should be erased 


        Zip = Addres.substr(0, Addres.find(blank) +3); //until find whitespace then other 2 values as the zip has two numbers at the end
        Zip.erase(remove(Zip.begin(), Zip.end(), blank), Zip.end());
        int zipcode = stoi(Zip);
        p.location.zip = zipcode;


        Addres.erase(0, Addres.find(blank) + 5); //after personal number there is two whitespaces
        City = Addres.substr(0, Addres.find_last_not_of(blank) + 1); //if i have 2 words in the city name then i need to read it 
      //  Addres.erase(0, Addres.find_last_not_of(blank));
        p.location.city = City;
    }


    return in;
}

std::vector <Person> read_file(std::string filename) {

    std::vector <Person> myvec;
    std::ifstream myfile;
    myfile.open(filename);

    Person mydata;

    if (myfile.fail()) {
        std::cout << "Error!" << std::endl;
    }

    while (myfile >> mydata) {
        myvec.push_back(mydata);
    }

    myfile.close();

    return myvec;
}

size_t find_in_names(const std::vector<Person>& haystack, std::string name_part) {


    size_t count_name = 0;

    std::transform(name_part.begin(), name_part.end(), name_part.begin(), ::tolower);

    for (size_t i = 0; i < haystack.size(); i++) {

        Person p = haystack[i];
        std::transform(p.name.begin(), p.name.end(), p.name.begin(), ::tolower);

        if (p.name.find(name_part) != std::string::npos) {

            count_name++;
        };
    };


    return count_name;
}

std::vector<Person> find_person_from_city(const std::vector<Person>& haystack, std::string city) {

    std::transform(city.begin(), city.end(), city.begin(), ::tolower);

    std::vector<Person>tempvec;

    for (int i = 0; i < haystack.size(); i++) {


        Person p = haystack[i];
        std::transform(p.location.city.begin(), p.location.city.end(), p.location.city.begin(), ::tolower);

        if (p.location.city == city) {
            tempvec.push_back(p);
        }

    }

    return tempvec;
}