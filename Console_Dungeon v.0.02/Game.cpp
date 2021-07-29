#include "Game.h"


	//Создание персонажа, выбор имени и оружия
	void Game::createCharacter() {
		player.setName();
		system("CLS");
		std::cout << player.getPlayerName() << " - отважный искатель приключений, решивший отправиться в одиночку в жуткое подземелье.\n";
		std::cout << "Кончено, Вы наслышаны о монстрах, которые там обитают, поэтому, собрав все свои сбережения,\n";
		std::cout << "отправляетесь в оружейную лавку." << std::endl;
		std::cout << "Ассортимент магазина не велик...\n";
		std::cout << "На витринах Вы видите АРБАЛЕТ, КИНЖАЛЫ и МЕЧ\n";
		std::cout << "1 - Арбалет(Высокий урон. Шанс попадания 30 процентов)\n";
		std::cout << "2 - Кинжалы(Низкий урон. Двойной удар. Шанс попадания 50 процентов каждый)\n";
		std::cout << "3 - Меч(Низкий урон. Шанс попадания 100 процентов)\n";
		short weaponNum;
		do {
			std::cout << "Какое оружие отважный герой возьмет с собой? Введите номер оружия: \n";
			std::cin >> weaponNum;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32000, '\n');
			}
		} while (weaponNum < 1 || weaponNum > 3);
		player.setWeapon(static_cast<Weapon::WeaponTypes>(weaponNum));
		system("CLS");
		std::cout << "Итак, " << player.getPlayerName() << ", у Вас в руках " << player.getWeaponName() <<
			". Вы полны сил, у Вас " << player.getPlayerHealth() << " очков здоровья\n";
		std::cout << "Взяв волю в кулак, Вы входите в темную крипту...\n\n";
		system("Pause");
	}
	//Спавн монстра с предварительным его описанием
	void Game::monsterSpawn() {
		Enemy enemy;
		std::cout << "Долго бродив по старинной крипте, Вы заходите в комнату, из которой издаются странные звуки...\n\n";
		switch (enemy.getEnemyType()) {
		case Enemy::EnemyTypes::SPIDER:
			std::cout << "Посмотрев на высокий потолок, Вы замечаете черные очертания. Кто или что это могло бы быть?\n";
			std::cout << "Вы кидаете камень в направлении черного существа.\n";
			std::cout << "О нет! Существо зашевелилось и спрыгнуло около ваших ног. Оказывается, это ОГРОМНЫЙ ПАУК!\n\n";
			break;
		case Enemy::EnemyTypes::SKELETON:
			std::cout << "В центре комнтаты стоит груда костей.\n";
			std::cout << "Как только Вы к ней приблизились, старые, покрытые плесенью, кости выстроились в человекоподобное " <<
				"существо.\n";
			std::cout << "О нет, это СКЕЛЕТ! Он настроен агрессивно!\n\n";
			break;
		case Enemy::EnemyTypes::ZOMBIE:
			std::cout << "Вы сразу чувствуете неприятный запах, из-за которого практически невозможно дышать.\n";
			std::cout << "Задержав дыхание, Вы подбираетесь к источнику этого зловония. Им оказался ЗОМБИ, пожирающий " <<
				"чьи-то останки!\n Заприметив Вас, он зарычал и двинулся в Вашу сторону!\n\n";
			break;
		case Enemy::EnemyTypes::TROLL:
			std::cout << "Из дальнего угла комнаты доносится очень громкий и продолжительный смех.\n";
			std::cout << "Интуиция подсказывает, что ничего хорошего здесь можно не ждать, но Ваше любопытство охватывает верх\n";
			std::cout << "Вы подходите к источнику смеха. В углу сидит громоздкий грязный зеленый ТРОЛЛЬ, стучащий дубиной по " <<
				"своему животу.\nВаша сдержанность оказалось непосильна чувству смеха, который выдал Ваше присутствие...\n\n";
			break;
		case Enemy::EnemyTypes::GHOST:
			std::cout << "Внезапно Вам становится очень холодно, при дыхании изо рта валит пар. "
				<< "\"Это ненормально,\" - подумали Вы.\n";
			std::cout << "Внезапно шкаф, стоящий неподалеку падает, разбрасывая книги по всей комнате.\n";
			std::cout << "За спиной доносятся шипящие звуки. Обернувшись, Вы видите полупрозрачное нечто. Это же ПРИЗРАК!\n\n";
			break;
		case Enemy::EnemyTypes::KNIGHT:
			std::cout << "Звон доспехов и скрежет меча отражаются эхом по всей комнате.\n";
			std::cout << "Неясное бормотание и медленные, но громкие шаги направляются в Вашу сторону...\n";
			std::cout << "К Вам приближается РЫЦАРЬ, одетый в латные доспехи! По его виду можно сказать, что он безумен\n";
			std::cout << "Приготовьтесь, схватка между Вами будет не на жизнь, а на смерть\n\n";
			break;
		}
		enemyBattle(enemy);
		system("Pause");
	}
	//Битва
	void Game::enemyBattle(Enemy& enemy) {
		std::cout << enemy.getEnemyName() << " имеет " << enemy.getEnemyHealth() << " очков здоровья.\n";
		std::cout << player.getPlayerName() << " имеет " << player.getPlayerHealth() << " очков здоровья.\n\n";
		system("Pause"); std::cout << std::endl;
		//Кто ходит первым
		FirstAttack firstAttack = static_cast<FirstAttack>(Random::randomize(0, 1));
		short gainedDamage;
		switch (firstAttack) {
		case FirstAttack::ENEMY:
			gainedDamage = enemy.dealDamage();
			player.changeHealth(-gainedDamage);
			std::cout << enemy.getEnemyName() << " внезапно наносит " << gainedDamage << " урона герою " << player.getPlayerName()
				<< std::endl;
			break;
		case FirstAttack::PLAYER:
			gainedDamage = player.dealDamage();
			enemy.changeHealth(-gainedDamage);
			std::cout << "Неожиданно подкравшись к врагу, вы резко наносите " << gainedDamage << " урона!" << std::endl;
			break;
		}
		if (enemy.getEnemyHealth() <= 0) player.changeCoins(enemy.drop());
		if (player.getPlayerHealth() <= 0) gameOver(enemy);
		//////////////////////////////////////////////////////////
		//Битва
		do {
			std::cout << "-----------------------------------------\n";
			std::cout << "У героя " << player.getPlayerHealth() << " очков здоровья\n";
			std::cout << "У врага " << enemy.getEnemyHealth() << " очков здоровья\n";
			std::cout << "-----------------------------------------\n\n";
			system("Pause"); system("CLS");
			int dealDamage = player.dealDamage();
			enemy.changeHealth(-dealDamage);
			std::cout << "Ловко используя " << player.getWeaponName() << ", Вы нанесли " << dealDamage
				<< " урона врагу " << enemy.getEnemyName() << std::endl;
			system("Pause");
			std::cout << std::endl;
			if (enemy.getEnemyHealth() <= 0) {
				player.changeCoins(enemy.drop());
				break;
			}
			dealDamage = enemy.dealDamage();
			player.changeHealth(-dealDamage);
			std::cout << enemy.getEnemyName() << " яростно замахивается и наносит " << dealDamage << " урона герою "
				<< player.getPlayerName() << std::endl;
			system("Pause");
			std::cout << std::endl;
			if (player.getPlayerHealth() <= 0) gameOver(enemy);
		} while (enemy.getEnemyHealth() > 0);
		////////////////////////////////////
		createRoom();
	}
	//Смерть игрока
	void Game::gameOver(Enemy enemy) {
		system("CLS");
		std::cout << enemy.getEnemyName() << " убил храброго героя " << player.getPlayerName() << std::endl;
		std::cout << "В его кошельке оказалось " << player.getPlayerCoins() << " монет" << std::endl;
		std::cout << "Теперь в комнате " << roomNum << " лежит бездыханное тело..." << std::endl;
		system("Pause"); std::cout << std::endl;
		exit(0);
	}
	//Генерация случайной комнаты
	void Game::createRoom() {
		roomNum++;
		Rooms room = static_cast<Rooms>(Random::randomize(1, static_cast<int>(Rooms::MAX_ROOMS) - 1));
		if (roomNum >= 10 && roomNum % 10 == 0) room = Rooms::SHOP;
		system("CLS");
		switch (room) {
		case Rooms::MONSTERS:
			monsterSpawn();
		case Rooms::TREASURE:
		{Treasures treasure = static_cast<Treasures>(Random::randomize(0, static_cast<int>(Treasures::MAX_TREASURES) - 1));
		switch (treasure) {
		case Treasures::COINS:
			player.changeCoins(Random::randomize(10, 25));
			std::cout << "Вы входите в освещенную комнату, посередине которой стоит сундук...\n";
			std::cout << "Вы нашли сокровище! Теперь Ваш баланс равен " << player.getPlayerCoins() << std::endl << std::endl;
			system("Pause");
			createRoom();
			break;
		case Treasures::HEAL_POTION:
			player.changeHealth(Random::randomize(15, 30));
			std::cout << "Вы входите в освещенную комнату, посередине которой стоит сундук...\n";
			std::cout << "Вы нашли бутылек с лекарством! Вам стало лучше, здоровье увеличилось до "
				<< player.getPlayerHealth() << " очков." << std::endl << std::endl;
			system("Pause");
			createRoom();
			break;
		}
		break;
		}
		case Rooms::TRAP:
			player.changeHealth(Random::randomize(-12, -6));
			std::cout << "Бродя по мрачным и сырым коридорам, Вы случайно наступаете на нажимную плиту.\n";
			std::cout << "Вдалеке слышен скрежет механизмов.\nВнезапно из щели в стене в Вас вонзается что-то острое.\n";
			std::cout << "Вы чувствуете себя хуже. Ваш запас здоровья снизился до " << player.getPlayerHealth() << " очков\n\n";
			if (player.getPlayerHealth() <= 0) gameOver(Enemy(Enemy::EnemyTypes::TRAP));
			system("Pause"); std::cout << std::endl;
			createRoom();
			break;
			/////////////////////////////////Магазин
		case Rooms::SHOP:
			static std::vector<Assortment> stock{ Assortment::GREAT_HAMMER, Assortment::HEAL_POTION, Assortment::RUNE_OF_ACCURACY };
			std::cout << "Незатейливый дряхлый старик пристально смотрит на Вас.\nОн предлагает что-нибудь у него купить." << std::endl;
			std::cout << "У Вас " << player.getPlayerCoins() << " монет.\n";
			std::cout << "У него на прилавке лежит: " << std::endl;
			for (int i = 1; i <= stock.size(); i++) {
				std::cout << i << '.';
				if (stock[i - 1] == Assortment::GREAT_HAMMER) std::cout << "Божественный молот(100 монет)\n";
				if (stock[i - 1] == Assortment::HEAL_POTION) std::cout << "Зелье исцеления(30 монет)\n";
				if (stock[i - 1] == Assortment::RUNE_OF_ACCURACY) std::cout << "Руна точности(500 монет)\n";
			}
			short choice;
			do {
				std::cout << "\nЧто хотите приобрести? (Введите номер товара, либо 0 для выхода): ";
				std::cin >> choice;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32000, '\n');
					continue;
				}
				if (static_cast<int>(stock[choice - 1]) > player.getPlayerCoins()) {
					std::cout << "\"Денег маловато\" - проговорил хриплым голосом старик...";
					continue;
				}
				if (choice == 1) {
					player.changeCoins(-static_cast<int>(stock[choice - 1]));
					player.setWeapon(Weapon::WeaponTypes::GREAT_HAMMER);
					std::cout << "Теперь у Вас в руках " << player.getWeaponName() << std::endl;
					stock.erase(stock.begin() + choice - 1);
					system("Pause");
					break;
				}
				if (choice == 2) {
					player.changeCoins(-static_cast<int>(stock[choice - 1]));
					player.changeHealth(40);
					std::cout << "Вы пьете зелье исцеления и восстанавливаете 40 единиц здоровья."
						<< "Теперь у Вас " << player.getPlayerHealth() << " очков здоровья.\n";
					system("Pause");
					break;
				}
				if (choice == 3) {
					player.changeCoins(-static_cast<int>(stock[choice - 1]));
					player.setWeaponAccuracy(1);
					std::cout << "Вы вставили руну меткости в Ваше текущее оружие...\n";
					stock.erase(stock.begin() + choice - 1);
					system("Pause");
					break;
				}
			} while (choice != 0);
			createRoom();

		}
		////////////////////////////////////////////////////////////////////
	}


