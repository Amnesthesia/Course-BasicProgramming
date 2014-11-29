#include <iostream>          //  cout, cin
#include <cctype>            //  toupper

using namespace std;
                             //  KLASSE:
class obligTime {                  //  Klasse inneholdende data om:
  private:
    int date, month, year;     //    - en gitt dato  og
    int hour, min, sec; //    - et gitt tidspunkt (klokkeslett).

    bool  leapYear(int year);                    //  Hentet/kopiert RETT
    int   day(int date, int month, int year);   //     fra OPPG_20.

  public:
    obligTime();                    //  2x constructorer:
    obligTime(int t, int m, int s);
    void printDate();        //  På formen:  dd/mm-aaaa
    void printTime();   //  På formen:  tt:mm:ss
    void printDatetime();         //  På formen:  dd/mm-aaaa   tt:mm:ss
    void readDate();          //  Leser inn ny dato.
    void readTime();     //  Leser inn nytt tidspunkt.
    void readDateTime();           //  Leser inn ny dato og nytt tidspunkt.
    bool dateCmp(const obligTime t);             //  Er datoene like eller ei.
    obligTime timeDiff(const obligTime tt);  //  Tiden mellom to tidspunkt samme dag.
    int dateDiff(const obligTime tt);  //  Antall dager mellom to datoer.
};

                             //  DEKLARASJON AV FUNKSJONER:
void printMenu();
char readCmd();
int  takeInput(const int MIN, const int MAX);



//  ********************  H O V E D P R O G R A M M E T:  *******************
int main()
{
  obligTime time1, time2, time3;  //  Tre tid-objekter.

  char choice;             //  Brukerens valg/ønske/kommando.
  int number;                //  Hvilken av tid1 og tid2 det skal endres på.

  printMenu();          //  Skriver/viser bruker-menyen.
  choice = readCmd(); //  Leser brukerens valg/ønske/kommando.

  while (choice != 'Q'  &&  choice != 'A')  {  //  Så lenge ikke avslutte:
    switch (choice)  {
      // If command is 'S', print date & time information
      case 'S':
            time1.printDatetime(); // Print date & time information from first object
            cout << "\n";
            time2.printDatetime(); // Print date & time info from second time object
            break;

       //If command is 'D', allow user to modify objects' date
       case 'D':
            // First, let the user select which object to modify
            cout << "\nWhich object do you want to modify? (1-2): ";
            number = takeInput(1,2);

            // If the user chose 1, read new date for object 1
            // and if the user chose 2, read new date for object 2
            switch(number)
            {
                case 1:
                    time1.readDate();
                    break;
                case 2:
                    time2.readDate();
                    break;
                default:
                    break;
            }
            break;
        case 'T':
            // Let the user choose an object to modify
            cout << "\nWhich object do you want to modify? (1-2): ";
            number = takeInput(1,2);

            // Read date and time information for the chosen object
            switch(number)
            {
                case 1:
                    time1.readDateTime();
                    break;
                case 2:
                    time2.readDateTime();
                    break;
                default:
                    break;
            }
            break;
        case 'P':
            // Let the user decide which object to modify
            cout << "\nWhich object do you want to modify? (1-2): ";
            number = takeInput(1,2);

            // And read new time data to the selected object
            switch(number)
            {
                case 1:
                    time1.readTime();
                    break;
                case 2:
                    time2.readTime();
                    break;
                default:
                    break;
            }
            break;

        case 'X':
            // If the dates are different, we apparently should not calculate time difference.
            if(!time1.dateCmp(time2))
                cout << "\nI'm afraid I can't let you do that, Dave. The dates are different.";
            // Otherwise, print the time difference between the two objects
            else
            {
                time3 = time1.timeDiff(time2);
                cout << "Time difference is: ";
                time3.printTime();
            }
            break;
            // Print difference in days between the two objects dates
        case 'Y':
            cout << "\nDifference in days is: " << time1.dateDiff(time2);
            break;

        // If unrecognized command, print the menu
        default:   printMenu();   break;
    }
    choice = readCmd(); //  Leser igjen brukerens valg/ønske/kommando.
  }
  cout << "\n\n";
  return 0;
}


//  *******************  DEFINISJON AV KLASSE-FUNKSJONER:  ********************

                                   //  IDENTISK TIL OPPG_20:
bool obligTime::leapYear(int year)
{    //  Sjekker om et visst år er skuddår:
  if ((year % 400 == 0)  || ((year % 4 == 0) && (year % 100) !=0))
     return true;                  //  Skuddår dersom: (delelig med 400)
  else                             //    ELLER (delelig med 4 OG ikke med 100)
     return false;
}

int obligTime::day(int date, int month, int year)
{
  //  Setter opp antall dager i månedene.
  int days_in_month[12] = {31,0,31,30,31,30,31,31,30,31,30,31}; //   Verdien for februar settes senere.
  int total_days,i;

  if (year < 1600  ||  year > 2100)
    return 0;    //  Ulovlig år.
  if (month < 1     ||  month > 12)
    return 0;    //  Ulovlig måned.

  //  Ut fra om året er skuddår eller ei,
  //  så settes verdien for februar:
  days_in_month[1] = (leapYear(year))  ?  29 : 28;
  if (date < 1 ||  date > days_in_month[month-1])
    return 0;  // Ulovlig dag:
               //  Garantert at er en lovlig dato !!
  total_days = date;
  for (i = 0;  i < month-1;  i++)  // Regner ut datoens dagnummer.
     total_days += days_in_month[i];

  return total_days; // Returnerer dagnummeret.
}


obligTime :: obligTime()  //  2x constructorer, som setter verdier:
{
    // Set default values
    date = 1;
    month = 1;
    year = 2000;
    hour = 0;
    min = 0;
    sec = 0;

}

