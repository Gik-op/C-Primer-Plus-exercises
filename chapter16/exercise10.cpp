#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
    std::string title;
    double price;
    int rating;
};

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool worseThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool lessThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool FillReview(Review & rr);
void ShowReview(const std::shared_ptr<Review> &rr);
int main()
{
    using namespace std;

    vector<shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp))
    {
        shared_ptr<Review> bk(new Review(temp));
        books.push_back(bk);
    }
    if (!books.empty())
    {
        string choice;
        cout << "Thank you. You entered " << books.size() << " books.\n";
        while(true)
        {
            cout << "Please select one of the following ways to display books.\n";
            cout << "o) original order   a) alphabetical order\n"
                    "s) ratings in ascending order  d) ratings in descending order\n"
                    "p) price in ascending order    i) price in descending order\n"
                    "q) quit\n";
            getline(cin,choice);
            if(!strchr("oasdpiq",choice[0]))
            {
                cout << "Invalid input.\n";
                continue;
            }
            else if(choice[0]=='q')
                break;
            else
            {
                switch(choice[0])
                {
                    case 'o':
                        cout << "You entered the following " << books.size() << " ratings:\n"
                             << "Rating\tBook\n";
                        for_each(books.begin(), books.end(), ShowReview);
                        break;
                    case 'a':
                        sort(books.begin(), books.end());
                        cout << "Sorted by title in alphabetical order:\nRating\tBook\n";
                        for_each(books.begin(), books.end(), ShowReview);
                        break;
                    case 's':
                        sort(books.begin(), books.end(), worseThan);    // ascending order
                        cout << "Sorted by rating in ascending order:\nRating\tBook\n";
                        for_each(books.begin(), books.end(), ShowReview);
                        break;
                    case 'd':
                        sort(books.begin(), books.end(), worseThan);
                        cout << "Sorted by rating in descending order:\nRating\tBook\n";
                        for_each(books.rbegin(), books.rend(), ShowReview);  // descending order
                        break;
                    case 'p':
                        sort(books.begin(), books.end(), lessThan);    // ascending order
                        cout << "Sorted by price in ascending order:\nRating\tBook\n";
                        for_each(books.begin(), books.end(), ShowReview);
                        break;
                    case 'i':
                        sort(books.begin(), books.end(), lessThan);
                        cout << "Sorted by price in descending order:\nRating\tBook\n";
                        for_each(books.rbegin(), books.rend(), ShowReview);   // descending order
                        break;
                }
            }
        }
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    return 0;
}

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool lessThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review> &rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}