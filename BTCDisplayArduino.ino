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

byte redOn[10][4] =   {{1,1,1,1},
                       {0,1,1,1},
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
  Serial.begin(9600);
  
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
  
  digitalWrite(data, LOW);
  
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
}

void loop() {
  digitalWrite(data, HIGH);
  digitalWrite(clock, HIGH);

  delay(1);

  digitalWrite(clock, LOW);
  digitalWrite(data, LOW);
  
  
  for(int i = 0; i < 10; i++){
    digitalWrite(LED1R, redOn[i][0]);
    digitalWrite(LED2R, redOn[i][1]);
    digitalWrite(LED3R, redOn[i][2]);
    digitalWrite(LED4R, redOn[i][3]);
    
    delay(1);
    
    digitalWrite(LED1R, HIGH);
    digitalWrite(LED2R, HIGH);
    digitalWrite(LED3R, HIGH);
    digitalWrite(LED4R, HIGH);
    
    digitalWrite(clock, HIGH);
    digitalWrite(clock, LOW);
  }



    

}
