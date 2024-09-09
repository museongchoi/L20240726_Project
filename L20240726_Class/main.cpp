#include <iostream>
using namespace std;

namespace unreal
{

}

class Actor {
// ���� ������
// �ܺο��� ���� ����
public:
	int Hp;
	int Ap;
	int Dp;

	Actor() // ������
	{
		initialize(0, 0, 0);
	}

	void initialize(int newhp, int newap, int newdp)
	{
		Hp = newhp;
		Ap = newap;
		Dp = newdp;
	}

	void DisplayStats()
	{
		cout << "���� [hp : " << Hp << ", ap : " << Ap << ", dp : " << Dp << "] �Դϴ�." << endl;
	}

	// ���� ���� �ʴ� ���
	// virtual : ���� �����.
	virtual int GetDeal(Actor other)
	{
		cout << "����!" << endl;
		//other.Hp = max(0, other.Hp + DeductDpFromAp(other.Dp, Ap));
		//return DeductDpFromAp(other.Dp, Ap);
		//return DeductDpFromAp(other->Dp, Ap); // == return DeductDpFromAp((*other).Dp, Ap);
		return max(0, DeductDpFromAp(other.Dp, Ap));

	}

	//int Attack(int hp, int dp, int ap)
	//{
	//	cout << "����!" << endl;
	//	character_hp = max(0, character_hp + DeductDpFromAp(character_dp, monster_ap));
	//	cout << "ĳ���� ���� HP : " << character_hp << endl;
	//	return 0;
	//}


	// �ش� Ŭ���� �޼ҵ�� ����� ���� �Ļ� Ŭ���������� ������ �����ϴ�.
	// ���� �Ұ��� + ���ο����� ����.
protected:
	int DeductDpFromAp(int dp, int ap)
	{
		return max(0, ap - dp);
	}

private:
	// Attack �ȿ��� ����ϴ� �Լ� �̹Ƿ� class ���� private�� �����Ͽ�, �ش� �Լ��� �ٸ� ������ ������� �ʴ´ٴ� ���� �� �� �ִ�.
	// ��ӹ��� Ŭ������ �����ϱ� ���� �Լ��̹Ƿ� �ڸ��� protected�� �Ű��.
	//int DeductDpFromAp(int dp, int ap)
	//{
	//	return min(0, dp - ap);
	//}
};

// ���
class Character : public Actor
{
public :

	Character() // ������
	{
		attackCount = 0;
		skillAp = 30;
	}

	int GetDeal(Actor other) override
	{
		// virtual Function ���
		//Actor::GetDeal(other);

		cout << "����!" << endl;
		//other.Hp = max(0, other.Hp + DeductDpFromAp(other.Dp, Ap));
		attackCount++;
		if (attackCount % 3 == 0) // attackCount 3��° ���� skillAp ���
		{
			return DeductDpFromAp(other.Dp, skillAp);
		}
		else
		{
			return DeductDpFromAp(other.Dp, Ap);
		}
	}

private:
	int attackCount;
	int skillAp;
};

int main()
{
	
	//Actor character; // Actor Ŭ������ character
	Character character; // Character Ŭ������ character : ���� Character Ŭ������ ����ִٰ� �ص� �����Ѵ�. ������
	Actor monster;

	character.initialize(100, 15, 5);
	monster.initialize(150, 10, 20);

	while (character.Hp > 0 && monster.Hp > 0)
	{
		cout << "ĳ����";
		character.DisplayStats();
		cout << "����";
		monster.DisplayStats();
		cout << endl;

		// ���� �����ؼ� �ѱ�� pass by value : ���� ������ ���� x
		// �ּ� ���� �����Ͽ� ���� ���� ���� Alias(����)�� �����ϴ� ��� pass by regerence : ���� ������ ���� o

		cout << "ĳ����";
		//int newHP = character.GetDeal(monster);
		//character.GetDeal(monster);
		monster.Hp = max(0, monster.Hp - character.GetDeal(monster)); // GetDeal�� monster.Dp �ʿ��� ���� �Ѱ��ִ� ����� ����.
		if (monster.Hp <= 0)
			break;
		cout << "������ ���� Hp : " << monster.Hp << endl;

		cout << "����";
		character.Hp = max(0, character.Hp - monster.GetDeal(character));
		if (character.Hp <= 0)
			break;
		cout << "ĳ������ ���� Hp : " << character.Hp << endl;
		cout << endl;
	}

	cout << "���� ����. ���� : ";
	if (character.Hp <= 0)
		cout << "����" << endl;
	else
		cout << "�÷��̾�" << endl;

	return 0;
}