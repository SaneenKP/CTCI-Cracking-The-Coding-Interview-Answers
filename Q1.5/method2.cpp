//A Concise and compact format of the code. With same complexities.
//Time Complexity - O(n) - n = length of the shorter string.
//Space Complexity - O(1)


#include<iostream>


bool OneEditAway(std::string first , std::string second){


    //pointers to track characters of both the strings individually.
    int index1 = 0;
    int index2 = 0;

    bool differenceFoundFlag = false;   //Flag to identify if difference is found or not.

    //string with shorter length is store in s1 and longer is stored in s2.
    std::string s1 = first.length() < second.length() ? first : second;
    std::string s2 = first.length() < second.length() ? second : first;


    //The basic idea of this method is that if it is replacement . Then both the indexes would be incremented.
    //If The character is not same we only increment the longer string pointer (index2) . Hence the extra character should be skipped.
    //Then if we encounter the difference again . it means that there are more than 1 difference character. Hence return false.
    while (index1 < s1.length() && index2 < s2.length())
    {
        if (s1[index1] != s2[index2])
        {
            if (differenceFoundFlag) return false;  //if characters of both string does not match , then check if a different character is already found or not. if found return false.

            differenceFoundFlag = true;     //difference found hence make the flag true.
            
            if (s1.length() == s2.length()) index1++;   //if difference found and both string have same length. It is a replacement , hence increment shorter string index.

        }else
            index1++; // if there is no difference in character increment the smaller index.

        index2++; // increment the longer string index always.
    }
    return true;
}

int main(){

    std::string s1 , s2;
    std::cout<<"Enter the string : ";
    std::cin>>s1;
    std::cout<<"Enter the string : ";
    std::cin>>s2;
    
    std::cout<<(OneEditAway(s1 , s2) ? "true" : "false") <<std::endl;
}
