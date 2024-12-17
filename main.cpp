#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <filesystem>
#include "include/json.hpp"

using json = nlohmann::json;

struct contact {
    std::string nickname;
    std::string name;
    std::string phoneNumber;
    std::string email;
    std::string address;
};

void to_json(nlohmann::json &j, const contact &c) {

    j = nlohmann::json{{"nickname", c.nickname}, {"name", c.name}, {"phoneNumber", c.phoneNumber}, {"email", c.email}, {"address", c.address}};

}

void from_json(const nlohmann::json &j, contact &c) {

    j.at("nickname").get_to(c.nickname);
    j.at("name").get_to(c.name);
    j.at("phoneNumber").get_to(c.phoneNumber);
    j.at("email").get_to(c.email);
    j.at("address").get_to(c.address);

}


bool save_contacts_to_file(const std::vector<contact>& contacts, const std::string &filename) {

    std::ofstream file(filename);

    if (!file.is_open()) {

        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;

    }

    json j = contacts;
    file << j.dump(4);
    file.close();
    return true;

}

bool load_contacts_from_file(std::vector<contact>& contacts, const std::string &filename) {

    std::ifstream file(filename);

    if (!file.is_open()) {

        std::cerr << "Error: Could not open file " << filename << std::endl;
        std::cerr << "Current path is " << std::filesystem::current_path() << std::endl;
        return false;

    }


    if (file.peek() == std::ifstream::traits_type::eof()) {

        return true;

    }

    json j;

    try {

        file >> j;
        contacts = j.get<std::vector<contact>>();

    } catch (json::exception &e) {

        std::cerr << "Error during JSON conversion: " << e.what() << std::endl;
        return false;

    }

    return true;
}


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

void viewAllContacts(const std::vector<contact>& contacts) {

    for (size_t i = 0; i < contacts.size(); ++i) {

        std::cout << "Contact number: " << i + 1 << "\n";
        std::cout << "_____________________\n";
        std::cout << "Nickname: " << contacts[i].nickname << "\n";
        std::cout << "Name: " << contacts[i].name << "\n";
        std::cout << "Phone Number: " << contacts[i].phoneNumber << "\n";
        std::cout << "Email: " << contacts[i].email << "\n";
        std::cout << "Address: " << contacts[i].address << "\n";
        std::cout << "_____________________\n";

    }
}

void viewSpecificContacts(const std::vector<contact>& contacts) {

    std::string contactNumber;

    std::cout << "Contact number: ";
    std::cin >> contactNumber;

    try {

        int contactIndex = std::stoi(contactNumber) - 1;

        if (contactIndex < 0 || contactIndex >= contacts.size()) {

            std::cout << "Invalid contact index!" << std::endl;
            return;

        }

        const contact& contact = contacts[contactIndex];

        std::cout << "\n_____________________\n";
        std::cout << "Nickname: " << contact.nickname << std::endl;
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

    std::cout << "Contact number: ";
    std::cin >> contactNumber;

    try {

        int contactIndex = std::stoi(contactNumber) - 1;

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


    std::string filename = std::filesystem::current_path().string() + "/saves/contacts.json";

    if (load_contacts_from_file(contacts, filename)) {

        std::cout << "Contacts loaded from file." << std::endl;

    } else {

        std::cerr << "Failed to read from file!" << std::endl;

    }

    do {

        std::cout << "\nContact Manager\n";
        std::cout << "_____________________\n";
        std::cout << "1. Add a new contact\n";
        std::cout << "2. View all contacts\n";
        std::cout << "3. View a specific contact\n";
        std::cout << "4. Delete a contact\n";
        std::cout << "5. Exit\n";
        std::cout << "_____________________\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {

            case 1:
                addContact(contacts);

                if (save_contacts_to_file(contacts, filename)) {

                    std::cout << "Contacts saved successfully!" << std::endl;

                }
                break;

            case 2:
                viewAllContacts(contacts);
                break;

            case 3:
                viewSpecificContacts(contacts);
                break;

            case 4:
                deleteContact(contacts);

                if (save_contacts_to_file(contacts, filename)) {

                    std::cout << "Contacts saved successfully!" << std::endl;

                }
                break;

            case 5:
                std::cout << "\nExiting...";
                break;

            default:
                std::cout << "\nInvalid choice. Please try again.";

        }

    } while (choice != 5);

    return 0;
}
