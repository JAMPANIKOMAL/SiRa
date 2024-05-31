#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class patient
{
    protected:
        string patient_name;
        string patient_username;
        string patient_password;
        long long patient_phone1;
        long long patient_phone2; // phone2 or emergnecy home contact number
        string patient_mail;
        string patient_address;
        string patient_citizenid;
        string patient_bloodgroup;
        string patient_pastmedicalhistory;
        long long patient_uniquecode;

        vector<string> patient_names {"Tejas Prakash Patil", "Aashutosh Thakur", "Jampani Komal"};
        vector<string> patient_usernames {"tejas", "aashutosh", "komal"};
        vector<string> patient_passwords {"tejas1", "aashutosh1", "komal1"};
        vector<long long> patient_phone1s {7720841778, 8102568219, 9182048179};
        vector<long long> patient_phone2s {0, 9825818717, 9704427177}; // 0 represnts phone number not provided.
        vector<string> patient_mails {"tppatil397@gmail.com", "thakuraashutosh13@gmail.com", "jampanikomal2005@gmail.com"};
        vector<string> patient_addresses {"Home World Hostel, Bhaijipura, Gandhinagar, Gujarat. - 382421", "Home World Hostel, Bhaijipura, Gandhinagar, Gujarat. - 382421", "Home World Hostel, Bhaijipura, Gandhinagar, Gujarat. - 382421"};
        vector<string> patient_bloodgroups {"B+", "O+", "B+"};
        vector<string> patient_citizenids {"230031101611052", "230031101611057", "230031101611054"};
        vector<long long> patient_uniquecodes {23052, 23057, 23054};
        vector <string> patient_pastmedicalhistories {"Cancer", "Sinus", "None"};

    public:
        int patient_index;

        void patient_start()
        {
            patient_homemenu();
        }

        void patient_homemenu()
        {
            while (1)
            {
                string a;
                cout << endl << " ----------- ";
                cout << endl << "| Hello!    |";
                cout << endl << "| 1. Login  |";
                cout << endl << "| 2. Signup |";
                cout << endl << "| 3. Exit   |";
                cout << endl << " -----------" << endl;
                cout << "> ";
                cin >> a;

                if (a == "1")
                {
                    patient_login();
                }
                else if (a == "2")
                {
                    patient_signup();
                }
                else if (a == "3")
                {
                    cout << endl << "Exiting!" << endl << "Exited Succesfully!" << endl << endl;
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid Choice!" << endl;;
                }
            }
        }

        void patient_menu()
        {
            while (1)
            {
                string a;
                cout << endl << " ---------------------------- ";
                cout << endl << "| 1. View your Profile       |";
                cout << endl << "| 2. View Nearby Hospitals.  |";
                cout << endl << "| 3. View Nearby Pharmacies. |";
                cout << endl << "| 4. Medicine Search.        |";
                cout << endl << "| 5. Exit                    |";
                cout << endl << " ---------------------------- "<< endl;
                cout << "> ";
                cin >> a;

                if (a == "1")
                {
                    patient_viewyourprofile();
                }
                else if (a == "2")
                {
                    patient_viewnearbyhospitals();
                }
                else if (a == "3")
                {
                    patient_viewnearbypharmacies();
                }
                else if (a == "4")
                {
                    patient_medicinesearch();
                }
                else if (a == "5")
                {
                    cout << endl << "Exiting!" << endl << "Exited Succesfully!" << endl << endl;
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid Choice!" << endl;
                }
            }
        }

        void patient_login()
        {
            cout << endl
                << "Enter Username: ";
            cin >> patient_username;
            cout << "Enter Password: ";
            cin >> patient_password;
            int flag = 0;

            for (int i = 0; i < patient_usernames.size(); i++)
            {
                if (patient_username == patient_usernames[i] && patient_password == patient_passwords[i])
                {
                    cout << endl << "Login Successfull!" << endl;
                    patient_index = i;
                    flag = 1;
                    patient_menu();
                }
            }

            if (flag == 0)
            {
                cout << endl << "Invalid Credentials!" << endl;
                patient_homemenu();
            }
        }

        void patient_signup()
        {
            cout << endl << "Enter your Name: ";
            cin.ignore();
            getline(cin, patient_name);
            cout << "Enter your phone number: ";
            while (!(cin >> patient_phone1) || cin.peek() != '\n') 
            {
                cout << "Please enter a valid mobile number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter your alternate [Emergency] phone number: ";
            while (!(cin >> patient_phone2) || cin.peek() != '\n') 
            {
                cout << "Please enter a valid mobile number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter your mail Id: ";
            cin >> patient_mail;
            cout << "Address: ";
            cin.ignore();
            getline(cin, patient_address);
            cout << "Enter blood group: ";
            cin >> patient_bloodgroup;
            cout << "Enter citizenship ID: ";
            cin >> patient_citizenid;
            cout << "Enter a Username: ";
            cin >> patient_username;
            cout << "Enter password: ";
            cin >> patient_password;

            patient_names.push_back(patient_name);
            patient_phone1s.push_back(patient_phone1);
            patient_phone2s.push_back(patient_phone2);
            patient_mails.push_back(patient_mail);
            patient_addresses.push_back(patient_address);
            patient_bloodgroups.push_back(patient_bloodgroup);
            patient_citizenids.push_back(patient_citizenid);
            patient_usernames.push_back(patient_username);
            patient_passwords.push_back(patient_password);
            patient_uniquecodes.push_back(rand() % 100);

            cout << endl << "Sign Up Succesfull!" << endl << "Visit nearest hospital to complete KYC to acces all features of the app!" << endl;
            patient_index = (patient_usernames.size() - 1);

            patient_homemenu();
        }

        void patient_viewyourprofile()
        {
            cout << endl << "Name: " << patient_names[patient_index];
            cout << endl << "Phone Number: " << patient_phone1s[patient_index];
            cout << endl << "Alternate Phone Number: " << patient_phone2s[patient_index];
            cout << endl << "Mail: " << patient_mails[patient_index];
            cout << endl << "Address: " << patient_addresses[patient_index];
            cout << endl << "Blood Group: " << patient_bloodgroups[patient_index];
            cout << endl << "Citizen ID: " << patient_citizenids[patient_index];
            cout << endl << "Unique Code: " << patient_uniquecodes[patient_index];
            cout << endl << "Username: " << patient_usernames[patient_index] << endl;
        }

       void patient_medicinesearch()
        {
            string hiarr[6][2] = {{"Fever", "Paracetmol"}, {"Cold", "Ceterizine"}, {"Stomach ache", "Cyclopam"}, {"Headache", "Aspirin"}, {"Back pain", "Hydrocodone"}, {"Nausea", "Domperidone"}};

            cout << endl<< "Which Symptom do you have: " << endl;
            int choice;
            for (int i = 0; i < 6; i++)
            {
                cout << i + 1 << ". " << hiarr[i][0] << endl;
            }
            cout << "Enter your choice: ";
            cin >> choice;

            if(choice > 7)
            {
                cout << endl << "Invalid Choice!" << endl;;
                patient_menu();
                return;
            }

            cout << endl << "You can take the following tablet for temporary relief. Consult a Doctor if symptoms persist." << endl;
            cout << hiarr[choice - 1][1] << endl;
        }

        void patient_viewnearbyhospitals()
        {
            cout << endl << "Where do you live?";
            int choice;
            while (1)
            {
                cout << endl << " ---------------- ";
                cout << endl << "| 1. Dahegam     |";
                cout << endl << "| 2. Gandhinagar |";
                cout << endl << "| 3. Ahmedabad   |";
                cout << endl << "| 4. Surat       |";
                cout << endl << "| 5. Vadodara    |";
                cout << endl << "| 6. Exit        |";
                cout << endl << " ---------------- " << endl;
                cout << "> ";
                cin >> choice;

                switch (choice)
                {
                    case 1:
                    {
                        cout << endl << "Life Care Hospital: \"16 Shreenath Arcade Dehgam, Dahegam, Gujarat 382305\"" << endl;
                        return;
                    }

                    case 2:
                    {
                        cout << endl << "Apollo Hospital: \"Plot no. 1555, GH Rd, near GH 2 Circle, Sector 6, Gandhinagar, Gujarat 382006\"" << endl;
                        return;
                    }
                        
                    case 3:
                    {
                        cout << endl << "Sterling Hospital: \"Shop No 12 & 13, Ground Floor, Kanam 2, near Reliance Chowkdi, Kudasan, Ahmedabad, Gujarat 382421\"" << endl;
                        return;
                    }
                    case 4:
                    {
                        cout << endl << "Surat General Hospital: \"Mann Complex, 6, Anand Mahal Rd, Opposite Shree Ram Petrol Pump, Adajan, Surat, Gujarat 395009\"" << endl;
                        return;
                    }
                    case 5:
                    {
                        cout << endl << "Sunshine Global Hospital: \"Shop No 7, Om Complex, Vasna Rd, near Taksh Complex, Shivashraya Society, Tandalja, Vadodara, Gujarat 390015\"" << endl;
                        return;
                    } 
                    case 6:
                    {
                        patient_menu();
                        // return;
                    }
                        
                    default:
                    {
                        cout << endl << "Invalid choice or few places are still left to update. Sorry for the inconvenience!" << endl;
                        return;
                    }   
                }
            }
        }

        void patient_viewnearbypharmacies()
        {
            cout << endl << "Where do you live?";
            int choice;
            while (1)
            {
                cout << endl << " ---------------- ";
                cout << endl << "| 1. Dahegam     |";
                cout << endl << "| 2. Gandhinagar |";
                cout << endl << "| 3. Ahmedabad   |";
                cout << endl << "| 4. Surat       |";
                cout << endl << "| 5. Vadodara    |";
                cout << endl << "| 6. Exit        |";
                cout << endl << " ---------------- " << endl;
                cout << "> ";
                cin >> choice;

                switch (choice)
                {
                    case 1:
                    {
                        cout << endl << "PharmEasy Medicine Point: \"16 Shreenath Arcade Dehgam, Dahegam, Gujarat 382305\"" << endl;
                        return;
                    } 
                    case 2:
                    {
                        cout << endl << "Apollo Pharmacy: \"Plot no. 1555, GH Rd, near GH 2 Circle, Sector 6, Gandhinagar, Gujarat 382006\"" << endl;
                        return;
                    }
                    case 3:
                    {
                        cout << endl << "Apollo Pharmacy: \"Shop No 12 & 13, Ground Floor, Kanam 2, near Reliance Chowkdi, Kudasan, Ahmedabad, Gujarat 382421\"" << endl;
                        return;
                    }
                    case 4:
                    {
                        cout << endl << "Apollo Pharmacy: \"Mann Complex, 6, Anand Mahal Rd, Opposite Shree Ram Petrol Pump, Adajan, Surat, Gujarat 395009\"" << endl;
                        return;
                    }
                    case 5:
                    {                    
                        cout << endl << "Medkart Pharmacy: \"Shop No 7, Om Complex, Vasna Rd, near Taksh Complex, Shivashraya Society, Tandalja, Vadodara, Gujarat 390015\"" << endl;
                        return;

                    }
                    case 6:
                    {
                        patient_menu();
                        return;
                    }  
                    default:
                    {
                        cout << endl << "Invalid choice or few places are still left to update. Sorry for the inconvenience!" << endl;
                        return;
                    }
                }
            }
        }
};

class doctor : public patient
{
    protected:
        string doctor_name;
        string doctor_username;
        string doctor_password;
        long long doctor_phone1;
        long long doctor_phone2;  //phone2 or emergnecy home contact number
        string doctor_mail;
        string doctor_address;
        string doctor_citizenid;
        string doctor_nmcid;
        string doctor_bloodgroup;
        long long doctor_uniquecode;
        
        vector <string> doctor_names {"Prasann Barot", "Rabel Guharoy"};
        vector <string> doctor_usernames {"prasann", "rabel"};
        vector <string> doctor_passwords {"prasann1", "rabel1"};
        vector <long long> doctor_phone1s {9924492472, 7980262223};
        vector <long long> doctor_phone2s {0, 0}; //0 represnts phone number not provided.
        vector <string> doctor_mails {"prasann.barot@rru.ac.in", "rabel.guharoy@rru.ac.in"};
        vector <string> doctor_addresses {"Rashtriya Raksha University, Lavad, Gandhinagar, Gujarat. - 382305", "Rashtriya Raksha University, Lavad, Gandhinagar, Gujarat. - 382305"};
        vector <string> doctor_bloodgroups {"B+", "O+"};
        vector <string> doctor_citizenids {"678677863561", "897765453442"};
        vector <string> doctor_nmcids {"2343er", "4534ty"};
        vector <long long> doctor_uniquecodes {33069, 33088};
        
    public:
        int doctor_index;
        
        void doctor_start()
        {
            doctor_homemenu();
        }

        void doctor_homemenu()
        {
            while(1)
            {
                string a;
                cout << endl << " ----------- ";
                cout << endl << "| Hello!    |";
                cout << endl << "| 1. Login  |";
                cout << endl << "| 2. Signup |";
                cout << endl << "| 3. Exit   |";
                cout << endl << " -----------" << endl;
                cout << "> ";
                cin >> a;

                if(a == "1")
                {
                    doctor_login();
                }
                else if(a == "2")
                {
                    doctor_signup();
                }
                else if(a == "3")
                {
                    cout << endl << "Exiting!" << endl << "Exited Succesfully!" << endl << endl;
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid Choice!" << endl;
                }
            }
            
        }

         void doctor_menu()
        {
            while(1)
            {
                string a;
                cout << endl << " ----------------------------------- ";
                cout << endl << "| 1. View your Profile              |";
                cout << endl << "| 2. View your Patient's Profiles.  |";
                cout << endl << "| 3. Exit                           |";
                cout << endl << " ----------------------------------- " << endl;
                cout << "> ";
                cin >> a;

                if(a == "1")
                {
                    doctor_viewprofile();
                }
                else if(a == "2")
                {
                    doctor_viewpatientsprofile();
                }
                else if(a == "3")
                {
                    cout << endl << "Exiting!" << endl << "Exited Succesfully!" << endl << endl;
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid Choice!" << endl;
                }
            }

        }

        void doctor_login()
        {
            cout << endl <<  "Enter Username: ";
            cin >> doctor_username;
            cout << "Enter Password: ";
            cin >> doctor_password;
            int flag = 0;

            for(int i = 0; i < doctor_usernames.size(); i++)
            {
                if(doctor_username == doctor_usernames[i] && doctor_password == doctor_passwords[i])
                {
                    cout << endl << "Login Successfull!" <<endl;
                    doctor_index = i;
                    flag = 1;
                    doctor_menu();
                }
            }

            if(flag == 0) 
            {
                cout << endl << "Invalid Credentials!" << endl;
                doctor_homemenu();
            }
        }

        void doctor_signup()
        {
            cout << endl << "Enter your Name: ";
            cin.ignore();
            getline(cin, doctor_name);
            cout << "Enter your phone number: ";
            while (!(cin >> doctor_phone1) || cin.peek() != '\n') 
            {
                cout << "Please enter a valid mobile number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter your alternate [Emergency] phone number: ";
            while (!(cin >> doctor_phone2) || cin.peek() != '\n') 
            {
                cout << "Please enter a valid mobile number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter your mail Id: ";
            cin >> doctor_mail;
            cout << "Address: ";
            cin.ignore();
            getline(cin, doctor_address);
            cout << "Enter blood group: ";
            cin >> doctor_bloodgroup;
            cout << "Enter citizenship ID: ";
            cin >> doctor_citizenid;
            cout << "Enter NMC ID: ";
            cin >> doctor_nmcid;
            cout << "Enter a Username: ";
            cin >> doctor_username;
            cout << "Enter password: ";
            cin >> doctor_password;

            doctor_names.push_back(doctor_name);
            doctor_phone1s.push_back(doctor_phone1);
            doctor_phone2s.push_back(doctor_phone2);
            doctor_mails.push_back(doctor_mail);
            doctor_addresses.push_back(doctor_address);
            doctor_bloodgroups.push_back(doctor_bloodgroup);
            doctor_citizenids.push_back(doctor_citizenid);
            doctor_nmcids.push_back(doctor_nmcid);
            doctor_usernames.push_back(doctor_username);
            doctor_passwords.push_back(doctor_password);
            doctor_uniquecodes.push_back(rand() % 100);

            cout << endl << "Sign Up Succesfull!" << endl << "Visit your hospital to complete KYC to acces all features of the app!" << endl;
            doctor_index = (doctor_usernames.size() - 1);

            doctor_homemenu();
        }

        void doctor_viewprofile()
        {
            cout << endl << "Name: " << doctor_names[doctor_index];
            cout << endl << "Phone Number: " << doctor_phone1s[doctor_index];
            cout << endl << "Alternate Phone Number: " << doctor_phone2s[doctor_index];
            cout << endl << "Mail: " << doctor_mails[doctor_index];
            cout << endl << "Address: " << doctor_addresses[doctor_index];
            cout << endl << "Blood Group: " << doctor_bloodgroups[doctor_index];
            cout << endl << "Citizen ID: " << doctor_citizenids[doctor_index];
            cout << endl << "NMC ID: " << doctor_nmcids[doctor_index];
            cout << endl << "Username: " << doctor_usernames[doctor_index] << endl;
        }

        void doctor_viewpatientsprofile()
        {
            int choice;
            while(1)
            {
                cout << endl << "Select a patient: " << endl;
                for(int i = 0; i < patient_names.size(); i++)
                {
                    cout << i + 1 << ". " << patient_names[i] << endl; 
                }
                cout << patient_names.size() + 1 << ". Exit" << endl;
                cout << "> ";
                cin >> choice;

                if(choice == patient_names.size() + 1)
                {
                    doctor_menu();
                }
                
                else if (choice != patient_names.size() + 1)
                {
                    long long a;
                    cout << endl << "Enter Patient's Unique Code to view profile: ";
                    cin >> a;
                    if (a == patient_uniquecodes[choice - 1])
                    {
                        cout << endl << "Name: " << patient_names[choice - 1];
                        cout << endl << "Phone Number: " << patient_phone1s[choice - 1];
                        cout << endl << "Alternate Phone Number: " << patient_phone2s[choice - 1];
                        cout << endl << "Mail: " << patient_mails[choice - 1];
                        cout << endl << "Address: " << patient_addresses[choice - 1];
                        cout << endl << "Blood Group: " << patient_bloodgroups[choice - 1];
                        cout << endl << "Citizen ID: " << patient_citizenids[choice - 1];
                        cout << endl << "Past Medical History: " << patient_pastmedicalhistories[choice - 1] << endl;
                    }
                    else
                    {
                        cout << endl << "You cannot view this profile." << endl;
                    }
                        
                }
                else
                {
                    doctor_menu();
                }
            }
        }
};

class admin : public doctor
{
    protected:
        string admin_hospitalname;
        string admin_username;
        string admin_password;
        long long admin_phone1;
        long long admin_phone2;  //phone2 or emergnecy home contact number
        string admin_mail;
        string admin_address;
        string admin_hospitalid;
        long long admin_uniquecode;
        
        vector <string> admin_names {"Apollo"};
        vector <string> admin_usernames {"apollo"};
        vector <string> admin_passwords {"apollo1"};
        vector <long long> admin_phone1s {9924492472};
        vector <long long> admin_phone2s {0}; //0 represnts phone number not provided.
        vector <string> admin_mails {"apollo.lavad@gmail.com"};
        vector <string> admin_addresses {"Near Rashtriya Raksha University, Lavad, Gandhinagar, Gujarat. - 382305"};
        vector <string> admin_hospitalids {"2343er", "4534ty"};
        vector <long long> admin_uniquecodes {33069, 33088};
        
    public:
        int admin_index;
        
        void admin_start()
        {
            admin_homemenu();
        }

        void admin_homemenu()
        {
            while(1)
            {
                string a;
                cout << endl << " ----------- ";
                cout << endl << "| Hello!    |";
                cout << endl << "| 1. Login  |";
                cout << endl << "| 2. Signup |";
                cout << endl << "| 3. Exit   |";
                cout << endl << " -----------" << endl;
                cout << "> ";
                cin >> a;

                if(a == "1")
                {
                    admin_login();
                }
                else if(a == "2")
                {
                    admin_signup();
                }
                else if(a == "3")
                {
                    cout << endl << "Exiting!" << endl << "Exited Succesfully!" << endl << endl;
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid Choice!" << endl;
                }
            }
            
        }

        void admin_menu()
            {
                while(1)
                {
                    string a;
                    cout << endl << " ----------------------------------- ";
                    cout << endl << "| 1. View your Profile              |";
                    cout << endl << "| 2. View your Patient's Profiles.  |";
                    cout << endl << "| 3. View your Doctor's Profiles.   |";
                    cout << endl << "| 4. View stock.                    |";
                    cout << endl << "| 5. Exit                           |";
                    cout << endl << " ----------------------------------- "<< endl;
                    cout << "> ";
                    cin >> a;

                    if(a == "1")
                    {
                        admin_viewprofile();
                    }
                    else if(a == "2")
                    {
                        admin_viewpatientsprofile();
                    }
                    else if(a == "3")
                    {
                        admin_viewdoctorsprofile();
                    }
                    
                    else if(a == "4")
                    {
                        admin_viewstock();
                    }
                    else if(a == "5")
                    {
                        cout << endl << "Exiting!" << endl << "Exited Succesfully!" << endl << endl;
                        exit(1);
                    }
                    else
                    {
                        cout << endl << "Invalid Choice!";
                    }
                }

            }

        void admin_login()
        {
            cout << endl <<  "Enter Username: ";
            cin >> admin_username;
            cout << "Enter Password: ";
            cin >> admin_password;
            int flag = 0;

            for(int i = 0; i < admin_usernames.size(); i++)
            {
                if(admin_username == admin_usernames[i] && admin_password == admin_passwords[i])
                {
                    cout << endl << "Login Successfull!" <<endl;
                    admin_index = i;
                    flag = 1;
                    admin_menu();
                }
            }

            if(flag == 0) 
            {
                cout << endl << "Invalid Credentials!" << endl;
                admin_homemenu();
            }
        }

        void admin_signup()
        {
            cout << endl << "Enter your Hospital Name: ";
            cin.ignore();
            getline(cin, admin_hospitalname);
            cout << "Enter your phone number: ";
            while (!(cin >> admin_phone1) || cin.peek() != '\n') 
            {
                cout << "Please enter a valid mobile number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter your alternate [Emergency] phone number: ";
            while (!(cin >> admin_phone2) || cin.peek() != '\n') 
            {
                cout << "Please enter a valid mobile number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter your mail Id: ";
            cin >> admin_mail;
            cout << "Address: ";
            cin.ignore();
            getline(cin, admin_address);
            cout << "Enter Hospital ID: ";
            cin >> admin_hospitalid;
            cout << "Enter a Username: ";
            cin >> admin_username;
            cout << "Enter password: ";
            cin >> admin_password;

            cout << endl << "Sign Up Succesfull!" << endl << "We will contact you soon to verify your hospital!" << endl;
            admin_index = (admin_usernames.size() - 1);
            
            admin_homemenu();
        }

        void admin_viewprofile()
        {
            cout << endl << "Name: " << admin_names[admin_index];
            cout << endl << "Phone Number: " << admin_phone1s[admin_index];
            cout << endl << "Alternate Phone Number: " << admin_phone2s[admin_index];
            cout << endl << "Mail: " << admin_mails[admin_index];
            cout << endl << "Address: " << admin_addresses[admin_index];
            cout << endl << "NMC ID: " << admin_hospitalids[admin_index];
            cout << endl << "Username: " << admin_usernames[admin_index] << endl;
        }

        void admin_viewpatientsprofile()
        {
            int choice;
            while(1)
            {
                cout << endl << "Select a patient: " << endl;
                for(int i = 0; i < patient_names.size(); i++)
                {
                    cout << i + 1 << ". " << patient_names[i] << endl; 
                }
                cout << patient_names.size() + 1 << ". Exit" << endl;
                cout << "> ";
                cin >> choice;

                if(choice == patient_names.size() + 1)
                {
                    admin_menu();
                }
                
                else if (choice != patient_names.size() + 1)
                {
                    cout << endl << "Name: " << patient_names[choice - 1];
                    cout << endl << "Phone Number: " << patient_phone1s[choice - 1];
                    cout << endl << "Alternate Phone Number: " << patient_phone2s[choice - 1];
                    cout << endl << "Mail: " << patient_mails[choice - 1];
                    cout << endl << "Address: " << patient_addresses[choice - 1];
                    cout << endl << "Blood Group: " << patient_bloodgroups[choice - 1];
                    cout << endl << "Citizen ID: " << patient_citizenids[choice - 1];
                    cout << endl << "Unique Code: " << patient_uniquecodes[choice - 1] << endl;
                }
                else
                {
                    admin_menu();
                }
            }
        }

        void admin_viewdoctorsprofile()
        {
            int choice;
            while(1)
            {
                cout << endl << "Select a doctor: " << endl;
                for(int i = 0; i < doctor_names.size(); i++)
                {
                    cout << i + 1 << ". " << doctor_names[i] << endl; 
                }
                cout << doctor_names.size() + 1 << ". Exit" << endl;
                cout << "> ";
                cin >> choice;

                if(choice == doctor_names.size() + 1)
                {
                    admin_menu();
                }
                
                else if (choice != doctor_names.size() + 1)
                {
                    cout << endl << "Name: " << doctor_names[choice - 1];
                    cout << endl << "Phone Number: " << doctor_phone1s[choice - 1];
                    cout << endl << "Alternate Phone Number: " << doctor_phone2s[choice - 1];
                    cout << endl << "Mail: " << doctor_mails[choice - 1];
                    cout << endl << "Address: " << doctor_addresses[choice - 1];
                    cout << endl << "Blood Group: " << doctor_bloodgroups[choice - 1];
                    cout << endl << "Citizen ID: " << doctor_citizenids[choice - 1];
                    cout << endl << "NMC ID: " << doctor_nmcids[choice - 1] << endl;
                }
                else
                {
                    admin_menu();
                }
            }

        }

        void admin_viewstock()
        {
            vector<string> stock_items;
            stock_items.push_back("Blood");
            stock_items.push_back("Bandages");
            stock_items.push_back("Gauze");
            stock_items.push_back("Saline Solution");
            stock_items.push_back("Pain Medication");
            stock_items.push_back("Sutures");  
            stock_items.push_back("IV Catheters");
            stock_items.push_back("Antiseptics");
            stock_items.push_back("Syringes");
            stock_items.push_back("Cotton Swabs");
            cout << endl << "Hospital Stock Items:" << endl;
            
            for (string item : stock_items) 
            {
                cout << "- " << item << endl;
            }
        }
};

int main()
{
    int choice;
    while (1)
    {
        string a;
        cout << endl << " ---------------- ";
        cout << endl << "|  Who are you?  |";
        cout << endl << "|  1. Pateint    |";
        cout << endl << "|  2. Doctor     |";
        cout << endl << "|  3. Admin      |";
        cout << endl << "|  4. Exit       |"; 
        cout << endl << " ---------------- "<<endl;
        cout << "> ";
        cin >> a;

        if (a == "1")
        {
            patient p1;
            p1.patient_start();
        }
        else if (a == "2")
        {
            doctor d1;
            d1.doctor_homemenu();
        }
        else if (a == "3")
        {
            admin a1;
            a1.admin_homemenu();
        }
        else if (a == "4")
        {
            cout << endl << "Exiting!" << endl << "Exited Succesfully!" << endl << endl;
            exit(1);
        }
        else
        {
            cout << endl << "Invalid Choice!" << endl;
        }
    }
}
