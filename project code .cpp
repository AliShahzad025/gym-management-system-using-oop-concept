#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#define RESET   "\033[0m"
#define RED     "\033[91m"    // Light Red
#define GREEN   "\033[92m"    // Light Green
#define YELLOW  "\033[93m"    // Light Yellow
#define BLUE    "\033[94m"    // Light Blue
#define MAGENTA "\033[95m"    // Light Magenta
#define CYAN    "\033[96m"    // Light Cyan


using namespace std;
class Attendance {
private:
    string membertype;
    int memberId;
    string date;
    bool present;
public:
    Attendance()
    {}

    void markattendance(int memberId, const string& date, string membertype, bool present) {
        ofstream att("attendence1.txt", ios::app); // Open file in append mode
        if (att.is_open()) {
            att << memberId << " " << date << " " << (present ? "Present" : "Absent") << endl;
            att.close();
            cout << "Attendance marked successfully for Member ID: " << memberId << endl;
        }
        else {
            cout << "Unable to open file for writing attendance." << endl;
        }
    }
    void displayAttendance() {
        ifstream attFile("attendence1.txt");
        if (attFile.is_open()) {
            string line;
            while (getline(attFile, line)) {
                cout << line << endl;
            }
            attFile.close();
        }
        else {
            cout << "Unable to open the attendance file." << endl;
        }
    }
    void markstaffattendance(string name, const string& date, bool present) {
        ofstream att("attendence2.txt", ios::app); // Open file in append mode
        if (att.is_open()) {
            att << name << " " << date << " " << (present ? "Present" : "Absent") << endl;
            att.close();
            cout << "Attendance marked successfully for : " << name << endl;
        }
        else {
            cout << "Unable to open file for writing attendance." << endl;
        }
    }
    void displaystaffAttendance() {
        ifstream attFile("attendence2.txt");
        if (attFile.is_open()) {
            string line;
            while (getline(attFile, line)) {
                cout << line << endl;
            }
            attFile.close();
        }
        else {
            cout << "Unable to open the attendance file." << endl;
        }
    }
};
class gymtiming {
    string maletimings;
    string femaletimings;
    string coedtimings;
public:
    gymtiming() {
        maletimings = "6:00 AM - 10:00 PM";
        femaletimings = "8:00 AM - 12:00 PM";
        coedtimings = "10:00 AM - 8:00 PM";
        saveTimings();

    }

    void setTimings() {
        cin.ignore();
        cout << "Enter Male timings: ";

        getline(cin, maletimings);


        cout << "Enter Female timings: ";
        getline(cin, femaletimings);

        cout << "Enter Co-ed timings: ";
        getline(cin, coedtimings);

        cout << "Timings updated successfully" << endl;
        saveTimings();
    }

    void displayTimings() const {
        cout << "Gym Timings:\n";
        cout << "Male Only: " << maletimings << endl;
        cout << "Female Only: " << femaletimings << endl;
        cout << "Co-ed: " << coedtimings << endl;
    }

    void saveTimings() const {
        ofstream outfile("timings.txt");
        if (outfile.is_open()) {
            outfile << maletimings << endl;
            outfile << femaletimings << endl;
            outfile << coedtimings << endl;
            outfile.close();
        }
        else {
            cout << "Error: Unable to save timings to file." << endl;
        }
    }
};

