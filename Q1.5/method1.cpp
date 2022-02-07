//Using an inbuilt string function of C++
//Time Complexity - O(n) - n = length of string.
//Space Complexity - O(1
#include<iostream>


bool OneEditReplacement(std::string s1 , std::string s2){

    int size = s1.length();

    bool foundEditFlag = false;
    for (int i = 0; i < size; ++i)
    {
        if (s1[i] != s2[i])
        {
            if (foundEditFlag)
                return false;
            
            foundEditFlag = true;
        }
        
    }

    return true;
}



bool OneEditAway(std::string s1 , std::string s2){


    //Compare the length of string to check if Replacement,insertion or removal is required.
    if (s1.length() == s2.length())
        return OneEditReplacement(s1 , s2);
    else    
        return false;
    
    return false;
    


}
int main(){

    std::string s1 , s2;
    std::cout<<"Enter the string : ";
    std::cin>>s1;
    std::cout<<"Enter the string : ";
    std::cin>>s2;
    
    std::cout<<(OneEditAway(s1 , s2) ? "true" : "false") <<std::endl;
}
