//Pin Definitions
int LED1R = 20;
int LED1G = 21;
int LED1B = 22;
int LED2R = 23;
int LED2G = 24;
int LED2B = 25;
int LED3R = 26;
int LED3G = 27;
int LED3B = 28;
int LED4R = 29;
int LED4G = 30;
int LED4B = 31;

int data = 12;
int clock = 13;

//Matrix Cordinates
// 0,0 (NC)
byte dollarSign[2] =   {9,3};
byte decimalPoint[2] = {1,3};
byte upArrow[2] =      {0,1};
byte downArrow[2] =    {0,3};

byte segmentDisplay[5][7][2] = {{{9,1},{9,2},{9,0},{6,2},{6,3},{8,3},{5,3}},
                                 {{6,0},{6,1},{5,1},{5,2},{4,3},{4,2},{7,3}},
                                 {{5,0},{8,2},{8,0},{8,1},{4,1},{7,1},{7,2}},
                                 {{7,0},{4,0},{3,0},{1,0},{1,1},{1,2},{3,3}},
                                 {{2,0},{3,1},{2,1},{2,2},{3,2},{0,2},{2,3}}};

byte digitDisplay[10][7] = {{0,0,0,1,0,0,0},
                            {1,1,0,1,1,1,0},
                            {0,1,0,0,0,1,0},
                            {0,1,0,0,1,0,0},
                            {1,0,0,0,1,0,1},
                            {0,0,1,0,1,0,0},
                            {0,0,1,0,0,0,0},
                            {0,1,0,1,1,0,1},
                            {0,0,0,0,0,0,0},
                            {0,0,0,0,1,0,1}};

//Display Buffers
byte redOn[10][4] =   {{1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1}};

byte blueOn[10][4] =  {{1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1}};

byte greenOn[10][4] = {{1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1},
                       {1,1,1,1}};

void setup() {
  //Open Serial
  Serial.begin(9600);
  
  //Set Pin Modes
  pinMode(LED1R, OUTPUT);
  pinMode(LED1G, OUTPUT);
  pinMode(LED1B, OUTPUT);
  pinMode(LED2R, OUTPUT);
  pinMode(LED2G, OUTPUT);
  pinMode(LED2B, OUTPUT);
  pinMode(LED3R, OUTPUT);
  pinMode(LED3G, OUTPUT);
  pinMode(LED3B, OUTPUT);
  pinMode(LED4R, OUTPUT);
  pinMode(LED4G, OUTPUT);
  pinMode(LED4B, OUTPUT);
  
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  
  //Turn off all LEDS
  digitalWrite(LED1R, HIGH);
  digitalWrite(LED1G, HIGH);
  digitalWrite(LED1B, HIGH);
  digitalWrite(LED2R, HIGH);
  digitalWrite(LED2G, HIGH);
  digitalWrite(LED2B, HIGH);
  digitalWrite(LED3R, HIGH);
  digitalWrite(LED3G, HIGH);
  digitalWrite(LED3B, HIGH);
  digitalWrite(LED4R, HIGH);
  digitalWrite(LED4G, HIGH);
  digitalWrite(LED4B, HIGH);
  
  setSymbol('$',HIGH); //Turn on '$'
  setSymbol('.',HIGH); //Turn on decimal
}

void loop() {
  displayStuff(1);
  
}

void displayStuff(int scanSpeed){
  
  //Prepare 1 High Pin on Shift Register
  digitalWrite(data, HIGH);
  digitalWrite(clock, HIGH);
  //delay(1);
  digitalWrite(clock, LOW);
  digitalWrite(data, LOW);
  
  //Scan through 10 pixel rows
  for(int i = 0; i < 10; i++){
    //Red Pixels
    digitalWrite(LED1R, redOn[i][0]);
    digitalWrite(LED2R, redOn[i][1]);
    digitalWrite(LED3R, redOn[i][2]);
    digitalWrite(LED4R, redOn[i][3]);
    
    //Green Pixels
    digitalWrite(LED1G, greenOn[i][0]);
    digitalWrite(LED2G, greenOn[i][1]);
    digitalWrite(LED3G, greenOn[i][2]);
    digitalWrite(LED4G, greenOn[i][3]);
    
    //Blue Pixels
    digitalWrite(LED1B, blueOn[i][0]);
    digitalWrite(LED2B, blueOn[i][1]);
    digitalWrite(LED3B, blueOn[i][2]);
    digitalWrite(LED4B, blueOn[i][3]);
    
    //Display each row for "scanSpeed" milliseconds
    delay(scanSpeed);
    
    //Turn Off All Pixels before Changing Row to prevent light bleed.
    digitalWrite(LED1R, HIGH);
    digitalWrite(LED2R, HIGH);
    digitalWrite(LED3R, HIGH);
    digitalWrite(LED4R, HIGH);
    digitalWrite(LED1G, HIGH);
    digitalWrite(LED2G, HIGH);
    digitalWrite(LED3G, HIGH);
    digitalWrite(LED4G, HIGH);
    digitalWrite(LED1B, HIGH);
    digitalWrite(LED2B, HIGH);
    digitalWrite(LED3B, HIGH);
    digitalWrite(LED4B, HIGH);
    
    //Change Row
    digitalWrite(clock, HIGH);
    digitalWrite(clock, LOW);
  }
}

//Changes a Segment to a numbert
void setSegment(int seg, int num){
  for(int i = 0; i < 7; i++){
    blueOn[segmentDisplay[seg][i][0]][segmentDisplay[seg][i][1]] = digitDisplay[num][i];
  }
}

//Changes Display Symbols
void setSymbol(char symbol, int state){
  switch (symbol) {
    case '$':
      if (state = HIGH) {
        greenOn[dollarSign[0]][dollarSign[1]] = 0;
      }
      else {
        greenOn[dollarSign[0]][dollarSign[1]] = 1;
      }
      break;
    case '.':
      if (state = HIGH) {
        blueOn[decimalPoint[0]][decimalPoint[1]] = 0;
      }
      else {
        blueOn[decimalPoint[0]][decimalPoint[1]] = 1;
      }
      break;
    case 'u':
      if (state = HIGH) {
        greenOn[upArrow[0]][upArrow[1]] = 0;
      }
      else {
        greenOn[upArrow[0]][upArrow[1]] = 1;
      }
      break;
    case 'd':
      if (state = HIGH) {
        redOn[downArrow[0]][downArrow[1]] = 0;
      }
      else {
        redOn[downArrow[0]][downArrow[1]] = 1;
      }
      break;
  }
}