class Feestructure {
private:
    int Trainerfees;
    int yogafees;
    int mmafees;
    int zumbafees;
    int aerobicsfees;
    int swimmingfees;
public:
    Feestructure() {
        Trainerfees = 5000;
        yogafees = 10000;
        mmafees = 10000;
        zumbafees = 5000;
        aerobicsfees = 10000;
        swimmingfees = 5000;
        saveFeestructure();
    }
    void setfees() {

        bool running = true;
        while (running) {
            int choice = 0;
            cout << "\nEdit Fees Structure:\n1.Trainer\n2.Yoga\n3.MMA\n4.Zumba\n5.Aerobics\n6.Swimming\n";
            cout << "Enter Activity you want to change Fees of: ";
            cin >> choice;

            int newfees;


            switch (choice) {
            case 1:
            {
                cout << "Enter new Fees: ";
                cin >> newfees;
                Trainerfees = newfees;
                break;
            }
            case 2:
            {
                cout << "Enter new Fees: ";
                cin >> newfees;
                yogafees = newfees;
                break;
            }
            case 3:
            {
                cout << "Enter new Fees: ";
                cin >> newfees;
                mmafees = newfees;
                break;
            }
            case 4:
            {
                cout << "Enter new Fees: ";
                cin >> newfees;
                zumbafees = newfees;
                break;
            }
            case 5:
            {
                cout << "Enter new Fees: ";
                cin >> newfees;
                aerobicsfees = newfees;
                break;
            }
            case 6:
            {
                cout << "Enter new Fees: ";
                cin >> newfees;
                swimmingfees = newfees;
                break;
            }
            default:
            {
                cout << "Invalid choice!\n";
                break;
            }
            }
            if (running) {
                char continueChoice;
                cout << "\nDo you want to continue? (Y/N): ";
                cin >> continueChoice;
                if (continueChoice != 'Y' && continueChoice != 'y') {
                    saveFeestructure();
                    running = false;
                }
            }
        }
    }
    void saveFeestructure() const {
        ofstream outfile("fees.txt");
        if (outfile.is_open()) {
            outfile << Trainerfees << endl;
            outfile << yogafees << endl;
            outfile << mmafees << endl;
            outfile << zumbafees << endl;
            outfile << aerobicsfees << endl;
            outfile << swimmingfees << endl;
            outfile.close();
        }
        else {
            cout << "Error: Unable to save timings to file." << endl;
        }
    }
    void displayfees() {
        cout << "Fees Structure: \n";
        cout << "Trainer Fees: " << Trainerfees << endl;
        cout << "Yoga Fees: " << yogafees << endl;
        cout << "MMA Fees: " << mmafees << endl;
        cout << "Zumba Fees: " << zumbafees << endl;
        cout << "Aerobics Fees: " << aerobicsfees << endl;
        cout << "Swimming Fees: " << swimmingfees << endl;
    }
};
class Person {
protected:
    string name;
    int age;
public:
    Person() {}
    Person(string name, int age) : name(name), age(age) {}
    virtual void display() const = 0;  // Making display a pure virtual function

    string getName() const { return name; }
    int getAge() const { return age; }
};

class Member : public Person {
private:
    int memberId;
    string membershipType;
    string joiningDate;
    string expiryDate;
public:
    void setName(const string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void setMembershipType(const string& newType) { membershipType = newType; }
    void setJoiningDate(const string& newDate) { joiningDate = newDate; }
    void setExpiryDate(const string& newDate) { expiryDate = newDate; }
    Member(string name, int age, int memberId, string membershipType, string joiningDate, string expiryDate)
        : Person(name, age), memberId(memberId), membershipType(membershipType), joiningDate(joiningDate), expiryDate(expiryDate) {}

    void display() const override {
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Member ID: " << memberId << ", Membership Type: " << membershipType
            << ", Joining Date: " << joiningDate << ", Expiry Date: " << expiryDate << endl;
    }
    int getId() const { return memberId; }
    string getMembershipType() const { return membershipType; }
    string getJoiningDate() const { return joiningDate; }
    string getExpiryDate() const { return expiryDate; }
};

class Trainer : public Person {
private:
    int trainerId;
public:
    Trainer(string name, int age, int trainerId) : Person(name, age), trainerId(trainerId) {}
    void setName(const string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void display() const override {
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Trainer ID: " << trainerId << endl;
    }
    int getTrainerId() const { return trainerId; }
};

class Staff : public Person {
private:
    int id; // Ensure this member is present if you wish to use getId() method
    string job;
    double fees;
public:
    Staff(string name, int age, int id, string job, double fees) : Person(name, age), id(id), job(job), fees(fees) {}

    int getId() const { return id; }  // Define getId method
    string getJob() const { return job; }
    double getFees() const { return fees; }
    void setId(int newId) { id = newId; } // If needed, setter for ID

