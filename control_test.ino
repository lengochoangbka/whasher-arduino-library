#define VALVE_HOT_WATER 7
#define VALVE_COOL_WATER 8
#define VALVE_CYCLIC 9
#define PUMP 6

void sixty_degrees() {
  digitalWrite(PUMP , LOW);
  digitalWrite(VALVE_CYCLIC , HIGH);
  digitalWrite(VALVE_COOL_WATER, LOW);
  digitalWrite(VALVE_HOT_WATER , LOW);
  digitalWrite(VALVE_COOL_WATER, LOW);
  delay(1500);
  digitalWrite(VALVE_HOT_WATER , LOW);
  digitalWrite(VALVE_COOL_WATER, HIGH);
  delay(1000);
}
void only_hot() {
  digitalWrite(PUMP , LOW);
  digitalWrite(VALVE_HOT_WATER , LOW);
  digitalWrite(VALVE_COOL_WATER , HIGH);
  digitalWrite(VALVE_CYCLIC , HIGH);
}
void only_cool()
{
  digitalWrite(PUMP , LOW);
  digitalWrite(VALVE_CYCLIC , HIGH);
  digitalWrite(VALVE_COOL_WATER , LOW);
  digitalWrite( VALVE_HOT_WATER, HIGH);
}
void cyclic() {
  digitalWrite(PUMP , LOW);
  digitalWrite(VALVE_HOT_WATER , HIGH);
  digitalWrite(VALVE_CYCLIC , LOW);
  digitalWrite(VALVE_COOL_WATER , HIGH);
}

void stop_all() {
  digitalWrite(PUMP , HIGH);
  digitalWrite(VALVE_HOT_WATER , HIGH);
  digitalWrite(VALVE_CYCLIC , HIGH);
  digitalWrite(VALVE_COOL_WATER , HIGH);
}
void setup() {
  Serial.begin(9600);
  pinMode(VALVE_HOT_WATER, OUTPUT);
  pinMode(VALVE_COOL_WATER, OUTPUT);
  pinMode(VALVE_CYCLIC, OUTPUT);
  pinMode(PUMP, OUTPUT);
}
void loop() {
  for (int i = 0; i < 720; i++) {
    sixty_degrees();
    Serial.println(i);
  }
  stop_all();
  delay(10000);
  stop_all();
  for (int i = 0; i < 600; i++) {
    only_hot();
    delay(1000);
  }
  for (int i = 0; i < 600; i++) {
    only_cool();
    delay(1000);
  }
  for (int i = 0; i < 600; i++) {
    cyclic();
    delay(1000);
  }
}
