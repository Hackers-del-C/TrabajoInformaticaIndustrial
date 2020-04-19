#pragma once
#pragma once

class Menu {
public:

	int level;



	Menu() :level(0) {};

	void Dibuja();
	void Tecla(unsigned char key);

	int GetLevel() { return level; }

	friend class Backgroud;
};