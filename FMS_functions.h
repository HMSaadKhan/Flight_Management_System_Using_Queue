#include <iostream>
using namespace std;
const int QS = 10;
struct time
{
    int day;
    int month;
    int hours;
    int mints;
};
struct landing
{
    int FlightID;
    int fuel;
    string destination;
    time schedule;
    time actual;
    int runway_ID;
};
struct departure
{
    int FlightID;
    string destination;
    time schedule;
    int status;
    time actual;
    int runway_ID;
};
bool chkdate(int date)
{
    if (date >= 1 && date <= 30)
        return true;
    else
        return false;
}
bool chkmonth(int month)
{
    if (month >= 1 && month <= 12)
        return true;
    else
        return false;
}
bool chkhours(int hours)
{
    if (hours >= 1 && hours <= 24)
        return true;
    else
        return false;
}
bool chkmint(int mint)
{
    if (mint >= 1 && mint <= 30)
        return true;
    else
        return false;
}

class landingQueue
{
private:
    int front, tail, tempcounter, Queuecounter;
    landing QArray[QS];

public:
    landingQueue()
    {
        Queuecounter = 0;
        tempcounter = 0;
        front = 0;
        tail = 0;
    }

    int gettail()
    {
        return tail;
    }
    int getfront()
    {
        return front;
    }
    int gettempcounter()
    {
        return tempcounter;
    }
    int getQueuecounter()
    {
        return Queuecounter;
    }
    bool isfull()
    {
        if (getQueuecounter() >= QS)
            return true;
        else
            return false;
    }
    bool isempty()
    {
        if (getQueuecounter() == 0)
            return true;
        else
            return false;
    }
    void getFlightID()
    {
        for (int i = 0; i <= getQueuecounter(); i++)
            cout << QArray[i].FlightID << endl;
    }

