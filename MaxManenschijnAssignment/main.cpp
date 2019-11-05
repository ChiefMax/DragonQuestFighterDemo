#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "main.h"


int main() {

	srand(time(NULL));

	int min = 10;
	int max = 20;

	bool battleWindowOpen = false;
	bool once = false;
	int counter = 0;
	bool magicOnce = false;
	bool fightWindowBool = false;
	bool specialMagic = false;
	bool PlayerTurn = true;
	bool EnemyTurn = false;
	bool reset = false;
	bool initPlayer = true;
	bool gameOver = false;
	int enemysDefeated = 0;

	std::vector<std::string> score;
	std::vector<std::string> nameHighscore;

	sf::Font font;
	font.loadFromFile("Lato-Regular.ttf");
	sf::Color darkColor = sf::Color(71, 82, 94, 255);
	sf::Color darkGreyColor = sf::Color(132, 146, 166, 255);
	sf::Color lightGreyColor = sf::Color(129, 144, 165, 255);
	sf::Color AlphaColor = sf::Color(129, 144, 165, 0);

	sf::RenderWindow ourWindow(sf::VideoMode(1280, 720), "Dronken Quest");
	Scene scene1("scene01");

	SpriteObject sprite1("backgroundSprite", "img/backgroundMainMenu.png");
	scene1.addGameObject(sprite1);

	SpriteObject playSprite("playSprite", "img/buttonStart.png");
	playSprite.setPosition(sf::Vector2f(1100.0f, 150.0f));
	scene1.addGameObject(playSprite);

	SpriteObject eraseSprite("eraseSprite", "img/trashcan.png");
	eraseSprite.setPosition(sf::Vector2f(1100.0f, 250.0f));
	scene1.addGameObject(eraseSprite);

	SpriteObject quitSprite("quitSprite", "img/exit.png");
	quitSprite.setPosition(sf::Vector2f(1100.0f, 350.0f));
	scene1.addGameObject(quitSprite);

	TextObject highScoreTextInfo("highScoreTextInfo", font, " ");
	highScoreTextInfo.setPosition(sf::Vector2f(50, 150));
	highScoreTextInfo.setCharacterSize(26);
	highScoreTextInfo.setFillColor(darkColor);
	highScoreTextInfo.setText("HIGHSCORES:");
	scene1.addGameObject(highScoreTextInfo);
	
	TextObject highScoreText1("highScoreText", font, " ");
	highScoreText1.setPosition(sf::Vector2f(50, 200));
	highScoreText1.setCharacterSize(26);
	highScoreText1.setFillColor(darkColor);
	scene1.addGameObject(highScoreText1);

	TextObject gameOverText("gameOverText", font, "");
	gameOverText.setPosition(sf::Vector2f(550, 200));
	gameOverText.setCharacterSize(26);
	gameOverText.setFillColor(lightGreyColor);
	scene1.addGameObject(gameOverText);

	//Button handling.
	sf::Texture playT;
	sf::Texture eraseT;
	sf::Texture quitT;
	if (!playT.loadFromFile("img/buttonStart.png"))
		return EXIT_FAILURE;
	if (!eraseT.loadFromFile("img/trashcan.png"))
		return EXIT_FAILURE;
	if (!quitT.loadFromFile("img/exit.png"))
		return EXIT_FAILURE;
	sf::Sprite play(playT);
	play.setPosition(sf::Vector2f(1100, 150));
	sf::Sprite erase(eraseT);
	erase.setPosition(sf::Vector2f(1100, 250));
	sf::Sprite quit(quitT);
	quit.setPosition(sf::Vector2f(1100, 350));

	Scene scene2("scene02");

	Character character("Hero", "img/player.png", 1, 0, 0);
	Character enemy("Slime", "img/enemy.png", 8, rand() % (10 - 5 + 1) + 5, 4);

	character.setAttack(rand() % 10 + 1);
	character.setDefense(rand() % 10 + 1);
	character.setHP(rand() % (max - min + 1) + min);

	TextObject infoText("infoText", font, " ");
	infoText.setPosition(sf::Vector2f(400, 400));
	infoText.setCharacterSize(26);
	infoText.setFillColor(darkColor);

	TextObject infoTextEnemy("infoText", font, " ");
	infoTextEnemy.setPosition(sf::Vector2f(400, 450));
	infoTextEnemy.setCharacterSize(26);
	infoTextEnemy.setFillColor(darkColor);

	/*--------Player stats---------*/
	TextObject hpText("hpText", font, "HP: " + std::to_string(character.getHP()));
	hpText.setPosition(sf::Vector2f(50, 200));
	hpText.setCharacterSize(26);
	hpText.setFillColor(darkColor);

	TextObject defenceText("defenceText", font, "Defence: " + std::to_string(character.getDefense()));
	defenceText.setPosition(sf::Vector2f(50, 250));
	defenceText.setCharacterSize(26);
	defenceText.setFillColor(darkColor);

	TextObject attackText("attackText", font, "Attack: " + std::to_string(character.getAttack()));
	attackText.setPosition(sf::Vector2f(50, 300));
	attackText.setCharacterSize(26);
	attackText.setFillColor(darkColor);
	/*----------------------------*/
	/*--------Enemy stats---------*/
	TextObject hpTextEnemy("hpTextEnemy", font, "HP: " + std::to_string(enemy.getHP()));
	hpTextEnemy.setPosition(sf::Vector2f(950, 200));
	hpTextEnemy.setCharacterSize(26);
	hpTextEnemy.setFillColor(darkColor);

	TextObject defenceTextEnemy("defenceTextEnemy", font, "Defence: " + std::to_string(enemy.getDefense()));
	defenceTextEnemy.setPosition(sf::Vector2f(950, 250));
	defenceTextEnemy.setCharacterSize(26);
	defenceTextEnemy.setFillColor(darkColor);

	TextObject attackTextEnemy("attackTextEnemy", font, "Attack: " + std::to_string(enemy.getAttack()));
	attackTextEnemy.setPosition(sf::Vector2f(950, 300));
	attackTextEnemy.setCharacterSize(26);
	attackTextEnemy.setFillColor(darkColor);
	/*----------------------------*/

	SpriteObject playerStatsSprite("playerStatsSprite", "img/headP.png");
	playerStatsSprite.setPosition(sf::Vector2f(50.0f, 50.0f));
	scene2.addGameObject(playerStatsSprite);

	SpriteObject enemyStatsSprite("enemyStatsSprite", "img/headE.png");
	enemyStatsSprite.setPosition(sf::Vector2f(950.0f, 50.0f));
	scene2.addGameObject(enemyStatsSprite);

	SpriteObject playerSprite("playerSprite", character.getSpriteFile());
	playerSprite.setPosition(sf::Vector2f(450, 200));
	scene2.addGameObject(playerSprite);

	SpriteObject enemySprite("enemySprite", enemy.getSpriteFile());
	enemySprite.setPosition(sf::Vector2f(700, 200));
	scene2.addGameObject(enemySprite);

	Button attackButton("attackButton", font, "ATTACK", sf::Vector2f(192.5f, 50.0f), darkColor);
	attackButton.setPosition(sf::Vector2f(150, 500));

	Button defenceButton("defenceButton", font, "DEFENCE", sf::Vector2f(192.5f, 50.0f), darkColor);
	defenceButton.setPosition(sf::Vector2f(350, 500));

	Button recoverButton("recoverButton", font, "RECOVER", sf::Vector2f(192.5f, 50.0f), darkColor);
	recoverButton.setPosition(sf::Vector2f(750, 500));

	Button magicButton("magicButton", font, "MAGIC", sf::Vector2f(192.5f, 50.0f), darkColor);
	magicButton.setPosition(sf::Vector2f(950, 500));

	Button returnMenu("returnMenu", font, "RETURN TO MENU", sf::Vector2f(250.0f, 50.0f), darkColor);
	returnMenu.setPosition(sf::Vector2f(950, 650));

	scene2.addGameObject(attackButton);
	scene2.addGameObject(defenceButton);
	scene2.addGameObject(recoverButton);
	scene2.addGameObject(magicButton);
	scene2.addGameObject(returnMenu);
	scene2.addGameObject(hpText);
	scene2.addGameObject(attackText);
	scene2.addGameObject(defenceText);
	scene2.addGameObject(hpTextEnemy);
	scene2.addGameObject(attackTextEnemy);
	scene2.addGameObject(defenceTextEnemy);
	scene2.addGameObject(infoText);
	scene2.addGameObject(infoTextEnemy);

	sf::RectangleShape rectangeleHealth(sf::Vector2f(200.f, 25.f));
	rectangeleHealth.setFillColor(sf::Color(255, 0, 0));

	sf::RectangleShape rectangeleMana(sf::Vector2f(200.f, 25.f));
	rectangeleMana.setFillColor(sf::Color(0, 0, 255));

	sf::RectangleShape rectangeleHealthEnemy(sf::Vector2f(200.f, 25.f));
	rectangeleHealthEnemy.setFillColor(sf::Color(255, 0, 0));

	sf::RectangleShape rectangeleManaEnemy(sf::Vector2f(200.f, 25.f));
	rectangeleManaEnemy.setFillColor(sf::Color(0, 0, 255));

	//Player Heatlh and Mana
	rectangeleHealth.setPosition(90, 300);
	rectangeleMana.setPosition(90, 350);

	//Enemy Health and Mana
	rectangeleHealthEnemy.setPosition(990, 300);
	rectangeleManaEnemy.setPosition(990, 350);

	SceneHandler handler;
	handler.addScene(scene1);
	handler.addScene(scene2);

	std::ifstream myfileRead("highscore.cmgt");
	if (!myfileRead.fail()) {
		std::string line;

		while (std::getline(myfileRead, line)) 
		{
			nameHighscore.push_back(line);
		}
		myfileRead.close();
	}
	else 
	{
		myfileRead.open("highscore.cmgt", std::fstream::in | std::fstream::out | std::fstream::app);
		myfileRead.close();
	}

	int elementCounter = nameHighscore.size();
	highScoreText1.setText("");
	for (auto it = nameHighscore.begin(); it != nameHighscore.end(); ++it)
	{
		if (elementCounter < 0)
		{
			continue;
		}
		elementCounter--;
		std::string lineList = nameHighscore.at(elementCounter);
		highScoreText1.setText(highScoreText1.getTextStr() + lineList + " enemies." + "\n");
		std::cout << "Test " << lineList << " \n";
		continue;
	}

	while (ourWindow.isOpen())
	{
		returnMenu.setButtonAction([&counter, &handler]() {
			counter--;
			handler.popScene();
			std::cout << "Going Back" << " | " << counter;
		});

		if (initPlayer) {
			hpText.setText("HP: " + std::to_string(character.getHP()));
			attackText.setText("Attack: " + std::to_string(character.getAttack()));
			defenceText.setText("Defence: " + std::to_string(character.getDefense()));
			initPlayer = false;
		}

		if (PlayerTurn) {
			PlayerHandler(attackButton, character, enemy, hpTextEnemy,attackTextEnemy,defenceTextEnemy, EnemyTurn, PlayerTurn, infoText, defenceButton, recoverButton, hpText, magicButton, specialMagic, magicOnce, reset);
		}

		if (EnemyTurn && !PlayerTurn)
		{
			EnemyHandler(infoTextEnemy, enemy, PlayerTurn, EnemyTurn, character, hpText);
		}

		if (enemy.getHP() <= 0 && !reset)
		{
			infoTextEnemy.setText(enemy.getName() + " Is defeated! Click attack again to continue.");
			reset = true;
			enemysDefeated++;
			score.push_back(std::to_string(enemysDefeated));
		}

		if (character.getHP() <= 0 && !gameOver)
		{
			std::vector<std::string> localinput;
			infoText.setText(character.getName() + " is defeated!");

			std::ifstream myfileReadLocal("highscore.cmgt");
			if (!myfileReadLocal.fail()) {
				std::string line;

				while (std::getline(myfileReadLocal, line))
				{
					localinput.push_back(line);
				}
				myfileReadLocal.close();
			}

			int counterLocal = localinput.size();

			if (localinput.size() > 5) 
			{
				localinput.erase(localinput.end() - 1);
			}

			//Clearing the list so it does not go over the 5 limit.
			std::ifstream myfileReadClear("highscore.cmgt", std::ofstream::out | std::ofstream::trunc);
			myfileReadClear.close();

			std::ofstream myfileRead("highscore.cmgt", std::fstream::app);
			if (!myfileRead.fail()) {
				int counterForRemoving = localinput.size();
				for (auto it = localinput.begin(); it != localinput.end(); ++it)
				{
					counterForRemoving--;
					std::string toAppend = localinput.at(counterForRemoving);
					myfileRead << toAppend << std::endl;
				}
				myfileRead << character.getName() + " has defeated: " + std::to_string(enemysDefeated) << std::endl;
				myfileRead.flush();
				myfileRead.close();
			}

			gameOver = true;

			if (gameOver) 
			{
				counter--;
				handler.popScene();
				gameOverText.setText(character.getName() + " has been defeated.");
			}

			int elementCounterUpdate = localinput.size();
			highScoreText1.setText("");
			for (auto it = localinput.begin(); it != localinput.end(); ++it)
			{
				if (elementCounterUpdate < 0)
				{
					continue;
				}
				elementCounterUpdate--;
				std::string lineList = localinput.at(elementCounterUpdate);
				highScoreText1.setText(highScoreText1.getTextStr() + lineList + " enemies." + "\n");
				std::cout << "Test " << lineList << " \n";
				continue;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// transform the mouse position from window coordinates to world coordinates
			sf::Vector2f mouse = ourWindow.mapPixelToCoords(sf::Mouse::getPosition(ourWindow));

			// retrieve the bounding box of the sprite
			sf::FloatRect boundsPlayButton = play.getGlobalBounds();
			sf::FloatRect boundsQuitButton = quit.getGlobalBounds();
			sf::FloatRect boundsEraseButton = erase.getGlobalBounds();

			//Going to the next screen.
			if (boundsPlayButton.contains(mouse))
			{
				// mouse is on sprite!
				battleWindowOpen = true;
				once = true;
				fightWindowBool = true;
				//counter++;
			}

			if (boundsEraseButton.contains(mouse)) 
			{
				std::ifstream myfileReadClearButton("highscore.cmgt", std::ofstream::out | std::ofstream::trunc);
				myfileReadClearButton.close();
				highScoreText1.setText("");
			}

			//Closing the game.
			if (boundsQuitButton.contains(mouse))
			{
				// mouse is on sprite!
				ourWindow.close();
			}
		}


		sf::Event evnt;
		while (ourWindow.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed) {
				ourWindow.close();
			}
			else
			{
				scene2.handleEvent(evnt, ourWindow);
			}
			if (battleWindowOpen && once) {
				if (counter == 0) {
					handler.stackScene("scene02");
					counter++;
					ourWindow.clear();
				}
				else {
					handler.popScene();
					counter--;
				}
			}
		}
		ourWindow.clear();
		handler.update();
		handler.render(ourWindow);
		ourWindow.display();

		if (battleWindowOpen && once)
		{
			once = false;
		}
	}
}

