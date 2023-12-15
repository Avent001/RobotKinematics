#include <Servo.h>

#define baseServoPin 10
#define armServo1Pin 3
#define armServo2Pin 5
#define armServo3Pin 6

Servo baseServo;
Servo armServo1;
Servo armServo2;
Servo armServo3;

int sudut_awal = 0;

int baseAngle = 0;
int arm1Angle = 90;
int arm2Angle = 90;
int arm3Angle = 90;

void moveToPos(int base, int arm1, int arm2, int arm3) {
  double baseAngle = 1.06 * base + (-0.571);
  double arm1Angle = 1.01 * arm1 + 83;
  double arm2Angle = 1.21 * arm2 + 70;
  double arm3Angle = 1.08 * arm3 + 119;

  moveServo(baseServo, int(baseAngle));
  moveServo(armServo1, int(arm1Angle));
  moveServo(armServo2, int(arm2Angle));
  moveServo(armServo3, int(arm3Angle));

  writePosSerial(int(baseAngle), int(arm1Angle), int(arm2Angle), int(arm3Angle));
}

void moveServo(Servo servo, int targetAngle) {
  int currentAngle = servo.read();
  while (currentAngle != targetAngle) {
    if (currentAngle < targetAngle) {
      currentAngle++;
    } else {
      currentAngle--;
    }
    servo.write(currentAngle);
    delay(10);
  }
}

void writePosSerial(int baseAngle, int arm1Angle, int arm2Angle, int arm3Angle) {
  Serial.println((String)baseAngle + ", " + arm1Angle + ", " + arm2Angle + ", " + arm3Angle);
}

void setup() {
  Serial.begin(9600);
  baseServo.attach(baseServoPin);
  armServo1.attach(armServo1Pin);
  armServo2.attach(armServo2Pin);
  armServo3.attach(armServo3Pin);
}

void loop() {
  if (Serial.available() > 0) {
    int servobase = Serial.parseInt();
    int link1 = Serial.parseInt();
    int link2 = Serial.parseInt();
    int link3 = Serial.parseInt();

    moveToPos(servobase, link1, link2, link3);
  }
}
