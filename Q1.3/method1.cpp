//Using an inbuilt string function of C++
//Time Complexity - O(n) - n = length of string.
//Space Complexity - O(1)

#include<iostream>

std::string replaceSpaces(std::string s){

    std::string str = "%20";
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ')
           s.replace(i , 1 , str) ;
    }
    return s;
}
int main(){

    std::string s;
    std::cout<<"Enter the string : ";
    std::getline(std::cin , s);

    std::cout<<replaceSpaces(s)<<std::endl;
}