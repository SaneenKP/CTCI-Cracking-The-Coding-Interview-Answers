//No additional Data Structures used
//Time Complexity - worst case (n^2) - n = length of the string
//Space Complexity - O(1)



#include<iostream>

bool check_unique(std::string value){


    //Simple linear searching mechanism by comparing each character with all other characters 

    for (int i = 0; i < value.length(); ++i)
    {
        for (int j = i+1; j < value.length(); j++)
        {
            if (value[i] == value[j])
                return false;
        }
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