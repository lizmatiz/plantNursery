/**
 * @file plantNursery.h
 * @author Elizabeth Hooton
 * @brief PlantNursery class with all associated functions declared
 * @version 0.1
 * @date 2023-02-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef PLANTNURSERY_H
#define PLANTNURSERY_H

#include <iostream>
#include <string>
#include "plant.h"

class PlantNursery{
    public:
        static const int CAPACITY = 200; // static const var for array

        /**
         * @brief Construct a new Plant Nursery object
         * 
         */
        PlantNursery(){used = 0;}

        /**
         * @brief loads all the data from a file into an array of Plants
         * 
         * @param ifs (input file stream)
         */
        void load_from_file(std::istream& ifs);

        /**
         * @brief shows all of the Plants in the array
         * 
         * @param outs (output stream)
         */
        void show_all(std::ostream& outs) const;

        /**
         * @brief adds a Plant to the array
         * 
         * @param ins (input stream)
         */
        void add_plant(std::istream& ins);

        /**
         * @brief removes a Plant from the array
         * 
         * @param pName (name of Plant)
         * @param pColor (color of Plant)
         */
        void remove(std::string pName, std::string pColor);

        /**
         * @brief changes the stock of a Plant
         * 
         * @param pName (name of Plant)
         * @param pColor (color of Plant)
         * @param amt (amount to increase in stock)
         */
        void change_stock_amt(std::string pName, std::string pColor, int amt);

        /**
         * @brief sorts the Plants by name
         * 
         */
        void name_sort();

        /**
         * @brief sorts the Plants by date
         * 
         */
        void date_sort();

        /**
         * @brief sorts the Plants by amount of stock
         * 
         */
        void stock_sort();

        /**
         * @brief shows all of the Plants of a certain color
         * 
         * @param p_color (color of Plant)
         */
        void show_plants(std::string p_color) const;

        /**
         * @brief shows all of the Plants before a certain date
         * 
         * @param before_date 
         */
        void show_before(Date before_date) const;

        /**
         * @brief shows all of the different colors of a certain Plant
         * 
         * @param p_name (name of Plant)
         */
        void show_colors(std::string p_name) const;

        /**
         * @brief returns the average stock of Plants
         * 
         * @return double (average)
         */
        double average() const;

        /**
         * @brief saves the Plants back to the file
         * 
         * @param ofs (output file stream)
         */
        void save(std::ostream& ofs);
    

    private:
        Plant plantArr[CAPACITY]; // Plant array
        int used; // counter for Plants used in the array

};

#endif