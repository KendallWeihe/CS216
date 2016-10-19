/*
 * bound_err class
 * it is a class used to handle out of bounds exceptions.
 *
 */
#ifndef BOUND_ERR_H
#define BOUND_ERR_H

#include <string>

using namespace std;

class bound_err
{
    public:
        //constructor
        bound_err(const string& i_what):what(i_what){};

        //System default assignment operator
        //System dafault copy constructor
        //System default ~bound_err() destructor

        //Set what caused the error
        void set_what(const string i_what) {what = i_what;}

        //Access what caused the error
        string get_what() const {return what;}

    private:
        string what;      //What caused the error
};

#endif  //BOUND_ERR_H
