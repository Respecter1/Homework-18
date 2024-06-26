/*
	6. Виправте лістинг, наведений у вправі 5, та відкомпілюйте його.

	Відповідь:
			 Ключове слово friend використовується для надання доступу до приватних членів класу іншим класам або функціям. 
			 Це дозволяє уникнути використання оператора :: для доступу до приватних членів. 
			 Отже, ви можете використовувати friend, щоб зробити код більш зрозумілим та зручним.
*/

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	int GetWeight() const { return itsWeight; }
	int GetAge() const { return itsAge; }
	friend void setValue(Animal&, int);
private:
	int itsWeight;
	int itsAge;
};

//void Animal:: можно і через але якщо ми тренуємо friend
void setValue(Animal& theAnimal, int theWeight)
{
	theAnimal.itsWeight = theWeight;
}

int main()
{
	Animal peppy;
	setValue(peppy, 5);
	return 0;
}
