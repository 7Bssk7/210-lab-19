// COMSC-210 | Lab 18 | Arkhip Finski
// IDE used : Visual Studio
#include <iostream>
#include <string>
#include <random>
#include <fstream>
using namespace std;

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
        string getTitle() const { return title; }
        void setTitle( string t ) { this->title = t; }
    private:
        string title;
        Node *list;
};

double randomRating();

int main(){

    double rating = randomRating();

    cout << "Rating: " << rating << endl;

    return 0;
}

double randomRating(){

    random_device rd;
    default_random_engine generator (rd());
    uniform_real_distribution<double> distribution(1.0 , 5.0);
    double rating = round(distribution(generator) * 10)/10.0;

    return rating;

}