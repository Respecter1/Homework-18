/*
	6. �������� ������, ��������� � ����� 5, �� ����������� ����.

	³������:
			 ������� ����� friend ��������������� ��� ������� ������� �� ��������� ����� ����� ����� ������ ��� ��������. 
			 �� �������� �������� ������������ ��������� :: ��� ������� �� ��������� �����. 
			 ����, �� ������ ��������������� friend, ��� ������� ��� ���� ��������� �� �������.
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

//void Animal:: ����� � ����� ��� ���� �� ������� friend
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
