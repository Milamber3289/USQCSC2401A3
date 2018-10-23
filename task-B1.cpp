#include<string>
#include<iostream>
#include <queue>
using namespace std;

class Car {
	public:
		Car();
		Car(string m, double p);
		string get_model();
		double get_price();
		void display()const;
	private:
		string model;
		double price;
};

class Collection {
	public:
		Collection();
		Collection(string n, string d);
		void add_item(Car c); 	// Add Car c to priority_queue task.
		void display_best(); 	// Display information of the Best car.
								// Use price to determine “best”.
								// Higher price means “better”.
	private:
		priority_queue <Car> task;
		string name; // Name of the collection
		string description; // Descriptions of the collection
};

bool operator<(Car left, Car right){
	//operator overloaded to allow priority_queue to function correctly
	return left.get_price()<right.get_price();
}
	
int main(){
	// Instantiate 3 car objects
	Car c1("MQ310", 12345.99);
	Car c2("AH211", 23456.78);
	Car c3("ZH42", 3456.49);
	
	// Instantiate a Collection object
	Collection c("Sports Car", "From 1900 to 2014");
	
	// Add 3 car objects to the car collection
	c.add_item(c1);
	c.add_item(c2);
	c.add_item(c3);
	// Display the information of the best car.
	c.display_best(); 
	return 0;
}

//implement Car member functions
Car::Car(){
	model="";
	price=0;
}

Car::Car(string m, double p){
	model=m;
	price=p;
}

string Car::get_model(){
	return model;
}

double Car::get_price(){
	return price;
}

void Car::display() const{
	cout<<"Model: "<<model<<'Price: '<<price<<endl;
}

//Implement Collection member functions
Collection::Collection(){
	name="";
	description="";
}

Collection::Collection(string n, string d){
	name=n;
	description=d;
}

void Collection::add_item(Car c){
	task.push(c);
}

void Collection::display_best(){
	cout<<name<<'\t'<<description<<endl;
	task.top().display();
}
