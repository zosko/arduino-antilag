int RELAY_1 = 4;
int RELAY_2 = 5;
int RELAY_3 = 6;
int RELAY_4 = 7;

int BUTTON_CALIBRATE = 2;
int BUTTON_START_FIRE = 3;

int MAX_RPM = 12;
int START_TO_FIRE = 0;
int CURRENT_RPM = 0;
int FIRE_TIME = 200;

void activateRelay(int relay) {
  digitalWrite(relay, HIGH);
}
void deactivateRelay(int relay) {
  digitalWrite(relay, LOW);
}
bool calibrateMaxVoltage() {
  return digitalRead(BUTTON_CALIBRATE);
}
bool startFire() {
  return digitalRead(BUTTON_START_FIRE);
}
int readCurrentRPM() {
  return map(analogRead(A0), 0, MAX_RPM, 0, 12); //1023 UNO 4095 DUE
}
int readRPMTriggerFire() {
  return map(analogRead(A1), 0, MAX_RPM, 0, 12); //1023 UNO 4095 DUE
}
int readFireTime() {
  return map(analogRead(A2), 0, MAX_RPM, 0, 100); //1023 UNO 4095 DUE
}
void logger() {
  Serial.print("[CURRENT_RPM]: "); Serial.print(CURRENT_RPM);
  Serial.print(" [FIRE_TIME]: "); Serial.print(FIRE_TIME);
  Serial.print(" [START_TO_FIRE]: "); Serial.print(START_TO_FIRE);
  Serial.print(" [MAX_RPM]: "); Serial.print(MAX_RPM);
  Serial.print(" [CALIBRATE VOLTAGE]: "); Serial.print(calibrateMaxVoltage());
  Serial.print(" [START FIRE]: "); Serial.print(startFire());

  Serial.println();
}
void makeFire(int ms) {
  activateRelay(RELAY_1);
  delay(ms);
  deactivateRelay(RELAY_1);

  activateRelay(RELAY_2);
  delay(ms);
  deactivateRelay(RELAY_2);

  activateRelay(RELAY_3);
  delay(ms);
  deactivateRelay(RELAY_3);

  activateRelay(RELAY_4);
  delay(ms);
  deactivateRelay(RELAY_4);
}
void setup()  {
  Serial.begin(9600);

  analogReadResolution(12);
  
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  pinMode(BUTTON_CALIBRATE, INPUT);
  pinMode(BUTTON_START_FIRE, INPUT);
}
void loop()  {

  makeFire(FIRE_TIME);  
//  Serial.println(FIRE_TIME);
  
//  CURRENT_RPM = readCurrentRPM();
//  FIRE_TIME = readFireTime();
//  START_TO_FIRE = readRPMTriggerFire();
//
//  logger();
//
//  if (calibrateMaxVoltage()) {
//    MAX_RPM = analogRead(A0);
//  }
//  else {
//    if (CURRENT_RPM > START_TO_FIRE && startFire()) {
//      while (startFire()) {
//        makeFire(FIRE_TIME);
//      }
//    }
//  }
}
