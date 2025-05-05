 #include<iostream>
#include<windows.h>
#include<unistd.h>
#include<fstream>
using namespace std;
const int a=100;
bool performLogin(); 
bool adminperformLogin(); 
void Header();
void menu();
int opt,rec;
int Main_Menu();
void Add_Std_Record();
void View_Std_Record();
void Delete_Record();
void Update_Record();
void preference();
void logout();
    string std_Name[a];
    int Roll_Num[a];
    int Matric_Marks[a];
    int Fsc_Marks[a];
    int Ecat_Marks[a];
    float aggregate[a];
    int studentcount=0;
    float Total_Aggr;
    int studentnum;
    string pref[3];
    fstream record;
int main()
{
	menu();
	cout<<"Enter Your Option:";
	cin>>opt;
	if(opt==1)
	{
			bool login=adminperformLogin();
	if (!login) {
        cout << "Exiting the program due to unsuccessful login." << endl;
        return 1;
    }
        	int opt =-1;
	do{
		
	system("cls");
	Header();	
	opt = Main_Menu();
	switch (opt)
	{	
	case 1:
     Add_Std_Record();
    break;
    Main_Menu();
	case 2:
	View_Std_Record();
	break;
	case 3:
	Delete_Record();
	break;
	case 4:
	Update_Record();	
	break;
	case 5:
		system("cls");
	logout();
	break;
    }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    } while (opt != 6);
    return 0;
    }
	if(opt==2)
	{
	bool login=performLogin();
	if (!login) {
        cout << "Exiting the program due to unsuccessful login." << endl;
        return 1;
    }
    else
    {
    	cout<<"Enter 1 to see Record:";
    	cin>>rec;
    	if(rec==1)
    	{
    		View_Std_Record();
		}
		else
		{
			cout<<"Please Enter correct Option";
			return 1;
		}
	}
    }
    logout();

    return 0;
}
//................... Logo Of Project...............
void Header()
{
	cout<<"*******************************************************************************\n";
	cout<<"*************University Admission Management System (UAMS)*********************\n";
	cout<<"*******************************************************************************\n";
}
//................... Main Menu ...............
int Main_Menu()
{
	int choice = -1;
	cout<<"-----------------------------------------------\n";
	cout<<"-----------------Main Menu---------------------\n";
	cout<<"1- Add  Student                               #\n";
	cout<<"2- View Record                                #\n";
	cout<<"3- Delete Record                              #\n";
	cout<<"4- Update Record                              #\n";
	cout<<"5- Logout                                     #\n";
	cout<<"6- Exit/Terminate program                     #\n";
	cout<<"----------------------------------------------- \n";
	cout<<"Choose option from menu press 1 for add 2 for view and so on..."<<endl;
	cout<<"Enter your option = ";
	cin>>choice;
	
	return choice;
}
//................... Students Record...............
void Add_Std_Record()
{
	cout<<"Enter number of student you want to add=";
	cin>>studentnum;
	system("CLS");
	Header();
	for(int i=0;i<studentnum;i++)
	{
	cout<<"------------------------------------------------ \n";
	cout<<"Add Student Record...\n";
	cin.ignore();
	cout<<"Enter Name of Student = ";
	getline(cin, std_Name[studentcount]);
	cout<<"Enter your Roll number las digits = ";
	cin>>Roll_Num[studentcount];
	cin.ignore();
	preference();
	cout<<"Enter 1st Preference:";
	getline(cin,pref[0]);
	cout<<"Enter 2nd Preference:";
	getline(cin,pref[1]);
	cout<<"Enter 3rd Prefernce:";
	getline(cin,pref[2]);
	cout<<"****************************"<<endl;
	cout<<"#  Aggregate Calculation   #"<<endl;
	cout<<"****************************"<<endl;
	cout<<"Enter Matric Marks = ";
	cin>>Matric_Marks[studentcount];
	cout<<"Enter F.Sc Marks = ";
	cin>>Fsc_Marks[studentcount];
	cout<<"Enter ECAT Test Marks = ";
	cin>>Ecat_Marks[studentcount];
	aggregate[studentcount]=((Matric_Marks[studentcount]*25)/1100)+((Fsc_Marks[studentcount]*45)/1100)+((Ecat_Marks[studentcount]*33)/400);
	cout<<"Aggregate of first student is="<<aggregate[studentcount]<<endl;
	if(aggregate[studentcount]>=75)
	{
		cout<<"You are selected in Computer Science."<<endl;
	}
	else if(aggregate[studentcount]>=70)
	{
		cout<<"You are slected in Electrical Engineering."<<endl;
	}
	else if(aggregate[studentcount]>=65)
	{
		cout<<"You are selected in Chemical Engineering."<<endl;
	}
	studentcount++;
}
//........................File Handling.....................................
	record.open("student.txt",ios::app);
	for(int i=0;i<studentnum;i++)
	{	
		record<<std_Name[i]<<",";
		record<<Roll_Num[i]<<",";
		record<<Matric_Marks[i]<<",";
		record<<Fsc_Marks[i]<<",";
		record<<Ecat_Marks[i]<<",";
		record<<aggregate[i]<<"\n";	
	}
    record.close();
}
//..........................View Record................................
void View_Std_Record()
{
	cout<<"Following Students exist in record"<<endl;
	cout<<"Name"<<"\t"<<"Roll Number"<<"\t"<<"Matric"<<"\t"<<"Intermediate"<<"\t"<<"Ecat"<<"\t"<<"Aggregate"<<endl;
	for(int i=0;i<studentcount;i++)
	{
	cout<<std_Name[i]<<"\t"<<Roll_Num[i]<<"\t\t"<<Matric_Marks[i]<<"\t"<<Fsc_Marks[i]<<"\t\t"<<Ecat_Marks[i]<<"\t"<<aggregate[i]<<endl;
    }  
}
//............................Perform Login............................
bool performLogin() 
{
    string username, password;
    const string correctUsername = "ali";
    const string correctPassword = "123";

    cout << "Welcome to the Login Screen!" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        cout << "Login successful. Welcome, " << username << "!" << endl;
        Sleep(1000);
        return true;
    } else {
        cout << "Login failed. Incorrect username or password." << endl;
        Sleep(1000);
        return false; 
    } 
}
//..........................Delete Record..............................
void Delete_Record()
{
    int Delete;
    cout << "Enter Roll number of the student to delete: ";
    cin >> Delete;
    for (int i = 0; i < studentcount; ++i)
    {
        if (Delete == Roll_Num[i])
        {
            for (int j = i; j < studentcount - 1; ++j)
            {
                std_Name[j] = std_Name[j + 1];
                Roll_Num[j] = Roll_Num[j + 1];
                Matric_Marks[j] = Matric_Marks[j + 1];
                Fsc_Marks[j] = Fsc_Marks[j + 1];
                Ecat_Marks[j] = Ecat_Marks[j + 1];
                aggregate[j] = aggregate[j + 1];
            }

            // Clear the last record
            std_Name[studentcount - 1].clear();
            Roll_Num[studentcount - 1] = 0;
            Matric_Marks[studentcount - 1] = 0;
            Fsc_Marks[studentcount - 1] = 0;
            Ecat_Marks[studentcount - 1] = 0;
            aggregate[studentcount - 1] = 0;

            cout << "Record Deleted Successfully" << endl;
            studentcount--;
            return;
        }
    }
    record.open("student.txt",ios::out);
    for(int i=0;i<studentcount;i++)
    {
    	record<<std_Name[i]<<",";
		record<<Roll_Num[i]<<",";
		record<<Matric_Marks[i]<<",";
		record<<Fsc_Marks[i]<<",";
		record<<Ecat_Marks[i]<<",";
		record<<aggregate[i]<<"\n";
	}
	record.close();
    cout << "Please Enter correct Roll Number" << endl;
}
//.........................Update Record................................
void Update_Record()
{
    int rollno;
    cout << "Enter Roll Number of student to Update Record:";
    cin >> rollno;

    // Read existing records from the file
    record.open("student.txt", ios::in);
    if (!record.is_open())
    {
        cout << "Error opening the file for reading." << endl;
        return;
    }

    // Temporary variables to store values read from the file
    string tempName;
    int tempRoll, tempMatric, tempFsc, tempEcat;
    float tempAggregate;

    for (int i = 0; i < studentnum; i++)
    {
        record >> tempName;
        record >> tempRoll;
        record >> tempMatric;
        record >> tempFsc;
        record >> tempEcat;
        record >> tempAggregate;

        // If the Roll_Num matches, update the record in memory
        if (Roll_Num[i] == rollno)
        {
            cout << "Entered Updated Matric Marks:";
            cin >> Matric_Marks[i];
            cout << "Entered Updated Fsc Marks:";
            cin >> Fsc_Marks[i];
            cout << "Entered Updated Ecat Marks:";
            cin >> Ecat_Marks[i];
            aggregate[i] = ((Matric_Marks[i] * 25) / 1100) + ((Fsc_Marks[i] * 45) / 1100) + ((Ecat_Marks[i] * 33) / 400);
            cout << "Updated Aggregate of student is=" << aggregate[i] << endl;
            cout << "Record Updated Successfully" << endl;
        }
    }

    record.close();

    // Write the updated records back to the file
    record.open("student.txt", ios::out);
    if (!record.is_open())
    {
        cout << "Error opening the file for writing." << endl;
        return;
    }

    for (int i = 0; i < studentnum; i++)
    {
        record << std_Name[i] << ",";
        record << Roll_Num[i] << ",";
        record << Matric_Marks[i] << ",";
        record << Fsc_Marks[i] << ",";
        record << Ecat_Marks[i] << ",";
        record << aggregate[i] << "\n";
    }

    record.close();
}


