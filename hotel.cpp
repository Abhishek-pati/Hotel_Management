#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;
struct Customer {
    string name;
    int roomNumber;
    string phoneNumber;
};

class Hotel {
private:
    vector<Customer> customers;
    vector<int> bookedRooms;

public:
    bool isRoomAvailable(int roomNumber) {
        return find(bookedRooms.begin(), bookedRooms.end(), roomNumber) == bookedRooms.end();
    }

    void bookRoom() {
        Customer cust;
        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, cust.name);
        cout << "Enter Room Number: ";
        cin >> cust.roomNumber;
        cout << "Enter Phone Number: ";
        cin >> cust.phoneNumber;

        if (!isRoomAvailable(cust.roomNumber)) {
            cout << "Room already booked! Try another room.\n";
            return;
        }

        customers.push_back(cust);
        bookedRooms.push_back(cust.roomNumber);
        cout << "Room " << cust.roomNumber << " successfully booked for " << cust.name << ".\n";
    }

    void displayCustomers() {
        if (customers.empty()) {
            cout << "No rooms are currently booked.\n";
            return;
        }

        cout << "\nBooked Rooms Details:\n";
        cout << "-----------------------------------\n";
        for (const auto &cust : customers) {
            cout << "Name: " << cust.name << ", Room: " << cust.roomNumber << ", Phone: " << cust.phoneNumber << endl;
        }
        cout << "-----------------------------------\n";
    }
    void checkOut() {
        int roomNumber;
        cout << "Enter Room Number to Check Out: ";
        cin >> roomNumber;

        bool found = false;
        for (size_t i = 0; i < customers.size(); i++) {
            if (customers[i].roomNumber == roomNumber) {
                customers.erase(customers.begin() + i);
                bookedRooms.erase(std::remove(bookedRooms.begin(), bookedRooms.end(), roomNumber), bookedRooms.end());
                cout << "Room " << roomNumber << " successfully checked out.\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Room not found or already vacant!\n";
        }
    }
};

int main() {
    Hotel hotel;
    int choice;

    while (true) {
        cout << "\n===== Hotel Management System =====\n";
        cout << "1. Book Room\n";
        cout << "2. Display Booked Rooms\n";
        cout << "3. Check Out\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.bookRoom();
                break;
            case 2:
                hotel.displayCustomers();
                break;
            case 3:
                hotel.checkOut();
                break;
            case 4:
                cout << "Exiting... Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}