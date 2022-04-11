#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void srch();
void deletefunction(string searchvalue);
int check(string searchvalue);
void addcontact();
void display_contact();
void update(string searchvalue);
int main() {
    system("color 5E");
    int option;
    string deletename;
    do {
        cout << "-------MENU-------" << endl;
        cout << "1- Add a New Contact" << endl;
        cout << "2- Show all Saved Contacts" << endl;
        cout << "3- Search for a Contact" << endl;
        cout << "4- Delete a Specific Contact" << endl;
        cout << "5- Update Existing Contact" << endl;
        cout << "6- Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> option;
        if (option>6 || option<0 || cin.fail()){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Invalid Option"<<endl;
            continue;
        }
        switch (option) {
            case 1:
                addcontact();
                break;
            case 2:
                display_contact();
                break;
            case 3:
                srch();
                break;
            case 4:
                cout<<"Enter the value you want to delete: "<<endl;
                cin>>deletename;
                deletefunction(deletename);
                break;
            case 5:
                cout<<"Enter the value you want to update: "<<endl;
                cin>>deletename;
                update(deletename);
                break;
        }
    } while (option!=6);
}
void srch(){
    ifstream try_file("E:\\c++\\phonebook\\phonebook.txt");
    int flag=0;
    string firstname, lastname, gender, number, email;
    char choice,gendervalue;
    string search;
    if (try_file.is_open()){
        cout << " Search Menu " << endl;
        cout << "==================" << endl;
        cout << " Select a method to search with : \n N-Name \n P-Phonenumber \n G-Gender \n E-Email \n";
        cin >> choice;
        cout << "===================" << endl;
        cout << " Enter what you search for : ";
        if(choice=='g'||choice=='G'){
            cin>>gendervalue;
        }
        else{
            cin>>search;
        }
        cout << endl;
        cout << "==================" << endl;
        if (choice!='g' || choice!='G' || choice!='E'|| choice!='e'|| cin.fail()){
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Invalid Option"<<endl;
            continue;
        }

        while (try_file >> firstname >> lastname >> number >> gender >> email) {

            switch (choice) {
                case 'N':
                case 'n':

                    while ((firstname.find(search) != std::string::npos) ||
                           (lastname.find(search) != std::string::npos)) {

                        cout << "First name : " << firstname << endl;
                        cout << "Last name : " << lastname << endl;
                        cout << "Phone number : " << number << endl;
                        cout << "Gender : " << gender << endl;
                        cout << "Email : " << email << endl;
                        cout << " _____" << endl;
                        flag=1;
                        break;
                    }
                    break;
                case 'P':
                case 'p':

                    while (number.find(search) != std::string::npos) {

                        cout << "First name : " << firstname << endl;
                        cout << "Last name : " << lastname << endl;
                        cout << "Phone number : " << number << endl;
                        cout << "Gender : " << gender << endl;
                        cout << "Email : " << email << endl;
                        cout << " _____" << endl;
                        flag=1;
                        break;
                    }
                    break;
                case 'g':
                case 'G':
                    while (gender.find(gendervalue) != std::string::npos || gender.find(gendervalue-32) != std::string::npos || gender.find(gendervalue+32) != std::string::npos) {
                        cout << "First name : " << firstname << endl;
                        cout << "Last name : " << lastname << endl;
                        cout << "Phone number : " << number << endl;
                        cout << "Gender : " << gender << endl;
                        cout << "Email : " << email << endl;
                        cout << " _____" << endl;
                        flag=1;
                        break;
                    }
                    break;
                case 'E':
                case 'e':
                    while (email.find(search)!= std::string::npos){
                        cout << "First name : " << firstname << endl;
                        cout << "Last name : " << lastname << endl;
                        cout << "Phone number : " << number << endl;
                        cout << "Gender : " << gender << endl;
                        cout << "Email : " << email << endl;
                        cout << " _____" << endl;
                        flag=1;
                        break;
                    }
            }
        }
    }
    if (flag==0){
        cout<<"The record you searched for is not found"<<endl;
    }
    try_file.close();
}
void deletefunction(string searchvalue){
    string Firstname,Lastname,Phonenumber,Gender,Email,Choice;
    string Deletenumber;
    int flag=0;
    ifstream our;
    ofstream temp;
    our.open("E:\\c++\\phonebook\\phonebook.txt");
    temp.open("E:\\c++\\phonebook\\temp.txt");
    while (our >> Firstname >> Lastname >> Phonenumber >> Gender >> Email) {
        if (Firstname.find(searchvalue) != std::string::npos || (Lastname.find(searchvalue) != std::string::npos) ||
            (Gender.find(searchvalue) != std::string::npos) || (Phonenumber.find(searchvalue) != std::string::npos) ||
            (Email.find(searchvalue) != std::string::npos)) {
            cout << "Would you like to delete this contact? (Y/N)" << endl;
            cout << "First name : " << Firstname << endl;
            cout << "Last name : " << Lastname << endl;
            cout << "Phone number : " << Phonenumber << endl;
            cout << "Gender : " << Gender << endl;
            cout << "Email : " << Email << endl;
            cout << " _____" << endl;
            cin >> Choice;
            if (Choice == "y" || Choice == "Y"){
                Deletenumber=Phonenumber;
                flag=1;
                break;
            }
        }
    }
    if (flag==0){
        cout<<"There is no more contacts"<<endl;
    }
    else{
        our.clear();
        our.seekg(0);
        while (our >> Firstname >> Lastname >> Phonenumber >> Gender >> Email){
            if(Deletenumber != Phonenumber){
                temp << Firstname << " " << Lastname << " " << Phonenumber << " " << Gender << " " << Email << endl;
            }
        }
        our.close();
        temp.close();
        remove("E:\\c++\\phonebook\\phonebook.txt");
        rename ("E:\\c++\\phonebook\\temp.txt","E:\\c++\\phonebook\\phonebook.txt");
    }
}
int check(string searchvalue){
    string name,gender,email,phonenumber,lastname;
    int found=0;
    ifstream infile("E:\\c++\\phonebook\\phonebook.txt");
    while((infile>>name>>lastname>>phonenumber>>gender>>email) && found==0){
        if (phonenumber==searchvalue){
            cout<<"This Contact is Already Saved:"<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Phone number: "<<phonenumber<<endl;
            cout<<"Gender: "<<gender<<endl;
            cout<<"Email: "<<email<<endl;
            found=1;
            break;
        }
    }
    infile.close();
    cout<<found;
    return found;
}
void addcontact() {
    string Firstname,Lastname,Phonenumber,Email,Firstname2,Lastname2,Phonenumber2,Email2;
    char Gender,choice,Gender2;
    ofstream phonebook;
    cout<<"Enter First Name: ";
    cin >> Firstname ;
    cout <<"Enter Last Name: ";
    cin>>Lastname;
    cout<<"Enter number: ";
    cin >> Phonenumber;
    cout<<"Enter gender (F/M): ";
    cin >> Gender;
    cout<<"Enter E-mail: ";
    cin >> Email;
    if (check(Phonenumber) == 1){
        cout<<"would u like to replace it?";
        cin>>choice;
        if(choice=='y'){
            ifstream myfile;
            ofstream temp;
            myfile.open("E:\\c++\\phonebook\\phonebook.txt");
            temp.open("E:\\c++\\phonebook\\temp.txt");
            while(myfile >> Firstname2 >> Lastname2 >> Phonenumber2 >> Gender2 >> Email2){
                if(Phonenumber2 != Phonenumber){
                    temp << Firstname2 << " " << Lastname2 << " " << Phonenumber2 << " " << Gender2 << " " << Email2 << endl;
                }
                else {
                    temp << Firstname << " " << Lastname << " " << Phonenumber << " " << Gender << " " << Email << endl;
                }
            }
            myfile.close();
            temp.close();
            remove("E:\\c++\\phonebook\\phonebook.txt");
            rename("E:\\c++\\phonebook\\temp.txt","E:\\c++\\phonebook\\phonebook.txt");
        }
    }
    else {
        phonebook.open("E:\\c++\\phonebook\\phonebook.txt", ios::app);
        phonebook << Firstname << " " << Lastname << " " << Phonenumber << " " << Gender << " " << Email << endl;
        phonebook.close();
    }
}
void display_contact() {
    string firstname, lastname, gender, number, email;
    int flag=0;
    ifstream infile("E:\\c++\\phonebook\\phonebook.txt");
    while (infile >> firstname >> lastname >> number >> gender >> email) {
        cout << "First name : " << firstname << endl;
        cout << "Last name : " << lastname << endl;
        cout << "Phone number : " << number << endl;
        cout << "Gender : " << gender << endl;
        cout << "Email : " << email << endl;
        cout << " _____" << endl;
        flag=1;
    }
    if (flag==0){
        cout<<"There is no contacts yet"<<endl;
    }
}
void update(string searchvalue){
    string Firstname,Lastname,Phonenumber,Email;
    string updatefname,updatelname,updatephonenumber,updateemail;
    char Gender,updategender,Choice,choice2;
    string updatenumber;
    ifstream our;
    ofstream temp;
    int flag=0;
    our.open("E:\\c++\\phonebook\\phonebook.txt");
    temp.open("E:\\c++\\phonebook\\temp.txt");
    while (our >> Firstname >> Lastname >> Phonenumber >> Gender >> Email) {
        if (Firstname.find(searchvalue) != std::string::npos || (Lastname.find(searchvalue) != std::string::npos) ||(Phonenumber.find(searchvalue) != std::string::npos) ||
            (Email.find(searchvalue) != std::string::npos)) {
            cout << "Would you like to update this contact? (Y/N)" << endl;
            cout << "First name : " << Firstname << endl;
            cout << "Last name : " << Lastname << endl;
            cout << "Phone number : " << Phonenumber << endl;
            cout << "Gender : " << Gender << endl;
            cout << "Email : " << Email << endl;
            cout << " _____" << endl;
            cin >> Choice;
            if (Choice == 'y' || Choice == 'Y'){
                updatenumber=Phonenumber;
                flag=1;
                break;
            }
        }
    }if (flag==0){
        cout<<"There is no more contacts to update"<<endl;
    }
    else {
        cout << "Enter New Firstname" << endl;
        cin >> updatefname;
        cout << "Enter New Lastname" << endl;
        cin >> updatelname;
        cout << "Would you like to update the Phone number?";
        cin >> choice2;
        if (choice2 == 'y' || choice2 == 'Y') {
            cout << "Enter the New Phone number" << endl;
            cin >> updatephonenumber;
            while(check(updatephonenumber)==1){
                cout<<"This number is already saved\n";
                cout << "Enter the New Phone number" << endl;
                cin >> updatephonenumber;
            }
        } else {
            updatephonenumber = updatenumber;
        }
        cout << "Enter Gender" << endl;
        cin >> updategender;
        cout << "Enter New Email" << endl;
        cin >> updateemail;
        our.clear();
        our.seekg(0);
        while (our >> Firstname >> Lastname >> Phonenumber >> Gender >> Email) {
            if (updatenumber != Phonenumber) {
                temp << Firstname << " " << Lastname << " " << Phonenumber << " " << Gender << " " << Email << endl;
            } else {
                temp << updatefname << " " << updatelname << " " << updatephonenumber << " " << updategender << " "
                     << updateemail;
            }

        }
        our.close();
        temp.close();
        remove("E:\\c++\\phonebook\\phonebook.txt");
        rename("E:\\c++\\phonebook\\temp.txt", "E:\\c++\\phonebook\\phonebook.txt");
    }
}