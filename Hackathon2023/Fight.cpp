#include "Character.hpp"



void attack(Character attacker, Character defender, int prep)
{
	//prep: 1 = attack doesn't miss, 2 = attack does extra damage
	//if boss, 100% success in attack, add later
	int accuracy = (rand() % 100) + 1, range = (rand() % 5) + 1, crement = (rand() % 3) + 1;
	int attackDamage = 0;
	//crement: 1 = down, 2 = no change, 3 = up
	if (prep == 1)//or there is a boss
	{
		if (crement == 1)
		{
			attackDamage = attacker.Atk - range - defender.Def;
		}
		else if (crement == 2)
		{
			attackDamage = attacker.Atk - defender.Def;
		}
		else
		{
			attackDamage = attacker.Atk + range - defender.Def;
		}
		defender.Health = defender.Health - attackDamage;
		std::cout << attacker.Name << " " << "hits for " << attackDamage << " " << "damage!" << std::endl;
	}
	else if (prep == 2)
	{
		if (accuracy <= 85)
		{
			if (crement == 1)
			{
				attackDamage = int((attacker.Atk - range - defender.Def) * 2.2);
			}
			else if (crement == 2)
			{
				attackDamage = attacker.Atk;
			}
			else
			{
				attackDamage = int((attacker.Atk + range - defender.Def) * 2.2);
			}
			defender.Health = defender.Health - attackDamage;
			std::cout << attacker.Name << " " << "hits for " << attackDamage << " " << "damage!" << std::endl;
		}
		else
		{
			std::cout << attacker.Name << " " << "missed!";
		}
	}
	else
	{
		if (accuracy <= 85)
		{
			if (crement == 1)
			{
				attackDamage = attacker.Atk - range - defender.Def;
			}
			else if (crement == 2)
			{
				attackDamage = attacker.Atk;
			}
			else
			{
				attackDamage = attacker.Atk + range - defender.Def;
			}
			defender.Health = defender.Health - attackDamage;
			std::cout << attacker.Name << " " << "hits for " << attackDamage << " " << "damage!" << std::endl;
		}
		else
		{
			std::cout << attacker.Name << " " << "missed!";
		}
	}
}



void heal(Character player, int prep)
{
	double percentage = 0.0;

	if (prep == 3)
	{
		percentage = (100 + player.Helmet.attributeMod) * .5;
		player.Health += int(percentage);
		std::cout << "You healed for " << int(percentage) << " " << "Health!" << std::endl;
	}
	else
	{
		percentage = double(100 + player.Helmet.attributeMod) * .25;


		player.Health += int(percentage);
		//std::cout << "You healed for " << int(percentage) << " " << "Health!" << std::endl;
	}
}