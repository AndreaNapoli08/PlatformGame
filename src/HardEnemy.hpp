#include "Character.hpp"

class HardEnemy : public Character{
private:
	bool findPlatform;
	int movement, last_movement;
public:
    HardEnemy(int x, int y, int points=30, int life=30, int attack=30, double cooldown_shoot=1.2, double cooldown_movement=0.5, char *symbol=(char *)"H");
    void follow(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformBelow, int width, int height);
};