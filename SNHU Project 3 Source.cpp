#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

// clean 
delete[] procname;
delete[] paramval;


return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


int main()
{
	/*
	CallProcedure("printsomething");
	cout << callIntFunc("PrintMe", "House") << endl;
	cout << callIntFunc("SquareValue", 2);
	*/
	while (1) {
		char input[2];
		string userWord;


		// Display menu is output, then asks for user input.
		cout << "--Corner Grocer Menu--" << endl;
		cout << "1: List all items purchased: Organized by quantity." << endl;
		cout << "2: Search for how many times an item was purchased." << endl;
		cout << "3: Display histogram of items purchased." << endl;
		cout << "4: Exit Program" << endl;
		cout << "Please choose an option from 1 - 4." << endl;
		cin >> input;

		if (input[0] == '1') {
			CallProcedure("DisplayOccurence"); //Calls function from Python to display the occurance of purchased items
			cout << endl;
		}
		else if (input[0] == '2') {
			cout << "Please enter specific word for the item you are searching for: "; // Prompts user for input into userWord, then sets it to be lowercase.
			cin >> userWord;
			transform(userWord.begin(), userWord.end(), userWord.begin(), tolower);
			if (callIntFunc("SearchItem", userWord) <= 0) { //If the returned number of occurences is less than or equal to 0, it will inform user no item found and to try again.
				cout << "Item not found, try again." << endl;
			}
			else { // Else statement to print out the item and how many times it occured. (I was prompted to only return the amount, but I decided to do so in a sentence)
				cout << "The item " << userWord << " was purchased " << callIntFunc("SearchItem", userWord) << " times." << endl;
			}
		}
		else if (input[0] == '3') {
			CallProcedure("WriteToFile"); // Calls function from python to read the DataInput, count its occurances and store to a file
			cout << "Histogram of purchased items:" << endl;
			string wordName[50];
			string frequency[50]; // I made this a string, despite being a number for easier altering of number to character lines.
			int size = 0;

			ifstream ReadFile("frequency.dat"); //Opens file created by python

			while (ReadFile >> wordName[size] >> frequency[size]) { // While readfile is open, puts input up to first space or new line to wordName, and frequency
				size++;
		}
			
			ReadFile.close();
			for (int i = 0; i < size; i++) // For loop to iterate through all frequencies and replace the number with the same count of *. So if frequency is 5, it will replace and produce 5 *'s
				if (frequency[i] == "1") { // While mildly tedious and bulky, it does get the job done. This could perhaps be a function, but due to time constraints I decided to leave it here.
					frequency[i] = "*";
				}
				else if (frequency[i] == "2") {
					frequency[i] = "**";
				}
				else if (frequency[i] == "3") {
					frequency[i] = "***";
				}
				else if (frequency[i] == "4") {
					frequency[i] = "****";
				}
				else if (frequency[i] == "5") {
					frequency[i] = "*****";
				}
				else if (frequency[i] == "6") {
					frequency[i] = "******";
				}
				else if (frequency[i] == "7") {
					frequency[i] = "*******";
				}
				else if (frequency[i] == "8") {
					frequency[i] = "********";
				}
				else if (frequency[i] == "9") {
					frequency[i] = "*********";
				}
				else if (frequency[i] >= "10") { // Set to be if greater or equal to 10, will produce 10. As more than that is not necessary in this scope.
					frequency[i] = "**********";
				}

			for (int i = 0; i < size; i++) { // Output the wordname and altered frequency
				cout << wordName[i] << " " << frequency[i] << endl;
			}

		}
		else if (input[0] == '4') {
			cout << "Exiting program. . . \n";
			return 0;
		}
		else {  //User validation check, if not 1 through 4 it will request another input.
			cout << "Invalid Input: Try again. . . \n\n";
		}
	}
}
