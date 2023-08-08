//
// Created by kaykac on 29.11.2022.
//


#include "RegionGrowing.h"


/*!
 * This class inherited from class Segmentation works the same as the constructor function of most base class CommonProcesses.
 * @param fname --> file path.
 */
RegionGrowing::RegionGrowing(const string &fname) : Segmentation(fname) {}


/*!
 * This function contains an output to see if it was called correctly
 */
void RegionGrowing::colorizedPCD(){
    cout<<"colorizedPCD function in RegionGrowing"<<endl;   //! for Detection whether we can reach the function
}

/*!
 * This function contains an output to see if it was called correctly
 */
void RegionGrowing::individual_savePCD() {
    cout<<"individual_savePCD function in RegionGrowing"<<endl;    //! for Detection whether we can reach the function
}