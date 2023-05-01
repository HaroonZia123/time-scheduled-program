#include <iostream>
#include <string>
#include <iomanip>
#include"schedule.h"
using namespace std;
#include <limits> // Needed for input validation

    int input(std::string * act, int* pri, std::string * dweek, int* sthour, int* stmint, int* sts, int* enhour, int* enmin, int* ens, int* dy, int* mn, int* yer)
    {
        std::cout << "Enter activity: ";
        std::cin >> *act;

        std::cout << "Enter Priority (High number High priority): ";
        while (!(std::cin >> *pri))
        {
            std::cout << "Invalid input. Please enter a valid priority: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        }

        std::cout << "Enter day of week [sunday, saturday]: ";
        while (!(std::cin >> *dweek))
        {
            std::cout << "Invalid input. Please enter a valid day of the week: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "\n*************Enter start time****************" << std::endl;
        std::cout << "hour (in 24-hour format): ";
        while (!(std::cin >> *sthour) || *sthour < 0 || *sthour >= 24)
        {
            std::cout << "Invalid input. Please enter a valid hour (0-23): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "minute: ";
        while (!(std::cin >> *stmint) || *stmint < 0 || *stmint >= 60)
        {
            std::cout << "Invalid input. Please enter a valid minute (0-59): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "second: ";
        while (!(std::cin >> *sts) || *sts < 0 || *sts >= 60)
        {
            std::cout << "Invalid input. Please enter a valid second (0-59): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "\n**************Enter end time***************" << std::endl;
        std::cout << "hour (in 24-hour format): ";
        while (!(std::cin >> *enhour) || *enhour < 0 || *enhour >= 24)
        {
            std::cout << "Invalid input. Please enter a valid hour (0-23): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "minute: ";
        while (!(std::cin >> *enmin) || *enmin < 0 || *enmin >= 60)
        {
            std::cout << "Invalid input. Please enter a valid minute (0-59): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "second: ";
        while (!(std::cin >> *ens) || *ens < 0 || *ens >= 60)
        {
            std::cout << "Invalid input. Please enter a valid second (0-59): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "\n*****************Enter date****************" << std::endl;
        std::cout << "day: ";
        while (!(std::cin >> *dy) || *dy <= 0 || *dy > 31)
        {
            std::cout << "Invalid input. Please enter a valid day (1-31): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "month (e.g., 1 for Jan, 2 for Feb): ";
        while (!(std::cin >> *mn) || *mn <= 0 || *mn > 12)
        {
            std::cout << "Invalid input. Please enter a valid month (1-12): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Year: ";
        while (!(std::cin >> *yer) || *yer < 0)
        {
            std::cout << "Invalid input. Please enter a valid year (0 or greater): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        return 1;
    }


int main()
{
    string dweek; //for weekday
    string act; //for acivity
    int pri;//for priority
    char ch;//for taking input for quitt or not
    cout << "****************Enter a schedule entry********************" << endl;
    int sthour, stmint, sts, dy, mn, yer, enhour, enmin, ens;
    //input function calling
    int check = input(&act, &pri, &dweek, &sthour, &stmint, &sts, &enhour, &enmin, &ens, &dy, &mn, &yer);
    {
        if (check == -1)
        {
            return 0;
        }
    }
    //pointer to tme class object
    tme* start = new tme(sthour, stmint, sts, dy, mn, yer);//time class object created
    tme* end = new tme(enhour, enmin, ens, dy, mn, yer);//time class object created
    Link d(dweek, start, end, act, pri);//Link(binary Tree) class object created
    do
    {
        int choice;//for choicing
        cout << "\n***********************Menue**********************\n";
        cout << "\t1) For Insert New Entry: \n";
        cout << "\t2) For Display Schedule: \n";
        cout << "\t3) For modifying Schedule: \n";
        cout << "Enter Choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 3) {
            cout << "Invalid input. Please enter a valid choice (1-3): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (choice == 1)
        {
            cout << "**************insert new entry***************\n";
            //taking input by calling function
            int check = input(&act, &pri, &dweek, &sthour, &stmint, &sts, &enhour, &enmin, &ens, &dy, &mn, &yer);
            {
                //for checking exception of input function
                if (check == -1)
                {
                    return 0;
                }
            }
            tme* stat = new tme(sthour, stmint, sts, dy, mn, yer);
            tme* ennd = new tme(enhour, enmin, ens, dy, mn, yer);
            d.insert(dweek, stat, ennd, act, pri);//insert function called
        }
        if (choice == 2)
        {
            cout << "\n";
            cout << setw(12) << "ACTIVITY " << setw(12) << "DAY " << setw(20) << "DATE " << setw(14) << " S_TIME " << setw(12) << "E_TIME " << setw(12) << " DURATION" << setw(7) << endl;
            cout << "--------------------------------------------------------------------------------\n";
            d.display();//display function called
        }
        if (choice == 3)
        {
            string ac;//for which activity you want to modification
            cout << "**************Modify an entry***************\n";

            cout << "Enter activity that is gonna modify : ";
            cin >> ac;
            //taking input by calling function
            int check = input(&act, &pri, &dweek, &sthour, &stmint, &sts, &enhour, &enmin, &ens, &dy, &mn, &yer);
            {
                //for checking exception of input function
                if (check == -1)
                {
                    return 0;
                }
            }
            start->day = dy;
            start->month = mn;
            start->year = yer;
            start->hour = sthour;
            start->minute = stmint;
            start->second = sts;
            end->hour = enhour;
            end->minute = enmin;
            end->second = ens;
            Schedule l(dweek, start, end, act, pri);//for schedule oject craeting
            d.modify(ac, l);//modification function called
        }
        cout << "\nDo u want to exit(y/n): ";
        cin >> ch;
    } while (ch != 'y' && ch != 'Y');
    return 0;
}