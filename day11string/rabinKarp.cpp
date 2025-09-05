#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class solution{
public : 
    int repeatedString(string a , string b){
        string repeat = b;
        int count = 1;

        while(repeat.size() < b){
            repeat += a;
            count++;
        }
        if(repeat.find(b) != string::npos){
            return count;
        }
        repeat += a;
        if((repeat + a).find(b) != string::npos){
            return count + 1;
        }

        return -1;
    }
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}