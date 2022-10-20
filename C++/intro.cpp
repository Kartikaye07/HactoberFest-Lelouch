#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){

    //decleration
    unordered_map<string,int> m;

    //----------insertion-----------------------
    //approch 1
    pair<string,int> p = make_pair("babber", 3);
    m.insert(p);

    //approch 2
    pair<string,int> pair2("love", 2);
    m.insert(pair2);

     //approch 3
     m["mera"] = 1;



    //------------------searching-------------------
    cout<< m["mera"]<<endl;
    cout<< m.at("babber") << endl;

    //-----------size---------------
    cout<< m.size() << endl;

    //---------to check if an elemnet is present or not-------------
    cout << m.count("love") << endl; //if element is present its show 1 or if not present it shows 0


    //------------erase-----------------------
    m.erase("love");

    //-----------itrator---------------
    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout << it -> first << " " << it->second << endl;
        it++;
    } 

    return 0;
}