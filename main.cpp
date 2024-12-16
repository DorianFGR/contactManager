#include <iostream>
#include <limits>
#include <vector>
#include <string>

struct contact {
    std::string nickname;
    std::string name;
    std::string phoneNumber;
    std::string email;
    std::string address;
};

void addContact(std::vector<contact>& contacts) {
    contact newContact;

    std::cout << "Enter Nickname: ";
    std::cin >> newContact.nickname;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Name: ";
    std::getline(std::cin, newContact.name);

    std::cout << "Enter Phone: ";
    std::getline(std::cin, newContact.phoneNumber);

    std::cout << "Enter Email: ";
    std::getline(std::cin, newContact.email);

    std::cout << "Enter Address: ";
    std::getline(std::cin, newContact.address);

    contacts.push_back(newContact);
    std::cout << "Contact Added" << std::endl;
}

void viewAllContacts(std::vector<contact>& contacts) {


    int lenght = contacts.size();

    for (int i = 0; i < lenght; i++) {

        std::cout<<"Contact number : ";
        std::cout<<i +1;

        std::cout<<"\n_____________________\n";
        std::cout<<"NickName : ";
        std::cout << contacts[i].nickname << std::endl;
        std::cout<<"Name : ";
        std::cout << contacts[i].name << std::endl;
        std::cout<<"phone Number : ";
        std::cout << contacts[i].phoneNumber << std::endl;
        std::cout<<"Email : ";
        std::cout << contacts[i].email << std::endl;
        std::cout<<"Address : ";
        std::cout << contacts[i].address << std::endl;
        std::cout<<"_____________________\n";

    }
}

void viewSpecificContacts(std::vector<contact>& contacts) {

    std::string contactNumber;

    std::cout<<"Contact number : ";
    std::cin >> contactNumber;

    try {

        int contactIndex = std::stoi(contactNumber);


        if (contactIndex < 0 || contactIndex >= contacts.size()) {
            std::cout << "Invalid contact index!" << std::endl;
            return;
        }

        contactIndex -= 1;
        const contact& contact = contacts[contactIndex];


        std::cout << "\n_____________________\n";
        std::cout << "NickName: " << contact.nickname << std::endl;
        std::cout << "Name: " << contact.name << std::endl;
        std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
        std::cout << "Email: " << contact.email << std::endl;
        std::cout << "Address: " << contact.address << std::endl;
        std::cout << "_____________________\n";

    } catch (const std::invalid_argument& e) {

        std::cout << "Invalid contact number!" << std::endl;

    } catch (const std::out_of_range& e) {

        std::cout << "Contact number is out of range!" << std::endl;

    }

}

void deleteContact(std::vector<contact>& contacts) {

    std::string contactNumber;

    std::cout<<"Contact number : ";
    std::cin >> contactNumber;

    try {

        int contactIndex = std::stoi(contactNumber);

        contactIndex -= 1;

        if (contactIndex < 0 || contactIndex >= contacts.size()) {
            std::cout << "Invalid contact index!" << std::endl;
            return;
        }


        const contact& contactToDelete = contacts[contactIndex];


        std::cout << "Are you sure you want to delete contact: " << contactToDelete.name
                  << " (Phone: " << contactToDelete.phoneNumber << ")? (y/n): ";
        char confirmation;
        std::cin >> confirmation;


        if (confirmation == 'y' || confirmation == 'Y') {
            contacts.erase(contacts.begin() + contactIndex);
            std::cout << "Contact deleted successfully." << std::endl;
        } else {
            std::cout << "Contact deletion canceled." << std::endl;
        }


    } catch (const std::invalid_argument& e) {

        std::cout << "Invalid contact number!" << std::endl;

    } catch (const std::out_of_range& e) {

        std::cout << "Contact number is out of range!" << std::endl;

    }

}


int main() {

    std::vector<contact> contacts;
    int choice;

    do{

        std::cout<<"\nContact Manager\n";
        std::cout<<"_____________________\n";
        std::cout<<"1. Add a new contact\n";
        std::cout<<"2. View all contacts\n";
        std::cout<<"3. View a specific contact\n";
        std::cout<<"4. Delete a contact\n";
        std::cout<<"5. Exit\n";


        std::cout<<"_____________________\n";
        std::cout<<"\nEnter your choice: ";
        std::cin >> choice;


        switch(choice) {

            case 1:

                addContact(contacts);
                break;

            case 2:

                viewAllContacts(contacts);
                break;

            case 3:

                viewSpecificContacts(contacts);
                break;

            case 4:

                deleteContact(contacts);
                break;


            case 5:

                std::cout<<"\n Exiting...";
                break;

            default:

                std::cout<<"\n Invalid Choice\n Please try again";

        }

    }while(choice !=5);

    return 0;
}




