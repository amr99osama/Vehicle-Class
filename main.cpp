// Program: Class and Inheritance.cpp
// Purpose: Representing Some member methods in 2 classes and inherited class
// Author:  Amr Osama
// ID:      20170185
// Date:    26 October 2018
// Version: 1.0


#include <iostream>
#include <string>

using namespace std;

//Provided Person class.
class Person{
      public:
             Person();
             Person(string theName);
             Person(const Person& theObject);
             string getName() const;
            void setName (string theName);
             Person& operator =(const Person& rtSide);
             private:friend istream& operator >>(istream& inStream,
                                                  Person& personObject);
             private:friend ostream& operator <<(ostream& outStream,
                                                  const Person& personObject);
      private:
              string name;
      };

//Required Vehicle class.
class Vehicle{
      public:
            Vehicle();
            Vehicle(string manuName, int numCyl, const Person& owner);
            Vehicle(const Vehicle& theVehicle);
            Vehicle& operator =(const Vehicle& theVehicle);
            string getManuName();
            int getNumCyl();
            Person getOwner();

      private:
              string manuName;
              int numCyl;
              Person owner;
      };

//Required derived class Truck from base class Vehicle.
class Truck : public Vehicle{
      public:
             Truck();
             Truck(double capTons, int capPounds, string manuName, int numCyl, const Person& owner);
             Truck(const Truck& theTruck);
             Truck&operator =(const Truck& theTruck);
             double getCapTons();
             int getCapPounds();
      private:
              double capTons;
              int capPounds;
      };

//Person Implementation
//Constructors
Person::Person() : name("Unknown"){}
Person::Person(string theName) : name(theName){}
 Person::Person(const Person& theName): name(theName.name){} //Copy Constructor
//Overloaded assignment operator
Person& Person::operator =(const Person& thePerson){
        this->name = thePerson.name;
        return *this;
        }
        void Person::setName(string theName)
        {
            name = theName;
        }
istream& operator >>(istream& inStream, Person& personObject){
         inStream >> personObject.name;
         return inStream;
         }
ostream& operator <<(ostream& outStream, const Person& personObject){
        outStream << personObject.name;
        return outStream;
        }
//Accessor methods
string Person::getName() const{
       return name;
       }

//Vehicle Implementation
//Constructors
Vehicle::Vehicle() : manuName("No Manufacturer"), numCyl(0), owner("No Owner"){}
Vehicle::Vehicle(string theManuName, int theNumCyl, const Person& theOwner)
                        : manuName(theManuName),
                          numCyl(theNumCyl),
                          owner(theOwner){}
Vehicle::Vehicle(const Vehicle& theVehicle)//Copy Constructor.
                       : manuName(theVehicle.manuName),
                         numCyl(theVehicle.numCyl),
                         owner(theVehicle.owner){}
//Overloaded Assignment Operator
Vehicle& Vehicle::operator =(const Vehicle& theVehicle){
         this->manuName = theVehicle.manuName;
         this->numCyl = theVehicle.numCyl;
         this->owner = theVehicle.owner;
         return *this;
         }
//Accessor methods
string Vehicle::getManuName(){
       return manuName;
       }
int Vehicle::getNumCyl(){
    return numCyl;
    }
Person Vehicle::getOwner(){
       return owner;
       }

//Truck Implementation
//Constructors
Truck::Truck() : capTons(0.0), capPounds(0){}
Truck::Truck(double theCapTons, int theCapPounds, string theManuName, int theNumCyl, const Person& theOwner)
                    : Vehicle(theManuName, theNumCyl, theOwner),
                      capTons(theCapTons),
                      capPounds(theCapPounds){}
Truck::Truck(const Truck& theTruck) //Copy Constructor.
                   : Vehicle(theTruck),
                     capTons(theTruck.capTons),
                     capPounds(theTruck.capPounds){}
//Overloaded Assigment Operator
Truck& Truck::operator =(const Truck& theTruck){
       Vehicle::operator =(theTruck);
       capTons = theTruck.capTons;
       capPounds = theTruck.capPounds;
       return *this;
       }
//Accessor methods
double Truck::getCapTons(){
       return capTons;
       }
int Truck::getCapPounds(){
    return capPounds;
}

//Driver Program
int main(){

    Person p1;
    p1.setName("Amrr");
    cout<<"enter a new name of the owner"<<endl;
    cin>>p1;
    Vehicle v1("BMW",20,p1.getName());
    cout << "Vehicle v1 Data: " << endl;
    cout << "Manufacturer's Name: " <<v1.getManuName() << endl;
    cout << "Number of Cylinders: " <<v1.getNumCyl() << endl;
    cout << "Owner: " << v1.getOwner() << endl;

    Vehicle v2(v1);
     cout << "Vehicle v2 Data: " << endl;
    cout << "Manufacturer's Name: " <<v1.getManuName() << endl;
    cout << "Number of Cylinders: " <<v1.getNumCyl() << endl;
    cout << "Owner: " << v1.getOwner() << endl;



    Truck t1(72.0, 1500, "Mercedes", 8, p1.getName());

    cout << "Truck t1 Data: " << endl;
    cout << "Manufacturer's Name: " << t1.getManuName()<<endl;
    cout << "Number of Cylinders: " <<t1.getNumCyl()<<endl;
    cout << "Owner: " <<t1.getOwner() << endl;
    cout << "Load Capacity (Tons): " << t1.getCapTons()<<endl;
    cout << "Towing Capacity (Pounds): " <<t1.getCapPounds()<<endl;

    Truck t2(t1);
    cout << "Truck t2 Data: " << endl;
    cout << "Manufacturer's Name: " << t2.getManuName()<<endl;
    cout << "Number of Cylinders: " <<t2.getNumCyl()<<endl;
    cout << "Owner: " <<t1.getOwner() << endl;
    cout << "Load Capacity (Tons): " << t2.getCapTons()<<endl;
    cout << "Towing Capacity (Pounds): " <<t2.getCapPounds()<<endl;;
    cout<<endl;
 }

