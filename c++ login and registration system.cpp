#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    // Check if user already exists
    ifstream infile("users.txt");
    string line, fileUser;
    bool exists = false;
    while (getline(infile, line)) {
        fileUser = line.substr(0, line.find(" "));
        if (fileUser == username) {
            exists = true;
            break;
        }
    }
    infile.close();

    if (exists) {
        cout << "Username already exists. Try a different one.\n";
        return;
    }

    // Append new user to file
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();
    cout << "Registration successful!\n";
}

// Function to login
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    string fileUser, filePass;
    bool loginSuccess = false;
    while (infile >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            loginSuccess = true;
            break;
        }
    }
    infile.close();

    if (loginSuccess)
        cout << "Login successful! Welcome, " << username << "!\n";
    else
        cout << "Invalid username or password.\n";
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        registerUser();
    else if (choice == 2)
        loginUser();
    else
        cout << "Invalid choice.\n";

    return 0;
}
