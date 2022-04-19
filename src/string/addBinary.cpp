#include<iostream>
#include<string.h>

using namespace std;
/*
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 */
string addBinary(string a, string b) {
    if (a.length() == 0 || b.length() == 0){
        return "";
    }
    int lenA = a.length()-1;
    int lenB = b.length()-1;
    int lenRst = (lenA > lenB)? lenA:lenB;
    int min = (lenA < lenB)? lenA:lenB;
    lenRst += 1; // +1 add the first odd  
//    char rst[lenRst] = {0};
    string rst;
    int temp = 0;

    for(int i = 0; i < min+1; i++){
        if ((a[lenA - i] == b[lenB - i]) && (a[lenA - i] == '1')){
            rst[lenRst - i] = (temp == 1)? '1' : '0'; 
            temp = 1;
        }
        else if((a[lenA - i] == b[lenB - i]) && (a[lenA - i] == '0')){
            rst[lenRst - i] = (temp == 1)? '1' : '0';
            temp = 0;
        }
        else if(a[lenA - i] != b[lenB - i]){
            rst[lenRst - i] = (temp == 1)? '0' : '1' ;

        }
    }

/*    for (int i = min+1; i < lenRst; i++){
        if (temp){
            if (rst[i] == '1'){
                rst[lenRst -i] = '0';
                temp = 1;
            }
            else{
                rst[lenRst -i] = '1';
                temp = 0;
            }
        }
        else{
            rst[i] = (lenA > lenB)? a[lenA - i]:b[lenB - i];
        }
    }
    */
    for (int i = min; i >0 ; i--){ 
        if (rst[lenA-1] == '1'){
            rst[i] = (temp == 1)? '0' : '1' ;
            temp = (rst[i] == '0')? 1 : 0;
        }
        else{
            rst[i] = (temp == 1)? '1' : '0' ;
            temp = 0;
        }
    }
    if (temp){
        rst[0] = '1';
    }
    else{
        rst[0] = '0';
    }
    rst[lenRst+1] = '\0';
    cout << "add binary 1: " << rst[0] << rst[1] << rst[2] << rst[3] << rst[4]  << rst[5] << rst[6] << endl;
    return rst;
}

int main(){
    string a = "11";
    string b = "101";
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    string rst = addBinary(a, b);
    cout << "add binary: " << rst << endl;
}