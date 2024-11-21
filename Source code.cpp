#include <iostream>
#include <string>
#include <vector>
using namespace std;

class University {
public:
    int ID;
    string AP23110011052_univ_code;
    string AP23110011052_univ_name;
    string AP23110011052_univ_address;
    string AP23110011052_univ_mail;
    string AP23110011052_univ_website;

    University(int ID, const string &AP23110011052_univ_code, const string &AP23110011052_univ_name,
               const string &AP23110011052_univ_address, const string &AP23110011052_univ_mail, const string &AP23110011052_univ_website)
        : ID(ID), AP23110011052_univ_code(AP23110011052_univ_code), AP23110011052_univ_name(AP23110011052_univ_name),
          AP23110011052_univ_address(AP23110011052_univ_address), AP23110011052_univ_mail(AP23110011052_univ_mail),
          AP23110011052_univ_website(AP23110011052_univ_website) {}

    int getID() const { return ID; }
    void setID(int ID) { this->ID = ID; }
    string getUnivCode() const { return AP23110011052_univ_code; }
    void setUnivCode(const string &AP23110011052_univ_code) { this->AP23110011052_univ_code = AP23110011052_univ_code; }
    string getUnivName() const { return AP23110011052_univ_name; }
    void setUnivName(const string &AP23110011052_univ_name) { this->AP23110011052_univ_name = AP23110011052_univ_name; }
    string getUnivAddress() const { return AP23110011052_univ_address; }
    void setUnivAddress(const string &AP23110011052_univ_address) { this->AP23110011052_univ_address = AP23110011052_univ_address; }
    string getUnivMail() const { return AP23110011052_univ_mail; }
    void setUnivMail(const string &AP23110011052_univ_mail) { this->AP23110011052_univ_mail = AP23110011052_univ_mail; }
    string getUnivWebsite() const { return AP23110011052_univ_website; }
    void setUnivWebsite(const string &AP23110011052_univ_website) { this->AP23110011052_univ_website = AP23110011052_univ_website; }

    void displayInfo() const {
        cout << "University ID: " << ID << endl;
        cout << "University Code: " << AP23110011052_univ_code << endl;
        cout << "University Name: " << AP23110011052_univ_name << endl;
        cout << "University Address: " << AP23110011052_univ_address << endl;
        cout << "University Email: " << AP23110011052_univ_mail << endl;
        cout << "University Website: " << AP23110011052_univ_website << endl;
    }
};

vector<pair<University, string>> sort_by_code;
vector<pair<University, string>> sort_by_name;
vector<pair<University, string>> sort_by_address;
vector<pair<University, string>> sort_by_email;
vector<pair<University, string>> sort_by_web;

// Merge Sort Implementation
void merge(vector<pair<University, string>> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<pair<University, string>> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<pair<University, string>> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].second <= R[j].second)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<pair<University, string>> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Linear Search Implementation
int AP23110011052_university_linearSearch(const vector<pair<University, string>> &arr, const string &key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].second == key) return i;
    }
    return -1;
}

void updateSortedVectors(const vector<University> &universities) {
    sort_by_code.clear();
    sort_by_name.clear();
    sort_by_address.clear();
    sort_by_email.clear();
    sort_by_web.clear();

    for (const auto &univ : universities) {
        sort_by_code.push_back({univ, univ.getUnivCode()});
        sort_by_name.push_back({univ, univ.getUnivName()});
        sort_by_address.push_back({univ, univ.getUnivAddress()});
        sort_by_email.push_back({univ, univ.getUnivMail()});
        sort_by_web.push_back({univ, univ.getUnivWebsite()});
    }

    mergeSort(sort_by_code, 0, sort_by_code.size() - 1);
    mergeSort(sort_by_name, 0, sort_by_name.size() - 1);
    mergeSort(sort_by_address, 0, sort_by_address.size() - 1);
    mergeSort(sort_by_email, 0, sort_by_email.size() - 1);
    mergeSort(sort_by_web, 0, sort_by_web.size() - 1);
}

// CRUD Operations and Menu
void AP23110011052_University_create(vector<University> &universities) {
    int ID;
    string AP23110011052_univ_code, AP23110011052_univ_name, AP23110011052_univ_address, AP23110011052_univ_mail, AP23110011052_univ_website;
    cout << "Enter University ID: ";
    cin >> ID;
    cout << "Enter University Code: ";
    cin >> AP23110011052_univ_code;
    cout << "Enter University Name: ";
    cin.ignore();
    getline(cin, AP23110011052_univ_name);
    cout << "Enter University Address: ";
    getline(cin, AP23110011052_univ_address);
    cout << "Enter University Email: ";
    getline(cin, AP23110011052_univ_mail);
    cout << "Enter University Website: ";
    getline(cin, AP23110011052_univ_website);

    universities.emplace_back(ID, AP23110011052_univ_code, AP23110011052_univ_name, AP23110011052_univ_address, AP23110011052_univ_mail, AP23110011052_univ_website);
    updateSortedVectors(universities);
    cout << "University added successfully!" << endl;
}

void AP23110011052_University_update(vector<University> &universities, int ID) {
    for (auto &univ : universities) {
        if (univ.getID() == ID) {
            string AP23110011052_univ_code, AP23110011052_univ_name, AP23110011052_univ_address, AP23110011052_univ_mail, AP23110011052_univ_website;
            cout << "Enter new University Code: ";
            cin >> AP23110011052_univ_code;
            cout << "Enter new University Name: ";
            cin.ignore();
            getline(cin, AP23110011052_univ_name);
            cout << "Enter new University Address: ";
            getline(cin, AP23110011052_univ_address);
            cout << "Enter new University Email: ";
            getline(cin, AP23110011052_univ_mail);
            cout << "Enter new University Website: ";
            getline(cin, AP23110011052_univ_website);

            univ.setUnivCode(AP23110011052_univ_code);
            univ.setUnivName(AP23110011052_univ_name);
            univ.setUnivAddress(AP23110011052_univ_address);
            univ.setUnivMail(AP23110011052_univ_mail);
            univ.setUnivWebsite(AP23110011052_univ_website);

            updateSortedVectors(universities);
            cout << "University updated successfully!" << endl;
            return;
        }
    }
    cout << "University with ID " << ID << " not found." << endl;
}

void AP23110011052_University_delete(vector<University> &universities, int ID) {
    for (auto it = universities.begin(); it != universities.end(); ++it) {
        if (it->getID() == ID) {
            universities.erase(it);
            updateSortedVectors(universities);
            cout << "University deleted successfully!" << endl;
            return;
        }
    }
    cout << "University with ID " << ID << " not found." << endl;
}

void AP23110011052_University_read(const vector<University> &universities, int ID) {
    for (const auto &univ : universities) {
        if (univ.getID() == ID) {
            univ.displayInfo();
            return;
        }
    }
    cout << "University with ID " << ID << " not found." << endl;
}

int main() {
    vector<University> universities;
    int choice, ID;

    do {
        cout << "\nUniversity Management System\n";
        cout << "1. Add University\n";
        cout << "2. Update University\n";
        cout << "3. Delete University\n";
        cout << "4. View University\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            AP23110011052_University_create(universities);
            break;
        case 2:
            cout << "Enter University ID to update: ";
            cin >> ID;
            AP23110011052_University_update(universities, ID);
            break;
        case 3:
            cout << "Enter University ID to delete: ";
            cin >> ID;
            AP23110011052_University_delete(universities, ID);
            break;
        case 4:
            cout << "Enter University ID to view: ";
            cin >> ID;
            AP23110011052_University_read(universities, ID);
            break;
        case 5:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
