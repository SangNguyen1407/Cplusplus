#include <iostream>
#include <string.h>

#define MAX_SIZE 30
using namespace std;

char *inputDate (char *inputDate){
    char *date = (char *)malloc(sizeof (char *) *MAX_SIZE);
    strcpy(date, inputDate);

    return date;
}

char **anlyDateInStr(char *date){
    int i = 0;
    char** arrDate = (char**) malloc(sizeof (char *) * MAX_SIZE);
    char *tp;
    tp = strtok(date, "/");
    while( tp != NULL){
        arrDate[i++] = tp;
        tp = strtok(NULL, "/");
    }

    return arrDate;
}

char *getNextDate(char *cYear, char *cMonth, char *cDay){
    char *cNextDate = (char *)malloc(sizeof (char *) * MAX_SIZE);
    
    //convert char to int 
    int iYear  = atoi (cYear);
    int iMonth = atoi (cMonth);
    int iDay   = atoi (cDay);
    //isLeapYear  
    int isLeapYear = iYear % 4;
    //nextDate
    int iLastDayInMonth = 0;
    int iNextYear  = 0;
    int iNextMonth = 0;
    int iNextDay   = 0;  

    switch (iMonth)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10: 
            iNextDay   = (iDay == 31)? 1:(iDay + 1);
            iNextMonth = (iDay == 31)? (iMonth + 1):(iMonth);
            iNextYear  = iYear;
            break;
        case 12:
            iNextDay   = (iDay == 31)? 1:(iDay + 1);
            iNextMonth = (iDay == 31)? 1:(iMonth);
            iNextYear  = (iDay == 31)? (iYear + 1):(iYear);
            break;
        case 2:
            if ( (!isLeapYear && iDay == 28) || (iDay == 29) ){
                iNextDay  = 1;
                iNextMonth = iMonth + 1;
                iNextYear = iYear;
            }
            else{
                iNextDay   = iDay + 1;
                iNextMonth = iMonth;
                iNextYear  = iYear;                
            }
            break;
        default:
            iNextDay   = (iDay == 30)? 1:(iDay + 1);
            iNextMonth = (iDay == 30)? (iMonth + 1):(iMonth);
            iNextYear  = iYear;
            break;
    }

    sprintf(cNextDate, "%s/%s/%s", std::to_string(iNextYear).c_str(),
                                   std::to_string(iNextMonth).c_str(),
                                   std::to_string(iNextDay).c_str());
    
//    cout << "test " << cNextDate << endl;
    
    return cNextDate;
}

int main (){
    char *date      = (char *)malloc(sizeof (char *) * MAX_SIZE);
    char *cYear     = (char *)malloc(sizeof (char *) * MAX_SIZE);
    char *cMonth    = (char *)malloc(sizeof (char *) * MAX_SIZE);
    char *cDay      = (char *)malloc(sizeof (char *) * MAX_SIZE);
    char **arrDate  = (char**)malloc(sizeof (char *) * MAX_SIZE);
    
    int n     = 0;
    int xDate = 0;

    cout << "Today is: (for example: 1990/1/1)  ";
    cin  >> date;
    cout << "Search next date(for example: 100) ";
    cin  >> xDate;

    cout << "The Date: " << date << endl;
    while(n++ < xDate){
        arrDate = anlyDateInStr(date);
        cYear   = arrDate[0];
        cMonth  = arrDate[1];
        cDay    = arrDate[2];
        date    = getNextDate(cYear, cMonth, cDay);
    }
    cout << "The next " << n-1 << " date: " << date << endl;

}