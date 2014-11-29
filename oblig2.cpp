#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct day
{
    int minTmp;
    int maxTmp;
    int rain;
};
void populateDay(int i, day &date);
void printCalendar(day* &date, int daysInMonth);

int main()
{
    cout << "Welcome to Oblig #2, by panda.\n";
    cout << "This program lets you enter the minimum temperature,\n";
    cout << "maximum temperature, and total rainfall for any given day";
    cout << "in a month. First, specify the amount of days in the month.\n";

    // We set run to false as a default value - rather have a 0 than a 1, a do/while will run at least once anyways.
    bool run = false;
    do
    {
        // We set up amount of days in the month, and an int called tries to
        // check if the user has attempted to input a value before and failed.
        int daysInMonth= 0,tries = 0;

        // Now we'll take input for amount of days,
        // this input must be a value between 28-31.
        do
        {
            if(tries>0)
                cout << "\nError: Amount of days must be a value between 28-31.";
            cout << "\nEnter amount of days for this month: ";
            cin >> daysInMonth;
            tries++;
        }while(daysInMonth<28 || daysInMonth>31);

        // We use the input for amount of days to set up our day-struct.
        day* date = new day[daysInMonth];

        // We also set up 3 variables containing the totals of all days' values
        float totalRain=0, totalMinTmp=0,totalMaxTmp=0;

        // Now we loop through each day and call populateDay to take the userinput
        for(int i=0;i<daysInMonth;i++)
        {
            populateDay(i,date[i]);
            totalRain += date[i].rain;
            totalMaxTmp += date[i].maxTmp;
            totalMinTmp += date[i].minTmp;
        }

        // Print information about each days values
        cout << "\nCalendar:\n";
        printCalendar(date,daysInMonth);

        cout << "\n\nAverage min. temperature: " << (totalMinTmp/daysInMonth);
        cout << "\nAverage max. temperature: " << (totalMaxTmp/daysInMonth);
        cout << "\nAverage rainfall: " << (totalRain/daysInMonth) << "(mm)";
        cout << "\nTotal rainfall: " << totalRain << "(mm)\n";

        // We set up a char variable to take the users input for whether or not to rerun.
        char retry;

        // We loop this until we get a y, or an n. We could just check for y and default to no,
        // but we're gonna be naggy instead. Require a yes (y) or a no (n).
        do
        {
            cout << "\nWould you like to run this program again? (y/n): ";
            cin >> retry;

            // Typecast the char to an int and compare against the ascii values
            switch((int)retry)
            {
                // 78 and 110 is N and nrespectively
                case 78:
                case 110:
                    run = false;
                    break;
                // 131 is Y and y respectively.
                case 131:
                case 171:
                    run = true;
                    break;
            }
        }while(retry!='y' && retry!='Y' && retry!='N' && retry!='n');

        delete date;
    }while(run);
    return 0;


}

void populateDay(int i, day &date)
{
    // attemptedInputs keeps track of whether or not the user has made an invalid input previously.
    int attemptedInputs = 0;
    const int maximumMinTmp = 70;
    const int maximumRainFall = 200;
    const int minimumMinTmp = -70;
    // Take userinput for minimum temperature. Must be between -70 - 70.
    do
    {
        if(attemptedInputs>0)
            cout << "\nInvalid input. Minimum temperature must be a value -70-70\n";
        cout << "Enter minimum temperature for day " << (i+1) << ": ";
        cin >> date.minTmp;
        attemptedInputs++;
    }while(date.minTmp>maximumMinTmp || date.minTmp<minimumMinTmp);

    // Take userinput for maximum temperature. Must be between minTmp - 70.
    attemptedInputs = 0;
    do
    {
        if(attemptedInputs>0)
            cout << "\nInvalid input. Maximum temperature must be a value " << date.minTmp << "-70\n";
        cout << "Enter maximum temperature for day " << (i+1) << ": ";
        cin >> date.maxTmp;
        attemptedInputs++;
    }while(date.maxTmp>maximumMinTmp || date.maxTmp<date.minTmp);

    // Take userinput for rainfall. Must be between 0 and 200.
    attemptedInputs = 0;
    do
    {
        if(attemptedInputs>0)
            cout << "\nInvalid input. Rainfall must be  " << date.minTmp << "-70\n";
        cout << "Enter rainfall (mm) for day " << (i+1) << ": ";
        cin >> date.rain;
        attemptedInputs++;
    }while(date.rain>maximumRainFall || date.rain<0);
}

void printCalendar(day* &date, int daysInMonth)
{
    // Print columns
    cout << "Day\t|\tMin. Tmp\t|\tMax. Tmp\t|\tRainfall ";

    // Loop through all elements of date and take the chars into the stream
    for(int i=0;i<daysInMonth;i++)
    {
        cout << "\n";
        cout << (i+1);
        cout << "\t|\t";
        cout << date[i].minTmp;
        cout << "\t\t|\t";
        cout << date[i].maxTmp;
        cout << "\t\t|\t";
        cout << date[i].rain;
    }

}
