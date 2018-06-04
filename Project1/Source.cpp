#include "DateTime.h"
#include "bubbleSort.h"
#include "stack.h"
#include "stack.cpp"
#include <stack>

template <typename T>
void bubbleSortMethod(T *a, int size)
{
	int j;
	for (int i = 0; i < size; i++)
	{
		for (j = (size - 1); j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				T temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
		cout << a[j] << "\t";
	}
}


int main()
{
	setlocale(LC_ALL, "russian");
	short nz, answer;
	do
	{
		cout << "выберете задание:" << endl
			<< "1 - время и дата статическим методом" << endl
			<< "2 - шаблон функции bubbleSort" << endl
			<< "3,4 - шаблонный класс bubbleSort" << endl
			<< "5 - стек стеков" << endl
			<< "6 - слияние двух стеков возрастающей последовательности" << endl
			<< "7 - стеки символов" << endl
			<< "8 - задание со скобками" << endl
			<< "9 - очереди" << endl
			<< "0 - для выхода\n";
		cin >> nz;
		system("cls");

		switch (nz)
		{
		case 1:
		{
			DateTime d1;
			cout << "текущее время: ";
			d1.getCurrentDateTime();
			cout << endl;
		}break;

		case 2:
		{
			const int size = 5;
			double arr[size] = { 4.2,5.1,6.2,1.5,2.7 };
			for (int i = 0; i < size; i++)
				cout << arr[i] << "\t";
			cout << "\nпосле сортировки" << endl;
			bubbleSortMethod(arr, size);
			cout << endl;
		}break;

		case 3:
		{
			const int size = 5;
			int arr[size] = { 4,5,6,1,2 };
			for (int i = 0; i < size; i++)
				cout << arr[i] << "\t";
			cout << endl;
			cout << "\nпосле сортировки" << endl;
			bubbleSort<int>::sort(arr, size);
		}break;

		case 4:
		{
			const int size = 5;
			int arr[size] = { 4,5,6,1,2 };
			for (int i = 0; i < size; i++)
				cout << arr[i] << "\t";
			cout << endl;
			cout << "\nпосле сортировки" << endl;
			bubbleSort<int>::sort(arr, size);
		}break;

		case 5:
		{
			stack<stack<int>>s;
			stack<int>in_s;

			int a[9] = { 8,1,2,3,4,5,2,4,9 };
			s.push(in_s);
			s.top().push(a[0]);

			for (int i = 1; i < 9; i++)
			{
				if (s.top().top() < a[i])
					s.top().push(a[i]);
				else
				{
					stack<int>in_st;
					s.push(in_st);
					s.top().push(a[i]);
				}
			}

			while (!s.empty())
			{
				while (!s.top().empty())
				{
					cout << s.top().top() << "\t";
					s.top().pop();
				}
				cout << endl;
				s.pop();
			}
		}break;

		case 6:
		{
			int arr[5] = { 8, 3, 1, 4, 7 };
			Stack<int>s(arr, 3);
			int arr2[5] = { 8, 3, 1, 4, 7 };
			Stack<int>s2(arr, 3);
		
		}break;

		case 7:
		{
			char arr1[3] = { '!','@','%' };
			Stack<char>s1(arr1, 3);

			char arr2[4] = { '^','&','*','=' };
			Stack<char>s2(arr2, 4);

			int count = 0;
			while (!s1.empty())
			{
				cout << s1.top() << endl;
				s1.pop();
				count++;
			}
			cout << "кол-во символов в первом стеке: " << count << endl;


			count = 0;
			while (!s2.empty())
			{
				cout << s2.top() << endl;
				s2.pop();
				count++;
			}
			cout << "кол-во символов во втором стеке: " << count << endl;

		}break;

		case 8:
		{
			char s[] = ")this is {example} {[task]} for me [group]students";
			stack<char>s1; //()
			stack<char>s2; //[]
			stack<char>s3; //{}

			for (int i = 0; i < strlen(s); i++)
			{
				if (s[i] == '(')
					s1.push('(');
				else if (s[i] == '[')
					s2.push('[');
				else if (s[i] == '{')
					s3.push('{');
			
				else if (s[i] == ')')
				{
					if (!s1.empty())
						s1.pop();
					else
					{
						break;
						cout << "uncorrect brackets";
					}
				}

				else if (s[i] == ']')
				{
					if (!s2.empty())
						s2.pop();
					else
					{
						break;
						cout << "uncorrect brackets";
					}
				}

				else if (s[i] == '}')
				{
					if (!s3.empty())
						s3.pop();
					else
					{
						break;
						cout << "uncorrect brackets";
					}
				}

				
			}

			if (s1.empty() && s2.empty() && s3.empty())
				cout << "correct brackets";
			else
				cout << "uncorrect";
		}break;



		}

		cout << endl;
		cout << "хотите продолжить?1/0 ";
		cin >> answer;
		system("cls");
	} while (answer != 0);


	system("pause");
	return 0;
}