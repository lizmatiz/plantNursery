#include "plantNursery.h"
#include "plant.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void PlantNursery::load_from_file(std::istream& ifs){
    while(!ifs.eof()){
        plantArr[used].input(ifs) ;
        used++;
    }
}

void PlantNursery::show_all(std::ostream& outs){
    for (int i = 0; i < used; i++){
        plantArr[i].output(outs);
    }
}

void PlantNursery::add_plant(std::istream& ins){
    Plant p;
    p.input(ins);
    plantArr[used] = p;
    used++;
}

void PlantNursery::remove(std::string pName, std::string pColor){
    bool exists;
    int index;
    for(int i = 0; i < used; i++){
        if(plantArr[i].get_name() == pName){
            if(plantArr[i].get_color() == pColor){
                exists = true;
                index = i;
                cout << "index: " << index << endl;
                for(int j = index; j < used; j++){
                    plantArr[j] = plantArr[j+1];
                }
            }
        }
    }
    if(exists == true){
        used --;
    }
    else{
        cout << "Sorry, the option you requested does not exist!" << endl;
    }
}

void PlantNursery::change_stock_amt(std::string pName, std::string pColor, int amt){
    bool exists;
    int index;
    for(int i = 0; i < used; i++){
        if(plantArr[i].get_name() == pName){
            if(plantArr[i].get_color() == pColor){
                exists = true;
                index = i;
                cout << "index: " << index << endl;
            }
        }
    }
    if(exists == true){
        plantArr[index].change_stock(amt);
    }
    else{
        cout << "Sorry, the option you requested does not exist!" << endl;
    }    
}

void PlantNursery::name_sort(){
    int i, upperBound = used - 1; //upper_bound is used to increase efficiency by ignoring already sorted items
    Plant tmp; //whatever type the array is holding, need for swapping
    bool done = false;

    while(!done){
        done = true;
        for(i = 0; i < upperBound; i++){
            if(plantArr[i].get_name() > plantArr[i + 1].get_name()){
                tmp = plantArr[i + 1];
                plantArr[i + 1] = plantArr[i];
                plantArr[i] = tmp;
                done = false;
            }
        }
    upperBound--;
    }
}

void PlantNursery::date_sort(){
    int i, j, smallsp;
    Plant tmp; //whatever type the array is holding, need for swapping

    // this loop keeps track of the position where I am putting the smallest piece of data
    for(i = 0; i < used - 1; i++){
        smallsp = i;

        // this loop looks for the smallest piece of data in the rest of the array
        for(j = i + 1; j < used; j++){
            // if the data where I am looking is "smaller" than the data in the current smallsp, make smallsp equal to j
            if (plantArr[j].get_cameIn() < plantArr[smallsp].get_cameIn()){
                smallsp = j;
            }
        }

        // swap the smallest data into the correct location (given by i)
        tmp = plantArr[i];
        plantArr[i] = plantArr[smallsp];
        plantArr[smallsp] = tmp;
    }
}

void PlantNursery::stock_sort(){
    for (int i = 1; i < used; i++)
    {
        Plant tmp = plantArr[i]; //whatever type the array is holding

        // Move all larger elements "up" one spot in the array
        int j = i;
        while (j > 0 && plantArr[j - 1].get_stock() > tmp.get_stock())
        {
            plantArr[j] = plantArr[j - 1];
            j--;
        }

        // Insert the element at the correct position
        plantArr[j] = tmp;
    }
}

void PlantNursery::show_plants(std::string p_color){
    cout << endl;
    int total = 0;
    for(int i = 0; i < used; i++){
        if(plantArr[i].get_color() == p_color){
            plantArr[i].output(cout);
            cout << endl;
            total++;
        }
    }

    cout << "Total plants that are " << p_color << " are / is " << total << endl << endl;
}

void PlantNursery::show_before(Date before_date) const{
    cout << endl;
    for(int i = 0; i < used; i++){
        if(plantArr[i].get_cameIn() < before_date){
            plantArr[i].output(cout);
        }
    }
}

void PlantNursery::show_colors(std::string p_name) const{
    cout << endl;
    for(int i = 0; i < used; i++){
        if(plantArr[i].get_name() == p_name){
            plantArr[i].output(cout);
        }
    }
}

double PlantNursery::average(){
    double sum = 0;
    double total = 0;
    for(int i = 0; i < used; i++){
        sum += plantArr[i].get_stock();
        total++;
    }
    return sum/total;
}