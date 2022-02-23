//Time Complexity - O(n) - n = length of the shorter string.
//Space Complexity - O(1)
#include<iostream>


//Check if both the strings have more than 1 diffrent character.
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

    return false;
}


bool OneEditInsertion(std::string s1 , std::string s2){

    //pointers to track characters of both the strings individually.
    int index1 = 0;
    int index2 = 0;


    while (index1 < s1.length() && index2 < s2.length())
    {
        //if the character is not same with same index.
        //Then increment the second index. This points that 1 diffrent character has been found.
        //if difference is encountered again and if the index2 is already moved . hence already a diffrent character has been found.
        //hence return false.

        if (s1[index1] != s2[index2])
        {
            if (index1 != index2)
                return false; 

            index2++;

        }else{

            //increment both the indexes if same character is found.
            index1++;
            index2++;
        }
    }
    return true;
}


bool OneEditAway(std::string s1 , std::string s2){


    //Compare the length of string to check if Replacement,insertion or removal is required.
    if (s1.length() == s2.length())
        return OneEditReplacement(s1 , s2);

    else if(s1.length()+1 == s2.length())
        return OneEditInsertion(s1,s2);

    else if (s1.length() - 1 == s1.length())
        return OneEditInsertion(s1,s2);
    
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
