#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    float f = 0;
    char c[3];

    cout << "Enter integer: ";
    cin >> i;
    cout << "\nEnter float: ";
    cin >> f;
    for(int k=0;k<3;k++)
    {
        cout << "\nEnter char: ";
        cin >> c[k];
    }

    cout << "\nInteger multiplied with float: " << (i*f) << endl;
    cout << "Chars: ";
    for(int k=0;k<3;k++)
        cout << " " << c[k];
    return 0;
}
