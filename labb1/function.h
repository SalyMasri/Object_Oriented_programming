#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include <vector>

struct Address {
    std::string street, city;
    int zip = 0;
};

struct Person {
    std::string name, id;
    Address location;
};

std::vector <Person> read_file(std::string filename);

std::istream& operator>>(std::istream& in, Person& p);

size_t find_in_names(const std::vector<Person>& haystack, std::string name_part);

std::vector<Person> find_person_from_city(const std::vector<Person>& haystack, std::string city);

#endif 

