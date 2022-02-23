//No additional Data Structures used.
//Time Complexity -  (n log(n)) - n = length of the string.
//Space Complexity - depends on the compiler implementation of the sorting algorithm.



#include<iostream>
#include<algorithm>

bool check_unique(std::string value){



    //Simple linear searching mechanism by comparing each character with all other characters 

    std::sort (value.begin() , value.end());

    //Checking the neighbouring elements.
    for (int i = 0; i < value.length()-1; ++i)
    {
        if (value[i] == value[i+1])
            return false;
        
    }
    return true;
}

int main(){

    std::string value;
    std::cout<<"Enter the string : ";
    std::cin>>value;

    std::cout<< (check_unique(value) ? "unique" : "not unique");
}

//Note : This is not an efficient algorithms but satisfies the condition of not using an additional data structure