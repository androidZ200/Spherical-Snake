#include "IConstGame.h"

bool IConstGame::isPlaying()
{
    return !isEndGame;
}

void IConstGame::Stop()
{
    isEndGame = true;
}

void IConstGame::PlayPause()
{
    isPause = !isPause;
}
