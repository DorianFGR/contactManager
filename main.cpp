#include <iostream>
#include <vector>
#include <string>

struct contact {
    std::string nickname;
    std::string name;
    std::string phoneNumber;
    std::string email;
    std::string address;
};

void addContact(std::vector<contact>& contacts){

    contact newContact;
    std::cout << "Enter Nickname: ";
    std::cin >> newContact.nickname;

    std::cout << "Enter Name: ";
    std::cin >> newContact.name;

    std::cout << "Enter Phone: ";
    std::cin >> newContact.phoneNumber;

    std::cout << "Enter Email: ";
    std::cin >> newContact.email;

    std::cout << "Enter Address: ";
    std::cin >> newContact.address;

    contacts.push_back(newContact);


}


int main() {

    std::vector<contact> contacts;
    int choice;

    do{

        std::cout<<"Contact Manager\n";
        std::cout<<"_____________________\n";
        std::cout<<"1. Add a new contact\n";
        std::cout<<"2. View all contacts\n";
        std::cout<<"3. View all contacts\n";
        std::cout<<"4. View all contacts\n";
        std::cout<<"5. Exit\n";

        std::cin >> choice;


        switch(choice) {

            case 1:

                addContact(contacts);
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




