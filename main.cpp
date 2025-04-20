//main.cpp
#include <iostream>
#include<vector>
#include<algorithm>
#include"contact.hpp"

void addContact(std::vector<Contact>& contacts){
    Contact c;
    std::cout<<"Enter name:";
    std::getline(std::cin,c.name);
    std::cout<<"Enter phone:";
    std::getline(std::cin,c.phone);
    std::cout<<"Enter email:";
    std::getline(std::cin,c.email);
    contacts.push_back(c);
    std::cout<<"Contact added!\n";
}

void displayContacts(const std::vector<Contact>& contacts){
    std::cout<<"\n---- Contact List ----\n";
    for(const auto& c:contacts){
        std::cout<<"Name: "<<c.name<<"\nPhone: "<<c.phone<<"\nEmail: "<<c.email<<"\n";

    }
}

void searchContacts(const std::vector<Contact>& contacts){
    std::string keyword;
    std::cout<<"Enter name or phone to search: ";
    std::getline(std::cin,keyword);

    bool found=false;
    for(const auto& c:contacts){
        if(c.name.find(keyword)!=std::string::npos || c.phone.find(keyword)!=std::string::npos){
            std::cout<<"Found:"<<c.name<<", "<<c.phone<<", "<<c.email<<"\n";
            found=true;
        }
    }
    if(!found){
        std::cout<<"No matching contacts found.\n";
    }
}

void deleteContact(std::vector<Contact>& contacts,const std::string& name){
    /*Find the contact by name(complete match)*/
    auto it=std::find_if(contacts.begin(),contacts.end(),[&name](const Contact& c){
        return c.name==name;
    });

    /*If contact is found, prompt for confirmation and delete if confirmed*/
    if(it!=contacts.end()){
        std::cout<<"Are you sure you want to delete the contact: "<<it->name<<"? (y/n): ";
        char confirm;
        std::cin>>confirm;

        if(confirm=='y' || confirm =='Y'){
            contacts.erase(it);
            std::cout<<"Contact deleted successfully.\n";

        }else{
            std::cout<<"Deletion cancelled.\n";
        }
    }else{
        std::cout<<"Contact not found.\n";
    }

}

int main(){
    std::vector<Contact> contacts;
    int choice;

    while(true){
        std::cout<<"\n1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Delete Contact\n5. Exit\n";
        std::cout<<"Enter your choice: ";
        std::cin>>choice;
        std::cin.ignore(); // Clear the newline character from the input buffer

        switch(choice){
            case 1:{
                addContact(contacts);
                break;
            }
            case 2:{
                displayContacts(contacts);
                break;
            }
            case 3:{
                searchContacts(contacts);
                break;
            }
            case 4:{
                std::string name;
                std::cout<<"Enter the name of the contact to delete: ";
                std::getline(std::cin,name);
                deleteContact(contacts,name);
                break;
            }
            case 5:{
                std::cout<<"Exiting...\n";
                return 0;
            }
            default:
                std::cout<<"Invalid choice! Please try again.\n";
        }
    }
}