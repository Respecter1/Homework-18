/*
	8. Виправте лістинг, наведений у вправі 7, та відкомпілюйте його.
*/

#include <iostream>
#include <string>

using namespace std;

class Animal
{
	friend void setValue(Animal&, int);//і яби цю функцію в классі писав вона дуже коротка 
	friend void setValue(Animal&, int,int);//і яби цю функцію в классі писав вона дуже коротка 

private:
	int itsWeight;
	int itsAge;
};

void setValue(Animal& theAnimal, int theWeight)//вага тварини
{
	theAnimal.itsWeight = theWeight;
}

void setValue(Animal& theAnimal, int theWeight, int theAge)//вага та вік тварини
{
	theAnimal.itsWeight = theWeight;
	theAnimal.itsAge = theAge;
}

int main()
{
	Animal peppy;
	setValue(peppy, 5);
	setValue(peppy, 7, 9);
	return 0;
}
