#include <iostream>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    Contact* next;
    Contact* prev;
};

class PhoneDirectory {
private:
    Contact* head;

public:
    PhoneDirectory() {
        head = nullptr;
    }

    // Function to add a contact to the directory
    void addContact(string name, string phoneNumber) {
        Contact* newContact = new Contact;
        newContact->name = name;
        newContact->phoneNumber = phoneNumber;
        newContact->next = nullptr;
        newContact->prev = nullptr;

        if (head == nullptr) {
            head = newContact;
        } else {
            Contact* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newContact;
            newContact->prev = current;
        }
    }

    // Function to display all contacts
    void displayContacts() {
        Contact* current = head;
        cout << "Contacts in the Phone Directory:" << endl;
        while (current != nullptr) {
            cout << "Name: " << current->name << ", Phone Number: " << current->phoneNumber << endl;
            current = current->next;
        }
    }

    // Function to search for a contact by name
    void searchContact(string name) {
        Contact* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                cout << "Contact Found - Name: " << current->name << ", Phone Number: " << current->phoneNumber << endl;
                return;
            }
            current = current->next;
        }
        cout << "Contact not found." << endl;
    }

    // Function to delete a contact by name
    void deleteContact(string name) {
        Contact* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Contact deleted." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Contact not found." << endl;
    }
};

int main() {
    PhoneDirectory directory;

    // Adding contacts with modified names
    directory.addContact("Rabin Mishra", "123-456-7890");
    directory.addContact("Sabin Mishra", "987-654-3210");
    directory.addContact("Dikshya Mishra", "555-123-4567");
    directory.addContact("Sadikshya Mishra", "777-888-9999");

    // Displaying the contacts
    directory.displayContacts();

    // Searching for a contact
    directory.searchContact("Sabin Mishra");
    directory.searchContact("Robert Johnson");  // A name not in the directory

    // Deleting a contact
    directory.deleteContact("Sabin Mishra");
    directory.displayContacts();  // Displaying the updated list

    return 0;
}
