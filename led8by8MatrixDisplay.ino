byte bigHeart[] = {  B01100110,  B11111111,  B11111111,  B11111111,  B01111110,  B00111100,  B00011000,  B00000000};
byte smallHeart[] = {  B00000000,  B00000000,  B00010100,  B00111110,  B00111110,  B00011100,  B00001000,  B00000000};
int pins[17] = { -1, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};
int cols[8] = { pins[13], pins[10], pins[15], pins[9], pins[4], pins[16], pins[1], pins[6]};
int rows[8] = {pins[8], pins[7], pins[3], pins[14], pins[2], pins[12], pins[11], pins[5]};
byte smile[] = {B01111110, B10000001, B10100101, B00000000, B00011000, B01000010, B00111100, B00000000};
byte nutral[] = {B11111111, B10000001, B10100101, B10000001, B10000001, B10111101, B10000001, B11111111};
byte angry[] = {B11111111, B10000001, B10100101, B10000001, B00000000, B00111100, B01000010, B00000000};
byte cA[] = {B00011000, B00111100, B01111110, B01100110, B01100110, B11111111, B11100111, B11100111};
byte cB[] = {B11111100, B11000110, B11000111, B11111110, B11111100, B11000110, B11000111, B11111110};
byte cC[] = {B11111111, B11111111, B11100000, B11100000, B11100000, B11100000, B11111111, B11111111};
byte cD[] = {B11111100, B11000110, B11000011, B11000011, B11000011, B11000011, B11000110, B11111100};
byte cE[] = {B11111111, B11111111, B00000111, B11111111, B11111111, B00000111, B11111111, B11111111};
byte cF[] = {B11111111, B11111111, B11000000, B11000000, B11111100, B11111100, B11000000, B11000000};
byte cG[] = {B11111110, B11111110, B11000000, B11000000, B11011110, B11000110, B11111110, B11111110};
byte cH[] = {B11100111, B11100111, B11100111, B11111111, B11111111, B11111111, B11100111, B11100111};
byte cI[] = {B11111111, B11111111, B00111100, B00111100, B00111100, B00111100, B11111111, B11111111};
byte cJ[] = {B11111111, B11111111, B00011000, B00011000, B00011000, B11011000, B11111000, B11111000};
byte cK[] = {B11001110, B11001110, B11011100, B11111000, B11111000, B11011100, B11001110, B11001110};
byte cL[] = {B00000111, B00000111, B00000111, B00000111, B00000111, B11111111, B11111111, B11111111};
byte cM[] = {B11000011, B11100111, B11111111, B11011011, B11011011, B11000011, B11000011, B11000011};
byte cN[] = {B11000011, B11001111, B11001111, B11011011, B11111011, B11110011, B11100011, B11000011};
byte cO[] = {B00111100, B01111110, B11000011, B11000011, B11000011, B11000011, B11111110, B00111100};
byte cP[] = {B11111100, B11000110, B11000110, B11111110, B11111100, B11000000, B11000000, B11000000};
byte cQ[] = {B11111110, B11111110, B11000110, B11000110, B11010110, B11001110, B11111111, B00000111};
byte cR[] = {B11111100, B11000110, B11000110, B11111100, B11110000, B11011000, B11001100, B11001100};
byte cS[] = {B11111111, B11111111, B11000000, B11111111, B11111111, B00000011, B11111111, B11111111};
byte cT[] = {B11111111, B11111111, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000};
byte cU[] = {B11000011, B11000011, B11000011, B11000011, B11000011, B11000011, B11111111, B11111111};
byte cV[] = {B00000000, B11000011, B11000011, B01100110, B01100110, B00111100, B00111100, B00011000};
byte cW[] = {B11000011, B11000011, B11011011, B11011011, B11011011, B11011011, B11111111, B11111111};
byte cX[] = {B11000011, B11000011, B01100110, B00111100, B00011000, B00111100, B11111111, B11100111};
byte cY[] = { B10000001, B11000011, B01100110, B00111100, B00011000, B00011000, B00011000, B00011000};
byte cZ[] = {B11111111, B11111111, B00000111, B00001110, B00011100, B00111000, B11111111, B11111111};

void setup() {
  for (int i = 0; i < 8; i++)  {
    pinMode(rows[i], OUTPUT);        // make all the LED pins outputs
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], HIGH);  // disconnect column pins from Ground
  }
}

void loop() {
  int pulseDelay = 800 ;          // milliseconds to wait between beats



  // int pulseDelay = 800;
  show(cA, 2000);

  show(cV, 1000);
  delay(100);
  show(cI, 1000);
  delay(100);
  show(cN, 1000);
  delay(100);
  show(cE, 1000);
  delay(100);
  show(cE, 1000);
  delay(100);
  show(cL, 1000);
  delay(100);
  show(smallHeart, 2000);          
  show(bigHeart, 1620);            
  delay(pulseDelay);              
  show(smile, 2000);
  delay(pulseDelay);
  show(angry, 2000);
  delay(pulseDelay);

}


void show(   byte * image, unsigned long duration)
{
  unsigned long start = millis();
  
  while (start + duration > millis())
   
  {
    for (int row = 0; row < 8; row++)    {
      digitalWrite(rows[row], HIGH);
      // connect row to +5 volts
      for (int column = 0; column < 8; column++)      {
        boolean pixel = bitRead(image[row], column);
        if (pixel == 1)        {
          digitalWrite(cols[column], LOW);  // connect column to Gnd
        }
        delayMicroseconds(300);
      
        digitalWrite(cols[column], HIGH);

      }
      digitalWrite(rows[row], LOW);            // disconnect LEDs
    }
  }
}


