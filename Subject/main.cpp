#include <stdio.h>

#include <iostream>



void SetPotion(int Count, int* P_HPPotion, int* P_MPPotion, int* P_StatPotion)
{
	*P_HPPotion += Count;
	*P_MPPotion += Count;
	*P_StatPotion += Count;
}


int main(void)
{
	int Level = 1;
	int Status[4] = { 0 };
	int HPPotion = 5;
	int MPPotion = 5;
	int StatPotion = 5;



	while (1)
	{
		printf("HP와 MP를 입력해주세요.\n");
		scanf_s("%d %d", &Status[0], &Status[1]);

		if (Status[0] <= 50 || Status[1] <= 50)
		{
			printf("HP와 MP는 50이하가 될 수 없습니다! 다시 입력해주세요\n");
		}
		else
		{
			printf("HP와 MP가 각각 %d, %d 으로 설정되었습니다.\n", Status[0], Status[1]);

			break;
		}
	}

	while (1)
	{
		printf("ATK와 DEF를 입력해주세요.\n");
		scanf_s("%d %d", &Status[2], &Status[3]);

		if (Status[2] <= 0 || Status[3] <= 0)
		{
			printf("ATK와 DEF는 0이하가 될 수 없습니다! 다시 입력해주세요\n");
		}
		else
		{
			printf("ATK 와 DEF 는 각각 %d, %d 으로 설정되었습니다.\n", Status[2], Status[3]);

			break;
		}

	}

	printf("유저님의 캐릭터는 HP는 %d, MP는 %d, ATK는 %d, DEF는 %d 으로 설정되었습니다.\n", Status[0], Status[1], Status[2], Status[3]);

	int Choice = 1;
	while (Choice == 1)
	{
		int Num = 0;

		printf("1.HP UP / 2.MP UP / 3. ATK UP / 4.DEF UP / 5.Now Stat / 6. Level UP / 0. Exit \n 번호를 입력해 주세요\n 현재 보유하신 포션 갯수: HP_Potion : %d, MP_Potion : %d, Stat_Potion : %d\n", HPPotion, MPPotion, StatPotion);
		scanf_s("%d", &Num);

		switch (Num)
		{
		case 1:
			if (HPPotion > 0)
			{
				Status[0] += 20;
				printf("HP가 20 올랐습니다! HP_Potion 이 한개 차감됩니다.\n");
				--HPPotion;
			}
			else
			{
				printf("HP 포션이 부족합니다!\n");
			}
			break;
		case 2:
			if (MPPotion > 0)
			{
				Status[1] += 20;
				printf("MP가 20 올랐습니다!\n");
				--MPPotion;
			}
			else
			{
				printf("MP 포션이 부족합니다!\n");
			}
			break;

		case 3:
			if (StatPotion > 0)
			{
				Status[2] *= 2;
				printf("ATK가 2배로 올랐습니다!\n");
				--StatPotion;
			}
			else
			{
				printf("Stat 포션이 부족합니다!\n");
			}
			break;

		case 4:
			if (StatPotion > 0)
			{
				Status[3] *= 2;
				printf("DEF가 2배로 올랐습니다!\n");
				--StatPotion;
			}
			else
			{
				printf("stat 포션이 부족합니다!\n");
			}
			break;

		case 5:
			printf("현재 유저님의 스테이터스 정보는 HP는 %d, MP 는 %d, ATK는 %d, DEF는 %d, Level은 %d 입니다.\n", Status[0], Status[1], Status[2], Status[3], Level);

			break;
		case 6:
			++Level;
			printf("Level UP!! 포션이 하나 충전되었습니다.\n");
			++HPPotion;
			++MPPotion;
			++StatPotion;
			break;

		case 0:
			Choice = 0;
			printf("프로그램을 종료합니다\n");
			break;
		}

	}


	return 0;
}