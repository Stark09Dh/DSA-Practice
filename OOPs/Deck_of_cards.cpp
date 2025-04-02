#include<bits/stdc++.h>
 
using namespace std ;

/*
Design the data structures for a generic deck of cards.
*/
 
template<typename T>

// particular card
class Card{
public:
    T value ;
    string suit ;
    Card(T v ,const string &s ) : value(v) , suit(s){}

    void printcard() const {
        cout << value << " of " << suit ;
    }

};

template<typename T>

class Deck{
private:
    vector<Card<T>>cards ;
public:
    Deck(){
        vector<string>suits = {"Hearts" ,"Daimond","Club","Spades"} ;
        vector<T>values = {1,2,3,4,5,6,7,8,9,11,12,13} ;

        for(const auto &suit : suits){
            for(const auto &value : values){
                cards.push_back(Card<T>(value,suit)) ;
            }
        }
    }

    void shuffleDeck(){
        random_device rd ;
        mt19937 g(rd()) ;
        shuffle(cards.begin() , cards.end(), g) ;
    }

    Card<T> drawCard(){
        if(cards.empty()){
            throw out_of_range("Deck is Empty");
        }
        Card<T> drawnCard = cards.back() ;
        cards.pop_back() ;
        return drawnCard ;
    }

    void displayDeck() const{
        for(const auto & card : cards){
            card.printcard() ;
            cout << endl;
        }
    }

    size_t size() const{
        return cards.size() ;
    }

} ;



int main(){

    try{
        Deck<int>deck ;
        cout << " Original deck :" <<endl;
        deck.displayDeck() ;
        deck.shuffleDeck() ;

        cout << "Shuffled Deck : " <<endl ;
        deck.displayDeck();

        Card<int> drawn = deck.drawCard() ;

        cout << "Drawn Card : " ;
        drawn.printcard() ;
        cout << endl;
    }
    catch(const exception &e) {
        cerr << e.what() << endl;
    }

    
    return 0;
}