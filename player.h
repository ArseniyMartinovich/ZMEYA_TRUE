#pragma once
#include "settings.h"

const int SNAKE_DIRECTION_UP = 0;
const int SNAKE_DIRECTION_RIGHT = 1;
const int SNAKE_DIRECTION_DOWN = 2;
const int SNAKE_DIRECTION_LEFT = 3;


int player_position_x = field_size_x / 2;
int player_position_y = field_size_y / 2;
int snake_lenth = 4;
int snake_direction = SNAKE_DIRECTION_RIGHT;

void move() {
	switch (snake_direction) {
	case SNAKE_DIRECTION_UP:
		player_position_y--;
		if (player_position_y < 0) {
			player_position_y = field_size_y - 1;
		}
		break;


	case SNAKE_DIRECTION_RIGHT:
		player_position_x++;
		if (player_position_x > field_size_x - 1) {
			player_position_x = 0;
		}
		break;


	case SNAKE_DIRECTION_DOWN:
		player_position_y++;
		if (player_position_y > field_size_y - 1) {
			player_position_y = 0;
		}
		break;


	case SNAKE_DIRECTION_LEFT:
		player_position_x--;
		if (player_position_x < 0) {
			player_position_x = field_size_x - 1;
		}
		break;
	}

	field[player_position_y][player_position_x] = snake_lenth + 1;

	for (int j = 0; j < field_size_y; j++) {
		for (int i = 0; i < field_size_x; i++) {
			if (field[j][i] > FIELD_CELL_TYPE_NONE) {
				field[j][i]--;
			}
		}
	}
}

void control() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		snake_direction = SNAKE_DIRECTION_UP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		snake_direction = SNAKE_DIRECTION_RIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		snake_direction = SNAKE_DIRECTION_DOWN;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		snake_direction = SNAKE_DIRECTION_LEFT;
	}
}