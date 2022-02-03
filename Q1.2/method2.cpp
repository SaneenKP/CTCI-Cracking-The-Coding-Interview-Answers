//This implementation uses sorting.
//Time Complexity - O(nlog(n)) - n - length of the string
//Space Complexity - depends on the compiler implemenation. 

#include<iostream>
#include<algorithm>

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
    else{
        //sort both the strings hence their order of characters would become same if it is a permutation.
        std::sort(s1.begin() , s1.end());
        std::sort(s2.begin() , s2.end());
        std::cout<< (s1==s2 ? "string is permutation" : "string not a permutation");
    }

}