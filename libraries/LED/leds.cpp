void lightPin(int pin_num, float freq, int base)
{
  float initialDelay = ((float)base)*freq;
  float postDelay = ((float)base)*(1-freq);
  delay(initialDelay);
  digitalWrite(pin_num, HIGH);
  delay(postDelay);
  digitalWrite(pin_num, LOW);
}

void setPins(int * pins) //same as int pins [] due to decay
{
    int size = pins[0];
    pins++;
    for(int i = 0; i < size; i++)
    {
        pinMode(13, OUTPUT);
    }
}