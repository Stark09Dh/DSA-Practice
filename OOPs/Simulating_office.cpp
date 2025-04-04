#include<bits/stdc++.h>
 
using namespace std ;

class Employee{
protected:
    string name ;
    bool isFree ;

public: 
    Employee(string n) : name(n) , isFree(true){}

    virtual bool canHandleCall() =  0; 

    void setAvailability(bool availability){
        isFree = availability ;
    }

    bool getAvailability(){
        return isFree ;
    }

    string getName(){
        return name ;
    }
};

class Fresher : public Employee{
public: 
    Fresher(string n) : Employee(n){}

    bool canHandleCall() override{
        return isFree ;
    }

};

class TechnicalLead : public Employee{
public:
    TechnicalLead(string n) : Employee(n){}

    bool canHandleCall() override{
        return isFree ;
    }

};

class ProductManager : public Employee{
public: 
    ProductManager(string n) : Employee(n){}

    bool canHandleCall() override {
        return isFree ;
    }
} ;


class CallCenter{

private:
    vector<Fresher>freshers ;
    vector<TechnicalLead>techlead ;
    ProductManager* pm ;

public:
    CallCenter(){
        pm = nullptr ;
    }

    void addFresher(Fresher f){
        freshers.push_back(f) ;
    }

    void addtechlead(TechnicalLead tl){
        techlead.push_back(tl) ;
    }

    void setPM(ProductManager *p){
        pm = p ;
    }

    Employee* getCallHandler(){
        for(auto &fresher : freshers){
            if(fresher.canHandleCall()){
                fresher.setAvailability(false);
                return &fresher ;
            }
        }
        for( auto &tl : techlead){
            if(tl.canHandleCall()){
                tl.setAvailability(false) ;
                return &tl ;
            }
        }
        if(pm && pm->canHandleCall()){
            pm ->setAvailability(false) ;
            return pm ;
        }

        return nullptr ;
    }


};

 

int main(){
    Fresher f1("Fresher1") ;
    Fresher f2("Fresher2") ;
    Fresher f3("Fresher3") ;
    Fresher f4("Fresher4") ;
    TechnicalLead tl1("TL1") ;
    ProductManager pm1("PM1") ;

    CallCenter cc ;
    cc.addFresher(f1);
    cc.addFresher(f2);
    cc.addFresher(f3);
    cc.addFresher(f4);

    cc.addtechlead(tl1) ;

    cc.setPM(&pm1) ;

    for(int i = 0 ; i < 7 ; i++){
        Employee* handler = cc.getCallHandler();
        if(handler){
            cout << "call is handled by : " << handler->getName() << endl;
        }
        else{
            cout << "No one is available to handle the call." <<endl ;
        }
    }
    

    return 0;
}