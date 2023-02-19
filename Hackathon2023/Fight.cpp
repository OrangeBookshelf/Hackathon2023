 #include "Character.hpp"



void attack(Character attacker, Character defender, int prep)
{
	//prep: 1 = attack doesn't miss, 2 = attack does extra damage
	//if boss, 100% success in attack, add later
	int accuracy = (rand() % 100) + 1, range = (rand() % 5) + 1, crement = (rand() % 3) + 1;
	int attackDamage = 0;
	//crement: 1 = down, 2 = no change, 3 = up
	if (prep == 1)
	{
		//the player prepared to defend
		std::cout << attacker.Name << " " << "tried to hit you, but you prepared and take no damage!" << std::endl;
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



//boss fight functions
void bossAttack(BigBoss attacker, Character defender, int prep)
{
	int range = (rand() % 5) + 1, crement = (rand() % 3) + 1, attackDamage = 0;
	//crement: 1 = down, 2 = no change, 3 = up
	if (prep == 1)
	{
		std::cout << attacker.Name << " " << "tried to hit you, but you prepared and take no damage!" << std::endl;
	}
	else
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
		defender.Health -= attackDamage;
		std::cout << attacker.Name << " " << "hits for " << attackDamage << " " << "damage!" << std::endl;
	}
}


void attackBoss(BigBoss defender, Character attacker, int prep)
{
	//prep: 1 = attack doesn't miss, 2 = attack does extra damage
	int accuracy = (rand() % 100) + 1, range = (rand() % 5) + 1, crement = (rand() % 3) + 1;
	int attackDamage = 0;
	//crement: 1 = down, 2 = no change, 3 = up
	if (prep == 2)
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


void startFight(Character player, Character enemy)
{
	int choice = 0, prepChoice = 0, cooldown = 0;
	while (player.Health > 0 || enemy.Health > 0)
	{
		if (player.SpD > enemy.SpD)
		{
			//player goes first
			do
			{
				std::cout << "What would you like to do?\n1: Attack\n2: Heal\n3: Prepare" << std::endl;
				std::cin >> choice;
			} while (choice < 1 || choice > 3);
			if (choice == 1)
			{
				if (prepChoice == 2)
				{
					attack(player, enemy, prepChoice);	
				}
				else
				{
					attack(player, enemy, 0);
				}
				prepChoice = 0;
				
			}
			else if (choice == 2)
			{
				heal(player, prepChoice);
				prepChoice = 0;
			}
			else
			{
				do
				{
					std::cout << "What would you like to do?\n1: Prep defense (take no damage till after your next turn)\n2: Prep damage (will do much more damage next turn)\n3: Prep heal (heal will heal you for 50% max)\n" << std::endl;
					std::cin >> prepChoice;
				} while (prepChoice > 3 || prepChoice < 1);
				cooldown = 2;
			}
			if (cooldown > 0)
			{
				cooldown--;
			}

			//enemy turn
			attack(enemy, player, 1);
		}
		else
		{
			//enemy goes first
			attack(enemy, player, 0);

			//player turn
			do
			{
				std::cout << "What would you like to do?\n1: Attack\n2: Heal\n3: Prepare" << std::endl;
				std::cin >> choice;
			} while (choice < 1 || choice > 3);
			if (choice == 1)
			{
				attack(player, enemy, prepChoice);
				prepChoice = 0;
			}
			else if (choice == 2)
			{
				heal(player, prepChoice);
				prepChoice = 0;
			}
			else
			{
				do
				{
					std::cout << "What would you like to do?\n1: Prep attack chances (you will have a guarnteed hit next turn)\n2: Prep damage (will do much more damage next turn)\n3: Prep heal (heal will heal you for 50% max)\n" << std::endl;
					std::cin >> prepChoice;
				} while (prepChoice > 3 || prepChoice < 1);
				cooldown = 2;
			}
			if (cooldown > 0)
			{
				cooldown--;
			}
		}
	}
}


void startBossFight(Character player, BigBoss boss)
{
	int choice = 0, prepChoice = 0, cooldown = 0;
	while (player.Health > 0 || boss.Health > 0)
	{
		if (player.SpD > boss.SpD)
		{
			//player goes first
			do
			{
				std::cout << "What would you like to do?\n1: Attack\n2: Heal\n3: Prepare" << std::endl;
				std::cin >> choice;
			} while (choice < 1 || choice > 3);
			if (choice == 1)
			{
				attackBoss(boss, player, prepChoice);
				prepChoice = 0;
			}
			else if (choice == 2)
			{
				heal(player, prepChoice);
				prepChoice = 0;
			}
			else
			{
				do
				{
					std::cout << "What would you like to do?\n1: Prep attack chances (you will have a guarnteed hit next turn)\n2: Prep damage (will do much more damage next turn)\n3: Prep heal (heal will heal you for 50% max)\n" << std::endl;
					std::cin >> prepChoice;
				} while (prepChoice > 3 || prepChoice < 1);
				cooldown = 2;
			}
			if (cooldown > 0)
			{
				cooldown--;
			}

			//enemy turn
			bossAttack(boss, player, prepChoice);
		}
		else
		{
			//enemy goes first
			bossAttack(boss, player, prepChoice);

			//player turn
			do
			{
				std::cout << "What would you like to do?\n1: Attack\n2: Heal\n3: Prepare" << std::endl;
				std::cin >> choice;
			} while (choice < 1 || choice > 3);
			if (choice == 1)
			{
				attackBoss(boss, player, prepChoice);
				prepChoice = 0;
			}
			else if (choice == 2)
			{
				heal(player, prepChoice);
				prepChoice = 0;
			}
			else
			{
				do
				{
					std::cout << "What would you like to do?\n1: Prep attack chances (you will have a guarnteed hit next turn)\n2: Prep damage (will do much more damage next turn)\n3: Prep heal (heal will heal you for 50% max)\n" << std::endl;
					std::cin >> prepChoice;
				} while (prepChoice > 3 || prepChoice < 1);
				cooldown = 2;
			}
			if (cooldown > 0)
			{
				cooldown--;
			}
		}
	}
}