// COMSC-210 | Lab 18 | Arkhip Finski
// IDE used : Visual Studio
#include <iostream>
#include <string>
using namespace std;

// Constants for rating bounds and input validation
const double RATING_MAX = 5.0, RATING_MIN = 1.0;
const char YES = 'y', NO = 'n';

// Movie class stores a single review's rating and comment
class Movie{
    public:
        string getComment() const { return comment; }
        void setComment( string c) { this->comment = c; }
        double getRating() const { return rating; }
        void setRating( double r ) { this->rating = r; }

    private:
        string comment;
        double rating;

};

// Node struct represents a single node on the linked list
struct Node{
    Movie choice;
    Node *next;
};

void outputMenu();
void outputList( Node *);
void addHead( Node *&);
void addTail ( Node *&);
double averageRating ( Node *);

int main(){
    Node *head = nullptr;
    int entry;
    
    outputMenu();
    cout << "Choice: ";
    cin >> entry;

    // Validate menu choice
    while((entry > 2) || (entry < 1)){
        cout << "Invalid choice, please enter your choice again(1 - 2): ";
        cin >> entry;
    }

    // Call appropriate insertion function 
    if(entry == 2){
        addTail(head);
    }
    else if(entry == 1){
        addHead(head);
    }

    // Output all review and average 
    outputList(head);

    return 0;
}

// OutputMenu() displays the insertion mode options to the user
// argument: none
// return: no return(void function)
void outputMenu(){
    cout << "Which linked list method should we use?" << endl;
    cout << "    [1] New nodes are added at the head of the linked list" << endl;
    cout << "    [2] New nodes are added at the tail of the linked list" << endl;
}

// outputList() traverses the linked list and prints all reviews and the average rating 
// argument: hd - pointer to the head of the linked list 
// return: no return(void function)
void outputList( Node *hd){
    int count = 1;
    Node *current = hd;
    cout << "Output all reviews" << endl;
    if(!hd){
        cout << "Empty list" << endl;
    }
    else{
        while(current){
            cout << "     > Review #" << count << ": "  << current->choice.getRating() << ": " << current->choice.getComment() << endl;
            count++;
            current = current->next;
        } 
    }
    cout << "     > Average: " << averageRating(hd) << endl;
}

// addHead() inserts new reviews at the head of the linked list
// argument: hd - reference to the pointer to the head pointer of the linked list 
// return: no return(void function)
void addHead( Node *&hd){
    double tempR;
    string tempC; 
    char q;
    bool review = 1;

    while( review != 0){
        Node *newNode = new Node;

        cout << "Enter review rating 0-5: ";
        cin >> tempR;
        while((tempR > RATING_MAX) || (tempR < RATING_MIN)){
            cout << "Invalid Rating, please enter your rating again(1-5): ";
            cin >> tempR;
        }
        cout << "Enter review comment: "; 
        cin.ignore();
        getline(cin, tempC);
        newNode->choice.setRating(tempR);
        newNode->choice.setComment(tempC);

        if(!hd){
            hd = newNode;
            newNode->next = nullptr;
        }
        else{
            newNode->next = hd;
            hd = newNode;
        }
        
        cout << "Enter another review? Y/N: ";
        cin >> q;
        while((tolower(q) != NO) && (tolower(q) != YES)){
            cout << "Invalid input, please enter your choice again(Y/N): ";
            cin >> q;
        }
        if(tolower(q) == NO){
             review = 0;
        }
    }



}

// addTail() inserts new reviews at the tail of the linked list
// argument: hd - reference to the pointer to the head pointer of the linked list 
// return: no return(void function)
void addTail ( Node *&hd){
    double tempR;
    string tempC;
    char q;
    bool review = 1;

    while(review == 1){
        Node *newNode = new Node;

        cout << "Enter review rating 0-5: ";
        cin >> tempR;
        while((tempR > RATING_MAX) || (tempR < RATING_MIN)){
            cout << "Invalid Rating, please enter your rating again(1-5): ";
            cin >> tempR;
        }
        cout << "Enter review comment: "; 
        cin.ignore();
        getline(cin, tempC);
        newNode->choice.setRating(tempR);
        newNode->choice.setComment(tempC);

        if(!hd){
            hd = newNode;
            newNode->next = nullptr;
        }
        else{
            Node *current = hd;
            while(current->next){
                current = current->next;
            }
            current->next = newNode;
            newNode->next = nullptr;
        }

        cout << "Enter another review? Y/N: ";
        cin >> q;
        while((tolower(q) != NO) && (tolower(q) != YES)){
            cout << "Invalid input, please enter your choice again(Y/N): ";
            cin >> q;
        }
        if(tolower(q) == NO){
             review = 0;
        }
    }

}

// averageRating() calculates the average rating of all reviews in the linked list
// argument: hd - pointer to the head of the linked list
// return: returns double - the average rating
double averageRating (Node *hd){
    Node *current = hd;
    int count = 0;
    double sum = 0;

    while(current){
        sum += current->choice.getRating();
        count++;
        current = current->next;
    }

    return (sum/count);
}