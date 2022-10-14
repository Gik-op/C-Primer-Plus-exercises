#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;  // set the queue size


    int hours=120;                              //set the time limit
    long cyclelimit = MIN_PER_HR * hours;
    double perhour=1000;                        //set the upper limit

    int wait_time,wait_time2;
    double average_wait;
    long turnaways,customers,served,sum_line,line_wait;


    while(true)
    {
        Queue line(qs);
        Queue line2(qs);

        double min_per_cust;
        min_per_cust = MIN_PER_HR / perhour;

        Item temp;
        wait_time2 = wait_time = 0;
        line_wait = sum_line = served = customers = turnaways = 0;

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line.isfull()&&line2.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);
                    if(line.member()<line2.member())
                        line.enqueue(temp);
                    else
                        line2.enqueue(temp);
                }
            }
            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue (temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue (temp);
                wait_time2 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            if (wait_time2 > 0)
                wait_time2--;
            sum_line += line.queuecount()+line2.queuecount();
        }
        average_wait=(double) line_wait / served;
        if(average_wait<=1)
            break;
        else
            perhour--;
    }

    if (customers > 0)
    {
        cout << "customers per hour: " << perhour <<endl;
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line/2 / cyclelimit << endl;
        cout << " average wait time: "
             << average_wait << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}