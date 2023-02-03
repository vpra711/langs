#include <iostream>

class printer
{
    std::string _name;
    int _availablePaper;

    public:
        printer(std::string name,int paper)
        {
            _name = name;
            _availablePaper = paper;
        }

        void print(std::string txtDoc)
        {
            int requiredPaper = txtDoc.length()/10;

            if(requiredPaper > _availablePaper)
                throw "No Paper Available";
            std::cout << txtDoc << std::endl;
            _availablePaper -= requiredPaper;
        }
}; 

int main()
{
    printer HP = printer("HP 1234",20);
    try
    {
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
        HP.print("My name is V.P.R.Achutharaman");
    }
    catch(const char *txtExc)
    {
        std::cout << txtExc << std::endl;
    }
    return 0;
}