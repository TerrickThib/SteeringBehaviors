#include "InputComponent.h"

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	//Get the direction from the key pressed
	float moveDirectionX = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_A) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_D);
	float moveDirectionY = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_W) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_S);

	//Return a new Vector representing the move direction
	return MathLibrary::Vector2(moveDirectionX, moveDirectionY);
}