    void enqueue(int num2)
    {
        cout << "Enter flight ID: ";
        cin >> QArray[tail].FlightID;
        cout << "Enter Destination: ";
        cin >> QArray[tail].destination;
        cout << "Enter flight fuel: ";
        cin >> QArray[tail].fuel;
        cout << "Enter arrival date and time: " << endl;
        cout << "Day:";
    date:
        cin >> QArray[tail].schedule.day;

        if (!(chkdate(QArray[tail].schedule.day)))
        {
            cout << "Enter Correct date";
            goto date;
        }
        else
        {
            cout << "Month:";
        month:
            cin >> QArray[tail].schedule.month;
            if (!chkmonth(QArray[tail].schedule.month))
            {
                cout << "Enter Correct month";
                goto month;
            }
            else
            {
                cout << "Hours:";
            hours:
                cin >> QArray[tail].schedule.hours;
                if (!(chkhours(QArray[tail].schedule.hours)))
                {
                    cout << "Enter Correct hours";
                    goto hours;
                }
                else
                {
                    cout << "Minutes:";
                minutes:
                    cin >> QArray[tail].schedule.mints;
                    if (!chkmint(QArray[tail].schedule.mints))
                    {
                        cout << "Enter Correct minutes";
                        goto minutes;
                    }

                    QArray[tail].runway_ID = num2;
                    cout << "\nFlight Sucessfully added to Queue\n"
                         << endl;
                    tail++;
                    Queuecounter++;
                }
            }
        }
    }
    landing dequeue()
    {
        cout << "Enter actual time for Flight ID: " << QArray[gettempcounter()].FlightID << endl;
        cout << "Hours:";
    hours:
        cin >> QArray[tempcounter].actual.hours;
        if (!(chkhours(QArray[tempcounter].actual.hours)))
        {
            cout << "Enter Correct hours";
            goto hours;
        }
        else
        {
            cout << "Minutes:";
        minutes:
            cin >> QArray[tempcounter].actual.mints;
            if (!chkmint(QArray[tempcounter].actual.mints))
            {
                cout << "Enter Correct minutes";
                goto minutes;
            }
        }
        tempcounter++;
        cout << "\nFlight Sucessfully landed\n"
             << endl;
        landing temp = QArray[front];

        for (int i = front; i < tail; i++)
        {
            QArray[i] = QArray[i + 1];
        }
        tail--;
        Queuecounter--;

        return temp;
    }
    int fuelreducer()
    {
        char option;
        for (int i = 0; i < getQueuecounter(); i++)
        {
            QArray[i].fuel = (QArray[i].fuel - 10);

            if (QArray[i].fuel < 50)
            {
                cout << " \nFlight ID " << QArray[i].FlightID << " is short of fuel.\n Added to Emergency landing\n";
                return QArray[i].FlightID;
            }
        }
        return 0;
    }
    landing addtoemergency(int ID)
    {
        landing temp;
        for (int i = front; i != ID || i < getQueuecounter(); i++)
        {
            if (QArray[i].FlightID == ID)
            {
                temp = QArray[i];

                for (int j = i; j < getQueuecounter(); j++)
                {
                    QArray[j] = QArray[j + 1];
                }
                tail--;
                Queuecounter--;
                return temp;
            }
        }
        temp = QArray[tail];
        return temp;
    }
    void flightadding(landing obj)
    {
        QArray[tail++] = obj;
        Queuecounter++;
        cout << "\nFlight Sucessfully addded to emergency\n";
    }
};
class departureQueue
{
private:
    int front, tempcounter, Queuecounter, tail;
    departure QArray[QS];

public:
    departureQueue()
    {
        Queuecounter = 0;
        tempcounter = 0;
        front = 0;
        tail = 0;
    }
    int gettail()
    {
        return tail;
    }
    int getfront()
    {
        return front;
    }
    int gettempcounter()
    {
        return tempcounter;
    }
    int getQueuecounter()
    {
        return Queuecounter;
    }
    bool isfull()
    {
        if (getQueuecounter() >= QS)
            return true;
        else
            return false;
    }
    bool isempty()
    {
        if (getQueuecounter() == 0)
            return true;
        else
            return false;
    }
    void enqueue(int num2)
    {

        cout << "Enter flight ID: ";
        cin >> QArray[tail].FlightID;
        cout << "Enter Destination: ";
        cin >> QArray[tail].destination;
        cout << "Enter schedule time: ";
        cout << "Day:";
    date:
        cin >> QArray[tail].schedule.day;

        if (!(chkdate(QArray[tail].schedule.day)))
        {
            cout << "Enter Correct date";
            goto date;
        }
        else
        {
            cout << "Month:";
        month:
            cin >> QArray[tail].schedule.month;
            if (!chkmonth(QArray[tail].schedule.month))
            {
                cout << "Enter Correct month";
                goto month;
            }
            else
            {
                cout << "Hours:";
            hours:
                cin >> QArray[tail].schedule.hours;
                if (!(chkhours(QArray[tail].schedule.hours)))
                {
                    cout << "Enter Correct hours";
                    goto hours;
                }
                else
                {
                    cout << "Minutes:";
                minutes:
                    cin >> QArray[tail].schedule.mints;
                    if (!chkmint(QArray[tail].schedule.mints))
                    {
                        cout << "Enter Correct minutes";
                        goto minutes;
                    }
                    QArray[tail].runway_ID = num2;
                    cout << "\nFligth Successfully Added to Queue\n"
                         << endl;

                    tail++;
                    Queuecounter++;
                }
            }
        }
    }
    departure dequeue()
    {
        cout << "Enter Flight Status" << endl
             << "0 for delay" << endl
             << "1 for cancel" << endl
             << "2 for takeoff: ";
        cin >> QArray[gettempcounter()].status;
        if (QArray[gettempcounter()].status == 2)
        {
            cout << "Enter actual time for Flight ID: " << QArray[gettempcounter()].FlightID << endl;
            cout << "Hours:";
        hours:
            cin >> QArray[tempcounter].actual.hours;
            if (!(chkhours(QArray[tempcounter].actual.hours)))
            {
                cout << "Enter Correct hours";
                goto hours;
            }
            else
            {
                cout << "Minutes:";
            minutes:
                cin >> QArray[tempcounter].actual.mints;
                if (!chkmint(QArray[tempcounter].actual.mints))
                {
                    cout << "Enter Correct minutes";
                    goto minutes;
                }
            }
        }

        tempcounter++;
        if(!QArray[tempcounter].status==2)
        cout << "\nFlight Sucessfully Departed\n"
             << endl;

        departure temp = QArray[front];

        for (int i = front; i < tail; i++)
        {
            QArray[i] = QArray[i + 1];
        }
        tail--;
        Queuecounter--;

        return temp;
    }
    void flightadding(departure obj)
    {

        QArray[gettail()] = obj;
        tail++;
        Queuecounter++;
        cout << "\nFlight Sucessfully addded\n";
    }
};
class functions
{
private:
    int counterL1, counterL2, counterR1, counterR2, counterhistL, counterhistR, counterem, countercan, counterE, counterdelay;
    landingQueue Landing1, Landing2, Emergency;
    departureQueue Runway1, Runway2;
    landing qhistory[QS], Emergencyhis[QS];
    departure takeoffhistory[QS], Cancelhist[QS], delayhistory[QS];

public:
    functions()
    {
        counterL1 = 0;
        counterL2 = 0;
        counterR1 = 0;
        counterR2 = 0;
        counterhistL = 0;
        counterhistR = 0;
        counterem = 0;
        countercan = 0;
        counterE = 0;
        counterdelay = 0;
    }

