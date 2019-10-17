#include <iostream>
#include <string>
using namespace std;
#include <iomanip>



struct listnode
{
	int empID;
	string name;
	string gender;
	string Address;
	int joineddate;
	int EPF;
	string EmplyoeeType;
	int salary;


	struct listnode *nextPtr;
};

typedef struct listnode EmpDetails;
typedef  EmpDetails*EmpDetailsPtr;

struct QueueNode
{
	int EmpID;
	string EmpName;
	int EPF;
	struct QueueNode *nextPtr;
};

typedef struct QueueNode RemovedEmp;
typedef RemovedEmp *QueueNodePtr;



void menu();
void Add();
EmpDetailsPtr Remove(EmpDetailsPtr *startPtr);
void Queue(QueueNodePtr *startPtr, QueueNodePtr *rPtr, int EmpID, string EmpName, int EPF);
void PrintRemovedEMP(QueueNodePtr headPtr);
int isEmpty(QueueNodePtr startPtr);
void givebonus(EmpDetailsPtr startPtr, int key);
void update(EmpDetailsPtr startPtr, int key);
void single(EmpDetailsPtr startPtr, int key);
void viewPart(EmpDetailsPtr startPtr);
void viewSal(EmpDetailsPtr startPtr);
void printlist(EmpDetailsPtr startPtr);
void promote(EmpDetailsPtr startPtr, int key);
bool searchlist(EmpDetailsPtr startPtr, int key);
void insert(EmpDetailsPtr *sPtr, int value, string name, string gender, string Address, int joineddate, int EPF, string EmplyoeeType, int salary);



