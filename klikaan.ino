char CH3_ON[]  = "221322132122232221223222132132131";
char CH3_OFF[] = "221322132122232221223222132222131";

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);
  sendCommand(CH3_ON);
  delay(200);
  sendCommand(CH3_OFF);
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