    int getcounterL1()
    {
        return counterL1;
    }
    int getcounterL2()
    {
        return counterL2;
    }
    int getcounterR1()
    {
        return counterR1;
    }
    int getcounterem()
    {
        return counterem;
    }
    int getcounterR2()
    {
        return counterR2;
    }
    int getcounterE()
    {
        return counterE;
    }
    int getcounterhistL()
    {
        return counterhistL;
    }
    int getcounterhistR()
    {
        return counterhistR;
    }
    int getcountercan()
    {
        return countercan;
    }
    int getcounterdelay()
    {
        return counterdelay;
    }
    // Departure Details
    void departureinput()
    {
        int runway;
        if (getcounterR1() <= getcounterR2())
        {
            if (Runway1.isfull())
            {
                cout << "\nrunway 1 is full\n";
            }
            else
            {

                runway = 1001;
                Runway1.enqueue(runway);
                counterR1++;
            }
        }
        else
        {
            if (Runway2.isfull())
            {
                cout << "\nRunway 2 is full\n";
            }
            else
            {

                runway = 1002;
                Runway2.enqueue(runway);
                counterR2++;
            }
        }
    }

    void departeddetails()
    {
        if (getcounterR1() >= getcounterR2())
        {
            if (Runway1.isempty())
            {
                cout << " Enter data first";
            }
            else
            {
                departure temphistory = Runway1.dequeue();
                if (temphistory.status == 1)
                {
                    Cancelhist[countercan++] = temphistory;
                    cout << "Flight added to cancel history" << endl;
                }
                else if (temphistory.status == 0)
                {
                    Runway1.flightadding(temphistory);
                    delayhistory[counterdelay++] = temphistory;
                    cout << "Flight added to delay history" << endl;
                }
                else
                {
                    takeoffhistory[counterhistR++] = temphistory;
                    cout << endl
                         << "Flight added to history" << endl;
                }
                counterR1--;
            }
        }
        else
        {
            if (Runway2.isempty())
            {
                cout << " Enter data first";
            }
            else
            {
                departure temphistory = Runway1.dequeue();
                if (temphistory.status == 1)
                {
                    Cancelhist[countercan++] = temphistory;
                }
                else if (temphistory.status == 0)
                {
                    Runway2.flightadding(temphistory);
                    delayhistory[counterdelay++] = temphistory;
                    cout << "\nFlight added to history" << endl;
                }
                else
                {
                    takeoffhistory[counterhistR++] = temphistory;
                    cout << endl
                         << "Flight added to history" << endl;
                }
                counterR2--;
            }
        }
    }
    // Landing Details
    void landinginput()
    {
        int prior, runway;
        cout << "Select Priority for landing"
             << "\n1-emergency\n2- Normal"
             << "\nEnter your option: ";
        cin >> prior;
        if (prior == 1)
        {
            if (Emergency.isfull())
            {
                cout << "\nEmergency Landing cannot be done\n";
            }
            else
            {
                if (getcounterL1() <= getcounterL2())
                    runway = 1001;
                else
                    runway = 1002;
                Emergency.enqueue(runway);
                counterE++;
            }
        }
        else if (prior == 2)
        {
            if (getcounterL1() <= getcounterL2())
            {
                if (Landing1.isfull())
                {
                    cout << "\nLanding 1 is full\n";
                }
                else
                {
                    runway = 1001;
                    Landing1.enqueue(runway);
                    counterL1++;
                }
            }
            else
            {
                if (Landing2.isfull())
                {
                    cout << " Landing 2 is full";
                }
                else
                {
                    runway = 1002;
                    Landing2.enqueue(runway);
                    counterL2++;
                }
            }
        }
        else
        {
            cout << "\nYou have entered wrong option\n";
            landinginput();
        }
    }
    void landeddetails()
    {
        if (getcounterL1() <= getcounterL2())
        {
            if (Landing2.isempty())
            {
                cout << "\nEnter data first\n";
            }
            else
            {
                qhistory[counterhistL++] = Landing2.dequeue();
                cout << "\nFlight added to landing history\n"
                     << endl;
                counterL2--;
            }
        }

        else
        {
            if (Landing1.isempty())
            {
                cout << "\nEnter data first\n";
            }
            else
            {

                qhistory[counterhistL++] = Landing1.dequeue();
                cout << "\nFlight added to landing history\n"
                     << endl;
                counterL1--;
            }
        }
    }
    // Emergency Handling
    void emergencylanded()
    {
        if (Emergency.isempty())
        {
            cout << "\nThere is no emergency flight\n";
        }
        else
        {
            Emergencyhis[counterem++] = Emergency.dequeue();
            counterE--;
        }
    }

