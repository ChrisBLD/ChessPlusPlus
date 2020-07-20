#include "Pawn.h"
#include "TextureHolder.h"

Pawn::Pawn()
{
	m_Sprite.setTexture(TextureHolder::GetTexture("assets/pawn.png"));

	m_InPlay = false;

	m_Movement.infiniteX = false;
	m_Movement.infiniteY = false;
	m_Movement.infiniteDiag = false;

	m_Movement.normalX = 0;
	m_Movement.normalY = 1;
	m_Movement.normalDiag = 0;
}

void Pawn::spawn(Vector2f startPosition)
{

}