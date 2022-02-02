
//Time Complexity - O(n) - n = length of the string
//Space Complexity - O(1)
#include<iostream>

bool check_unique(std::string value){


    //Originally based on the English alphabet, ASCII encodes 128 specified characters.
    //This could be extended to 256 if the question mentions extended ASCII.
    bool arr[128] = {0};


    
    //There would be no Unique characters if there are more than 128 characters in the string.
    if (value.length() > 128)
        return false;
    
    for (int i = 0; i < value.length(); ++i)
    {
        //Check the boolean array if the integer position of that character is already true of not.
        //if its true then the character has already been encountered in the sting hence not unique hence return false.

        if (arr[value[i]] == 1)
            return false; 
    
        //make the integer position of that array true.
        arr[value[i]] = 1;

    }
    return true;
}

int main(){

    std::string value;
    std::cout<<"Enter the string : ";
    std::cin>>value;

    std::cout<< (check_unique(value) ? "unique" : "not unique");
}