void PlayerHandler(Button &attackButton, Character &character, Character &enemy, TextObject &hpTextEnemy, TextObject &attackTextEnemy, TextObject &defenceTextEnemy, bool &EnemyTurn, bool &PlayerTurn, TextObject &infoText, Button &defenceButton, Button &recoverButton, TextObject &hpText, Button &magicButton, bool &specialMagic, bool &magicOnce, bool &reset)
{
	attackButton.setButtonAction([&character, &enemy, &hpTextEnemy, &EnemyTurn, &PlayerTurn, &infoText, &reset, &attackTextEnemy, &defenceTextEnemy]() {
		
		if (reset)
		{
			enemy.setAttack(rand() % (10 - 5 + 1) + 5);
			enemy.setDefense(rand() % 10 + 1);
			enemy.setHP(rand() % 10 + 1);
			hpTextEnemy.setText("HP: " + std::to_string(enemy.getHP()));
			attackTextEnemy.setText("Attack: " + std::to_string(enemy.getAttack()));
			defenceTextEnemy.setText("Defence: " + std::to_string(enemy.getDefense()));
			reset = false;
			return;
		}

		int damage = character.attackCharacter(enemy);
		enemy.takeDamage(damage);
		if (damage <= 0)
		{
			infoText.setText(character.getName() + " swong your sword at the enemy, but you missed!");
			EnemyTurn = true;
			PlayerTurn = false;
		}
		else
		{
			infoText.setText(character.getName() + " swong your sword at the enemy!");
			hpTextEnemy.setText("HP: " + std::to_string(enemy.getHP()));
			EnemyTurn = true;
			PlayerTurn = false;
		}
	});

	defenceButton.setButtonAction([&character, &enemy, &infoText, &EnemyTurn, &PlayerTurn]() {
		infoText.setText(character.getName() + " is bracing for impact.");
		EnemyTurn = true;
		PlayerTurn = false;
	});

	recoverButton.setButtonAction([&character, &enemy, &infoText, &hpText, &EnemyTurn, &PlayerTurn]() {
		infoText.setText(character.getName() + " used a heal spell.");
		character.setHP(5);
		hpText.setText("HP: " + std::to_string(character.getHP()));
		EnemyTurn = true;
		PlayerTurn = false;
	});

	magicButton.setButtonAction([&character, &enemy, &infoText, &hpTextEnemy, &specialMagic, &magicOnce, &EnemyTurn, &PlayerTurn]() {
		int damage = character.attackCharacterWithMagic(enemy);
		int magicPower = rand() % 10 + 1;

		if (magicPower >= 3)
		{
			infoText.setText(character.getName() + " used a magic spell. It Failed!");
			EnemyTurn = true;
			PlayerTurn = false;
		}
		else
		{
			specialMagic = true;
			if (specialMagic && !magicOnce) {
				enemy.takeMagicDamage(damage, specialMagic);
				specialMagic = false;
				magicOnce = true;
			}
			infoText.setText(character.getName() + " used a magic spell. Here take this!");
			hpTextEnemy.setText("HP: " + std::to_string(enemy.getHP()));
			EnemyTurn = true;
			PlayerTurn = false;
		}
	});
}

void EnemyHandler(TextObject &infoTextEnemy, Character &enemy, bool &PlayerTurn, bool &EnemyTurn, Character &character, TextObject &hpText)
{
	int chanceCal = rand() % 10 + 1;

	if (chanceCal >= 7)
	{
		infoTextEnemy.setText(enemy.getName() + " just stood there!");
		PlayerTurn = true;
		EnemyTurn = false;
	}
	else
	{
		int enemyDamage = enemy.attackCharacter(character);
		character.takeDamage(enemyDamage);
		if (enemyDamage <= 0)
		{
			infoTextEnemy.setText(enemy.getName() + " just swong at you, but failed to do damage.");
			hpText.setText("HP: " + std::to_string(character.getHP()));
			PlayerTurn = true;
			EnemyTurn = false;
		}
		else
		{
			infoTextEnemy.setText(enemy.getName() + " just swong at you.");
			hpText.setText("HP: " + std::to_string(character.getHP()));
			PlayerTurn = true;
			EnemyTurn = false;
		}
	}
}
