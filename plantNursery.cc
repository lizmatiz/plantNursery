/**
 * @file plantNursery.cc
 * @author Elizabeth Hooton
 * @brief PlantNursery implementation of functions
 * @version 0.1
 * @date 2023-02-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "plantNursery.h"
#include "plant.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void PlantNursery::load_from_file(std::istream& ifs){
    while(!ifs.eof()){ // while not the end of file, call the input function for each Plant
        plantArr[used].input(ifs) ;
        used++; // increment used
    }
}

void PlantNursery::show_all(std::ostream& outs) const{
    for (int i = 0; i < used; i++){ // for all the Plants, output them
        plantArr[i].output(outs);
    }
}

void PlantNursery::add_plant(std::istream& ins){
    Plant p; // declare a Plant object
    p.input(ins); // input data for the Plant object
    plantArr[used] = p; // set the new Plant in the array to the Plant object
    used++; // increment used
}

void PlantNursery::remove(std::string pName, std::string pColor){
    bool exists; // if the requested Plant exists or not
    int index; // index in which the Plant is found
    for(int i = 0; i < used; i++){ // for all of the Plants
        if(plantArr[i].get_name() == pName){ // see if the name is equal to the user entered name
            if(plantArr[i].get_color() == pColor){ // see if the color is equal to the user entered color
                exists = true;
                index = i;
                for(int j = index; j < used; j++){ // move all of the other Plants
                    plantArr[j] = plantArr[j+1];
                }
            }
        }
    }
    if(exists == true){
        used --; // if the Plant existed, decrement used
    }
    else{
        cout << "Sorry, the option you requested does not exist!" << endl;
    }
}

void PlantNursery::change_stock_amt(std::string pName, std::string pColor, int amt){
    bool exists; // see if the Plant exists
    int index; // index if it does exist

    // checks all of the Plants to see if the name and color match
    for(int i = 0; i < used; i++){ 
        if(plantArr[i].get_name() == pName){
            if(plantArr[i].get_color() == pColor){
                exists = true; // if it matches, exists = true
                index = i;
            }
        }
    }
    if(exists == true){
        plantArr[index].change_stock(amt); // if the Plant exists, update the stock
    }
    else{
        cout << "Sorry, the option you requested does not exist!" << endl;
    }    
}

void PlantNursery::name_sort(){
    int i, upperBound = used - 1; // bubble sort!
    Plant tmp;
    bool done = false;

    while(!done){
        done = true; // assume you are done to start
        for(i = 0; i < upperBound; i++){
            
            // if the name > the name next to it
            if(plantArr[i].get_name() > plantArr[i + 1].get_name()){ 
                tmp = plantArr[i + 1]; // swap
                plantArr[i + 1] = plantArr[i];
                plantArr[i] = tmp;
                done = false; // if the swap had to be done, it is not sorted
            }
        }
    upperBound--;
    }
}

void PlantNursery::date_sort(){ // selection sort!
    int i;
    int j;
    int smallSpot; // small spot
    Plant tmp; // temp for swapping

    // keeps track of where the smallest piece of data is
    for(i = 0; i < used - 1; i++){
        smallSpot = i;

        // looks for the smallest piece of data in the rest of the array
        for(j = i + 1; j < used; j++){

            // if the current data is smaller than the small spot, make small spot equal to j
            if (plantArr[j].get_cameIn() < plantArr[smallSpot].get_cameIn()){
                smallSpot = j;
            }
        }

        // swap the smallest data into the right place
        tmp = plantArr[i];
        plantArr[i] = plantArr[smallSpot];
        plantArr[smallSpot] = tmp;
    }
}

void PlantNursery::stock_sort(){ // insertion sort!
    for (int i = 1; i < used; i++){
        Plant tmp = plantArr[i];

        // move all the Plants with the larger stock up
        int j = i;
        while (j > 0 && plantArr[j - 1].get_stock() > tmp.get_stock()){ 
            plantArr[j] = plantArr[j - 1];
            j--;
        }

        // insert the Plant in the correct position
        plantArr[j] = tmp; 
    }
}

void PlantNursery::show_plants(std::string p_color) const{
    cout << endl;
    int total = 0;
    for(int i = 0; i < used; i++){ // for all of the Plants
        if(plantArr[i].get_color() == p_color){ // if the color matches the user input color
            plantArr[i].output(cout); // output the Plant
            cout << endl;
            total++; // increment the total
        }
    }
    
    cout << "Total plants that are " << p_color << " are / is " << total << endl << endl;
}

void PlantNursery::show_before(Date before_date) const{
    cout << endl;
    for(int i = 0; i < used; i++){ // for all of the Plants
        if(plantArr[i].get_cameIn() < before_date){ // if they are before the user given date
            plantArr[i].output(cout); // output the Plant
        }
    }
}

void PlantNursery::show_colors(std::string p_name) const{
    cout << endl;
    for(int i = 0; i < used; i++){ // for all of the Plants
        if(plantArr[i].get_name() == p_name){ // if their name is the same as the user input
            plantArr[i].output(cout); // output the Plant
        }
    }
}

double PlantNursery::average() const{
    double sum = 0;
    double total = 0;
    for(int i = 0; i < used; i++){ // for all the Plants
        sum += plantArr[i].get_stock(); // add the stock to the sum
        total++; // increment the total
    }
    return sum/total; // return the average
}

void PlantNursery::save(std::ostream& ofs){
    for(int i = 0; i < used; i++){ // for all the Plants
        plantArr[i].output(ofs); // output them
    }
}