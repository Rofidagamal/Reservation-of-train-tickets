
#include<iostream>
using namespace std;

struct carriges
{
	int classes;
	double  price;
	int seats[30];

};
void menu()
{
	cout << "enter 1 to book a ticket" << endl;
	cout << "enter 2 to cancel a ticket" << endl;
	cout << "enter 3 to show avalibe seats" << endl;
	cout << "enter 4 to print profits in detail" << endl;
	cout << "enter 0 to exit" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}
void book(carriges arr[], int size, int &classes)
{

	int k = 0, t = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (arr[i].seats[j] == 0 && classes == arr[i].classes)
			{
				arr[i].seats[j] = 1;
				cout << "the seat of" << " " << j + 1 << " " << "of carrige" << " " << i + 1 << " " << "is recived" << endl;
				cout << "-----------------------------------------------------" << endl;
				return;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (arr[i].seats[j] == 1 && classes == arr[i].classes);

		}
		k++;
	}
	for (int i = 0; i < size; i++)
	{
		if (classes = arr[i].classes)
			t++;
	}
	if (k == t)
	{
		cout << "Sorry.. the required class is completed ..please choose a nother class  " << endl;
	}
	else
	{

	}

	cout << "--------------------------------------------------------------------------" << endl;


}

void cancel(carriges arr[], int carrige, int seats[], int seat)
{
	if (arr[carrige].seats[seat] == 1)
	{
		arr[carrige].seats[seat] = 0;
		cout << "the seat" << " " << seat + 1 << " " << "of the carrige" << " " << carrige + 1 << " " << "is canceled" << endl;
		cout << "--------------------------------------------------" << endl;
		return;
	}
	else

		return;

}
void availble(carriges arr[], int size)
{


	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < 30; j++)
		{

			if (arr[i].seats[j] == 0)
			{

				cout << "the seat of" << " " << j + 1 << " " << "of carrige" << " " << i + 1 << " " << "is avalible" << endl;
				cout << "---------------------------------------------------" << endl;

			}

		}


	}
}
void profit(carriges arr[], int size)
{
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		int sum = 0;
		for (int j = 0; j < 30; j++)
		{

			if (arr[i].seats[j] == 1)
			{
				sum += arr[i].price;
				c += arr[i].price;

			}

		}
		cout << "the class of the carrige" << " " << i + 1 << " : " << "is" << " " << arr[i].classes << endl;
		cout << "sum of tickets of carrige " << " " << i + 1 << " " << "had sold" << "  " << "is" << " " << sum / arr[i].price << endl;
		cout << "the sum of profits of the tickets had sold of carrige" << " " << i + 1 << " " << "is :" << " " << sum << endl;

		cout << "-------------------------------------------------------" << endl;

	}
	cout << "the sum of all profits of all carriges is" << " : " << c << endl;
	cout << "------------------------------------------------" << endl;

}
int main()
{
	int n;
	cout << "Please ,Enter the number of carriges of train : "  ;
	cin >> n;
	carriges *arr = new carriges[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Carrige#" << i + 1 << ":" << endl;
		cout << "Enter class" << ":" << " ";
		cin >> arr[i].classes;
		cout << "Enter price" << ":" << " ";
		cin >> arr[i].price;
		for (int j = 0; j < 30; j++)
			arr[i].seats[j] = 0;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	
	int choose;

	do
	{

		menu();
		cout << "Please,Enter the choose you want : "  ;
		cin >> choose;
		if (choose == 0)
		{
			break;
		}
		int t = 0;// t it is the condition if it used 

		switch (choose)
		{
		case 1:	cout << "your choose is" << " " << choose << endl;
			int cl;
			cout << "Please,Enter class you want to recieve in it " << " " << ":" ;
			cin >> cl;

			for (int i = 0; i < n; i++)
			{
				if (cl == arr[i].classes)
				{
					book(arr, n, cl);//cl is the reqired class
					t = 1;// t it is the condition if it used 
					break;
				}
			}
			if (t == 0)
			{
				cout << "The required class is not avalible in this train" << " " << "..Please enter another class" ;
			}


			break;
		case 2:cout << "your choose is" << " " << choose << endl;
			int carr_num, seat;//d the number of carrige and s the number of seat
			cout << "Please ,Enter the number of your ticket carrige : ";
			cin >> carr_num;
			cout << "Please ,Enter  second your ticket seat number to cancel it : ";
			cin >> seat;
			if ((carr_num > 0 && carr_num <= n) && (seat > 0 && seat <= 30))

			{
				cancel(arr, carr_num - 1, arr[carr_num - 1].seats, seat - 1);
			}
			else
			{
				cout << "Please,Try again and Enter the correct number of carrige and seat you want to cancel" << endl;
				cout << "-----------------------------------------------------------------------------" << endl;
			}
			break;
		case 3:cout << "your choose is " << " " << choose << endl;
			availble(arr, n);
			break;
		case 4: cout << "your choose is " << " " << choose << endl;
			profit(arr, n);
			break;
		default: cout << "Please,Try again and choose corrcet number from menu" << endl;
			cout << "---------------------------------------------------------" << endl;
			break;
		}

	} while (choose != 0);
	cout << "your choose is" << " " << choose << " " << ":" << " " << "exit" << endl;
	cout << "--------------------------------------------" << endl;

	delete[]arr;
	system("pause");


}