int main()
{


	EmpDetailsPtr startPtr = NULL;
	QueueNodePtr rPtr = NULL;
	QueueNodePtr headPtr = NULL;


	int response = 0;
	int id;
	string name;
	string gender;
	string Address;
	int joineddate;
	int EPF;
	string EmplyoeeType;

	int salary;
	menu();
	cout << "Enter Response: ";
	cin >> response;

	while (response != 12)
	{


		switch (response)
		{
		case 1: cout << "===========================================================" << endl;
			cout << "                 ADD NEW EMPLOYEE                          " << endl;
			cout << "===========================================================" << endl;
			cout << "1)Enter EmplyoeeID:";
			cin >> id;
			if (searchlist(startPtr, id) == true)
			{

				break;
			}
			cout << "2)Enter Name:";
			cin.ignore();
			getline(cin, name);
			cout << "3)Enter Gender:";
			cin >> gender;
			cout << "4)Enter Address:";
			cin.ignore();
			getline(cin, Address);
			cout << "5)Enter JoinedDate:";
			cin >> joineddate;
			cout << "6)Enter EPF:";
			cin >> EPF;
			cout << "7)Enter EmplyoeeType:";
			cin.ignore();
			getline(cin, EmplyoeeType);
			cout << "8)Enter Salary:";
			cin >> salary;
			insert(&startPtr, id, name, gender, Address, joineddate, EPF, EmplyoeeType, salary);
			break;
		case 2:
			cout << "===========================================================" << endl;
			cout << "                 REMOVE EMPLOYEE                          " << endl;
			cout << "===========================================================" << endl;
			id = startPtr->empID;
			name = startPtr->name;
			EPF = startPtr->EPF;
			Remove(&startPtr);
			Queue(&headPtr, &rPtr, id, name, EPF);
			break;

		case 3:
			cout << "===========================================================" << endl;
			cout << "                 UPDATE EMPLOYEE                          " << endl;
			cout << "===========================================================" << endl;
			cout << "1)Enter EmplyoeeID:";
			cin >> id;
			update(startPtr, id);
			break;
		case 4:
			cout << "===========================================================" << endl;
			cout << "                 SINGLE EMPLOYEE DETAILS                         " << endl;
			cout << "===========================================================" << endl;
			cout << "1)Enter EmplyoeeID:";
			cin >> id;
			single(startPtr, id);
			break;
		case 5:
			printlist(startPtr);
			break;
		case 6:
			cout << "===========================================================" << endl;
			cout << "                 PROMOTE EMPLOYEE                          " << endl;
			cout << "===========================================================" << endl;
			cout << "1)Enter EmplyoeeID:";
			cin >> id;
			promote(startPtr, id);
			break;
		case 7:
			cout << "===========================================================" << endl;
			cout << "                 GIVE EMPLOYEE                          " << endl;
			cout << "===========================================================" << endl;
			cout << "1)Enter EmplyoeeID:";
			cin >> id;
			givebonus(startPtr, id);
			break;
		case 8:
			PrintRemovedEMP(headPtr);
			break;
		case 9:
			cout << "===========================================================" << endl;
			cout << "                     VIEW SALARY                          " << endl;
			cout << "===========================================================" << endl;
			viewSal(startPtr);
			break;
		case 10:
			cout << "===========================================================" << endl;
			cout << "                 VIEW PART-TIME EMPLOYEES                        " << endl;
			cout << "===========================================================" << endl;
			viewPart(startPtr);
			break;
		default:cout << "Invalid Choice.";
			break;
		}
		cout << "\n\n" << endl;
		menu();
		cout << "\nEnter Response: " << endl;
		cin >> response;

	}

}
//Main Menu.
void menu()
{

	cout << "==========================================\n"
		<< "                 MENU                      \n"
		<< "==========================================\n"
		<< " 1) Add Employee\n"
		<< " 2) Remove Employee\n"
		<< " 3) Update Employee Details\n"
		<< " 4)View Details of a Single Employee\n"
		<< " 5)View Details of All Employees\n"
		<< " 6)Promote Employee\n"
		<< " 7)Give Bonus\n"
		<< " 8)View Removed Employees\n"
		<< " 9)View Salary of Employees\n"
		<< " 10)View Part Time Employees\n";
}
//SearchList function. 
bool searchlist(EmpDetailsPtr startPtr, int key)
{
	while (startPtr != NULL)
	{
		if (startPtr->empID == key)
		{
			cout << "ID found\n";
			return true;
		}
		startPtr = startPtr->nextPtr;
	}
	cout << "ID not found\n";
}
//Insert New Employee.
void insert(EmpDetailsPtr *sPtr, int value, string name, string gender, string Address, int joineddate, int EPF, string EmplyoeeType, int salary)
{
	EmpDetailsPtr newPtr = NULL;
	EmpDetailsPtr previousPtr = NULL;
	EmpDetailsPtr currentPtr = NULL;

	newPtr = new EmpDetails;

	if (newPtr != NULL)
	{
		newPtr->empID = value;
		newPtr->name = name;
		newPtr->gender = gender;
		newPtr->Address = Address;
		newPtr->joineddate = joineddate;
		newPtr->EPF = EPF;
		newPtr->EmplyoeeType = EmplyoeeType;
		newPtr->salary = salary;
		newPtr->nextPtr = NULL;
		previousPtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr != NULL && value>currentPtr->empID)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (previousPtr == NULL)
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else
	{
		cout << "not inserted. No memory available.\n" << value;
	}


}
//Remove Employee.
EmpDetailsPtr Remove(EmpDetailsPtr *startPtr)
{
	int key = 0;
	{
		cout << "Enter Employee ID: \n";
		cin >> key;
		EmpDetailsPtr previousPtr = NULL;
		EmpDetailsPtr currentPtr = NULL;
		EmpDetailsPtr tempPtr = NULL;

		if (key == (*startPtr)->empID)
		{
			tempPtr = *startPtr;
			*startPtr = (*startPtr)->nextPtr;
			return tempPtr;
			delete(tempPtr);
			cout << "Employee Successfully Deleted\n";
		}
		else
		{
			previousPtr = *startPtr;
			currentPtr = (*startPtr)->nextPtr;

			while (currentPtr != NULL && currentPtr->empID != key)
			{
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
			}
			if (currentPtr != NULL)
			{
				tempPtr = currentPtr;
				previousPtr->nextPtr = currentPtr->nextPtr;
				return tempPtr;
				delete(tempPtr);
				cout << "Employee Successfully Deleted\n";
			}

		}
	}



}
//Update Employee Information.
void update(EmpDetailsPtr startPtr, int key)
{
	int response;
	string EmpType;
	int Sal;
	string address;

	while (startPtr != NULL)
	{
		if (startPtr->empID == key)
		{
			cout << "ID found\n";
			cout << "Select 1 to update Address.\n"
				"Select 2 to update Employee Type\n"
				"Select 3 to update Salary\n";
			cout << "Enter your choice: \n";
			cin >> response;

			switch (response)
			{
			case 1:cout << "Employee Address: ";
				cin.ignore();
				getline(cin, address);
				startPtr->Address = address;
				cout << "Address updated\n";
				break;

			case 2:
				do
				{
					cout << "Enter Employee Type\n";
					cin >> EmpType;
					if (EmpType != "PartTime" && EmpType != "Permenent")
					{
						cout << "Invalid Type\n";
					}

				} while (EmpType != "PartTime" && EmpType != "Permenent");
				startPtr->EmplyoeeType = EmpType;
				cout << "Employee Type Successfully Updated\n";
				break;
			case 3:
				do
				{
					cout << "Enter Employee Salary\n";
					cin >> Sal;
					if (Sal <= startPtr->salary)
					{
						cout << "New Salary should be greater than the previous\n";
					}
				} while (Sal <= startPtr->salary);
				startPtr->salary = Sal;
				cout << "Employee Salary Successfully Updated\n";
				break;


			default:
				cout << "You have entered an Invalid Choice\n";
				break;


			}
			return;
		}
		startPtr = startPtr->nextPtr;

	}
}
//View single employees.
void single(EmpDetailsPtr startPtr, int key)
{
	while (startPtr != NULL)
	{
		if (startPtr->empID == key)
		{
			cout << "1)Employee ID :" << startPtr->empID << endl;
			cout << "2)Employee Name: " << startPtr->name << endl;
			cout << "3)Gender: " << startPtr->gender << endl;
			cout << "4)Address: " << startPtr->Address << endl;
			cout << "5)Joined Date: " << startPtr->joineddate << endl;
			cout << "6)EPF Number: " << startPtr->EPF << endl;
			cout << "7)Employee Type: " << startPtr->EmplyoeeType << endl;
			cout << "8)Salary: " << startPtr->salary << endl;

			return;


		}
		else
		{
			cout << "ID not found\n";
			

		}
		startPtr = startPtr->nextPtr;
	}
}

