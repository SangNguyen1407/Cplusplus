#include <iostream>
#include <string>
#include <set>

using namespace std;

bool isHappy(int n) {
    int rst = 0;
    int temp = 0;

    do {
        rst = 0;
        temp = 0;
        while (n != 0) {
            temp = n%10;
            rst += temp*temp;
            n = (n - n%10)/10;
        }
        if(rst == 1) {
            return true;
        }
        else if(rst  == 7) {
            return true;
        }
        else if (rst < 10){
            return false;
        }
        n = rst; 
    } while (true);

    return false;        
}

int main(){
    cout << isHappy(1111111) << endl;
    cout << isHappy(19) << endl;
}