#pragma once
#include <Windows.h>
#include "fightScreen.h"
#include "scene.h"
#include "spriteObject.hpp"
#include "sceneHandler.h"
#include "button.hpp"
#include "character.hpp"
#include "textObject.hpp"
#include "quitButton.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//void PlayerHandler(Button &attackButton, Character &character, Character &enemy, TextObject &hpTextEnemy, Button &defenceButton, TextObject &infoText, Button &recoverButton, TextObject &hpText, Button &magicButton, bool &specialMagic, bool &magicOnce, bool &EnemyTurn);

void EnemyHandler(TextObject &infoTextEnemy, Character &enemy, bool &PlayerTurn, bool &EnemyTurn, Character &character, TextObject &hpText);

//void PlayerHandler(Button &attackButton, Character &character, Character &enemy, TextObject &hpTextEnemy, bool &EnemyTurn, bool &PlayerTurn, TextObject &infoText, Button &defenceButton, Button &recoverButton, TextObject &hpText, Button &magicButton, bool &specialMagic, bool &magicOnce, bool );
void PlayerHandler(Button &attackButton, Character &character, Character &enemy, TextObject &hpTextEnemy, TextObject &attackTextEnemy, TextObject &defenceTextEnemy, bool &EnemyTurn, bool &PlayerTurn, TextObject &infoText, Button &defenceButton, Button &recoverButton, TextObject &hpText, Button &magicButton, bool &specialMagic, bool &magicOnce, bool &reset);
