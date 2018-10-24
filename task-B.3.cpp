#include<string>
#include<iostream>
#include<iomanip>
#include <queue>
using namespace std;

template<typename T> bool operator<(T left, T right){
	//operator overloaded to allow priority_queue to function correctly
	return left<right;
}

template<typename T>
class Collection {
	public:
		Collection();					// Default constructor
		Collection(string n, string d);	// Constructor initialising the name and description of the collection
		void add_item(T c); 			// Add object of class T to priority_queue task.
		void display_best(); 			// Display information of the best object of type T using class T's definition of greater than
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
		bool operator< (Car& b);	//overload < operator for use in Priority Queue. Highest cost is highest priority
		void display()const;		//print the model and price of the car to the output stream
	private:
		string model;				//model of the car
		double price;				//price of the car
};

class Person {
	public:
		Person();					//Default constructor
		Person(string n, int a);	//Constructor initialising all private variables
		int get_age();				//return persons age as an int
		bool operator< (Person& b);	//overload < operator for use in Priority Queue. Highest age is highest priority
		void display()const;		//print the name and age of the Person to the output stream
	private:
		string name;				//name of the person
		double age;					//age of the person. Suspect typo in assignment task sheet made this a double, with getter and setter as an int. Have used static_cast in various functions to match assignment task sheet and demo output
};

class Book {
	public:
		Book();						//Default constructor
		Book(string n, string i);	//Constructor initialising all private variables
		string get_isbn();			//return isbn of book
		bool operator< (Book& b);	//overload < operator for use in Priority Queue. Highest ISBN is highest priority
		void display()const;		//print the name and isbn of the book to the output stream
	private:
		string name;				//name of the book
		string isbn;				//isbn of the book
};

int main(){
	
	//instantiate 3 Person objects
	Person p1("Peter", 64);
	Person p2("Paul", 46);
	Person p3("Mary", 24);
	
	//Instantiate a collection of People using the template
	Collection<Person> P("Family", "My Cousins");
	P.add_item(p1);
	P.add_item(p2);
	P.add_item(p3);
	P.display_best();
	cout << endl; 
	
	//instantiate 3 Person objects
	Book b1("Moby Dick", "123-4567-89");
	Book b2("Wuthering Heights", "921-4567-89");
	Book b3("Thre Three Musketeers", "654-4567-89");
	
	//Instantiate a collection of People using the template
	Collection<Book> b("My Library", "Literature");
	b.add_item(b1);
	b.add_item(b2);
	b.add_item(b3);
	b.display_best();
	cout << endl; 
	
	
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

bool Car::operator<(Car& right){
	//operator overloaded to allow priority_queue to function correctly
	return this->get_price()<right.get_price();
}

//implement Book member functions
Book::Book(){
	name="";
	isbn="";
}

Book::Book(string n, string i){
	name=n;
	isbn=i;
}

string Book::get_isbn(){
	return isbn;
}

bool Book::operator<(Book& right){
	//operator overloaded to allow priority_queue to function correctly
	return this->get_isbn()<right.get_isbn();
}

void Book::display() const{
	cout<<fixed<<setprecision(1)<<"Name: "<<setw(7)<<name<<" ISBN: "<<isbn<<endl;
}

//implement Person member functions
Person::Person(){
	name="";
	age=0;
}

Person::Person(string n, int a){
	name=n;
	age=static_cast<double>(a);
}

int Person::get_age(){
	return static_cast<int>(age);
}

bool Person::operator<(Person& right){
	//operator overloaded to allow priority_queue to function correctly
	return this->get_age()<right.get_age();
}

void Person::display() const{
	cout<<fixed<<setprecision(1)<<"Name: "<<setw(7)<<name<<" Age: "<<static_cast<int>(age)<<endl;
}

