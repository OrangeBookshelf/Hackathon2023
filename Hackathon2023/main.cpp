#include "hackathon.hpp"

int main(void) 
{
    int menuChoice = 0;

    std::cout << "GAME NAME" << std::endl;
    do
    {
        std::cout << "1: Play\n2: Quit" << std::endl;
        std::cin >> menuChoice;
    } while(menuChoice < 1 || menuChoice > 2);

    if (menuChoice == 1)
    {
        system("pause");
        system("cls");

        //this is where the entire program goes
         
        srand(time(NULL));

    }
    


    return 0;
}