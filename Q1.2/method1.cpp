
//This implementation is the brute method by comparing each character of string 1 with each character of string 2.
//Time Complexity - O(n^2) - n - length of the string
//Space Complexity - O(1)

#include<iostream>

bool check_permutation(std::string s1 , std::string s2){

    //flag variable to check if the compared character exists of not.
    bool flag = false;


    for (int i = 0; i < s1.length(); ++i)
    {
        for (int j = 0; j < s2.length(); ++j)
        {
            //compare character of string 1 with each character of string 2.
            if (s1[i] == s2[j]){

                //if found set the flag to true and break the loop.
                flag = true; 
                break;
            }

            flag = false;
        }
    }
    
    return flag;

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