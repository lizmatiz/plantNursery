#ifndef PLANTNURSERY_H
#define PLANTNURSERY_H

#include <iostream>
#include <string>
#include "plant.h"

class PlantNursery{
    public:
    static const int CAPACITY = 200;

    PlantNursery(){used = 0;}

    void load_from_file(std::istream& ifs);
    void show_all(std::ostream& outs) const;
    void add_plant(std::istream& ins);
    void remove(std::string pName, std::string pColor);
    void change_stock_amt(std::string pName, std::string pColor, int amt);
    void name_sort();
    void date_sort();
    void stock_sort();
    void show_plants(std::string p_color) const;
    void show_before(Date before_date) const;
    void show_colors(std::string p_name) const;
    double average();
    void save(std::ostream& ofs);
    

    private:

    Plant plantArr[CAPACITY];
    int used;

};

#endif