    void emergencybyID()
    {
        int fid;

        if (Landing1.isempty())
        {
            cout << "\nNo record found\n";
        }
        else
        {
            Landing1.getFlightID();
            cout << "Enter ID you want: ";
            cin >> fid;
            Emergency.flightadding(Landing1.addtoemergency(fid));
            counterL1--;
        }

        if (Landing2.isempty())
        {
            cout << "\nNo record found\n";
        }
        else
        {
            Landing2.getFlightID();
            cout << "Enter ID you want: ";
            cin >> fid;
            Emergency.flightadding(Landing2.addtoemergency(fid));
            counterL2--;
        }
        counterE++;
    }

    // History
    void history(int num)
    {

        if (num == 2)
        {
            printlanding();
        }
        else if (num == 1)
        {
            printdeparture();
        }
        else if (num == 4)
        {
            printemergency();
        }
        else if (num == 3)
        {
            printcancel();
        }
        else if (num == 5)
        {
            printdelayed();
        }
        else
        {
            cout << "\nYou entered a wrong option\n";
        }
    }
    // Printing Records
    void printlanding()
    {
        cout << "\nLanded Flights\n"
             << endl
             << "__________________________________________________________________________________________________________________________________________________________________________";
        if (getcounterhistL() <= 0)
            cout << endl
                 << "\nNo flight landed yet\n";
        else
        {

            for (int i = 0; i < getcounterhistL(); i++)
            {
                cout << endl
                     << "FlightID:\t\t\t" << qhistory[i].FlightID << endl
                     << "Fuel:\t\t\t\t" << qhistory[i].fuel << endl
                     << "Schedule Data and Month:\t " << qhistory[i].schedule.day << " " << getmonth(qhistory[i].schedule.month) << endl
                     << "LandingTime: \t\t\t" << qhistory[i].schedule.hours << " hours" << qhistory[i].schedule.mints << " minutes" << endl
                     << "ActualTime:\t \t\t" << qhistory[i].actual.hours << " Hours" << qhistory[i].actual.mints << " Minutes" << endl
                     << "WaitingTime:\t\t\t" << timecal(qhistory[i].actual.hours, qhistory[i].schedule.hours) << " Hours" << timecal(qhistory[i].actual.mints, qhistory[i].schedule.mints) << " Minutes" << endl
                     << "RunwayID:\t\t\t" << qhistory[i].runway_ID
                     << endl;
            }
        }
        cout << endl
             << "___________________________________________________________________________________________________________________________________________________________________________";
    }
    void printdeparture()
    {
        cout << "\ndeparted Flights\n"
             << endl
             << "__________________________________________________________________________________________________________________________________________________________________________";

        if (getcounterhistR() <= 0)
            cout << endl
                 << "\nNo flight departed yet\n"
                 << endl;
        else
        {
            for (int i = 0; i < getcounterhistR(); i++)
            {
                cout << endl
                     << "FlightID:\t\t\t " << takeoffhistory[i].FlightID << endl
                     << "Flight Status: \t\t\t" << setstatus(takeoffhistory[i].status) << endl
                     << "Schedule Data and Month: \t" << takeoffhistory[i].schedule.day << " " << getmonth(takeoffhistory[i].schedule.month) << endl
                     << "Schedule Time:\t\t\t" << takeoffhistory[i].schedule.hours << " hours" << takeoffhistory[i].schedule.mints << " minutes" << endl
                     << "Actual Time:\t\t\t" << takeoffhistory[i].actual.hours << " Hours" << takeoffhistory[i].actual.mints << " Minutes" << endl
                     << "Waiting Time:\t\t\t" << timecal(takeoffhistory[i].actual.hours, takeoffhistory[i].schedule.hours) << " Hours" << timecal(takeoffhistory[i].actual.mints, takeoffhistory[i].schedule.mints) << " Minutes" << endl
                     << "RunwayID:\t\t\t" << takeoffhistory[i].runway_ID
                     << endl;
            }
        }
        cout << endl
             << "___________________________________________________________________________________________________________________________________________________________________________";
    }
    void printdelayed()
    {
        cout << "\nDelayed Flights\n"
             << endl
             << "__________________________________________________________________________________________________________________________________________________________________________";

        if (getcounterdelay() <= 0)
            cout << endl
                 << "\nNo flight delayed yet\n"
                 << endl;
        else
        {
            for (int i = 0; i < getcounterdelay(); i++)
            {
                cout << endl
                     << "FlightID:\t\t\t " << delayhistory[i].FlightID << endl
                     << "Flight Status: \t\t\t" << setstatus(delayhistory[i].status) << endl
                     << "Schedule Data and Month: \t" << delayhistory[i].schedule.day << " " << getmonth(delayhistory[i].schedule.month) << endl
                     << "LandingTime:\t\t\t" << delayhistory[i].schedule.hours << " hours" << delayhistory[i].schedule.mints << " minutes" << endl
                     << "RunwayID:\t\t\t" << delayhistory[i].runway_ID
                     << endl;
            }
        }
        cout << endl
             << "___________________________________________________________________________________________________________________________________________________________________________";
    }

