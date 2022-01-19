#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <stdlib.h>

using namespace std;
/// ///////////////////////////////////////////////////////////////////////

class ListNode {
public:
	ListNode(char a = 'O', int b = 0, int c = 0, ListNode* link_ = NULL)
	{
		monitor_state = a;
		real_state = b;
		surround_state = c;
		link = link_;
	};

	char monitor_state;
	int real_state;
	int surround_state;
	ListNode* link;
};


class List {
public:
	List(int lengthx_, int lengthy_, int b, int h) { first = NULL; length_x = lengthx_; length_y = lengthy_; bomb = b; hint = h;};
	void Surround_add(int x, int y);
	void Make_Map();
	void Destruct_Map();
	void Place_bomb();
	void Print_map();
	int Mark(int x, int y);
	int Hint(int x, int y);
	int Open(int x, int y);
	int Is_Success();

private:
	ListNode* first;
	int length_x;
	int length_y;
	int bomb;
	int hint;
};

int List::Is_Success() {
	if (bomb != 0) return 0;
	else {
		stack<int> real;
		stack<int> monitor;
		ListNode* temp = first;
		for (int i = 0; i < length_x * length_y; i++) {
			if (temp->real_state == 1)real.push(i);
			if (temp->monitor_state == 'm') monitor.push(i);
			temp = temp->link;
		}
		int idx = real.size();
		for (int i = 0; i < idx; i++) {
			cout << real.top() << endl;
			cout << monitor.top() << endl;
			if (real.top() != monitor.top()) return 0;
			real.pop();
			monitor.pop();
		}
		this->Print_map();
		cout << "Success!" << endl;
		return 1;
	}
}

void List::Surround_add(int x, int y) {

	if (x <= 0 || y <= 0 || x > length_x || y > length_y) return;
	ListNode* temp = first;
	for (int i = 1; i < (x + (y - 1) * length_x); i++) {
		temp = temp->link;
	}
	temp->surround_state = temp->surround_state + 1;
	
}

void List::Make_Map() {

	ListNode* node = new ListNode;
	node->link = NULL;
	first = node;
	ListNode* temp = first;

	for (int i = 1; i < (length_x * length_y); i++) {
		ListNode* node = new ListNode;
		node->link = NULL;
		temp->link = node;
		temp = node;
	}

};

void List::Place_bomb() {
	int* array = new int[bomb];
	for (int i = 0; i < bomb; i++) {
		array[i] = -1;
	}

	srand(time(0));
	for (int i = 0; i < bomb; i++) {
		int number = rand () % (length_x * length_y);
		array[i] = number;

		for (int k = 0; k < i; k++) {
			if (array[k] == number) {
				array[i] = -1;
				i--;
				break;
			}
		}
		
	}


	for (int i = 0; i < bomb; i++) {
		int number = array[i];
		int k;

		ListNode* temp = first;
		ListNode* ind = first;

		for (k = 0; k < number; k++) {
			temp = temp->link;
		}

		temp->real_state = 1;

		int x = k % length_x + 1;
		int y = k / length_x + 1;

		this->Surround_add(x-1,y-1);
		this->Surround_add(x, y-1);
		this->Surround_add(x+1,y-1);
		this->Surround_add(x-1,y);
		this->Surround_add(x+1,y);
		this->Surround_add(x-1,y+1);
		this->Surround_add(x,y+1);
		this->Surround_add(x+1,y+1);

	}
	delete[] array;
}

void List::Print_map() {
	system("cls");
	ListNode* temp = first;

	cout << "Bombs left = " << bomb << ", " << "Hints left = " << hint << endl;
	for (int i = 0; i<length_x; i++) {
		cout << "---";
	}
	cout << endl;

	cout << "   ";
	for (int i = 1; i <= length_x; i++) {
		cout << i << "  ";
	}
	cout << endl;

	for (int i = 1; i <= length_y; i++) {
		cout << i;
		for (int k = 0; k < length_x; k++) {
			cout << "  " << temp->monitor_state;
			temp = temp->link;
		}
		cout << endl;
	}

	for (int i = 0; i < length_x; i++) {
		cout << "---";
	}
	cout << endl;
	
}

int List::Mark(int x, int y) {
	int j = 0;
	ListNode* temp = first;
	for (int i = 1; i < (x + (y-1)*length_x); i++) {
		temp = temp->link;
	}
	if (temp->monitor_state == 'O') {
		temp->monitor_state = 'm';
		bomb--;
	}
	else if (temp->monitor_state == 'm') {
		temp->monitor_state = 'O';
		bomb++;
	}

	else {
		cout << "Cannot mark this place." << endl;
		//Sleep(1000);
	}

	return this->Is_Success();
}

