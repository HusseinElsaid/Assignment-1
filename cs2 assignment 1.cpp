#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Car {
private:
	string Car_Brand;
	string Car_Type;
	string Car_Plate;
	int Speed;
	int Year_model;
public:
	Car();
	Car(string brand, int speed, int model) {
		Car_Brand = brand;
		Speed = speed;
		Year_model = model;
	}
	void setbrand(string x) {
		Car_Brand = x;
	}
	void settype(string x) {
		Car_Type = x;
	}
	void setplate(string x) {
		Car_Plate = x;
	}
	void setspeed(int x) {
		Speed = x;
	}
	void setmodel(int x) {
		Year_model = x;
	}
	string getbrand() {
		return Car_Brand;
	}
	string gettype() {
		return Car_Type;
	}
	string getplate() {
		return Car_Plate;
	}
	int getspeed() {
		return Speed;
	}
	int getmodel() {
		return Year_model;
	}
};
class Road {
private:
	char Road_type;
	int Speed_limit;
	int countA, countB, countC;
public:
	Road();
	Road(char type, int speed) {
		Speed_limit = speed;
		while (type != 'A' && type != 'a' && type != 'B' && type != 'b' && type != 'C' && type != 'c') {
			cout << "Enter a valid road type(A, B, or C): ";
			cin >> type;
		}
		Road_type = toupper(type);
	}
	void settype(char type) {
		while (type != 'A' && type != 'a' && type != 'B' && type != 'b' && type != 'C' && type != 'c') {
			cout << "Enter a valid road type(A, B, or C): ";
			cin >> type;
		}
		Road_type = toupper(type);
	}
	void setspeed(int speed) {
		Speed_limit = speed;
	}
	void setcountA(int count) {
		countA = count;
	}
	void setcountB(int count) {
		countB = count;
	}
	void setcountC(int count) {
		countC = count;
	}
	char gettype() {
		return Road_type;
	}
	int getspeed() {
		return Speed_limit;
	}
	int getcountA() {
		return countA;
	}
	int getcountB() {
		return countB;
	}
	int getcountC() {
		return countC;
	}
	bool Radar(int speed, char type) {
		if (speed > Speed_limit) {
			return true;
		} else {
			return false;
		}
	}
	void allow(string type) {
		switch (Road_type)
		{
		case 'A':
			if (type != "Private" || type != "Motorcycle") {
				cout << "Your car is not allowed";
				break;
			} else {
				cout << "Your car is allowed";
				countA++;
				break;
			}
		case 'B':
			cout << "All cars are allowed";
			countB++;
			break;
		case 'C':
			if (type != "Truck") {
				cout << "Your car is not allowed";
				break;
			} else {
				cout << "Your car is allowed";
				countC++;
				break;
			}
		default:
			break;
		}

	}
	int age(int year) {
		return 2022 - year;
	}
};
int main() {
	Car c1("toyota", 150, 2003);
	c1.settype("Private");
	c1.setplate("abc123");
	Road r1('A', 120);
	if (r1.Radar(c1.getspeed(), r1.gettype())) {
		cout << c1.getplate() << endl;
		cout << c1.gettype() << endl;
		cout << c1.getspeed() << endl;
		cout << "Your Car will be fined." << endl;
	}
	queue<Car> carq;
	carq.push(c1);
	while (!carq.empty()) {
		r1.Radar(carq.front().getspeed(), r1.gettype());
		r1.allow(carq.front().gettype());
		r1.age(carq.front().getmodel());
		carq.pop();
	}
	Road r2('B', 100);
	Road r3('C', 80);
	r1.setcountA(3);
	cout << r1.getcountA() << " Cars passed by road A" << endl;
	r2.setcountB(6);
	cout << r2.getcountB() << " Cars passed by road B" << endl;
	r3.setcountC(9);
	cout << r3.getcountC() << " Cars passed by road C" << endl;
	int highest;
	int roads[3] = { r1.getcountA(),r2.getcountB(),r3.getcountC()};
	for (int i = 0; i < 2; i++) {
		if (roads[i] >= roads[i + 1]) {
			highest = roads[i];
		} else {
			highest = roads[i + 1];
		}
	}
	cout << "Road 1 efficiency = " << float(r1.getcountA()) / highest * 100 << endl;
	cout << "Road 2 efficiency = " << float(r2.getcountB()) / highest * 100 << endl;
	cout << "Road 3 efficiency = " << float(r3.getcountC()) / highest * 100 << endl;
}