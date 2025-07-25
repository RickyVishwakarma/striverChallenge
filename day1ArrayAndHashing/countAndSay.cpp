#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 38 countAndSay 
// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the run-length encoding of countAndSay(n - 1).

// Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number
//  marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11".
//  Thus the compressed string becomes "23321511".

// Given a positive integer n, return the nth element of the count-and-say sequence.


// so this is problem statement in simple we can say that this is compression of the string

// ex n = 4
// countAndSay(1) = "1"
// countAndSay(2) = "11" (1 times 1)
// countAndSay(3) = "21" (2 times 1)
// countAndSay(4) = "1211" (1 times 2 and 1 times 1)

// and 1211 is ans for n = 4


// so we have this n is int so we have to convert it into the char 



char inToChar(int num){
    return '0' + num;
}
string countAndSay(int n) {
  
        if(n == 1) return "1";

        string result = "1";

        for(int i = 2 ; i <= n ; i++){
            string prev = result ;
            result = "";

            int count = 1;

            for(int j = 1 ;prev[j] != '\0' ; ++j){
                if(prev[j] == prev[j - 1]){
                    count++;
                }else{
                    result += inToChar(count);
                    result += prev[j - 1];
                    count = 1 ;
                }
            }

            result += inToChar(count);
            result += prev[prev.length() - 1];
        }

        return result;
        
}





int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    string result = countAndSay(n);

    cout << "The " << n << "th element of the count-and-say sequence is: " << result << endl;

    return 0;
}