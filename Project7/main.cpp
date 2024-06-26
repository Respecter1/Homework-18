/*
	7. Жучки: що неправильно у цій програмі?
*/

#include <iostream>
#include <string>

using namespace std;

class Animal;//тут є сенс, для наших марних прототипів функцій

void setValue(Animal&, int);//не знаю навіщо ці прототипи не бачу в них сенсу 

void setValue(Animal&, int, int);//не знаю навіщо ці прототипи не бачу в них сенсу 

class Animal
{
	friend void setValue(Animal&, int);//і яби цю функцію в классі писав вона дуже коротка 

private:
	int itsWeight;
	int itsAge;
};

void setValue(Animal& theAnimal, int theWeight)
{
	theAnimal.itsWeight = theWeight;
}

void setValue(Animal& theAnimal, int theWeight, int theAge)// тут не має доступу для наших полів але якщо ми зробимо аналагічно функції яка зверху воно все запрацює 
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
