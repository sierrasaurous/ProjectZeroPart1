//
//  main.cpp
//  Project Zero
//
//  Created by Sierra on 8/19/15.
//  Copyright (c) 2015 Sierra Adibi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    
    // Define how many machines and define the median and range values for each.
    
    int numofmachines = 3;
    int firstmachine;

    vector<int> machineMedian (numofmachines);
    vector<int> machineRange (numofmachines);
    vector<int> machineCount (numofmachines,0);
    vector<double> lastValue (numofmachines);
    vector<double> averageValue (numofmachines);
    vector<double> deviationValue (numofmachines);
    vector<double> highValue (numofmachines);
    vector<double> lowValue (numofmachines);
    
    for (int i=0;i < numofmachines; i++){
        machineMedian.at(i) = rand()%10;
        machineRange.at(i) = rand()%10;
        // cout << "The median value for machine " << i+1 << " is " << machineMedian.at(i) << endl;
       //  cout << "The range value for machine " << i+1 << " is " << machineRange.at(i)<< endl;
        
    };
    

    
    
    cout << "\n Welcome to the Multi-Armed Bandit \n";
    cout << "There are " << numofmachines << " machines available for play. \n";
    cout << "Which machine would you like to play first? \n";
    cin >> firstmachine;
    
    while((firstmachine > numofmachines) || (firstmachine < 1)){
        cout << "Please enter a number between 1 and " << numofmachines << endl;
        cin >> firstmachine;
        }

    int currentmachine = firstmachine;
    
    
    while (currentmachine != 0){
        if (currentmachine > numofmachines || currentmachine < 1){
            cout << "Please enter a number between 1 and " << numofmachines << endl;
            cout << "To exit, enter the number zero.\n";
            cin >> currentmachine;
            
        }
    
    
        if(currentmachine == 0){
            break;
        }
        
        cout << "\n You played machine number " << currentmachine  << endl;
        int position = currentmachine - 1;
        machineCount.at(position) = machineCount.at(position) + 1;
        double r1 = (double) rand()/RAND_MAX*machineRange.at(position);
        double r2 = (double) rand()/RAND_MAX*machineRange.at(position);
        lastValue.at(position) = machineMedian.at(position) + r1 - r2;
        
        
        averageValue.at(position) = (averageValue.at(position)*(machineCount.at(position)-1)+lastValue.at(position))/machineCount.at(position);
        
        if (machineCount.at(position) ==1){
            lowValue.at(position) = lastValue.at(position);
            highValue.at(position) = lastValue.at(position);
        };
        
        if(lastValue.at(position)<lowValue.at(position)){
            lowValue.at(position)=lastValue.at(position);
        };
        
        if (lastValue.at(position)>highValue.at(position)){
            highValue.at(position) = lastValue.at(position);
        };
        
        
 //       cout << "Rounds on this Machine: " << machineCount.at(position) << endl;
 //       cout << "Reward This Round: " << lastValue.at(position) <<endl;
 //       cout << "Average Reward for this Machine: " << averageValue.at(position) << endl;
 //       cout << "Best Reward for this Machine: " << highValue.at(position) << endl;
 //       cout << "Worst Reward for this Machine: " << lowValue.at(position) << endl;
   
        cout << "Current Results: \n \n";
        cout << "Machine Number |  Last Pull | Average |   High   |     Low \n";
        cout << "---------------------------------------------------------------\n";
        
        for(int j=0;j<numofmachines;j++){
            
            cout << "       " << j+1 << "           " << lastValue.at(j) << "    " << averageValue.at(j) << "    ";
            cout << highValue.at(j) << "    " << lowValue.at(j) << endl << endl;
        };
        

    
    
    
    cout << "To continue playing, please select a machine number to play.\n";
    cout << "To exit the game, enter the number 0. \n";
    cin >> currentmachine;
    
        if(currentmachine==0){
            break;
        };
    
    };
    
    return 0;
};
