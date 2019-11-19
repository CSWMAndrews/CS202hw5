//Created by Matt Andrews
//Based on code by Matthew Perry
//box.hpp

#ifndef BOX_HPP_INCLUDED
#define BOX_HPP_INCLUDED
#include <string>
#include <ostream>
#include <memory>


class Box {
    friend std::ostream & operator<<(std::ostream& os, const Box & b);
    //enable << operator
public:
    //virtual for Box Print
    virtual void print(std::ostream &os) const =0;
    //virtual for report type
    virtual std::string type()const =0;

    /*
    static int getBoxCounter(); //const; //returns the current number of boxes
    int numBoxes() const; //returns the current number of boxes
    void moreBoxes(); //adds a box
    void lessBoxes(); //subtracts a box
    */

    //Default Constructor
    Box();
    //Passed Value Constructor
    Box(int userWidth, int userHeight);
    //Pure Virtual Destructor
    virtual ~Box() =0;

    //Setters and Getters
    void setWidth(int userWidth);
    void setHeight(int userHeight);
    int getWidth()const;
    int getHeight()const;

private:
    //Base Class Box Values
    int _boxWidth;
    int _boxHeight;

    //Box Counter
    //static int _BoxCounter;
};



//Filled Box
class FilledBox : public Box{
public:
    void print(std::ostream & os) const override;
    std::string type()const override;
    FilledBox();
    FilledBox(int userWidth, int userHeight);
    ~FilledBox();
};



//Hollow Box
class HollowBox : public Box{
public:
    void print(std::ostream & os)const override;
    std::string type() const override;
    HollowBox();
    HollowBox(int userWidth, int userHeight);
    ~HollowBox();
};



//Checkered Box
class CheckeredBox : public Box{
public:
    void print(std::ostream & os)const override;
    std::string type()const override;
    CheckeredBox();
    CheckeredBox(int userWidth, int userHeight);
    ~CheckeredBox();
};



//Box Factory
std::unique_ptr<Box> boxFactory(char c, int w, int h);

#endif // BOX_HPP_INCLUDED