obligTime :: obligTime(int t, int m, int s)
{
    // First set default values, then change time values.
    obligTime();
    hour = t;
    min = m;
    sec = s;
}

void obligTime :: printDate()           //  På formen:  dd/mm-aaaa
{
    cout << (date<10 ? "0" : "") << date << (month<10 ? "/0":"/") << month << "-" << year;
}

void obligTime :: printTime()      //  På formen:  tt:mm:ss
{
    cout << (hour<10 ? "0" : "") << hour << (min<10 ? ":0" : ":") << min << (sec<10 ? ":0" : ":") << sec;
}

void obligTime :: printDatetime()            //  På formen:  dd/mm-aaaa   tt:mm:ss
{
    printDate();
    cout << "\t";
    printTime();
}

void obligTime :: readDate()             //  Leser inn ny dato:
{
    cout << "\nAccepting values for date\n---------------------";
    // Read date in year, month, daý order with proper intervals.
    int days_in_month[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
    cout << "\nEnter year: ";
    year = takeInput(1600,2100);
    cout << "\nEnter month: ";
    month = takeInput(1,12);
    cout << "\nEnter day: ";
    date = takeInput(1,days_in_month[month-1]);
}

void obligTime :: readTime()        //  Leser inn nytt tidspunkt:
{
    cout << "\nAccepting values for time\n---------------------";
    // Read time values in hour, minute, seconds order
    // from input and set as values for object.
    cout << "\nEnter new value for hour: ";
    hour = takeInput(0,24);
    cout << "\nEnter new value for minute: ";
    min = takeInput(0,60);
    cout << "\nEnter new value for seconds: ";
    sec = takeInput(0,60);
}

void obligTime :: readDateTime()              //  Leser inn ny dato og nytt tidspunkt:
{
   // Read both date and time. This is a shortcut for
   // readTime() and readDate()
   readTime();
   readDate();
}

bool obligTime :: dateCmp(const obligTime t)  //  Er to datoer like eller ei:
{
    // Check if date is the same, and if it is check if month
    // is the same as well, and if it is, check if the year
    // is the same as well. If any of it differs, return false.
    if(t.date==date)
        if(t.month==month)
            if(t.year==year)
                return true;
            else return false;
        else return false;
    else return false;
}

obligTime obligTime :: timeDiff(const obligTime tt) //  Forskjellen mellom to tidspunkt:
{
    // Get the time in seconds, multiply hours with 3600
    // minutes with 60 and then add the remaining seconds.
    int currentTimeInSeconds = (hour*(60*60)) + (min*60) + sec;
    int compareToTimeInSeconds = (tt.hour*(60*60)) + (tt.min*60) + tt.sec;
    int diff = 0;

    // Both times are now in seconds, subtract the smaller
    // from the larger value.
    if(currentTimeInSeconds>compareToTimeInSeconds)
        diff = currentTimeInSeconds-compareToTimeInSeconds;
    else
        diff = compareToTimeInSeconds-currentTimeInSeconds;

    // Turn it back into hour / minute / seconds format and create
    // a time object from it.
    int hourDiff = diff/3600;
    int minuteDiff = diff/60-(hourDiff*60);
    int secDiff = diff%60;

    return obligTime(hourDiff,minuteDiff,secDiff);
}              // (Hentet MYE fra OPPG_16.)

int obligTime :: dateDiff(const obligTime tt)   //  Antall dager mellom to datoer:
{
    // Calculate what day of the year (0-366)
    int currentTotalDay = day(date,month,year);
    int cmpToDay = day(tt.date,tt.month,tt.year);

    // Check the difference between the dates.
    // Should the difference become negative, make it positive.
    int dayDiff = cmpToDay-currentTotalDay;
    if(dayDiff<0)
        dayDiff *= -1;

    // If the years are different, we gotta add up the days from
    // the years in between:
    if(tt.year!=year)
    {
        int countFromYear = (tt.year>year ? year : tt.year);
        int countToYear = (tt.year>year ? tt.year : year);
        for(int c = countFromYear;c<countToYear;c++)
            if(leapYear(c))
                dayDiff += 366;
            else
                dayDiff += 365;
    }
    return dayDiff;
}



//  ***********************  DEFINISJON AV FUNKSJONER:  ***********************

void printMenu()  {         //  Skriver brukerens valg/muligheter/meny:
  cout << "\n\nFølgende kommandoer er aktuelle:\n";
  cout << "\tS   - Skriv begge tidene\n";
  cout << "\tD   - Dato-innlesning\n";
  cout << "\tP   - Tidspunkt-innlesning\n";
  cout << "\tT   - Tid-innlesning (= Dato + Tidspunkt)\n";
  cout << "\tX   - Tidspunkt-forskjell (når samme dato)\n";
  cout << "\tY   - Dato-forskjell\n";
  cout << "\tQ/A - Quit / Avslutt\n";
}


char readCmd()
{       //  Leser brukerens valg/ønske/kommando:
  char ch;                   //  Innskrevet tegn.
  cout << "\n\nEnter command (S, D, P, T, X, Y, Q/A):  ";  //  Ber om ett tegn.
  cin >> ch;
  ch = toupper(ch);        //  Leser og upcaser tegn.
  return ch;                 //  Returnerer tegn/kommando.
}

                                //  Leser inn og returnerer verdi i [MIN, MAX]:
int takeInput(const int MIN, const int MAX)  {
  int num;                     //  Innskrevet tallverdi.
  cin >> num;                  //  Leser tall.
  while (num < MIN  ||  num > MAX)  {    //  Utenfor gyldig intervall:
     cout << "\tbetween (" << MIN << '-' << MAX << "):  ";
     cin >> num;
  }
  return num;                  //  Returnerer akseptert (gyldig) tall
}

