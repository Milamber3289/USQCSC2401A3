#include<string>
#include<iostream>
#include<iomanip>
#include <queue>
using namespace std;

template<typename T> bool operator<(T left, T right){
	//operator overloaded to allow priority_queue to function correctly
	return left.get_price()<right.get_price();
}

template<typename T>
class Collection {
	public:
		Collection();					// Default constructor
		Collection(string n, string d);	// Constructor initialising the name and description of the collection
		void add_item(T c); 			// Add object of class T to priority_queue task.
		void display_best(); 			// Display information of the best object of type T.
										// Use price to determine “best”.
										// Higher price means “better”.
	private:
		priority_queue <T> task;		// Priority queue containing all objects of type T in the collection
		string name; 					// Name of the collection
		string description; 			// Descriptions of the collection
};

class Car {
	public:
		Car();						//Default constructor
		Car(string m, double p);	//Constructor initialising all private variables
		string get_model();			//return model of car
		double get_price();			//return the price of the car
		void display()const;		//print the model and price of the car
	private:
		string model;				//model of the car
		double price;				//price of the car
};

int main(){
	// Instantiate 3 car objects
	Car c1("MQ310", 12345.99);
	Car c2("AH211", 23456.78);
	Car c3("ZH42", 3456.49);
	
	// Instantiate a Collection of Cars using the template
	Collection<Car> c("Sports Car", "From 1900 to 2014");
	
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
	cout<<fixed<<setprecision(1)<<"Model: "<<setw(7)<<model<<" Price: "<<price<<endl;
}

//Implement Collection member functions as templates
template<typename T>
Collection<T>::Collection(){
	name="";
	description="";
}

template<typename T>
Collection<T>::Collection(string n, string d){
	name=n;
	description=d;
}

template<typename T>	//template T determines type of object stored in priority queue task
void Collection<T>::add_item(T c){
	task.push(c);
}

template<typename T>
void Collection<T>::display_best(){
	cout<<setw(12)<<left<<name<<" "<<description<<endl;
	task.top().display();
}
