char CH1_ON[]  = "221322132122232221223222132132212";
char CH1_OFF[] = "221322132122232221223222132222212";

char CH2_ON[]  = "221322132122232221223222132132222";
char CH2_OFF[] = "221322132122232221223222132222222";

char CH3_ON[]  = "221322132122232221223222132132131";
char CH3_OFF[] = "221322132122232221223222132222131";

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
  Serial1.begin(9600);
}

void parseChar(char c) {
  switch(c) {
      case '1':
        sendCommand(CH1_ON);
        break;
      case '2':
        sendCommand(CH2_ON);
        break;
      case '3':
        sendCommand(CH3_ON);
        break;
      case '4':
        sendCommand(CH1_OFF);
        break;
      case '5':
        sendCommand(CH2_OFF);
        break;
      case '6':
        sendCommand(CH3_OFF);
        break;
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(2000);
  //sendCommand(CH1_ON);
  //delay(2000);
  //sendCommand(CH1_OFF);
  if (Serial.available() > 0) {
    char c = Serial.read();
    parseChar(c);
  }
  if (Serial1.available() > 0) {
    char c = Serial1.read();
    parseChar(c);
  }
}

void sendCommand(char* command){
  for (int i=0; i<5; i++){
    runSequence(command, 33);
    delay(10);
  }
}

void runSequence(char* sequence, int len){
  sendData(1);
  delayMicroseconds(1382);
  for (int i=0; i<len; i++){
    sendData(int(sequence[i])-48);
  }
}

void sendData(int number) {
  for (int i=0; i<number; i++){
    PORTC |= (1 << 7);
    delayMicroseconds(225);
    PORTC &= ~(1 << 7);
    delayMicroseconds(380);
  }
  delayMicroseconds(940);
}

