#include<bits/stdc++.h>
 
using namespace std ;

/*
 • To set or get the value of private member we use getter and setter methods;

*/

class Tekken{

    




    // properties
    private: // can be accessed inside the class
    string name ;
    public : // can be Accessed anywhere
    int power ;

    Tekken(){   // constructor 
        cout << "Contructor  Called";
    }
    Tekken(int power){   // parameterized constructor 
        this->power = power ;
    }

    string get(){ // getter
        return name ;
    }

    void set(string n){ // setter
        name = n ;
    }
} ;
 
int main(){
    Tekken paul(400) ; // object instanciation

    cout << "size -> " << sizeof(paul)<<endl;// size of == size of all properties
    // if there is no properties size would be 1  

    paul.set("Paul Pogba");

    cout <<"Name : "<< paul.get() <<endl ;

    cout << "Power : " << paul.power << endl ;

    
    return 0;
}