// Define which pin we’re using to accept the signal
#define ch1input 14
#define ch2input 16
#define ch3input 17
#define ch4input 20
#define ch5input 22

// We have to declare as volatile as this will be modified
// by the interrupt routine, and read outside of it
volatile uint16_t ch1;
volatile uint16_t ch2;
volatile uint16_t ch3;
volatile uint16_t ch4;
volatile uint16_t ch5;
uint16_t ch1_start;
uint16_t ch2_start;
uint16_t ch3_start;
uint16_t ch4_start;
uint16_t ch5_start;

void setup() {
  
Serial.begin(115200);

pinMode(ch1input, INPUT);
pinMode(ch2input, INPUT);
pinMode(ch3input, INPUT);
pinMode(ch4input, INPUT);
pinMode(ch5input, INPUT);

// Attach an interrupt handler to be called whenever
// the pin changes from LOW to HIGH or vice versa
attachInterrupt(ch1input, RCchannel1, CHANGE);
attachInterrupt(ch2input, RCchannel2, CHANGE);
attachInterrupt(ch3input, RCchannel3, CHANGE);
attachInterrupt(ch4input, RCchannel4, CHANGE);
attachInterrupt(ch5input, RCchannel5, CHANGE);

analogWriteFrequency(1, 250);
analogWriteFrequency(2, 250);
analogWriteFrequency(3, 250);
analogWriteFrequency(4, 250);
analogWriteResolution(12);

while(ch3<2000){
  ch3 = constrain(pulseIn(ch3input, HIGH, 30000), 1000, 2000);
  Serial.println(ch3);
  delay(4);
}
}

void loop() {
// Output the channel value
Serial.print("Channel 1: ");
Serial.print(ch1);
Serial.print("      |      Channel 2: ");
Serial.print(ch2);
Serial.print("      |      Channel 3: ");
Serial.print(ch3);
Serial.print("      |      Channel 4:");
Serial.print(ch4);
Serial.print("      |      Channel 5:");
Serial.println(ch5);


analogWrite(1, constrain(ch3, 1000, 2000));
//analogWrite(2, constrain(ch3, 1000, 2000));
//analogWrite(3, constrain(ch3, 1000, 2000));
//analogWrite(4, constrain(ch3, 1000, 2000));
delay(10);

}

void RCchannel1() {
// If the pin is HIGH, start a timer
if (digitalRead(ch1input) == HIGH) {
ch1_start = micros();
} else {
// The pin is now LOW so output the difference
// between when the timer was started and now
ch1 = (uint16_t) (micros() - ch1_start);
}
}

void RCchannel2() {
// If the pin is HIGH, start a timer
if (digitalRead(ch2input) == HIGH) {
ch2_start = micros();
} else {
// The pin is now LOW so output the difference
// between when the timer was started and now
ch2 = (uint16_t) (micros() - ch2_start);
}
}

void RCchannel3() {
// If the pin is HIGH, start a timer
if (digitalRead(ch3input) == HIGH) {
ch3_start = micros();
} else {
// The pin is now LOW so output the difference
// between when the timer was started and now
ch3 = (uint16_t) (micros() - ch3_start);
}
}

void RCchannel4() {
// If the pin is HIGH, start a timer
if (digitalRead(ch4input) == HIGH) {
ch4_start = micros();
} else {
// The pin is now LOW so output the difference
// between when the timer was started and now
ch4 = (uint16_t) (micros() - ch4_start);
}
}

void RCchannel5() {
// If the pin is HIGH, start a timer
if (digitalRead(ch5input) == HIGH) {
ch5_start = micros();
} else {
// The pin is now LOW so output the difference
// between when the timer was started and now
ch5 = (uint16_t) (micros() - ch5_start);
}
}
