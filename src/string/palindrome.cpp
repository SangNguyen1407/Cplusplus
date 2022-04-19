#include <iostream>
#include <string>

using namespace std;

string getCharInPhrase(string s){
    if (s == ""){
        return s;
    }
    int sLen = 0;
    string rst = s;

    for (int i = 0; i < s.length(); i++){
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            rst[sLen] = std::tolower(s[i]);
            sLen++;
        }
        else if (s[i] >= '0' && s[i] <= '9'){
            rst[sLen] = s[i];
            sLen++;
        }
    }
    
    rst = rst.substr(0, sLen);
    return rst;
}

bool isPalindrome(string s) {
    string rst = getCharInPhrase(s);
    if(rst == string(rst.rbegin(), rst.rend())){
        return true;
    }

    return false;
}

int main(){
    string S = "A Man, a plaN, a canal: Panama";
    cout << isPalindrome(S) << endl;

    S = "race a car";
    cout << isPalindrome(S) << endl;

    S = " ";
    cout << isPalindrome(S) << endl;

    S = "A Man, a plaN, a 0c000anal: Panama";
    cout << isPalindrome(S) << endl;

    return 0;
}