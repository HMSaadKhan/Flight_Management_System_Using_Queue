#include <iostream>
#include "FMS_functions.h"
using namespace std;

int main()
{
    int opt, i;
    functions f;
    while (i == 0)
    {

        cout << endl
             << endl;
        cout << "Press 1 to enter departure details " << endl;
        cout << "Press 2 to enter departed details " << endl;
        cout << "Press 3 to enter landing detail" << endl;
        cout << "Press 4 to enter landed detail" << endl;
        cout << "Press 5 to add emergency landing" << endl;
        cout << "Press 6 to land emergency landings" << endl;
        cout << "Press 7 to view reports" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "Enter your choice:";
        cin >> opt;

        if (opt == 1)
        {
            f.departureinput();
        }
        else if (opt == 3)
        {
            f.landinginput();
        }
        else if (opt == 2)
        {
            f.departeddetails();
        }
        else if (opt == 4)
        {
            f.landeddetails();
        }
        else if (opt == 5)
        {
            f.emergencybyID();
        }
        else if (opt == 6)
        {
            f.emergencylanded();
        }
        else if (opt == 7)
        {
            int choice;
            for (int j = 0; j != 1;)
            {
                cout << endl
                     << endl
                     << "Press 1 to see departed flights " << endl
                     << "Press 2 to see landed" << endl
                     << "Press 3 to see cancel flights" << endl
                     << "Press 4 to see emergency landed detail" << endl
                     << "Press 5 to see delayed detail" << endl
                     << "Press 0 to go back" << endl
                     << "Enter your choice:";
                cin >> choice;
                if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
                    f.history(choice);
                else if (choice == 0)
                    j = 1;
                else
                    cout << "Enter Correct option";
            }
        }
        else if (opt == 0)
            i = 1;
        else
        {
            cout << "You Entered a wrong number";
        }
        f.fueldecreaser();
    }
}
