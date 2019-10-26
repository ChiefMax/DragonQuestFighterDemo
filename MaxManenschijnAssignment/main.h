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

void PlayerHandler(Button &attackButton, Character &character, Character &enemy, TextObject &hpTextEnemy, Button &defenceButton, TextObject &infoText, Button &recoverButton, TextObject &hpText, Button &magicButton, bool &specialMagic, bool &magicOnce, bool &EnemyTurn);
