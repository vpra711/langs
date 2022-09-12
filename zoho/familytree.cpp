#include <iostream>
#include <deque>

class person
{
    std::string name;
    person* father;
    person* mother;
    person* spouse;
    person* child;
    person* brother;
    int gender;

    person(std::string name, person* father, person* mother, person* spouse, person* child, person* brother, int gender)
    {
        this->name = name;
        this->father = father;
        this->mother = mother;
        this->spouse = spouse;
        this->child = child;
        this->brother = brother;
        this->gender = gender;

    }
};

std::deque<person*> members;

int main()
{
    person* main;
    return 0;
}

person* createPerson(person* member)
{

}

person* search(person* member)
{
    if(member == NULL)
        return NULL;
    
    
    

}