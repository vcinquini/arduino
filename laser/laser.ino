

int laser_pin = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(laser_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(laser_pin, HIGH);
  delay(1000);

  digitalWrite(laser_pin, LOW);
  delay(1000);
}
