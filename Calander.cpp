#include <iostream>
using namespace std;

// checking leap_Year
// return 1 if LeapYear else return 0;
bool isLeapyear(int year)
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (year % 4 == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}
class Calander
{
public:
    int date;

    void calculate(int date);
};

void Calander ::calculate(int date)
{
    // 12 03 2004
    int D = date / 1000000;
    int month = (date / 10000) % 100;
    int year = (date % 10000);
    cout << "Date =  " << D << endl;
    cout << "Month = " << month << endl;
    cout << "Year =  " << year << endl;
    // cout<<isLeapyear(year)<<endl;
    int odd_days_of_nonLeapyear[] = {0, 3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
    int odd_days_of_Leapyear[] = {0, 3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};

    int sum_of_odd_days_Month = 0;

    // odd_days_of_Leapyear

    if (isLeapyear(year) == 1)
    {
        for (int i = 0; i < month; i++)
        {
            sum_of_odd_days_Month += odd_days_of_Leapyear[i];
        }
    }
    else
    {

        for (int i = 1; i < month; i++)
        {
            sum_of_odd_days_Month += odd_days_of_nonLeapyear[i];
        }
    }
    // cout << "sum of odd days of month ==> " << sum_of_odd_days_Month << endl;

    int Last_year = (year - 1) - ((((year) / 100) / 4) * 400);
    // cout << Last_year << endl;

    int odd_days_century;

    int remaningyear = odd_days_century = ((Last_year / 100) * 100);
    (odd_days_century == 100) ? odd_days_century = 5 : (odd_days_century == 200) ? odd_days_century = 3
                                                   : (odd_days_century == 300)   ? odd_days_century = 1
                                                                                 : odd_days_century = 0;

    // cout << "odd days of century year = > " << odd_days_century << endl;
    int leap = ((Last_year - remaningyear) / 4);
    int odd_days_in_leap = (leap * 2) % 7;

    int odd_days_in_Nonleap = ((Last_year - remaningyear) - leap) % 7;

    // Sum all the odd days which above calculate

    int Day = (D + sum_of_odd_days_Month + odd_days_century + odd_days_in_leap + odd_days_in_Nonleap) % 7;

    // cout << Day << endl;
    cout << "\nThe Day on " << D << "/" << month << "/" << year << " is ";
    switch (Day)
    {
    case 0:
        cout << "Sunday\n";
        break;
    case 1:
        cout << "Monday\n";
        break;
    case 2:
        cout << "Tuesday\n";
        break;
    case 3:
        cout << "Wednesday\n";
        break;
    case 4:
        cout << "Thusday\n";
        break;
    case 5:
        cout << "Friday\n";
        break;
    case 6:
        cout << "Saturday\n";
        break;
    }
}
int main()
{

Again:
    Calander d1;
    cout << "Find The day of a Date : \n";
    cout << "\nEnter date in this format --> 00/00/0000" << endl;
    int date, repeat;
    cout << "\nEnter date : ";
    cin >> date;
    d1.calculate(date);
    cout << endl;
    goto Again;
}