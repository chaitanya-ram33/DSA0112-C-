#include <iostream>
#include <string>
using namespace std;

class Hotel {
private:
    int roomNo;
    string guestName;
    string phone;
    string roomType;
    int days;
    bool booked;

public:
    Hotel() {
        roomNo = 0;
        guestName = "";
        phone = "";
        roomType = "";
        days = 0;
        booked = false;
    }

    void setRoom(int no, string type) {
        roomNo = no;
        roomType = type;
    }

    void bookRoom() {
        if (booked) {
            cout << "Room is already booked!\n";
            return;
        }

        cout << "Enter Guest Name: ";
        cin >> guestName;

        cout << "Enter Phone Number: ";
        cin >> phone;

        cout << "Enter Number of Days: ";
        cin >> days;

        booked = true;

        cout << "\nRoom booked successfully!\n";
    }

    void cancelRoom() {
        if (!booked) {
            cout << "Room is not booked!\n";
        } else {
            booked = false;
            guestName = "";
            phone = "";
            days = 0;
            cout << "Reservation cancelled successfully!\n";
        }
    }

    void checkIn() {
        if (booked)
            cout << "Guest " << guestName << " checked in successfully.\n";
        else
            cout << "Room is not reserved.\n";
    }

    void checkOut() {
        if (!booked) {
            cout << "Room is not occupied.\n";
            return;
        }

        int rate;

        if (roomType == "Single")
            rate = 1500;
        else if (roomType == "Double")
            rate = 2500;
        else
            rate = 4000;

        int bill = rate * days;

        cout << "\n----- HOTEL BILL -----\n";
        cout << "Guest Name : " << guestName << endl;
        cout << "Room No    : " << roomNo << endl;
        cout << "Room Type  : " << roomType << endl;
        cout << "Days       : " << days << endl;
        cout << "Total Bill : Rs." << bill << endl;
        cout << "----------------------\n";

        booked = false;
        guestName = "";
        phone = "";
        days = 0;

        cout << "Check-out completed successfully!\n";
    }

    void display() {
        cout << roomNo << "\t"
             << roomType << "\t\t"
             << (booked ? "Booked" : "Available") << endl;
    }
};

int main() {
    Hotel rooms[5];

    rooms[0].setRoom(101, "Single");
    rooms[1].setRoom(102, "Single");
    rooms[2].setRoom(201, "Double");
    rooms[3].setRoom(202, "Double");
    rooms[4].setRoom(301, "Suite");

    int choice, room;

    do {
        cout << "\n====================================\n";
        cout << " HOTEL RESERVATION MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. View Room Availability\n";
        cout << "2. Book Room\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. Check-In\n";
        cout << "5. Check-Out and Generate Bill\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "\nRoom No\tRoom Type\tStatus\n";
            for (int i = 0; i < 5; i++)
                rooms[i].display();
            break;

        case 2:
            cout << "Enter room number: ";
            cin >> room;

            if (room == 101)
                rooms[0].bookRoom();
            else if (room == 102)
                rooms[1].bookRoom();
            else if (room == 201)
                rooms[2].bookRoom();
            else if (room == 202)
                rooms[3].bookRoom();
            else if (room == 301)
                rooms[4].bookRoom();
            else
                cout << "Invalid room number!\n";
            break;

        case 3:
            cout << "Enter room number: ";
            cin >> room;

            if (room == 101)
                rooms[0].cancelRoom();
            else if (room == 102)
                rooms[1].cancelRoom();
            else if (room == 201)
                rooms[2].cancelRoom();
            else if (room == 202)
                rooms[3].cancelRoom();
            else if (room == 301)
                rooms[4].cancelRoom();
            else
                cout << "Invalid room number!\n";
            break;

        case 4:
            cout << "Enter room number: ";
            cin >> room;

            if (room == 101)
                rooms[0].checkIn();
            else if (room == 102)
                rooms[1].checkIn();
            else if (room == 201)
                rooms[2].checkIn();
            else if (room == 202)
                rooms[3].checkIn();
            else if (room == 301)
                rooms[4].checkIn();
            else
                cout << "Invalid room number!\n";
            break;

        case 5:
            cout << "Enter room number: ";
            cin >> room;

            if (room == 101)
                rooms[0].checkOut();
            else if (room == 102)
                rooms[1].checkOut();
            else if (room == 201)
                rooms[2].checkOut();
            else if (room == 202)
                rooms[3].checkOut();
            else if (room == 301)
                rooms[4].checkOut();
            else
                cout << "Invalid room number!\n";
            break;

        case 6:
            cout << "Thank you for using the system!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
