#include <iostream>
#include <vector>
#include <algorithm>
#include <#bits/stdc++.h>

using namespace std;


class solution {
public :    
    int minAddtoMakeValid(){
        int x =0;
        int y=0;
        for(char c : s){
            if(c == '('){
                x++;

            }else{
                if(x > 0){
                    x--;
                }else{
                    y++;
                }
            }
        }
        return x + y;
    }    
}


int main() {
    
    
    return 0;
}