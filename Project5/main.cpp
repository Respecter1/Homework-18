/*
	5. Жучки: що неправильно у цій програмі?
	Відповідь:
				- не правильна реалізація ключового слова freind
				
*/

#include <iostream>
#include <string>

using namespace std;

class Animal;//це нажаль виділити 

void setValue(Animal&, int);// впринципі правильно що оголошено више прототипу але воно не треба 
//це треба в класс запихнути і буде все працювати 

class Animal
{
public:
	int GetWeight() const { return itsWeight; }
	int GetAge() const { return itsAge; }

private:
	int itsWeight;
	int itsAge;
};

setValue(Animal& theAnimal, int theWeight)//не висточає в классі прототипа функції з реалізацією ключового слова friend 
{
	friend class Animal;//це круто але ні, так не роблять 
	theAnimal.itsWeight = theWeight;
}

int main()
{
	Animal peppy;
	setValue(peppy, 5);
	return 0;
}