int List::Hint(int x, int y) {
	ListNode* temp = first;
	for (int i = 1; i < (x + (y - 1) * length_x); i++) {
		temp = temp->link;
	}

	if (temp->real_state == 1 && temp->monitor_state == 'O') {
		hint--;
		return this->Mark(x, y);
		
	}

	else if (temp->real_state == 1 && temp->monitor_state == 'm') {
		hint--;
	}

	else if (temp->real_state == 0 && temp->monitor_state == 'O') {
		hint--;
		this->Open(x, y);
	}

	else if (temp->real_state == 0 && temp->monitor_state == 'm') {
		hint--;
		temp->monitor_state = 'O';
		this->Open(x, y);
	}

	else {
		cout << "Cannot open already opened place" << endl;
		//Sleep(1000);
	}

	return 0;
}

int List::Open(int x, int y) {
	if (x <= 0 || y <= 0 || x > length_x || y > length_y) return 0;
	ListNode* temp = first;
	for (int i = 1; i < (x + (y - 1) * length_x); i++) {
		temp = temp->link;
	}

	if (temp->monitor_state == 'O' && temp->real_state == 1) {
		temp = first;
		for (int i = 0; i < (length_x * length_y); i++) {
			if (temp->real_state == 1) temp->monitor_state = 'B';
			temp = temp->link;
		}
		this->Print_map();
		return 1;
	}

	else if (temp->monitor_state == 'O' && temp->real_state == 0) {
		if (temp->surround_state == 0) {
			temp->monitor_state = 'X';
			this->Open(x - 1, y - 1);
			this->Open(x , y - 1);
			this->Open(x + 1, y - 1);
			this->Open(x - 1, y );
			this->Open(x + 1, y );
			this->Open(x - 1, y + 1);
			this->Open(x , y + 1);
			this->Open(x + 1, y + 1);
		}
		else {
			temp->monitor_state = temp->surround_state + 48;
		}
	}
}

void List::Destruct_Map() {
	ListNode* temp = first;
	while (temp != NULL) {
		first = temp->link;
		delete temp;
		temp = first;
	}
}

/// ///////////////////////////////////////////////////////////////////////

int main()
{
	int x, y, b, h;
	int x_idx, y_idx;
	int t = 0;
	char c;

	while (1) {
		cout << "size (x) : ";
		cin >> x;
		if (x <= 0) {
			cout << "Invalid x value" << endl;
			//Sleep(1000);
			system("cls");
			continue;
		}
		cout << "size (y) : ";
		cin >> y;
		if (y <= 0) {
			cout << "Invalid y value" << endl;
			//Sleep(1000);
			system("cls");
			continue;
		}
		cout << "Total number of bombs : ";
		cin >> b;
		if (b < 0 || b >(x*y)) {
			cout << "Invalid bomb number" << endl;
			//Sleep(1000);
			system("cls");
			continue;
		}
		cout << "Total number of hints : ";
		cin >> h;

		break;
	}

	List Map(x, y, b, h);
	Map.Make_Map();
	Map.Place_bomb();

	while (1) {
		Map.Print_map();
		cout << "Enter (x) : ";
		cin >> x_idx;
		if (x_idx <= 0 || x_idx > x) {
			cout << "Invalid x value" << endl;
			//Sleep(1000);
			system("cls");
			continue;
		}

		cout << "Enter (y) : ";
		cin >> y_idx;
		if (y_idx <= 0 || y_idx > y) {
			cout << "Invalid y value" << endl;
			//Sleep(1000);
			system("cls");
			continue;
		}

		cout << "Action - (o)pen, (m)ark, (h)int, (e)xit : ";
		cin >> c;
		if (c != 'o' && c != 'm' && c != 'h' && c!= 'e') {
			cout << "Invalid action" << endl;
			//Sleep(1000);
			system("cls");
			continue;
		}

		if (c == 'm') t = Map.Mark(x_idx, y_idx);
		else if (c == 'h') t = Map.Hint(x_idx, y_idx);
		else if (c == 'e') t = 1;
		else if (c == 'o') t = Map.Open(x_idx, y_idx);

		if (t == 1) {
			Map.Destruct_Map();
			break;
		} 
	}
}