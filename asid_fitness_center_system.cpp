#include <iostream>
#include <string>
using namespace std;

// FUNCTION DECLARATION
void membermenu();
void workoutmenu();
void paymentmenu();
void reportmenu();
void customerreport();

int findmemberindex(string id);
bool isvalidemail(string email);
void pressenter();
double expectedfee(int index);

// GLOBAL DATA
string membername[100];
string memberemail[100];
string memberid[100];
int memberage[100];
bool isstudent[100];
int membershipmonths[100] = {0};
int membercount = 0;

// PAYMENT
string payid[100];
double payamount[100];
string paystatus[100];
int paycount = 0;

// WORKOUT
string wname[100];
string wpart[100];
string wschedule[100];
int wcount = 0;

// GYM USAGE
string usagememberID[200];
string usageworkout[200];
string usageday[200];
int usagecount = 0;

// ===== UTILITY =====
void pressenter() {
    string temp;
    cout << "\nPress Enter to continue...";
    getline(cin, temp);
}

bool isvalidemail(string email) {
    return email.find('@') != string::npos;
}

// FIND MEMBER BY ID (IMPORTANT)
int findmemberindex(string id) {
    for (int i = 0; i < membercount; i++) {
        if (memberid[i] == id) {
            return i;
        }
    }
    return -1;
}

double expectedfee(int index) {
    return isstudent[index] ? 50.0 : 100.0;
}

// ===== MAIN =====
int main() {
    string choice;

    while (true) {
        cout << "\n=====================================\n";
        cout << "      ASID FITNESS CENTER SYSTEM     \n";
        cout << "=====================================\n";

        cout << "\n1. Member Module\n";
        cout << "2. Workout Module\n";
        cout << "3. Payment Module\n";
        cout << "4. Admin Report\n";
        cout << "5. Customer Report\n";
        cout << "6. Exit\n";

        cout << "\nEnter choice: ";
        getline(cin, choice);

        if (choice == "1") membermenu();
        else if (choice == "2") workoutmenu();
        else if (choice == "3") paymentmenu();
        else if (choice == "4") reportmenu();
        else if (choice == "5") customerreport();
        else if (choice == "6") break;
        else cout << "Invalid choice!\n";
    }
}

// ===== MEMBER MODULE =====
void membermenu() {
    string option;

    while (true) {
        cout << "\n===== MEMBER MODULE =====\n";
        cout << "1. Add Member\n";
        cout << "2. Search Member\n";
        cout << "3. Renew Membership\n";
        cout << "4. Back\n";

        cout << "Choice: ";
        getline(cin, option);

        if (option == "1") {
            cout << "\nEnter Name: ";
            getline(cin, membername[membercount]);

            string email;
            do {
                cout << "Enter Email: ";
                getline(cin, email);
                if (!isvalidemail(email))
                    cout << "Invalid email!\n";
            } while (!isvalidemail(email));

            memberemail[membercount] = email;

            cout << "Enter Age: ";
            cin >> memberage[membercount];
            cin.ignore();

            cout << "Enter Member ID: ";
            getline(cin, memberid[membercount]);

            cout << "Student? (1=Yes 0=No): ";
            cin >> isstudent[membercount];
            cin.ignore();

            membershipmonths[membercount] = 1;
            membercount++;

            cout << "Member Added!\n";
        }

        else if (option == "2") {
            string id;
            cout << "Enter Member ID: ";
            getline(cin, id);

            int index = findmemberindex(id);

            if (index == -1) {
                cout << "Member not found!\n";
            } else {
                cout << "\nName: " << membername[index];
                cout << "\nEmail: " << memberemail[index];
                cout << "\nMonths: " << membershipmonths[index] << endl;
            }
        }

        else if (option == "3") {
            string id;
            cout << "Enter Member ID: ";
            getline(cin, id);

            int index = findmemberindex(id);

            if (index == -1) {
                cout << "Member not found!\n";
            } else {
                membershipmonths[index]++;
                cout << "Membership renewed!\n";
            }
        }

        else if (option == "4") return;
    }
}

