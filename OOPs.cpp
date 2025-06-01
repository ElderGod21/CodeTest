#include<iostream>
#include <string.h>
// #include "Hero.cpp" to add another file and use its functions and whatever

using namespace std;

class Hero{

    private:
    int health;

    public:

    char *name;
    char level;// but this is coming as size 4  ********** Because of padding concept to make 4 or 8 multiple 


    //default constructor khudse bhi bnaliya ***original default waala gaayab hojayega*** 
    Hero(){
        cout<<"Constructor called"<<endl;
        name = new char[100];
    }

    //Parameterised Constructor

    Hero(int health){
        cout<<"This -> "<<this<<endl;
        this-> health = health;
    }

    //Copy constructor

    // Hero(Hero& temp){
    //     this->health = temp.health;
    //     this->level = temp.level;
    // }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }       

    void setHealth(int h){
        health = h;
    }

    void setLevel(char l){
        level= l;
    }          

    void setName(char name[]){
        this->name=name;
    }           

    void print(){
        cout<<this->health<<endl;
        cout<<this->level<<endl;
        cout<<this->name<<endl;
    }

    //like a password
    /*
    void setSomething(int n, char pswd){
        if(pswd == 'Actual Password'){
            oldthing = n;
        }else{
            cout<<"Access Denied";
        }
    }*/  

    Hero(Hero& temp){
        char *ch = new char[strlen(temp.name)+ 1];
        strcpy(ch, temp.name);
        this->name= ch;
        this->health=temp.health;
        this->level = temp.level;
    }
};

int main(){

    // cout<<"Hi"<<endl;

    // Hero h1;
    
    // cout<<"Hello"<<endl;
    
    // char ch;
    
    // cout<<"Size of H1 is : "<<sizeof(h1)<<endl;
    
    // cout<<sizeof(ch)<<endl; //why this is coming 1

    // cout<<h1.getHealth();

    // //Dynamic allocation
    // Hero *h = new Hero; //or new Hero();

    // // to access the values either use (*b).getLevle() or b->getLevel()
    // cout<<h->level<<endl;
    // cout<<(*h).name<<endl;
    // cout<<sizeof(h)<<endl;

    // Hero ramesh(10 );
    // cout<<"Address of Ramesh: "<<&ramesh;

    // Hero suresh(ramesh); //Copy constructor called

    Hero hero1;
    char name[8] = "Abhisar";
    hero1.setHealth(50);
    hero1.setLevel('A');
    hero1.setName(name);

    hero1.print();

    Hero hero2(hero1);

    hero2.print();

    hero1.name[0]= 'G';

    hero1.print();
    hero2.print();


}