//...................Login Interface.........................
void menu()
{
	cout<<"............."<<endl;
	cout<<"1.Admin"<<endl;
	cout<<"2.User"<<endl;
	cout<<"............."<<endl;
}
bool adminperformLogin() 
{
    string username, password;
    const string correctUsername = "admin";
    const string correctPassword = "123";

    cout << "Welcome to the Login Screen!" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        cout << "Login successful. Welcome, " << username << "!" << endl;
        Sleep(1000);
        return true;
    } else {
        cout << "Login failed. Incorrect username or password." << endl;
        Sleep(1000);
        return false; 
    } 
}
void preference()
{
	cout<<"        Preference List"<<endl;
	cout<<"*********************************"<<endl;
	cout<<"1.Computer Science"<<endl;
	cout<<"2.Electrical Engineering"<<endl;
	cout<<"3.Chemical Engineering"<<endl;
	cout<<"*********************************"<<endl;
}
void logout()
{
    menu();
    cout << "Enter Your Option:";
    cin >> opt;

    if (opt == 1)
    {
        bool login = adminperformLogin();
        if (!login)
        {
            cout << "Exiting the program due to unsuccessful login." << endl;
            exit(0); // Terminate the program
        }

        int opt = -1;
        do
        {
            system("cls");
            Header();
            opt = Main_Menu();
            switch (opt)
            {
            case 1:
                Add_Std_Record();
                break;
            case 2:
                View_Std_Record();
                break;
            case 3:
                Delete_Record();
                break;
            case 4:
                Update_Record();
                break;
            case 5:
                logout();
                break;
            }
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        } while (opt != 6);
    }
    else if (opt == 2)
    {
        bool login = performLogin();
        if (!login)
        {
            cout << "Exiting the program due to unsuccessful login." << endl;
            exit(0); // Terminate the program
        }
        else
        {
            cout << "Enter 1 to see Record:";
            cin >> rec;
            if (rec == 1)
            {
                View_Std_Record();
            }
            else
            {
                cout << "Please Enter correct Option";
                exit(0); // Terminate the program
            }
        }
    }
    exit(0); // Terminate the program
}
