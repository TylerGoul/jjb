#include <iostream>
using namespace std;

//node elements
class NextWordElement{
public:
    //values stored in node
    string word;
    int count;
    
    //pointers to corresponding elements
    NextWordElement *next;
    KeyWordListElement *keyword
};

class KeywordListElement{
public:
    //values for element 
    string value;
    
    //pointers to related elements
    NextWordListElement *nextWord;
    KeywordListElement *next;
};

//list elements
class NextWordList{
private:
    NextWordElement *head;
    NextWordElement *tail;
    
public:
    NextWordList(){
        *head = NULL;
        *tail = NULL;
    }
    
    void foundNextWord(string nextword){
        
    }
    
    //prints the list from head to tail
    void printlist(){
        NextWordListElement *current = head;

        cout << current->value << "\n";

        while(current->next != NULL){
            current = current->next;
            cout << current->value << "\n";
        }
    }
};

//this class represents a linked list for KeyWordElements
class KeywordList{
private:
    KeywordListElement *head;
    KeywordListElement *tail;
    
public:
    //constructor -- Initializes the list
    KeywordList(){
        head = NULL;
        tail = NULL;
    }
    
    //adds an element to the list
    void add(string keyword){
        if (head == NULL){
            //this is the first one
            KeywordListElement *temp = new KeywordListElement;
            temp->value=keyword;
            temp->next=NULL;

            head = temp;
            tail = temp;
        }else{
            //its not
            KeywordListElement *temp = new KeywordListElement;
            temp->value=keyword;
            temp->next=NULL;

            tail->next=temp;
            tail = temp;
        }
    }

    //adds to list only if the value does not exist in another node
    void addUnique(string keyword){
        if (!findInList(keyword)){
            add(keyword);
        }
    }
    
    //prints out the entire list from head to tail
    void printlist(){
        KeywordListElement *current = head;

        cout << current->value << "\n";

        while(current->next != NULL){
            current = current->next;
            cout << current->value << "\n";
        }
    }

    //returns true if it exists in the list and false if it does not
    bool findInList(string keyword){
        KeywordListElement *current = head;

        if(keyword == current->value){
            return true;
        }

        while(current->next != NULL){
            current = current->next;

            if(keyword == current->value){
                return true;
            }
        }

        return false;
    }
};

int main(){
    //string array[] = {"one", "two", "three"};

    KeywordList *kwl = new KeywordList;

    kwl->add("one");
    kwl->add("two");
    kwl->addUnique("two");
    kwl->addUnique("one");

    kwl->printlist();

//    for (int i = 0; i < 3; i++){
//        keywordlist->add(array[i]);
//    }
}

