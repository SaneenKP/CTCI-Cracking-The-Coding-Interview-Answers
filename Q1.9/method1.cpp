// Brute force implementation
//Time Complexity - O(n) - n = length of the string
//Space Complexity - o(n^2)

#include<iostream>

//Custom method to check if string 2 is a substring of 1 or not.
//Time complexity O(n)
//Not necessary for the question.
bool isSubString(std::string s1 , std::string s2){

    int subStringCounter = 0; 

    //iterate over each character of the first string.
    for (int i = 0 ; i < s1.length(); i++) 
    {
        if (s1[i] == s2[subStringCounter]){ //check if the character matches the character of 2nd string.
            subStringCounter++;             //Increase the counter pointer to the next character. 
        }
        else
            subStringCounter = 0;           //if found a different character , get the pointer back to the first character.
            if (s1[i] == s2[subStringCounter])             // check if the different character is same as first character in the second string.
                subStringCounter++;         // if yes increase the pointer to next character.

        if (subStringCounter == s2.length()) return true; // Found a substring if all the characters from second string is encountered.
    }
    
    return false;
}

int main(){

    std::string s1 , s2;
    std::cout<<"Enter the string 1 : ";
    std::cin>>s1;
    std::cout<<"Enter the string 2 : ";
    std::cin>>s2;

    std::cout<<((isSubString(s1 , s2)) ? "True" : "False");


}