    void setName(const string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void setJob(const string& newJob) { job = newJob; }
    void setFees(double newFees) { fees = newFees; }

    void display() const override {
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Job: " << job << ", Fees: $" << fees << ", ID: " << id << endl;
    }
};

class Equipment {
private:
    string equipmentName;
    int equipmentId;
public:
    Equipment(string equipmentName, int equipmentId)
        : equipmentName(equipmentName), equipmentId(equipmentId) {}
    void display() const {
        cout << "Equipment Name: " << equipmentName << ", Equipment ID: " << equipmentId << endl;
    }
    string getEquipmentName() const { return equipmentName; }
    int getEquipmentId() const { return equipmentId; }
};

class Session {
private:
    int sessionId;
    string sessionType;
    string dateTime;
public:
    Session(int sessionId, string sessionType, string dateTime)
        : sessionId(sessionId), sessionType(sessionType), dateTime(dateTime) {}
    void display() const {
        cout << "Session ID: " << sessionId << ", Type: " << sessionType << ", Date/Time: " << dateTime << endl;
    }
    int getSessionId() const { return sessionId; }
    string getSessionType() const { return sessionType; }
    string getDateTime() const { return dateTime; }
};

class Payment {
private:
    int paymentId;
    double amount;
    string date;
public:
    Payment(int paymentId, double amount, string date)
        : paymentId(paymentId), amount(amount), date(date) {}
    void display() const {
        cout << "Payment ID: " << paymentId << ", Amount: $" << amount << ", Date: " << date << endl;
    }
    int getPaymentId() const { return paymentId; }
    double getAmount() const { return amount; }
    string getDate() const { return date; }
};

class GymManagement {
private:
    Feestructure r;
    static const int maxMembers = 100;
    static const int maxTrainers = 50;
    static const int maxStaff = 10;
    static const int maxEquipments = 100;
    static const int maxSessions = 200;
    static const int maxPayments = 300;
    Member* members[maxMembers];
    Trainer* trainers[maxTrainers];
    Staff* staff[maxStaff];
    Equipment* equipments[maxEquipments];
    Session* sessions[maxSessions];
    Payment* payments[maxPayments];
    int numMembers = 0;
    int numTrainers = 0;
    int numStaff = 0;
    int numEquipments = 0;
    int numSessions = 0;
    int numPayments = 0;
    gymtiming g1;
    Attendance a1;
public:
    GymManagement() {
        loadAllData();
    }

