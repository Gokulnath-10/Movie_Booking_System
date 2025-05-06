#include <iostream>
#include <vector>
using namespace std;

struct MovieBooking {
    string title;
    int availableSeats;
};

class BookingSystem {
private:
    vector<MovieBooking> movies;
public:
    BookingSystem() {
        movies.push_back({"Jailer", 120});
        movies.push_back({"Avengers", 75});
        movies.push_back({"Avatar", 90});
    }
    void displayMovies() {
        cout << "Available Movies:\n";
        for (int i = 0; i < movies.size(); ++i) {
            cout << i + 1 << ". " << movies[i].title << " has " << movies[i].availableSeats << " seats \n";
        }
    }
    void bookTicket() {
        int movieNo, seats;
        displayMovies();
        cout << "Enter movie number that you want to watch: ";
        cin >> movieNo;
        if (movieNo < 1 || movieNo > movies.size()) {
            cout << "Please choose the available movie No...\n";
            return;
        }
        cout << "Enter number of seats: ";
        cin >> seats;
        if (seats <= 0 || seats > movies[movieNo - 1].availableSeats) {
            cout << "Invalid seat number.\n";
            return;
        }
        movies[movieNo - 1].availableSeats -= seats;
        cout << "The ticket booked successful for " << seats << " seat(s) in \"" << movies[movieNo - 1].title << "\".\n";
    }

    void start() {
        int option;
        while (true) {
            cout << "\n 1. View Movies\n 2. Book Ticket\n 3. Exit \nChoose option: ";
            cin >> option;
            switch (option) {
                case 1: displayMovies(); break;
                case 2: bookTicket(); break;
                case 3: cout << "Thankyou!\n"; return;
                default: cout << "Please choose the correct option!\n";
            }
        }
    }
};

int main() {
    BookingSystem Application;
    Application.start();
    return 0;
}
