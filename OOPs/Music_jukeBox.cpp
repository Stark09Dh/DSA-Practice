#include<bits/stdc++.h>
 
using namespace std ;

class Song{
public:
    string title ;
    int duration ; // in seconds

    Song(string t , int d) : title(t) , duration(d) {}

    void display(){
        cout << title << "("<<duration<<" seconds)"<<endl;
    }
};

class CD{
private:
    string title ;
    vector<Song> tracks ;
public:
    CD(string t) : title(t) {} ;

    void addtrack(const Song &s){
        tracks.push_back(s) ;
    }
    void removeTrack(int index){
        if (index >= 0 && index < tracks.size()) {
            tracks.erase(tracks.begin() + index);
        }
    }

    void displayTrack(){
        cout<< "Tracks in CD : " <<endl;
        for(size_t i = 0 ; i < tracks.size() ; i++){
            cout << i+1 << ". " ;
            tracks[i].display() ;
        }
    }

    int getTrackCount(){
        return tracks.size() ;
    }

    Song getTrack(int index){
        if(index >= 0 && index < tracks.size()){
            return tracks[index] ;
        }
        return Song("" , 0) ; 
    }

};

class Playlist{
private:
    vector<Song>songs ;
    int currIndex ;
public:
    Playlist() : currIndex(0){
        
    }

    void addSong(const Song &s){
        songs.push_back(s) ;
    }

    void removeSong(int index){
        if(index >= 0 && index < songs.size()){
            songs.erase(songs.begin() + index) ;
        }
    }

    void shufflePlaylist(){
        default_random_engine rng(static_cast<unsigned>(time(nullptr)));
        
        shuffle(songs.begin(), songs.end(), rng);
    }

    Song getNextSong(){
        if(songs.empty()) return Song("" , 0) ;
        currIndex = (currIndex+1) % songs.size() ;

        return songs[currIndex] ;
    }

    void displayplaylist(){
        cout << "Playlist : " << endl;
        for(size_t i = 0  ;i < songs.size() ; i++){
            cout<< i+1 << ". ";
            songs[i].display() ;
        }
    }

    int getsize(){
        return songs.size() ;
    }
};

class CDPlayer{

private:
    CD* currentCD ;
    Playlist playlist ;
    Song currentSong ;

public:

    CDPlayer() : currentCD(nullptr), playlist(), currentSong("", 0) {
        
    }

    void loadCD(CD& cd) {
        currentCD = &cd;
        playlist = Playlist();
        for (int i = 0; i < cd.getTrackCount(); i++) {
            playlist.addSong(cd.getTrack(i));
        }
    }

    void playSong(){
        currentSong = playlist.getNextSong();
        cout << "Now playing :" ;
        currentSong.display() ;
    }

    void skip(){
        currentSong = playlist.getNextSong() ;
        cout << " Skipping to : ";
        currentSong.display() ;
    }

    void pause(){
        cout << "Paused : ";
        currentSong.display() ;
    }

    void displayPlaylist(){
        return playlist.displayplaylist() ;
    }

    void removeTrack(int index){
        playlist.removeSong(index) ;
    }
};


class Display{

public:
    void showSonginfo(const Song &song , int remainingTime){
        cout << "Now Playing : " << song.title << "(" <<song.duration <<" seconds)" << endl;
        cout << " Remaining Time : " << remainingTime << endl ;
    }

};

class Users{
private:
    string name ;
    int credits ;
public:
    Users(string name): name(name) , credits(0) {}
    void addCredit(int amount){
        credits += amount ;
        cout << "User now has " << credits <<" Credits"<<endl ; 
    }
    void spendCredits(int amount){
        if(credits >= amount){
            credits -= amount ;
            cout << "User now has " << credits <<" Credits"<<endl ;
        }
        else{
            cout << "Not enough Credits." <<endl ;
        }
    }

    void addTrack(const Song &song , CD &cd){
        cd.addtrack(song) ;
    }

    void removetrack(int index , CD &cd){
        cd.removeTrack(index) ;
    }

};
 

int main(){
 
    CD myCD("Best Hits");
    myCD.addtrack(Song("Song 1", 180));
    myCD.addtrack(Song("Song 2", 200));
    myCD.addtrack(Song("Song 3", 240));

    Users user("JohnDoe");
    user.addCredit(20);  // Add credits to user

    CDPlayer player;
    player.loadCD(myCD);  // Load the CD into the player
    Display display;

    // User interacts with the jukebox system
    std::cout << "\n--- View Playlist ---\n";
    player.displayPlaylist();  // Display current tracks on the CD

    std::cout << "\n--- Play First Song ---\n";
    player.playSong();  // Play the first song

    std::cout << "\n--- Skip to Next Song ---\n";
    player.skip();  // Skip to the next song


    std::cout << "\n--- Pause the Song ---\n";
    player.pause();  // Pause the song

    std::cout << "\n--- Add Song to CD (After Spending Credits) ---\n";
    user.spendCredits(5);  // Spend 5 credits
    user.addTrack(Song("Song 4", 210), myCD);  // Add new song to the CD

    std::cout << "\n--- Remove Song from CD ---\n";
    user.removetrack(1, myCD);  // Remove Song 2 from the CD

    std::cout << "\n--- View Updated Playlist ---\n";
    player.displayPlaylist();  // View the updated playlist
    
    return 0;
}