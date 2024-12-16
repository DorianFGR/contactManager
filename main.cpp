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

void viewAllContacts(std::vector<contact>& contacts) {


    int lenght = contacts.size();
    std::cout << lenght << std::endl;

    for (int i = 0; i < lenght; i++) {

        std::cout<<"Contact number : " + i ;

        std::cout<<"\n_____________________\n";
        std::cout<<"NickName : \n";
        std::cout << contacts[i].nickname << std::endl;
        std::cout<<"Name : \n";
        std::cout << contacts[i].name << std::endl;
        std::cout<<"phone Number : \n";
        std::cout << contacts[i].phoneNumber << std::endl;
        std::cout<<"Email : \n";
        std::cout << contacts[i].email << std::endl;
        std::cout<<"Address : \n";
        std::cout << contacts[i].address << std::endl;
        std::cout<<"_____________________\n";

    }
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

            case 5:

                std::cout<<"\n Exiting...";
                break;

            default:

                std::cout<<"\n Invalid Choice\n Please try again";

        }

    }while(choice !=5);

    return 0;
}




