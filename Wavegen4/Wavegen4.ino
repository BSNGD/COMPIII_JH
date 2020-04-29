
// Array to hold hex values
int currentEntry[32]= {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
                        0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF};
int currentEntrySize = 32;

// timer variable to hold period/32
double timer = 1;

// variables to cycle trough the different waves
int button_state = 0;
int lastbutton_state = 0;
int wave_state = 0;
unsigned long lastDebounceTime = millis();
unsigned long debounceDelay = 250;

//declaration of helping functions
void SawTooth();
void SquareWave();
void TriangleWave();
void SineWave();
void PinCounter();

void setup() {
  Serial.begin(9600);
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(A0, INPUT); //input potentiometer for frequency
  pinMode(5, INPUT); //input pushbutton toggle waves
  pinMode(13, OUTPUT);
}

void loop() {
  // reading button and cyling waves with switch statement 
  button_state = digitalRead(5);
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (button_state != lastbutton_state){
      if (button_state == HIGH){
        wave_state += 1;
        switch(wave_state){
          case 0: SquareWave(); Serial.print("Square \n"); break;
          case 1: SawTooth(); Serial.print("SawTooth \n"); break;
          case 2: TriangleWave(); Serial.print("Triangle \n"); break;
          case 3: SineWave(); Serial.print("Sine \n"); break;
          case 4: WhiteWave(); Serial.print("White Noise \n"); break;
        }
        if (wave_state > 4){
          wave_state = -1;
        }
      }
      
    }
    lastbutton_state = button_state;
  }
  //Adjusting timer at loop() will allow the wave to be updated after the total period is over
  timer = map(analogRead(A0), 0 , 1023, 1 , 1500);
  PinCounter();
}

// Waves Functions
void SquareWave(){
  memset(currentEntry, 0, sizeof(currentEntry));
  int SquareWave[32] = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
                        0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF,0xF};
  for (int i = 0; i < 32; ++i){
    currentEntry[i] = SquareWave[i];
  }
}
void SawTooth(){
  memset(currentEntry, 0, sizeof(currentEntry));
  int SawTooth[32] = {0x0,0x0,0x1,0x1,0x2,0x2,0x3,0x3,0x4,0x4,0x5,0x5,0x6,0x6,0x7,0x7,
                      0x8,0x8,0x9,0x9,0xA,0xA,0xB,0xB,0XC,0XC,0XD,0XD,0XE,0XE,0XF,0XF};
  for (int i = 0; i < 32; ++i){
    currentEntry[i] = SawTooth[i];
  }
}
void TriangleWave(){
  memset(currentEntry, 0, sizeof(currentEntry));
  int Triangle[32] = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF,
                      0xE,0xD,0xC,0xB,0xA,0x9,0x8,0x7,0X6,0X5,0X4,0X3,0X2,0X1,0X0,0X0};
  for (int i = 0; i < 32; ++i){
    currentEntry[i] = Triangle[i];
  }
}
void SineWave(){
  memset(currentEntry, 0, sizeof(currentEntry));
  int Sine[32] = {0x7,0x9,0xb,0xc,0xe,0xf,0xf,0x10,0x10,0x10,0xf,0xf,0xe,0xc,0xb,0xa,
                  0x8,0x6,0x5,0x4,0x2,0x1,0x1,0x0,0x0,0x0,0x1,0x1,0x2,0x4,0x5,0x6};
  for (int i = 0; i < 32; ++i){
    currentEntry[i] = Sine[i];
  }
}

void WhiteWave(){
  memset(currentEntry, 0, sizeof(currentEntry));
  int White[32];
  for (int i = 0; i < 32; ++i){
    White[i] = random(0x0,0xF);
    currentEntry[i] = White[i];
  }
}
void PinCounter(){
  for(int i = 0; i < 32; ++i){
    if(i == 32){
      i = 0;
    }
    switch(currentEntry[i]){
      case 0x0: digitalWriteFast(3,LOW); digitalWriteFast(2,LOW);digitalWriteFast(1,LOW);digitalWriteFast(0,LOW); break;
      case 0x1: digitalWriteFast(3,LOW); digitalWriteFast(2,LOW);digitalWriteFast(1,LOW);digitalWriteFast(0,HIGH); break;
      case 0x2: digitalWriteFast(3,LOW); digitalWriteFast(2,LOW);digitalWriteFast(1,HIGH);digitalWriteFast(0,LOW); break;
      case 0x3: digitalWriteFast(3,LOW); digitalWriteFast(2,LOW);digitalWriteFast(1,HIGH);digitalWriteFast(0,HIGH); break;
      case 0x4: digitalWriteFast(3,LOW); digitalWriteFast(2,HIGH);digitalWriteFast(1,LOW);digitalWriteFast(0,LOW); break;
      case 0x5: digitalWriteFast(3,LOW); digitalWriteFast(2,HIGH);digitalWriteFast(1,LOW);digitalWriteFast(0,HIGH);break;
      case 0x6: digitalWriteFast(3,LOW); digitalWriteFast(2,HIGH);digitalWriteFast(1,HIGH);digitalWriteFast(0,LOW); break;
      case 0x7: digitalWriteFast(3,LOW); digitalWriteFast(2,HIGH);digitalWriteFast(1,HIGH);digitalWriteFast(0,HIGH); break;
      case 0x8: digitalWriteFast(3,HIGH); digitalWriteFast(2,LOW);digitalWriteFast(1,LOW);digitalWriteFast(0,LOW); break;
      case 0x9: digitalWriteFast(3,HIGH); digitalWriteFast(2,LOW);digitalWriteFast(1,LOW);digitalWriteFast(0,HIGH); break;
      case 0xA: digitalWriteFast(3,HIGH); digitalWriteFast(2,LOW);digitalWriteFast(1,HIGH);digitalWriteFast(0,LOW); break;
      case 0xB: digitalWriteFast(3,HIGH); digitalWriteFast(2,LOW);digitalWriteFast(1,HIGH);digitalWriteFast(0,HIGH); break;
      case 0xC: digitalWriteFast(3,HIGH); digitalWriteFast(2,HIGH);digitalWriteFast(1,LOW);digitalWriteFast(0,LOW); break;
      case 0xD: digitalWriteFast(3,HIGH); digitalWriteFast(2,HIGH);digitalWriteFast(1,LOW);digitalWriteFast(0,HIGH); break;
      case 0xE: digitalWriteFast(3,HIGH); digitalWriteFast(2,HIGH);digitalWriteFast(1,HIGH);digitalWriteFast(0,LOW); break;
      case 0xF: digitalWriteFast(3,HIGH); digitalWriteFast(2,HIGH);digitalWriteFast(1,HIGH);digitalWriteFast(0,HIGH); break;     
    }
    delayMicroseconds(timer); 
  }
}
