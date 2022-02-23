//Using C++ Set Data Structure.
//C++ Sets only store unique characters
//Time Complexity -  (n log(n)) - n = length of the string.
//Space Complexity - depends on the compiler implementation of the sorting algorithm.



#include<iostream>
#include<algorithm>
#include<set>

bool check_unique(std::string value){



    std::set<char> character_set;

    //insert every character of the string to the set.
    for (char x : value)
        character_set.insert(x);
    
    //check if the set has the same size as string , if not return false.
    if (character_set.size() != value.length())
        return false;
    
    return true;
}

int main(){

    std::string value;
    std::cout<<"Enter the string : ";
    std::cin>>value;

    std::cout<< (check_unique(value) ? "unique" : "not unique");
}
