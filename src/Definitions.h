#pragma once

enum class State {
	MENU, PLAYING, MID_TURN, CHECKMATE, PAUSED
};

enum class Directions {
	NORTH, NEAST, EAST, SEAST, SOUTH, SWEST, WEST, NWEST
};

//NOTMOVABLE used for when a check is in progress and this piece will not impact it.
enum class PieceState {
	MOVED, STATIONARY, CAPTURED, NOTSPAWNED, NOTMOVABLE, HOVERED
};

enum class InGameState {
	WHITE_TURN, BLACK_TURN, NOTPLAYING
};

enum class Colour {
	WHITE, BLACK, NONE
};