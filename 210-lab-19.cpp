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
    private:
        string title;
        Node *list;
};

double randomRating();

int main(){

    vector<Movie> movies;
    movies.push_back(Movie("Avengers: Endgame"));
    movies.push_back(Movie("Guardians of the Galaxy Vol. 3"));
    movies.push_back(Movie("Spider-Man: No Way Home"));
    movies.push_back(Movie("Black Panther: Wakanda Forever"));
    ifstream inputFile("Comments.txt");

    if(!inputFile){
        cout << "Error, file is not opening!" << endl;

        return 1;
    }

    return 0;
}


double randomRating(){

    random_device rd;
    default_random_engine generator (rd());
    uniform_real_distribution<double> distribution(1.0 , 5.0);
    double rating = round(distribution(generator) * 10)/10.0;

    return rating;

}