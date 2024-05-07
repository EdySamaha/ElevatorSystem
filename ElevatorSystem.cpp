#include <iostream>
using namespace std;
#include <vector>

// Creating an elevator system where the input is a sequence of clicks, and for each click the closest elevator AND the one going in the same direction should be selected to respond to the click

//Global vars
int topfloor=10;
int bottomfloor=0;

template<typename T>
void PrintVector(T myvector){
    cout<<"Printing Vector:\n";
    for (int i = 0; i < myvector.size(); i++)
        cout<<myvector[i]<<" ";
    cout<<'\n';
}

class Elevator{
    //keep private
    // int defaultposition; //no need, will be the first in sequence
    vector<int> sequence=[];

    Elevator(int _defaultposition){sequence.push_back(_defaultposition);}
    
    public:
    //getters
    int getCurrentFloor(){return sequence.end();}

    bool isGoingup(){ //opposite of is going down
        if (getCurrentFloor()==topfloor)
            return false;
        if (getCurrentFloor()==bottomfloor)
            return true;

        if(sequence[-1]>sequence[-2])
            return true;
        else
            return false;
    }

    bool isGoingTowards(int i){
        if (i==getCurrentFloor())
            return true;

        if (i>getCurrentFloor() && isGoingup())
            return true;

        if (i<getCurrentFloor() && !isGoingup())
            return true;

        return false;
    }

    void PrintElevator(){PrintVector(sequence);}

    //setters
    void addFloor(int num){sequence.push_back(num);}

   
};


int main(){
    vector<int> inputsequence = [10,1,2,6,9,3]; //NOTE: have to also remove duplicates

    //first sort
    for (int i = 0; i < inputsequence.size()-1; i++)
    {
        // int minimum = inputsequence[i];
        for (int j = i+1; j < inputsequence.size(); j++)
        {
            if (inputsequence[j]<inputsequence[i]){ //if smaller than minimum
                int temp = inputsequence[i];
                inputsequence[i] = inputsequence[j];
                inputsequence[j] = temp;
            }
        }
        
    }

    cout<<"Sorted input sequence set:\n";
    PrintVector(inputsequence);
    
    Elevator* a = new Elevator(2);
    Elevator* b = new Elevator(8);

    //Elevator Manager
    vector<Elevator*> AllElevators = [a,b];

    //check which elevator is closest for each input
    for (int i = 0; i < inputsequence.size()-1; i++)
    { 
        vector<Elevator*> eligibleElevators = [];
        for (e in AllElevators)
        {
            if (e->isGoingTowards(i))
                eligibleElevators->push_back(e);
        }

        //select best elevator

        //if no elevator was selected throw error
        if (eligibleElevators==[])
        {
            cout<<"ERROR: no elevator was selected\n";
            break;
        }
        else{
            //select closest elevator
            Elevator* selectedElevator;

            //add floor to elevator and continue
            selectedElevator->addFloor(i);
            continue;
        }
        
    }    

    return 0;
} 