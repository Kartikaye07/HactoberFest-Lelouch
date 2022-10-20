#include <iostream>
using namespace std;

bool pallindrome(string&  str, int i, int j)
{

    // base case
    if (i > j)
        return true;

    if(str[i] == str[j])
        return true;
    else
        return false;    
    
    i++;
    j--;   

    pallindrome(str, i, j); 
}

int main()
{
    string name = "WoW";

    bool ispallindrome = pallindrome(name, 0, name.length()-1);

    if(ispallindrome){
        cout << "string is Pallendrome";
    }
    else{
        cout << "string is not Pallendrome";
    }

    return 0;

}