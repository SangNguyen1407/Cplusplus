#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string columnTitle) {
    if (columnTitle == ""){
        return 0;
    }
    int result = 0;
    for (int i = 0; i< columnTitle.length(); i++){
        result *= 26;
        result += columnTitle[i] - 'A' + 1;
    }

    return result;
}

int main(){
    cout << titleToNumber("CDA") << endl;
    cout << titleToNumber("AA") << endl;
    cout << titleToNumber("AAAA") << endl;
}