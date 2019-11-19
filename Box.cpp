//Created by Matt Andrews
//Based on code by Matthew Perry
//box.cpp

#include <iostream>
#include <ostream>
#include "box.hpp"
#include <string>

using std::cout;
using std::endl;
using std::ostream;



//Base Abstract Class
//friend function for printing and passing ostream
std::ostream & operator<<(std::ostream& os, const Box & b)
{
    b.print(os);
    return os;
}
//getters
int Box::getWidth()const
{
    return _boxWidth;
}
int Box::getHeight()const
{
    return _boxHeight;
}
//setters
void Box::setWidth(int userWidth)
{
    _boxWidth = userWidth;
}
void Box::setHeight(int userHeight)
{
    _boxHeight = userHeight;
}

//default constructor
Box::Box(){
    _boxHeight = 1;
    _boxWidth = 1;
    cout << "I made a box and set it to " << _boxWidth << " by " << _boxHeight << "!" << endl;
    /*Box::moreBoxes();
    int numBoxes = _BoxCounter;
    cout << "Number of Boxes: " << numBoxes << endl;
    */
}
//User Input Constructor
Box::Box(int userWidth, int userHeight)
{
    _boxHeight = userHeight;
    _boxWidth = userWidth;
    cout << "I made a box and set it to " << _boxWidth << " by " << _boxHeight <<  "!" << endl;
}
//Destructor
Box::~Box()
{
    cout << "I destroyed a box!" << endl;
}

/*
int Box::numBoxes() const //returns the current number of boxes
{
    int numBoxes = _BoxCounter;
    return numBoxes;
}
int Box::getBoxCounter()
{
    return _BoxCounter;
}

void Box::moreBoxes() //adds a box
{
    _BoxCounter++;
}
void Box::lessBoxes() //subtracts a box
{
    _BoxCounter--;
}
*/


//Filled BOx Constructors
FilledBox::FilledBox() : Box()
{
    cout << "I made a default filled box" << endl;
}
FilledBox::FilledBox(int userWidth, int userHeight) : Box(userWidth, userHeight)
{
    cout << "I made a filled box and set it to " << userWidth << " by " << userHeight << endl;
}
std::string FilledBox::type()const
{
    return "Filled";
}

//Print a Filled Box
void FilledBox::print(std::ostream & os)const
{
    for(auto i = 0; i < Box::getHeight(); i++){
        for(auto ii = 0; ii < Box::getWidth(); ii++){
            os << "x";
        }
        os << std::endl;
    }
}

//destroy a filled box
FilledBox::~FilledBox()
{
    cout << "I destroyed a filled box" << endl;
}


//Hollow Box Constructors
HollowBox::HollowBox() : Box()
{
    cout << "I made a default hollow box" << endl;
}
HollowBox::HollowBox(int userWidth, int userHeight) : Box(userWidth, userHeight)
{
    cout << "I made a hollow box and set it to " << userWidth << " by " << userHeight << endl;
}


std::string HollowBox::type()const
{
    return "Hollow";
}

//Print a Hollow Box
void HollowBox::print(std::ostream & os)const{
    for(auto i = 0; i < Box::getHeight(); i++){
        for(auto ii = 0; ii < Box::getWidth(); ii++){
            if(i == 0 || i == Box::getHeight()-1){
                os << "x";
            }
            else{
                if(ii == 0 || ii == Box::getWidth()-1){
                    os << "x";
                }
                else{
                    os << " ";
                }
            }
        }
        os << std::endl;
    }
}

//destroy a hollow box
HollowBox::~HollowBox()
{
    cout << "I destroyed a hollow box" << endl;
}

// Checkered Box Constructors
CheckeredBox::CheckeredBox() : Box()
{
    cout << "I made a default checkered box" << endl;
}
CheckeredBox::CheckeredBox(int userWidth, int userHeight) : Box(userWidth, userHeight)
{
    cout << "I made a checkered box and set it to " << userWidth << " by " << userHeight << endl;
}
std::string CheckeredBox::type()const
{
    return "Checkered";
}

//print a Checkered Box
void CheckeredBox::print(std::ostream & os)const{
    for(auto i = 0; i < Box::getHeight(); i++){
        for(auto ii = 0; ii < Box::getWidth(); ii++){
            os << ((i+ii) % 2 == 0 ? "x" : " ");
        }
        os << std::endl;
    }
}

//destroy a checkered box
CheckeredBox::~CheckeredBox()
{
    cout << "I destroyed a checkered box" << endl;
}




//Box Factory
std::unique_ptr<Box> boxFactory(char c, int w, int h){
    if(c == 'f'){
        std::unique_ptr<Box> b = std::make_unique<FilledBox>(w,h);
        return b;
    }
    if(c=='c'){
        std::unique_ptr<Box> b =  std::make_unique<CheckeredBox>(w,h);
        return b;
    }
    if(c=='h'){
        std::unique_ptr<Box> b =  std::make_unique<HollowBox>(w,h);
        return b;
    }
    return 0;
}

