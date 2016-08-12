#include <iostream>
using namespace std;


class NextWordList{
public:

    void foundNextWord(string nextword){

    }

    void printlist(){

    }


};

class NextWordElement{
public:
    string word;
    int count;
    NextWordElement* next;
};










class KeywordListElement{
public:
    string value;
    KeywordListElement *next;
};

class KeywordList{
public:
    KeywordListElement *head;
    KeywordListElement *tail;

    KeywordList(){
        head = NULL;
        tail = NULL;
    }

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

    void addUnique(string keyword){
        if (!findInList(keyword)){
            add(keyword);
        }
    }

    void printlist(){
        KeywordListElement *current = head;

        cout << current->value << "\n";

        while(current->next != NULL){
            current = current->next;
            cout << current->value << "\n";
        }

    }

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