    ~GymManagement() {
        saveAllData();
        clearAllData();
    }
    void updateMember(int memberId) {
        bool found = false;
        for (int i = 0; i < numMembers; ++i) {
            if (members[i]->getId() == memberId) {
                found = true;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

                cout << "Enter new Name: ";
                string name;
                getline(cin, name);
                members[i]->setName(name);

                cout << "Enter new Age: ";
                int age;
                while (!(cin >> age)) {
                    cout << "Invalid input. Please enter a valid age: ";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                cin.ignore();
                members[i]->setAge(age);

                cout << "Enter new Membership Type: ";
                string membershipType;
                getline(cin, membershipType);
                members[i]->setMembershipType(membershipType);

                cout << "Enter new Joining Date: ";
                string joiningDate;
                getline(cin, joiningDate);
                members[i]->setJoiningDate(joiningDate);

                cout << "Enter new Expiry Date: ";
                string expiryDate;
                getline(cin, expiryDate);
                members[i]->setExpiryDate(expiryDate);

                cout << "Member details updated successfully.\n";
                break;
            }
        }
        if (!found) {
            cout << "Member ID not found.\n";
        }
    }


    void deleteMember(int memberId) {
        for (int i = 0; i < numMembers; ++i) {
            if (members[i]->getId() == memberId) {
                delete members[i];
                for (int j = i; j < numMembers - 1; ++j) {
                    members[j] = members[j + 1];
                }
                numMembers--;
                cout << "Member deleted successfully." << endl;
                return;
            }
        }
        cout << "Member ID not found." << endl;
    }
    void updateEquipment(int equipmentId) {
        bool found = false;
        for (int i = 0; i < numEquipments; ++i) {
            if (equipments[i]->getEquipmentId() == equipmentId) {
                found = true;
                cout << "Enter new details (Equipment Name): ";
                string equipmentName;
                cin.ignore();
                getline(cin, equipmentName);
                equipments[i] = new Equipment(equipmentName, equipmentId);
                cout << "Equipment details updated successfully." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Equipment ID not found." << endl;
        }
    }

    void deleteEquipment(int equipmentId) {
        for (int i = 0; i < numEquipments; ++i) {
            if (equipments[i]->getEquipmentId() == equipmentId) {
                delete equipments[i];
                for (int j = i; j < numEquipments - 1; ++j) {
                    equipments[j] = equipments[j + 1];
                }
                numEquipments--;
                cout << "Equipment deleted successfully." << endl;
                return;
            }
        }
        cout << "Equipment ID not found." << endl;
    }
    void updateTrainer(int trainerId) {
        bool found = false;
        for (int i = 0; i < numTrainers; ++i) {
            if (trainers[i]->getTrainerId() == trainerId) {
                found = true;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Enter new Name: ";
                string name;
                getline(cin, name);
                trainers[i]->setName(name);

                cout << "Enter new Age: ";
                int age;
                while (!(cin >> age)) {
                    cout << "Invalid input. Please enter a valid age: ";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                cin.ignore();
                trainers[i]->setAge(age);

                cout << "Trainer details updated successfully.\n";
                break;
            }
        }
        if (!found) {
            cout << "Trainer ID not found.\n";
        }
    }
    void deleteTrainer(int trainerId) {
        for (int i = 0; i < numTrainers; ++i) {
            if (trainers[i]->getTrainerId() == trainerId) {
                delete trainers[i];
                for (int j = i; j < numTrainers - 1; ++j) {
                    trainers[j] = trainers[j + 1];
                }
                numTrainers--;
                cout << "Trainer deleted successfully.\n";
                return;
            }
        }
        cout << "Trainer ID not found.\n";
    }
    void updateStaff(int staffId) {
        bool found = false;
        for (int i = 0; i < numStaff; ++i) {
            if (staff[i]->getId() == staffId) { // Assuming getId() is defined
                found = true;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Enter new Name: ";
                string name;
                getline(cin, name);
                staff[i]->setName(name);

                cout << "Enter new Age: ";
                int age;
                while (!(cin >> age)) {
                    cout << "Invalid input. Please enter a valid age: ";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                cin.ignore();

                cout << "Enter new Job: ";
                string job;
                getline(cin, job);
                staff[i]->setJob(job);

                cout << "Enter new Fees: ";
                double fees;
                while (!(cin >> fees)) {
                    cout << "Invalid input. Please enter a valid fee amount: ";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                staff[i]->setFees(fees);

                cout << "Staff details updated successfully.\n";
                break;
            }
        }
        if (!found) {
            cout << "Staff ID not found.\n";
        }
    }
    void deleteStaff(int staffId) {
        for (int i = 0; i < numStaff; ++i) {
            if (staff[i]->getId() == staffId) {
                delete staff[i];
                for (int j = i; j < numStaff - 1; ++j) {
                    staff[j] = staff[j + 1];
                }
                numStaff--;
                cout << "Staff deleted successfully.\n";
                return;
            }
        }
        cout << "Staff ID not found.\n";
    }

    void memberdisplay() {
        loadMembers(); // Load members data

        int searchid;
        cout << "Welcome to Our Gym " << endl;

        while (true) {
            cout << "Enter your Membership ID: ";
            cin >> searchid;

            bool found = false;

            // Search for the member with the entered ID
            for (int i = 0; i < numMembers; ++i) {
                if (members[i]->getId() == searchid) {
                    found = true;

                    cout << "Welcome, " << members[i]->getName() << "!" << endl;
                    cout << "What would you like to do?" << endl;
                    cout << "1. View Trainer details" << endl;
                    cout << "2. Mark Attendance" << endl;
                    cout << "3. View Gym Timings" << endl;
                    cout << "4. Make Fee Payment" << endl;

                    int choice;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                    case 1:
                        loadTrainer();
                        break;
                    case 2:
                        attendance(searchid);
                        break;

                    case 3:
                        g1.displayTimings();
                        break;
                    case 4:
                    {
                        int id; double  amount;
                        string date;
                        cout << "Enter Payment ID, Amount, Date: ";
                        cin >> id >> amount >> date;
                        addPayment(new Payment(id, amount, date));
                    }
                    break;
                    default:
                        cout << "Invalid choice! Please enter a valid option." << endl;
                    }
                    break;
                }
            }

            if (!found) {
                cout << "Member ID not found. Please enter a valid ID." << endl;
            }

            char cont;
            cout << "Do you want to continue? (Y/N): ";
            cin >> cont;
            if (cont != 'Y' && cont != 'y') {
                break;
            }
        }
    }
    void attendance(int id)
    {
        string type, date;


        cout << "Enter todays date :";
        cin >> date;
        a1.markattendance(id, date, type, true);

    }
    void staffdisplay() {
        loadStaff();
        string searchname;

        cout << "Welcome to the Gym!\n";

        cout << "Enter your Name: ";
        cin.ignore();
        getline(cin, searchname);

        bool found = false;

        while (true) {
            // Search for the staff member with the entered name
            for (int i = 0; i < numStaff; ++i) {
                if (staff[i]->getName() == searchname) {
                    found = true;

                    cout << "Welcome, " << staff[i]->getName() << "!" << endl;
                    cout << "What would you like to do?" << endl;
                    cout << "1. Mark Attendance" << endl;
                    cout << "2. View Gym Timings" << endl;

                    int choice;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                    case 1: {
                        staffattendance(searchname);
                        break;
                    }
                    case 2: {
                        gymtiming g2;
                        g2.displayTimings();
                        break;
                    }
                    default:
                        cout << "Invalid choice! Please enter a valid option." << endl;
                        break;
                    }
                    break;
                }
            }

            if (!found) {
                cout << "No Staff Member found with name " << searchname << endl;
            }

            char cont;
            cout << "Do you want to continue? (Y/N): ";
            cin >> cont;
            if (cont != 'Y' && cont != 'y') {
                break;
            }
        }
    }

    void staffattendance(string name) {
        string date;

        cout << "Enter todays date :";
        cin >> date;
        Attendance a2;
        a2.markstaffattendance(name, date, true);

    }

    void loadAllData() {
        loadMembers();
        loadTrainers();
        loadStaff();
        loadEquipments();
        loadSessions();
        loadPayments();
    }

    void saveAllData() {
        saveMembers();
        saveTrainers();
        saveStaff();
        saveEquipments();
        saveSessions();
        savePayments();
    }

    void clearAllData() {
        for (int i = 0; i < numMembers; i++) delete members[i];
        for (int i = 0; i < numTrainers; i++) delete trainers[i];
        for (int i = 0; i < numStaff; i++) delete staff[i];
        for (int i = 0; i < numEquipments; i++) delete equipments[i];
        for (int i = 0; i < numSessions; i++) delete sessions[i];
        for (int i = 0; i < numPayments; i++) delete payments[i];
        numMembers = numTrainers = numStaff = numEquipments = numSessions = numPayments = 0;
    }

    void addMember(Member* m) {
        if (numMembers < maxMembers) {
            members[numMembers++] = m;
        }

    }

    void addTrainer(Trainer* t) {
        if (numTrainers < maxTrainers) {
            trainers[numTrainers++] = t;
        }
    }

    void addStaff(Staff* s) {
        if (numStaff < maxStaff) {
            staff[numStaff] = s;
            numStaff++;
        }
    }

    void addEquipment(Equipment* e) {
        if (numEquipments < maxEquipments) {
            equipments[numEquipments++] = e;
        }
    }

    void addSession(Session* s) {
        if (numSessions < maxSessions) {
            sessions[numSessions++] = s;
        }
    }

    void addPayment(Payment* p) {
        if (numPayments < maxPayments) {
            payments[numPayments++] = p;
        }
    }

    void loadMembers() {
        ifstream inFile("members.txt");
        string name, membershipType, joiningDate, expiryDate;
        int age, memberId;
        while (inFile >> ws && getline(inFile, name, ' ')) {
            inFile >> age >> memberId;
            inFile >> ws;
            getline(inFile, membershipType, ' ');
            getline(inFile, joiningDate, ' ');
            getline(inFile, expiryDate);
            addMember(new Member(name, age, memberId, membershipType, joiningDate, expiryDate));
        }
        inFile.close();
    }

    void saveMembers() {

        ofstream outFile("members.txt");
        for (int i = 0; i < numMembers; i++) {
            outFile << members[i]->getName() << " "
                << members[i]->getAge() << " "
                << members[i]->getId() << " "
                << members[i]->getMembershipType() << " "
                << members[i]->getJoiningDate() << " "
                << members[i]->getExpiryDate() << "\n";
        }
        outFile.close();
    }

    void loadTrainers() {
        ifstream inFile("trainer.txt");
        string name;
        int age, trainerId;
        while (inFile >> ws && getline(inFile, name, ' ')) {
            inFile >> age >> trainerId;
            addTrainer(new Trainer(name, age, trainerId));
        }
        inFile.close();
    }
    void loadTrainer() {
        ifstream inFile("trainer.txt");
        string name;
        int age, trainerId;


        if (inFile >> ws && getline(inFile, name, ' ')) {
            inFile >> age >> trainerId;
            cout << "Name of the trainer: " << name << endl << "Age:"
                << age << endl << "Trainer Id: " << trainerId << endl;
        }
        else {
            cout << "No trainer data found in the file." << endl;
        }

        inFile.close();
    }
    void saveTrainers() {
        ofstream outFile("trainer.txt");
        for (int i = 0; i < numTrainers; i++) {
            outFile << trainers[i]->getName() << " "
                << trainers[i]->getAge() << " "
                << trainers[i]->getTrainerId() << "\n";
        }
        outFile.close();
    }

    void loadStaff() {
        ifstream inFile("staff.txt");
        string name, job;
        int age, id;
        double fees;
        while (inFile >> id >> ws && getline(inFile, name, ' ')) {
            inFile >> age >> fees;
            getline(inFile, job);
            addStaff(new Staff(name, age, id, job, fees));  // Corrected
        }
        inFile.close();
    }


    void saveStaff() {
        ofstream outFile("staff.txt");
        for (int i = 0; i < numStaff; i++) {
            outFile << staff[i]->getName() << " "
                << staff[i]->getAge() << " "
                << staff[i]->getJob() << " "
                << staff[i]->getFees() << "\n";
        }
        outFile.close();
    }
    void loadEquipments() {
        ifstream inFile("equipment.txt");
        string equipmentName;
        int equipmentId;
        while (inFile >> ws && getline(inFile, equipmentName, ' ')) {
            inFile >> equipmentId;
            addEquipment(new Equipment(equipmentName, equipmentId));
        }
        inFile.close();
    }

    void saveEquipments() {
        ofstream outFile("equipment.txt");
        for (int i = 0; i < numEquipments; i++) {
            outFile << equipments[i]->getEquipmentName() << " "
                << equipments[i]->getEquipmentId() << "\n";
        }
        outFile.close();
    }

    void loadSessions() {
        ifstream inFile("sessions.txt");
        int sessionId;
        string sessionType, dateTime;
        while (inFile >> sessionId >> ws && getline(inFile, sessionType, ' ') && getline(inFile, dateTime)) {
            addSession(new Session(sessionId, sessionType, dateTime));
        }
        inFile.close();
    }

    void saveSessions() {
        ofstream outFile("sessions.txt");
        for (int i = 0; i < numSessions; i++) {
            outFile << sessions[i]->getSessionId() << " "
                << sessions[i]->getSessionType() << " "
                << sessions[i]->getDateTime() << "\n";
        }
        outFile.close();
    }

    void loadPayments() {
        ifstream inFile("payments.txt");
        int paymentId;
        double amount;
        string date;
        while (inFile >> paymentId >> amount >> ws && getline(inFile, date)) {
            addPayment(new Payment(paymentId, amount, date));
        }
        inFile.close();
    }

    void savePayments() {
        ofstream outFile("payments.txt");
        for (int i = 0; i < numPayments; i++) {
            outFile << payments[i]->getPaymentId() << " "
                << payments[i]->getAmount() << " "
                << payments[i]->getDate() << "\n";
        }
        outFile.close();
    }

    void showAllMembers() {
        cout << "All Members:" << endl;
        for (int i = 0; i < numMembers; i++) {
            members[i]->display();
        }
    }

    void showAllTrainers() {
        cout << "All Trainers:" << endl;
        for (int i = 0; i < numTrainers; i++) {
            trainers[i]->display();
        }
    }

    void showAllStaff() {
        cout << "All Staff:" << endl;
        for (int i = 0; i < numStaff; i++) {
            staff[i]->display();
        }
    }

    void showAllEquipments() {
        cout << "All Equipment:" << endl;
        for (int i = 0; i < numEquipments; i++) {
            equipments[i]->display();
        }
    }

    void showAllSessions() {
        cout << "All Sessions:" << endl;
        for (int i = 0; i < numSessions; i++) {
            sessions[i]->display();
        }
    }

    void showAllPayments() {
        cout << "All Payments:" << endl;
        for (int i = 0; i < numPayments; i++) {
            payments[i]->display();
        }
    }

    void adminPanel() {
        int choice, memberId, trainerId, staffId, equipmentId;

        bool running = true;
        while (running) {
            cout << "\n\t\t\t" << BLUE << "Admin Panel - Gym Management System\n" << RESET;
            cout << "\t\t\t" << BLUE << "===================================\n" << RESET;
            cout << "\t" << BLUE << "1. " << YELLOW << "Add Member\n" << RESET;
            cout << "\t" << BLUE << "2. " << YELLOW << "Add Trainer\n" << RESET;
            cout << "\t" << BLUE << "3. " << YELLOW << "Add Staff Members\n" << RESET;
            cout << "\t" << BLUE << "4. " << YELLOW << "Add Equipment\n" << RESET;
            cout << "\t" << BLUE << "5. " << YELLOW << "Add Session\n" << RESET;
            cout << "\t" << BLUE << "6. " << YELLOW << "Add Payment\n" << RESET;
            cout << "\t" << BLUE << "7. " << YELLOW << "Show All Members\n" << RESET;
            cout << "\t" << BLUE << "8. " << YELLOW << "Show All Trainers\n" << RESET;
            cout << "\t" << BLUE << "9. " << YELLOW << "Show All Staff Members\n" << RESET;
            cout << "\t" << BLUE << "10. " << YELLOW << "Show All Equipments\n" << RESET;
            cout << "\t" << BLUE << "11. " << YELLOW << "Show All Sessions\n" << RESET;
            cout << "\t" << BLUE << "12. " << YELLOW << "Show All Payments\n" << RESET;
            cout << "\t" << BLUE << "13. " << YELLOW << "Exit Admin Panel\n" << RESET;
            cout << "\t" << BLUE << "14. " << YELLOW << "Update Member\n" << RESET;
            cout << "\t" << BLUE << "15. " << YELLOW << "Delete Member\n" << RESET;
            cout << "\t" << BLUE << "16. " << YELLOW << "Update Equipment\n" << RESET;
            cout << "\t" << BLUE << "17. " << YELLOW << "Delete Equipment\n" << RESET;
            cout << "\t" << BLUE << "18. " << YELLOW << "Update Trainer\n" << RESET;
            cout << "\t" << BLUE << "19. " << YELLOW << "Delete Trainer\n" << RESET;
            cout << "\t" << BLUE << "20. " << YELLOW << "Update Staff\n" << RESET;
            cout << "\t" << BLUE << "21. " << YELLOW << "Delete Staff\n" << RESET;
            cout << "\t" << BLUE << "22. " << YELLOW << "Update Timings\n" << RESET;
            cout << "\t" << BLUE << "23. " << YELLOW << "See All Timings\n" << RESET;
            cout << "\t" << BLUE << "24. " << YELLOW << "Set fees\n" << RESET;
            cout << "\t" << BLUE << "Enter your choice: ";

            string name, membershipType, equipmentName, sessionType, dateTime, date, job;
            int age, id;
            double amount, fees;
            cin >> choice;

            switch (choice) {
            case 1:
            {

                cout << "Enter Name :";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Age :";
                cin >> age;
                cout << "Enter Id :";
                cin >> id;
                cout << "membership type :";
                cin.ignore();
                getline(cin, membershipType);
                cout << "Enter joiningtime :";
                cin.ignore();
                getline(cin, dateTime);
                cout << "enter expiry date :";
                cin.ignore();
                getline(cin, date);
                addMember(new Member(name, age, id, membershipType, dateTime, date));
                break;
            }
            case 2: {
                cout << "Enter Name ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer fully
                getline(cin, name); // Read the full line for the name

                cout << "Enter Age: ";
                cin >> age;


                cout << "Enter Trainer ID: ";
                cin >> id;


                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer after last numeric input
                addTrainer(new Trainer(name, age, id));
                cout << "Trainer added successfully!" << endl;
                break;
            }

            case 3: { // Adding Staff
                cout << "Enter Name ";
                cin.ignore();  // Always clear buffer immediately after reading numeric input
                getline(cin, name);
                cout << "Entr age:";
                cin >> age;
                cout << "Enter id:";
                cin >> id;
                cout << "Enter Job:";


                cin.ignore();  // Clear buffer again as we read strings next
                getline(cin, job);
                cout << "enter fees";
                cin >> fees;
                addStaff(new Staff(name, age, id, job, fees));
                cout << "staff member added successfully";
                break;
            }
            case 4:
            {
                cout << "Enter Equipment Name: ";
                cin.ignore();
                getline(cin, equipmentName);
                cout << "Enter id:";
                cin >> id;
                addEquipment(new Equipment(equipmentName, id));
                break;
            }
            case 5:
            {
                cout << "Enter Session ID: ";
                cin >> id;
                cout << "Enter type:";
                cin.ignore();
                getline(cin, sessionType);
                cout << "Enter date/time";
                cin.ignore();
                getline(cin, dateTime);
                addSession(new Session(id, sessionType, dateTime));
                break;
            }
            case 6:
            {
                cout << "Enter Payment ID ";
                cin >> id;
                cout << "Enter amount";
                cin >> amount;
                cout << "Enter date";
                cin.ignore();
                getline(cin, date);
                addPayment(new Payment(id, amount, date));
                break;
            }
            case 7:
            {
                showAllMembers();
                break;
            }
            case 8:
            {
                showAllTrainers();
                break;
            }
            case 9:
                showAllStaff();
                break;
            case 10:
            {
                showAllEquipments();
                break;
            }
            case 11:
            {
                showAllSessions();
                break;
            }
            case 12:
            {
                showAllPayments();
                break;
            }
            case 13:
            {
                running = false; // Exiting admin panel but not the program
                break;
            }
            case 14:
                cout << "Enter Member ID to update: ";
                int memberId;
                cin >> memberId;
                updateMember(memberId);
                break;
            case 15:
                cout << "Enter Member ID to delete: ";
                cin >> memberId;
                deleteMember(memberId);
                break;
            case 16:
                cout << "Enter Equipment ID to update: ";
                int equipmentId;
                cin >> equipmentId;
                updateEquipment(equipmentId);
                break;
            case 17:
                cout << "Enter Equipment ID to delete: ";
                cin >> equipmentId;
                deleteEquipment(equipmentId);
                break;
            case 18:
                cout << "Enter Trainer ID to update: ";
                int trainerId;
                cin >> trainerId;
                updateTrainer(trainerId);
                break;
            case 19:
                cout << "Enter Trainer ID to delete: ";
                int trainerid;
                cin >> trainerid;
                deleteTrainer(trainerid);
                break;
            case 20:
                cout << "Enter Staff ID to update: ";
                int staffId;
                cin >> staffId;
                updateStaff(staffId);
                break;
            case 21:
                cout << "Enter Staff ID to delete: ";
                int staffid;
                cin >> staffid;
                deleteStaff(staffid);
                break;
            case 22:
                g1.setTimings();

                break;
            case 23:
                g1.displayTimings();
                break;
            case 24:
            {

                r.setfees();
                break;
            }

            default:
            {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
            }

            if (running) {
                char continueChoice;
                cout << "\nDo you want to continue in admin panel? (Y/N): ";
                cin >> continueChoice;
                if (continueChoice != 'Y' && continueChoice != 'y') {
                    running = false;
                }
            }
        }
    }
};

class NewMember : public GymManagement {
public:
    void visitingdisplay() {
        cout << "Welcome to Visiting Panel:\n";
        int choice;
        bool running = true;
        while (true) {
            cout << "1. View Timings\n";
            cout << "2. View Fee Structure\n";
            cout << "3. Become Member\n";

            cout << "4. Exit visiting member Panel\n";
            cout << "Enter your choice: ";
            cin >> choice;
            gymtiming v1;
            string name, membershipType, equipmentName, sessionType, dateTime, date, job;
            int age, id;
            double amount, fees;

            switch (choice) {
            case 1:
            {
                v1.displayTimings();
                break;
            }
            case 2:
            {
                Feestructure f1;
                f1.displayfees();
                break;
            }
            case 3:
            {
                cout << "Enter Name, Age, Member ID, Membership Type, Joining Date, Expiry Date: ";
                cin.ignore();
                string line;
                getline(cin, line);
                istringstream iss(line);
                iss >> name >> age >> id >> membershipType >> dateTime >> date;
                addMember(new Member(name, age, id, membershipType, dateTime, date));
                cout << "Do you want to make Payment (Y/N): ";
                char opt;
                cin >> opt;
                if (opt == 'Y' || opt == 'y') {
                    cout << "Enter Payment ID, Amount, Date: ";
                    cin >> id >> amount >> date;
                    addPayment(new Payment(id, amount, date));
                    break;
                }
                else {
                    break;
                }
            }

            case 10:
            {
                running = false; // Exiting admin panel but not the program
                break;
            }
            default:
            {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
            }

            if (running) {
                char continueChoice;
                cout << "\nDo you want to continue in Visiting panel? (Y/N): ";
                cin >> continueChoice;
                if (continueChoice != 'Y' && continueChoice != 'y') {
                    running = false;
                    break;
                }
            }
        }
    }
};

int main() {
    GymManagement gym;
    bool running = true;

    while (running) {
        cout << CYAN << "Welcome to the Gym Management System\n";
        cout << "Are you an Admin or a Member or Staff or Visiting Member? (A/M/S/V): ";
        char userType;
        cin >> userType; RESET;

        if (userType == 'A' || userType == 'a') {
            string adminPassword;
            cout << CYAN << "Enter admin password: ";
            cin >> adminPassword; RESET;
            if (adminPassword == "adminpass") {
                gym.adminPanel();
            }
            else {
                cout << "Incorrect password. Access denied.\n";
            }
        }

        if (userType == 'M' || userType == 'm') {
            gym.memberdisplay();

        }

        if (userType == 'S' || userType == 's') {
            gym.staffdisplay();
        }

        if (userType == 'V' || userType == 'v') {
            NewMember v1;
            v1.visitingdisplay();

        }

        else {
            cout << "Invalid choice. Please start again.\n";
        }

        cout << "Do you want to continue using the system? (Y/N): ";
        char continueChoice;
        cin >> continueChoice;
        if (continueChoice != 'Y' && continueChoice != 'y') {
            running = false;
        }
    }
    cout << "T H A N K S !" << endl;
    return 0;
}