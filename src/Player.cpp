#include "Player.hpp"

Player::Player(int x, int y, int points, int life, int attack, double cooldown_shoot, char *symbol, char *mir_symbol)
				:Character(x, y, points, life, attack, cooldown_shoot, symbol, mir_symbol) {
	name = new char[MAX_NAME_LENGTH];
	offset = 0;
	isInvincible = false;
	invincibility_timer = 5.0;
	minigun_timer = 5.0;
	default_cooldown_shoot = cooldown_shoot;
}

void Player::move(int input, int width, int height, bool hasPlatformAbove, bool hasPlatformBelow, double time) {
	Direction last_direction = direction;
	Character::move(input, width, height, hasPlatformAbove, hasPlatformBelow, time);
	if ((offset > 0 && x < FIXED_X) || x > FIXED_X) {
		offset += x-FIXED_X;
		x = FIXED_X;
	}
}

void Player::checkBonusesTimer(double time) {
	if (time - invincibilityActivation_time > invincibility_timer)
		isInvincible = false;
	if (time - minigunActivation_time > minigun_timer)
		cooldown_shoot = default_cooldown_shoot;
}

void Player::increaseLife(int bonus_life) {
	life += bonus_life;
}

void Player::increasePoints(int bonus_points) {
	points += bonus_points;
}

void Player::setCooldownShoot(double minigun_cooldown, double time) {
	this->cooldown_shoot = minigun_cooldown;
	minigunActivation_time = time;
}

void Player::setInvincibility(double time) {
	isInvincible = true;
	invincibilityActivation_time = time;
}

bool Player::hasInvincibility() {
	return isInvincible;
}
char *Player::getName() {
	return name;
}
int Player::getOffset() {
	return offset;
}
int Player::noOffsetX() {
	return x;
}
int Player::getX() {
	return offset+Character::getX();
}