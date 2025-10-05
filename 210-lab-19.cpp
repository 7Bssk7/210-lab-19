// COMSC-210 | Lab 19 | Arkhip Finski
// IDE used : Visual Studio
#include <iostream>
#include <string>
#include <random>
#include <fstream>
using namespace std;

// Constant for number of movies
const int SIZE = 4;

// Class to store individual reviews 
class MovieRating{
    public:
        string getComment() const { return comment; }
        void setComment(string c) { this->comment = c; }
        double getRating() const { return rating; }
        void setRating( double r ) { this-> rating = r; }
    private:
        string comment;
        double rating;
};

// Node struct represents a single node on the linked list 
struct Node{
    MovieRating review;
    Node *next;

};

// Class to represent a Movie and its linked list of (3)reviews
class Movie{
    public:
        // Default constructor 
        Movie() { title = "", list = nullptr; }
        // Partial constructor with title
        Movie(string t) { title = t, list = nullptr; }
        string getTitle() const { return title; }
        void setTitle( string t ) { this->title = t; }
        // This method adds a review to the head of the linked list
        void addReview( double r, string c) {
            Node *newNode = new Node;
            newNode->review.setComment(c);
            newNode->review.setRating(r);
            
            // Inserts data at head of the linked list
            if(!list){
                list = newNode;
                newNode->next = nullptr;
            }
            else{
                newNode->next = list;
                list = newNode;
            }

        }
        // Prints all reviews for a movie
        void printReview(){
            Node *current = list;
            while(current){
                cout << current->review.getRating() << " " << current->review.getComment() << endl;
                current = current->next;
            }

        }
    private:
        string title;
        Node *list;
};

double randomRating();
void addReviews(vector<Movie> &);
void outputReviews(vector<Movie>);

int main(){

    vector<Movie> movies;
    movies.push_back(Movie("Avengers: Endgame"));
    movies.push_back(Movie("Guardians of the Galaxy Vol. 3"));
    movies.push_back(Movie("Spider-Man: No Way Home"));
    movies.push_back(Movie("Black Panther: Wakanda Forever"));

    addReviews(movies);

    outputReviews(movies);
 

    return 0;
}



double randomRating(){

    random_device rd;
    default_random_engine generator (rd());
    uniform_real_distribution<double> distribution(1.0 , 5.0);
    double rating = round(distribution(generator) * 10)/10.0;

    return rating;

}

void addReviews(vector<Movie>& m){
    ifstream inputFile("Comments.txt");
    int i = 0;
    string tempC;

    if(!inputFile){
        cout << "Error, file is not opening!" << endl;
    }
    else{
        while((getline(inputFile, tempC)) && (i < m.size())){
            if(tempC != ""){
                m.at(i).addReview( randomRating(), tempC );
            }
            else{
                i++;
            }

        }
    }
}

void outputReviews(vector<Movie> m){
    for(int i = 0; i < m.size(); ++i){
        cout << "Movie: " << m.at(i).getTitle() << endl;
        m.at(i).printReview();

        cout << endl;
    }

}