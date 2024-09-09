#include <iostream>
using namespace std;

namespace unreal
{

};

class Actor {
// ���� ������
// �ܺο��� ���� ����
public :
	int hp;
	int ap;
	int dp;

	void DisplayStats()
	{

	}

	void Attack()
	{

	}

	
// �ش� Ŭ���� �޼ҵ�� ����� ���� �Ļ� Ŭ���������� ������ �����ϴ�
protected:
// ���� �Ұ��� + ���ο����� ����
private:
};

int character_hp;
int character_ap;
int character_dp;

int monster_hp;
int monster_ap;
int monster_dp;

// Attack �ȿ��� ����ϴ� �Լ� �̹Ƿ� class ���� private�� �����Ͽ�, �ش� �Լ��� �ٸ� ������ ������� �ʴ´ٴ� ���� �� �� �ִ�.
int DeductDpFromAp(int dp, int ap)
{
	return min(0, dp - ap);
}

void initializeCharacter()
{
	character_hp = 100;
	character_ap = 10;
	character_dp = 5;
}

void initializeMonster()
{
	monster_hp = 120;
	monster_ap = 5;
	monster_dp = 1;
}

void displayCharacterStats()
{
	cout << "�÷��̾� ���� [hp : " << character_hp << ", ap : " << character_ap << "dp : " << character_dp << "] �Դϴ�." << endl;
}

void displayMonsterStats()
{
	cout << "���� ���� [hp : " << monster_hp << ", ap : " << monster_ap << "dp : " << monster_dp << "] �Դϴ�." << endl;
}

void characterAttack()
{
	cout << "ĳ���� ����!" << endl;
	//monster_hp = max(0, monster_hp + min(0, monster_dp - character_ap));
	monster_hp = max(0, monster_hp + DeductDpFromAp(monster_dp, character_ap));
	cout << "���� ���� HP : " << monster_hp << endl;
}



void monsterAttack()
{
	cout << "���� ����!" << endl;
	// character_hp = max(0, character_hp + min(0, character_dp - monster_ap));
	character_hp = max(0, character_hp + DeductDpFromAp(character_dp, monster_ap));
	cout << "ĳ���� ���� HP : " << character_hp << endl;
}


int main()
{
	Actor monster;
	Actor character;
	
	monster.hp;
	monster.ap;
	monster.dp;
	monster.Attack();


	initializeCharacter();
	initializeMonster();

	while (character_hp > 0 && monster_hp > 0)
	{
		displayCharacterStats();
		displayMonsterStats();

		characterAttack();
		if (monster_hp <= 0)
			break;

		monsterAttack();
		if (character_hp <= 0)
			break;
	}


	cout << "���� ����. ���� : ";
	if (character_hp <= 0)
		cout << "����" << endl;
	else
		cout << "�÷��̾�" << endl;

	return 0;
}