//Printing all Employee Details.
void printlist(EmpDetailsPtr startPtr)
{
	if (startPtr == NULL)
	{
		cout << "The List is Empty\n";
	}
	else
	{
		cout << "Printing all Employee Details\n";
		while (startPtr != NULL)
		{
			cout << "Employee ID :" << startPtr->empID << endl;
			cout << "Employee Name: " << startPtr->name << endl;
			cout << "Gender: " << startPtr->gender << endl;
			cout << "Address: " << startPtr->Address << endl;
			cout << "Joined Date: " << startPtr->joineddate << endl;
			cout << "EPF Number: " << startPtr->EPF << endl;
			cout << "Employee Type: " << startPtr->EmplyoeeType << endl;
			cout << "Salary: " << startPtr->salary << endl;

			startPtr = startPtr->nextPtr;
		}
	}
}
//Promoting all Part Time Employees
void promote(EmpDetailsPtr startPtr, int key)
{
	int y;
	y = 2018 - (startPtr->joineddate);
	while (startPtr != NULL)
	{
		if (startPtr->empID == key)
		{
			cout << "Employee ID Found\n";
			if (startPtr->EmplyoeeType == "PartTime"&&y>3)
			{
				startPtr->EmplyoeeType = "Permanent";
				startPtr->salary = (startPtr->salary) * 10 / 100 + (startPtr->salary);
				cout << "Employee Promoted Successfully\n";
				return;
			}
			else
			{
				cout << "This Employee is Already Promoted\n";
				return;
			}
		}

		startPtr = startPtr->nextPtr;
	}
}
//Giving bonus to employees.
void givebonus(EmpDetailsPtr startPtr, int key)
{
	int bonus;
	while (startPtr != NULL)
	{
		if (startPtr->empID == key)
		{
			cout << "Employee ID found\n";

			cout << "Please Enter bonus percentage: ";
			cin >> bonus;
			startPtr->salary = (startPtr->salary)*(bonus) / 100 + (startPtr->salary);
			return;
		}
		startPtr = startPtr->nextPtr;
	}
	cout << "Employee ID not found\n";
}

//View salary of all employees
void viewSal(EmpDetailsPtr startPtr)
{
	if (startPtr == NULL)
	{
		cout << "No Employees in the list.\n";
	}
	else
	{
		cout << "Printing all Employee Salary Details\n";
		while (startPtr != NULL)
		{
			cout << "Employee ID :" << startPtr->empID << endl;
			cout << "Employee Name: " << startPtr->name << endl;
			cout << "Salary: " << startPtr->salary << endl;

			startPtr = startPtr->nextPtr;
		}
	}
}
//View all Part Time Employees.
void viewPart(EmpDetailsPtr startPtr)
{
	string PartTime;
	if (startPtr == NULL)
	{
		cout << "Employee List is Empty\n";
	}
	else
	{
		cout << "Printing all Employee Details\n";
		while (startPtr != NULL)
		{
			if (startPtr->EmplyoeeType == "PartTime")
			{
				cout << "Employee ID :" << startPtr->empID << endl;
				cout << "Employee Name: " << startPtr->name << endl;
				cout << "EPF Number: " << startPtr->EPF << endl;
			}
			startPtr = startPtr->nextPtr;

		}
	}
}
void Queue(QueueNodePtr *startPtr, QueueNodePtr *rPtr, int EmpID, string EmpName, int EPF)
{
	QueueNodePtr newPtr;
	newPtr = new RemovedEmp;
	if (newPtr != NULL)
	{
		newPtr->EmpID = EmpID;
		newPtr->EmpName = EmpName;
		newPtr->EPF = EPF;
		newPtr->nextPtr = NULL;

		if (isEmpty(*startPtr))
		{
			*startPtr = newPtr;
		}
		else
		{
			(*rPtr)->nextPtr = newPtr;
		}
		*rPtr = newPtr;
	}
}
int isEmpty(QueueNodePtr startPtr)
{
	return startPtr == NULL;
}
//View Removed.
void PrintRemovedEMP(QueueNodePtr headPtr)
{
	if (headPtr == NULL)
	{
		cout << "There No Deleted Employees to Display\n";
	}
	else
	{
		cout << "Displaying All Deleted Employees\n";
		while (headPtr != NULL)
		{
			cout << "Employee ID: \n" << headPtr->EmpID << endl;
			cout << "Employee Name: \n" << headPtr->EmpName << endl;
			cout << "EPF: \n" << headPtr->EPF << endl;
			headPtr = headPtr->nextPtr;
		}
	}
}
