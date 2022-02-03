//This implementation uses an additional datastructure to count the characters.
//More efficient and robust method as this can be used to check strings with all type of characters from ASCII.
//Time Complexity - O(n) - n - length of the string
//Space Complexity - O(1)

#include<iostream>


bool check_permutation(std::string s1 , std::string s2){

    //integer array to store the count of all characters of the string.
    //128 is used because of the character count of ASCII . could be 256 according to the question.
    int letters[128] = {0};

    //increment the array according to the characters of first string.
    for (int i = 0; i < s1.length(); ++i)
        letters[s1[i]]++;

    //Decrement the array according the characters of second string.
    //And check if all the value of the array is zero.

    for (int i = 0; i < s2.length(); ++i)
    {
        letters[s2[i]]--;
        if (letters[s2[i]] < 0)
            return false;
        
    }
    
    //all the values of the array is 0 .
    return true;

}

int main(){

    std::string s1 , s2;

    std::cout<<"Enter string 1 : ";
    std::cin>>s1;
    std::cout<<std::endl;
    std::cout<<"Enter string 2 : ";
    std::cin>>s2;
    std::cout<<std::endl;

    //if both the string does not have same number of characters then they are not permutation of each other.
    if (s1.length() != s2.length())
        std::cout<<"String not a permutation";
    else
        std::cout<< (check_permutation(s1 , s2) ? "string is permutation" : "string not a permutation");

}