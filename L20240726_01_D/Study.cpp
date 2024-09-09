#include <iostream>
using namespace std;

int CharacterHp; // ü��
int CharacterDam; // ���ݷ�
int CharacterDefence; // ����

int MonsterHp;
int MonsterDam;
int MonsterDefence;

void initializeCharacter();
void cininitializeCharacter();

void initializeMonster();
void cininitializeMonster();

void displayCharacterStats();
void displayMonsterStats();
void characterAttack(); // ĳ���Ͱ� ���͸� �����Ͽ� ������ ü���� ����
void monsterAttack();	// ���Ͱ� ĳ���͸� �����Ͽ� ĳ������ ü���� ����

int study()
{
	initializeCharacter();
	initializeMonster();
	displayCharacterStats();
	displayMonsterStats();
	cout << "\n";


	while (true)
	{
		cout << "ĳ���Ͱ� ���͸� �����մϴ�." << "\n";
		characterAttack();
		displayMonsterStats();
		cout << "���Ͱ� ĳ���͸� �����մϴ�." << "\n";
		monsterAttack();
		displayCharacterStats();

		if (CharacterHp <= 0 || MonsterHp <= 0)
			break;
	}

	if (CharacterHp <= 0)
		cout << "Monster �¸�";
	else if (MonsterHp <= 0)
		cout << "Character �¸�";

	return 0;
}

// ĳ���� �ʱ�ȭ
void initializeCharacter()
{
	CharacterHp = 100;
	CharacterDam = 20;
	CharacterDefence = 10;
}
void cininitializeCharacter()
{
	cout << "ĳ���� Hp | Dam | Defence : ";
	cin >> CharacterHp >> CharacterDam >> CharacterDefence;
}

// ���� �ʱ�ȭ
void initializeMonster()
{
	MonsterHp = 100;
	MonsterDam = 30;
	MonsterDefence = 5;
}

void cininitializeMonster()
{
	cout << "���� Hp | Dam | Defence : ";
	cin >> CharacterHp >> CharacterDam >> CharacterDefence;
}

void displayCharacterStats()
{
	cout << "ĳ������ ���� ü�� | ���ݷ� | ���� : " << CharacterHp << " | " << CharacterDam << " | " << CharacterDefence << endl;
}

void displayMonsterStats()
{
	cout << "������ ���� ü�� | ���ݷ� | ���� : " << MonsterHp << " | " << MonsterDam << " | " << MonsterDefence << endl;

}

void characterAttack()
{
	int chDam = max(0, CharacterDam - MonsterDefence);
	MonsterHp -= chDam;
}

void monsterAttack()
{
	int monDam = (0, MonsterDam - CharacterDefence);
	CharacterHp -= monDam;
}
