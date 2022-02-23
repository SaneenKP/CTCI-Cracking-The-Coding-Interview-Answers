//This is the brute force Implementation.


#include<iostream>
#include<string>

std::string compress(std::string s){

    int count = 1;
    std::string result = "";

    for (int i = 0; i < s.length(); ++i) {
        
        if (s[i] != s[i+1] || i+1 >= s.length())
        {
            result += s[i] + std::to_string(count); 
            count = 0;
        }
        count++;
    }
    return result;
}
int main(){

    std::string s ;
    std::cout<<"Enter the string : ";
    std::cin>>s;

    std::string result = compress(s);
    std::cout<<(result.length() == s.length() || result.length() >= s.length() ? s : result)<<std::endl;

}