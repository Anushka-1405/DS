#include<iostream>
using namespace std;

int key[10], n;

class hash_m {
public:
    int prn;
    string name;
    string address;

    void create();
    void accept();
    void display();
    void search();
    void modify();
    void deleteRecord();
} h[100];

void hash_m::create() {
    cout << "\nEnter number of keys: ";
    cin >> n;

    cout << "\nEnter key (PRN) values:\n";
    for (int i = 0; i < n; i++) {
        cin >> key[i];
    }

    for (int i = 0; i < 10; i++) {
        h[i].prn = -1;
    }
}

void hash_m::accept() {
    int loc;
    for (int i = 0; i < n; i++) {
        loc = key[i] % 10;
        do {
            if (h[loc].prn == -1) {
                h[loc].prn = key[i];
                cout << "\nEnter name of Student: ";
                cin.ignore(); // flush newline
                getline(cin, h[loc].name);

                cout << "Enter address of Student: ";
                getline(cin, h[loc].address);
                break;
            } else {
                loc = (loc + 1) % 10; 
            }
        } while (true);
    }
}

void hash_m::display() {
    cout << "\nLoc\tPRN\tName\t\tAddress\n";
    for (int i = 0; i < 10; i++) {
        cout << i << "\t";
        if (h[i].prn == -1) {
            cout << "-1\t-1\t\t-1\n";
        } else {
            cout << h[i].prn << "\t" << h[i].name << "\t\t" << h[i].address << "\n";
        }
    }
}

void hash_m::search() {
    int s_key, loc;
    bool found = false;
    cout << "\nEnter key (PRN) to search: ";
    cin >> s_key;

    loc = s_key % 10;

    for (int i = 0; i < 10; i++) {
        int index = (loc + i) % 10;
        if (h[index].prn == s_key) {
            cout << "\nKey found at location " << index << ":\n";
            cout << "Name = " << h[index].name << "\n";
            cout << "Address = " << h[index].address << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Key not found.\n";
    }
}

void hash_m::modify() {
    int m_key, loc;
    bool found = false;
    cout << "\nEnter PRN to modify: ";
    cin >> m_key;

    loc = m_key % 10;

    for (int i = 0; i < 10; i++) {
        int index = (loc + i) % 10;
        if (h[index].prn == m_key) {
            cout << "Current name: " << h[index].name << "\n";
            cout << "Current address: " << h[index].address << "\n";

            cout << "Enter new name: ";
            cin >> h[index].name;

            cout << "Enter new address: ";
            cin >> h[index].address;

            cout << "Record updated.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "PRN not found.\n";
    }
}


void hash_m::deleteRecord() {
    int d_key, loc;
    bool found = false;
    cout << "\nEnter PRN to delete: ";
    cin >> d_key;

    loc = d_key % 10;

    for (int i = 0; i < 10; i++) {
        int index = (loc + i) % 10;
        if (h[index].prn == d_key) {
            h[index].prn = -1;
            h[index].name = "-1";
            h[index].address = "-1";
            cout << "Record deleted.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "PRN not found.\n";
    }
}

int main() {
    int ch;
    do {
        cout << "\n\n--- Hash Table Menu ---\n";
        cout << "1. Create\n2. Accept\n3. Display\n4. Search\n5. Modify\n6. Delete\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                h[0].create();
                break;
            case 2:
                h[0].accept();
                break;
            case 3:
                h[0].display();
                break;
            case 4:
                h[0].search();
                break;
            case 5:
                h[0].modify();
                break;
            case 6:
                h[0].deleteRecord();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (ch != 0);

    return 0;
}
