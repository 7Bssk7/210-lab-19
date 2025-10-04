// COMSC-210 | Lab 19 | Arkhip Finski
// IDE used : Visual Studio
#include <iostream>
#include <string>
#include <random>
#include <fstream>
using namespace std;

const int SIZE = 4;

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

struct Node{
    MovieRating review;
    Node *next;

};

class Movie{
    public:
        Movie() { title = "", list = nullptr; }
        Movie(string t) { title = t, list = nullptr; }
        string getTitle() const { return title; }
        void setTitle( string t ) { this->title = t; }
        void addReview( double r, string c) {
            Node *newNode = new Node;
            newNode->review.setComment(c);
            newNode->review.setRating(r);

            if(!list){
                list = newNode;
                newNode->next = nullptr;
            }
            else{
                newNode->next = list;
                list = newNode;
            }

        }
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