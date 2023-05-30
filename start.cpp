#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

void all()
{
    fstream myfile;
    vector<string> row;
    string word, line, id, name, group;
    myfile.open("key.csv", ios::in);

    while (getline(myfile, line))
    {
        row.clear();
        // used for breaking words
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        id = row[0];
        name = row[1];
        group = row[2];

        cout << "NIS : " << id << "\nName : " << name << "\nClass : " << group << "\n\n";
    }
}

void search(string input)
{
    fstream myfile;
    vector<string> row;
    string word, line, id, name, group;
    myfile.open("key.csv", ios::in);

    while (getline(myfile, line))
    {
        row.clear();
        // used for breaking words
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        id = row[0];
        name = row[1];
        group = row[2];

        transform(input.begin(), input.end(), input.begin(), ::toupper);

        if (id == input || name.find(input) != string::npos || group == input)
        {
            cout << "\nNIS : " << id << "\nName : " << name << "\nClass : " << group << "\n";
        }
    }
}

int main()
{
    string input, choice;
    cout << "1. View all\n2. Search data\n";
    cout << "Enter your choice : ";
    cin >> choice;
    if (choice == "1") {
        all();
    } else if (choice == "2") {
        cout << "Enter the keywords : ";
        cin >> input;
        search(input);
    }
}