//Create a patient management system in the polyclinic.Each patient has
//the program is assigned a random number.The system should contain the following
//functions.After calling each function, the time it takes should be displayed
//was performed The system should contain the following functions :
//1. Creation, reductionand expansion of the list of patients.
//2. Adding and removing a patient.
//3. QuickSort and BogoSort sorting to choose from.
//4. Patient search through binary and linear search.
//5. Insertion of the patient on a certain index.Implement it iteratively and
//recursively
//6. Finding the largest and smallest index.Implement iteratively
//and recursively.

#include <iostream>;


using namespace std;

void seen_mas(int Massiv[], int size_massiv, int col);
void swap(int Massiv[], int pos1, int pos2);
int partition(int Massiv[], int low, int high, int pivot);
void quickSort(int Massiv[], int low, int high);
int search(int Massiv[], int n, int x);
void del_pat(int Massiv[], int size_massiv);
void new_pat_id(int Massiv[], int size_massiv);
void max_and_min(int Massiv[], int size_massiv);

int main()
{ 
	int size_massiv = 0;
	int* Massiv = new int[size_massiv];
	bool check1 = true;
	int sel = 0;
	int id_patient = 0;
	int a = 0;
	int col = 0;

	cout << "Enter a size massive: ";
	cin >> size_massiv;
	while (check1)
	{
		cout << "Add id patient: ";
		cin >> id_patient;
		Massiv[a] = id_patient;
		a++;

		if (a == size_massiv)
		{
			check1 = false;
		}
	}
	seen_mas(Massiv, size_massiv, col);

	bool check2 = true;
	while (check2)
	{
		cout << endl;
		cout << "\tWelcome to Hospital." << endl << endl;
		cout << "Select a function: " << endl;
		cout << "1 - QuickSort.\n";
		cout << "2 - Patient lineary search.\n";
		cout << "3 - delete patient.\n";
		cout << "4 - Insertion of the patient on a certain index.\n";
		cout << "5 - Finding the largest and smallest index.Recursively.\n\n";
		cin >> sel;
		if (sel == 1)//quickSort
		{
			quickSort(Massiv, 0, size_massiv - 1);
			cout << "The sorted patients is: ";
			for (int i = 0; i < size_massiv; i++) {
				cout << Massiv[i] << " ";
			}
			check2 = false;
		}
		if (sel == 2)//lineary search;
		{
			cout << "Enter the ID of the patient you want to find: " << endl;
			int x;
			cin >> x;
			int n = sizeof(Massiv) / sizeof(Massiv[0]);

			int result = search(Massiv, n, x);
			(result == -1)
				? cout << "Element is not present in array"
				: cout << "Element is present at index " << result;
			return 0;
			check2 = false;
		}
		if (sel == 3)//delete patient
		{
			del_pat(Massiv, size_massiv);
			check2 = false;
		}
		if (sel == 4)// Insertion of the patient
		{
			new_pat_id(Massiv, size_massiv);
			check2 = false;
		}
		if (sel == 5)//Finding the largest and smallest index
		{
			max_and_min(Massiv, size_massiv);
			check2 = false;
		}
	}
}


void seen_mas(int Massiv[], int size_massiv, int col)
{
	if (col == size_massiv)
	{
		return;
	}
	cout << "Patient id: " << Massiv[col] << endl;
	col++;
	seen_mas(Massiv, size_massiv, col);
}

void max_and_min(int Massiv[], int size_massiv)
{
	int max = Massiv[0];
	for (int i = 0; i < size_massiv; i++)
	{
		if (Massiv[i] > max)
			max = Massiv[i];
	}
	cout << "Max id: " << max << endl;
	int min = Massiv[0];
	for (int i = 0; i < size_massiv; i++)
	{
		if (Massiv[i] < min)
			min = Massiv[i];
	}
	cout << "Min id: " << min << endl;
}

void new_pat_id(int Massiv[], int size_massiv)
{
	int index_pat;
	int new_pat;
	cout << "Enter index: " << endl;
	cin >> index_pat;
	cout << "Enter id new patient: " << endl;
	cin >> new_pat;

	int* nArr = new int[size_massiv + 1];

	for (int i = 0; i < index_pat; i++)
	{
		nArr[i] = Massiv[i];
	}

	nArr[index_pat] = new_pat;

	for (int i = index_pat + 1; i < size_massiv + 1; i++)
	{
		nArr[i] = Massiv[i - 1];
	}

	for (int i = 0; i < size_massiv + 1; i++)
	{
		cout << nArr[i] << ' ';
	}
	cout << endl;
}

void del_pat(int Massiv[], int size_massiv)
{
	int rem = 0;
	cout << "Press id patient from delete: ";
	cin >> rem;
	Massiv[rem] = 0;
	int size = size_massiv - 1;
	int* Temp_mas = new int[size];
	for (int i = 0, j = 0; i < size_massiv; i++)
	{
		if (Massiv[i] != 0)
		{
			Temp_mas[j] = Massiv[i];
			j++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << Temp_mas[i] << " ";
	}
	cout << endl;
}

void swap(int Massiv[], int pos1, int pos2) {
	int temp;
	temp = Massiv[pos1];
	Massiv[pos1] = Massiv[pos2];
	Massiv[pos2] = temp;
}

int partition(int Massiv[], int low, int high, int pivot) {
	int i = low;
	int j = low;
	while (i <= high) {
		if (Massiv[i] > pivot) {
			i++;
		}
		else {
			swap(Massiv, i, j);
			i++;
			j++;
		}
	}
	return j - 1;
}

void quickSort(int Massiv[], int low, int high) {
	if (low < high) {
		int pivot = Massiv[high];
		int pos = partition(Massiv, low, high, pivot);

		quickSort(Massiv, low, pos - 1);
		quickSort(Massiv, pos + 1, high);
	}
}

int search(int Massiv[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (Massiv[i] == x)
			return i;
	return -1;
}