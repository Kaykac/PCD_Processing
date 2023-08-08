//
// Created by kaykac on 29.11.2022.
//

#include "Segmentation.h"
#include "CommonProcesses.h"


/*!
 * This class inherited from class CommonProcesses works the same as the constructor function of class CommonProcesses.
 * @param fname --> file path.
 */
Segmentation::Segmentation(const string &fname) : CommonProcesses(fname){}



/*!
 * This functions is virtual function for polymorphism (if used)
 */
void Segmentation::segmented(){

}

/*!
 * This functions is virtual function for polymorphism  (if used)
 */
void Segmentation::individual_savePCD(){

}

/*!
 * This functions is virtual function for polymorphism  (if used)
 */
void Segmentation::colorizedPCD(){

}

/*!
 * This functions is virtual function for polymorphism  (if used)
 */
void Segmentation::labeledPCD(){

}







