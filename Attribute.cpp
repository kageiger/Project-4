/**
 * Attribute.cpp
 *
 * Katherine Geiger, Keyaria Walker
 * kageiger, keyariaw
 *
 * EECS 183: Project 4
 *
 * This program matches people based on their
 *  answers to a personalily test 
 */

#include "Attribute.h"


Attribute::Attribute() {
    index = 0;
    points = 0;
}


int Attribute::getValueWithinRange(int value) {
// checks if parameter entered is within range
    if ((value >= 0) && (value < MAX_NUM_ATTRIBUTES)) {
        return value;
    }
// if it is above range, return the last value in the range
    if (value > (MAX_NUM_ATTRIBUTES - 1)) {
        return (MAX_NUM_ATTRIBUTES - 1);
    }
// if it is not within or above range, it is below so set it to zero
    else {
        value = 0;
    } 
        return value;
}


Attribute::Attribute(int inIndex, int inPoints) {
// sets the parameter inIndex equal to the checked validity parameter  
    inIndex = getValueWithinRange(inIndex);
// sets the parameters equal to index and points  
    index = inIndex;
    points = inPoints;
}


int Attribute::getIndex()  {
    return index;
}


int Attribute::getPoints()  {
    return points;
}


void Attribute::setIndex(int inIndex) {
 // checks if input is within range   
    inIndex = getValueWithinRange(inIndex);
// then sets the input inIndex equal to index
    index = inIndex;
}



void Attribute::setPoints(int inPoints) {
    points = inPoints;
}


void Attribute::read(istream &ins) {
    ins >> index;
    ins >> points;
    setIndex(index);
}


void Attribute::write(ostream &outs)  {
    outs << index;
    outs << points;
}
