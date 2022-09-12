#include <iostream>

int main()
{
    using namespace std;
    long long time = 0;
    long day,hour,min,sec;
    const int hr2day = 24;
    const int min2hr = 60;
    const int sec2min = 60;
    cout << "Please enter the number of seconds: ";
    cin >> time;
    day = time/(sec2min*min2hr*hr2day);
    hour = (time%(sec2min*min2hr*hr2day))/(sec2min*min2hr);
    min = ((time%(sec2min*min2hr*hr2day))%(sec2min*min2hr))/sec2min;
    sec = ((time%(sec2min*min2hr*hr2day))%(sec2min*min2hr))%sec2min;
    cout << time << " seconds = " << day << " days, " << hour << " hours, " << min << " minutes, " << sec << " seconds\n";
    return 0;
}
