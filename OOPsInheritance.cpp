#include<iostream>

using namespace std;

class Human {
    
    protected:
    int head=2;

    private:
    int genitals=1;

    public:
    int height=6;
    int age=22;
    int weight=72;

    int getHeight(){
        return this->height;
    }

    void setWeight(int w){
        this->weight= w;
    }

    int getGenitals(){
        return this->genitals;
    }

    void setHeight(int h){
        this->height = h;
    }

};

//Single Inheritance

class Male: public Human{

    public:
    string beard;

    void sleep(){
        cout<<"Male is sleeping"<<endl;
    }

    int getHeight(){
        return 1;
    }
    /*
    protected:
    protected members
    
    
    private:
    not accessible
    
    public:
    public members
    
    */
};

class Female: protected Human{

    public:
    string size;

    /*
    protected:
    int head, and public (protected and public members)
    
    
    private:
    nothing
    
    
    public:
    nothing
    
    */
};

class Transgender: private Human{

    public:
    string chanda;

    int getHead(){
        return this->head;
    }


    

    /*
    protected:
    nothing


    private:
    everything
    except private from base class


    public:
    nothing

    
    */

};

//Multilevel Inheritance

class Boy: public Male{
    public:
    string hair;

};

//Multiple Inheritance

class child: public Male, public Female{

    public:

    string color;

};

//Inheritance Ambiguity

class A{
    public:
    void abc(){
        cout<<"Class A"<<endl;
    }
};

class B{
    public:
    void abc(){
        cout<<"Class B"<<endl;
    }
};

class C : public A, public B{
    public:
};

int main(){
    Human h1;
    Male h2;
    Female h3;
    Transgender h4;
    
    // h2.setWeight(80);
    // h2.setHeight(5);

    // cout<<h1.weight<<endl;
    // cout<<h2.height<<endl;
    // cout<<h2.weight<<endl;
    // cout<<h1.height<<endl;

    // cout<<h4.getHead()<<endl;

    C obj;

    //obj.abc(); will give an error of ambiguity

    //Scope resolution operator

    // obj.A::abc();
    // obj.B::abc();

    cout<<h2.getHeight();
    
}