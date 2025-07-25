#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// the simple defination of the prime number the number which have ether 1 or itself devisor meaning it have 0 when devide by 2 and and if not is is prime numnr 

// 23 / 2 = 11 = 1 remainder so it is a prime number

// n <= 1 is a not a prime numebr so it fasle 
// n == 2 is a prime number
// n &2 == 0  it is also fasle 
// we more the loop square time of the lpp 


// dependinf on n it is if n = 2 
// 2 4 16 ......

bool isPrime(int n){
    // we have 3 base condition 
    if(n <= 1 ) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false; 

    for(int i = 3 ; i <= n*n ; i+=2){
        if(n % i == 0){
            return false;
        }

        return true;
    }
}

int main() {
    int n;
    cin >> n;

    if(isPrime(n)){
        cout << "It is a prime" << endl;
    }else{
        cout << "It is not a prime number" << endl;
    }
    return 0;
}