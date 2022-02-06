//Using an inbuilt string function of C++
//Time Complexity - O(n) - n = length of string.
//Space Complexity - O(1)
#include<iostream>


//check no more than one character has odd count.
bool checkMaxOneOdd(int table[] , int size){

     //Flag to check if an odd Character is already found or not.
    bool foundOddCharacter = false;
    for (int i = 0; i < size; ++i)
    {
        //if a character count is odd then flag is true.
        if(table[i]%2 == 1 ){

             //Checks if the flag is already true . 
             //if its already true meaning it has already found an odd no. of character.
             //means finding it again says that there are more than 1 odd no. of character.
             //Hence the above string cant be a permutation of a palindrome . return false.
            if (foundOddCharacter)
                return false;
            
            foundOddCharacter = true;
        }
    }

    return true;
}

bool permutaionOfPalindrome(std::string s){

     //Table to store the count of alphabets
    int a = 'a';
    int z = 'z';
    int table[z - a + 1] ={0};

    //Populate the table with the count of each character.
    for (int i = 0; i < s.length(); ++i)
    {
        //Check if the character is an alphabet. ie comes in between the ASCII values of a and z.
        bool check = s[i] >= a && s[i] <= z;

        //increment that position in the table to count the character.
        if (check)
            table[s[i] - a]++;

    }

    return checkMaxOneOdd(table , z-a+1);

}
int main(){

    std::string s;
    std::cout<<"Enter the string : ";
    std::getline(std::cin , s);

    std::cout<<(permutaionOfPalindrome(s) ? "true" : "false") <<std::endl;
}