// ===== WORKOUT MODULE =====
void workoutmenu() {
    string option;

    while (true) {
        cout << "\n===== WORKOUT MODULE =====\n";
        cout << "1. Add Workout Plan\n";
        cout << "2. View Workouts\n";
        cout << "3. Record Gym Usage\n";
        cout << "4. Back\n";

        cout << "Choice: ";
        getline(cin, option);

        if (option == "1") {

            cout << "Enter Member ID: ";
            string id;
            getline(cin, id);

            int index = findmemberindex(id);

            if (index == -1) {
                cout << "Member not found!\n";
                continue;
            }

            wname[wcount] = membername[index];

            cout << "Select Body Part:\n";
            cout << "1. Chest\n2. Back\n3. Legs\n4. Arms\n5. Shoulders\n";

            string choice;
            getline(cin, choice);

            if (choice == "1") wpart[wcount] = "Chest";
            else if (choice == "2") wpart[wcount] = "Back";
            else if (choice == "3") wpart[wcount] = "Legs";
            else if (choice == "4") wpart[wcount] = "Arms";
            else if (choice == "5") wpart[wcount] = "Shoulders";
            else {
                cout << "Invalid choice!\n";
                continue;
            }

            cout << "Enter Schedule: ";
            getline(cin, wschedule[wcount]);

            cout << "\n--- Recommended Exercises ---\n";

            if (wpart[wcount] == "Chest")
                cout << "Bench Press 8-12 reps\nPush Ups 15 reps\n";
            else if (wpart[wcount] == "Back")
                cout << "Lat Pulldown 10 reps\nDeadlift 8 reps\n";
            else if (wpart[wcount] == "Legs")
                cout << "Squat 12 reps\nLeg Press 12 reps\n";
            else if (wpart[wcount] == "Arms")
                cout << "Bicep Curl 12 reps\nTricep Pushdown 12 reps\n";
            else if (wpart[wcount] == "Shoulders")
                cout << "Shoulder Press 10 reps\nLateral Raise 12 reps\n";

            wcount++;
            cout << "Workout Added!\n";
        }

        else if (option == "2") {
            for (int i = 0; i < wcount; i++) {
                cout << "\nMember: " << wname[i];
                cout << "\nPart: " << wpart[i];
                cout << "\nSchedule: " << wschedule[i] << endl;
            }
        }

        else if (option == "3") {
            string id;
            cout << "Enter Member ID: ";
            getline(cin, id);

            int index = findmemberindex(id);

            if (index == -1) {
                cout << "Member not found!\n";
                continue;
            }

            usagememberID[usagecount] = id;

            cout << "Workout Done: ";
            getline(cin, usageworkout[usagecount]);

            cout << "Day: ";
            getline(cin, usageday[usagecount]);

            usagecount++;

            cout << "Usage Recorded!\n";
        }

        else if (option == "4") return;
    }
}

// PAYMENT MODULE
void paymentmenu() {
    string option;

    while (true) {
        cout << "\n===== PAYMENT MODULE =====\n";
        cout << "1. Record Payment\n";
        cout << "2. View Payment\n";
        cout << "3. Back\n";

        getline(cin, option);

        if (option == "1") {
            cout << "Enter Member ID: ";
            getline(cin, payid[paycount]);

            int index = findmemberindex(payid[paycount]);

            if (index == -1) {
                cout << "Member not found!\n";
                continue;
            }

            cout << "Enter Amount: ";
            cin >> payamount[paycount];
            cin.ignore();

            double fee = expectedfee(index);

            if (payamount[paycount] > fee)
                paystatus[paycount] = "Overpaid";
            else if (payamount[paycount] < fee)
                paystatus[paycount] = "Underpaid";
            else
                paystatus[paycount] = "Paid";

            paycount++;
            cout << "Payment Recorded!\n";
        }

        else if (option == "2") {
            for (int i = 0; i < paycount; i++) {
                cout << "\nID: " << payid[i];
                cout << "\nAmount: RM" << payamount[i];
                cout << "\nStatus: " << paystatus[i] << endl;
            }
        }

        else if (option == "3") return;
    }
}

// ADMIN REPORT
void reportmenu() {

    cout << "\n===== ADMIN REPORT =====\n";

    cout << "\nTotal Members: " << membercount;
    cout << "\nTotal Workouts: " << wcount;
    cout << "\nTotal Payments: " << paycount;

    double total = 0;
    for (int i = 0; i < paycount; i++) {
        total += payamount[i];
    }

    cout << "\nTotal Revenue: RM" << total << endl;

    cout << "\n--- GYM USAGE ---\n";
    for (int i = 0; i < usagecount; i++) {
        cout << usagememberID[i]
             << " | " << usageworkout[i]
             << " | " << usageday[i] << endl;
    }

    cout << "\n--- WORKOUT SUMMARY ---\n";
    for (int i = 0; i < membercount; i++) {
        cout << "\n" << membername[i] << ":\n";

        for (int j = 0; j < usagecount; j++) {
            if (usagememberID[j] == memberid[i]) {
                cout << "- " << usageworkout[j]
                     << " (" << usageday[j] << ")\n";
            }
        }
    }
}

// CUSTOMER REPORT
void customerreport() {

    string id;
    cout << "\n===== CUSTOMER REPORT =====\n";
    cout << "Enter Member ID: ";
    getline(cin, id);

    int index = findmemberindex(id);

    if (index == -1) {
        cout << "Member not found!\n";
        return;
    }

    cout << "\nName: " << membername[index];
    cout << "\nEmail: " << memberemail[index];
    cout << "\nMembership Months: " << membershipmonths[index];

    cout << "\n--- Payments ---\n";
    for (int i = 0; i < paycount; i++) {
        if (payid[i] == id) {
            cout << payamount[i] << " | " << paystatus[i] << endl;
        }
    }

    cout << "\n--- Gym Usage ---\n";
    for (int i = 0; i < usagecount; i++) {
        if (usagememberID[i] == id) {
            cout << usageworkout[i]
                 << " (" << usageday[i] << ")\n";
        }
    }
}