    void printemergency()
    {
        cout << "\n\nEmergency Landed Flights\n"
             << endl
             << "__________________________________________________________________________________________________________________________________________________________________________";

        if (getcounterem() <= 0)
            cout << endl
                 << "\nNo Emergency flight landed yet\n";
        else
        {
            for (int i = 0; i < getcounterem(); i++)
            {
                cout << endl
                     << "FlightID:\t\t\t" << Emergencyhis[i].FlightID << endl
                     << "Fuel:\t\t\t\t " << Emergencyhis[i].fuel << endl
                     << "Schedule Data and Month: \t" << Emergencyhis[i].schedule.day << " " << getmonth(Emergencyhis[i].schedule.month) << endl
                     << "Landing Time: \t\t\t" << Emergencyhis[i].schedule.hours << " hours" << Emergencyhis[i].schedule.mints << " minutes" << endl
                     << "Actual Time: \t\t\t" << Emergencyhis[i].actual.hours << " Hours" << Emergencyhis[i].actual.mints << " Minutes" << endl
                     << "Waiting Time:\t\t\t " << timecal(Emergencyhis[i].actual.hours, Emergencyhis[i].schedule.hours) << " Hours" << timecal(Emergencyhis[i].actual.mints, Emergencyhis[i].schedule.mints) << " Minutes" << endl
                     << "RunwayID: \t\t\t" << Emergencyhis[i].runway_ID
                     << endl;
            }
        }
        cout << endl
             << "___________________________________________________________________________________________________________________________________________________________________________";
    }
    void printcancel()
    {
        cout << "\n\nCancel Flights\n"
             << endl
             << "__________________________________________________________________________________________________________________________________________________________________________";

        if (getcountercan() <= 0)
            cout << endl
                 << "\nNo Cancel flights yet\n";
        else
        {
            for (int i = 0; i < getcountercan(); i++)
            {
                cout << endl
                     << "FlightID:\t\t\t " << Cancelhist[i].FlightID << endl
                     << "Fuel:\t\t\t\t " << Cancelhist[i].status << endl
                     << "Schedule Data and Month:\t " << Cancelhist[i].schedule.day << " " << getmonth(Cancelhist[i].schedule.month) << endl
                     << "Scheduled Time:\t\t\t " << Cancelhist[i].schedule.hours << " hours" << Cancelhist[i].schedule.mints << " minutes" << endl
                     << "RunwayID:\t\t\t " << Cancelhist[i].runway_ID
                     << endl;
            }
        }
        cout << endl
             << "___________________________________________________________________________________________________________________________________________________________________________";
    }

    string getmonth(int num)
    {
        switch (num)
        {
        case 1:
            return "januaray";
        case 2:
            return "Febuary";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        default:
            return "December";
        }
    }
    int timecal(int t1, int t2)
    {
        int t3 = t1 - t2;
        if (t3 > 0)
        {
            return t3;
        }
        else
        {
            return 0;
        }
    }
    string setstatus(int num)
    {
        if (num == 1)
            return "Cancel";
        if (num == 0)
            return "Delay";
        if (num == 2)
            return "normal";
    }
    void fueldecreaser()
    {
        if (Landing1.fuelreducer() != 0)
        {
            Emergency.flightadding(Landing1.addtoemergency(Landing1.fuelreducer()));
            counterE++;
        }
        if (Landing2.fuelreducer() != 0)
        {
            Emergency.flightadding(Landing2.addtoemergency(Landing2.fuelreducer()));
            counterE++;
        }
    }
};
