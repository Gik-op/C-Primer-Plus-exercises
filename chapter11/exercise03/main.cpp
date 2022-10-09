// randwalk.cpp -- using the Vector class
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vector.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0,step_max,step_min,step_all=0,average;//average maybe change to double
    int times=1;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        cout << "Enter the test times: ";
        cin >> times;

        for(int i=0;i<times;i++)
        {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, VECTOR::Vector::POL);
                result = result + step;
                steps++;
            }
            if(i==0)
                step_max=step_min=steps;
            if(steps > step_max)
                step_max=steps;
            if(steps < step_min)
                step_min=steps;
            step_all += steps;
            steps = 0;
            result.reset(0.0, 0.0);
        }
        average = step_all / times;
        cout << "The max number of steps is " << step_max << ".\n"
             << "The min number of steps is " << step_min << ".\n"
             << "The average number of steps is " << average << ".\n";
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}