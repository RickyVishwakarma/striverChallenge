#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution {
public :
    int strAns(string haysytack , string needle){
        int n 
        int m 
        for(int i = 0 ; i <= n - m ; i++){
            if(haysytack.substr(i , m) == needle){
                return i;
            }
        }
        return -1;
    }    
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}