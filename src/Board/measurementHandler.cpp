#include "FTRLab/Board.hpp"

void Board::measurementTask()
{
  Serial.println("Measurement task running on core " + String(xPortGetCoreID()));

  while (true)
  {
    TickType_t xLastWakeTime = xTaskGetTickCount();
    while (this->client.connected())
    {
      BaseType_t xWasDelayed = xTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(this->targetTakeingPeriod));
      this->takeAllMeasurements();
    }
    delay(100);
  }
}
