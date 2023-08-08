#include "FTRLab/Board.hpp"

Board::Board()
{
  this->macAddress = WiFi.macAddress();
  this->chipId = this->getChipId();

  this->measurementsQueue = xSemaphoreCreateMutex();
  xSemaphoreGive(this->measurementsQueue);
}
