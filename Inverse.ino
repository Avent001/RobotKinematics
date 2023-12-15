#include <Servo.h>
#include <math.h>

Servo baseServo;
Servo armServo1;
Servo armServo2;
Servo armServo3;

void setup() {
  Serial.begin(9600);
  baseServo.attach(10);
  armServo1.attach(3);
  armServo2.attach(5);
  armServo3.attach(6);
}

void loop() {
  // Meminta input dari pengguna melalui Serial Monitor
  double x_input = 10;
  double y_input = 0;
  double z_input = 13;

  // Hitung inverse kinematics
  double theta_1 = atan2(y_input, x_input) * 180.0 / PI;
  double de1 = z_input - 4.7;
  double sa1 = x_input - 5;
  double mi1 = sqrt(pow(de1, 2) + pow(sa1, 2));

  double theta_3 = 180.0 - acos((pow(5.0, 2) + pow(5.0, 2) - pow(mi1, 2)) / (2.0 * 5.0 * 5.0)) * 180.0 / PI;
  double mi4 = sqrt(pow(de1, 2) + pow(5, 2));
  double theta_4 = atan(de1 / 5) * 180.0 / PI;
  double theta_2 = 90.0 - (atan(de1 / sa1) * 180.0 / PI + acos((pow(mi1, 2) + pow(5, 2) - pow(5, 2)) / (2.0 * mi1 * 5.0)) * 180.0 / PI);

  // Pindahkan servo ke posisi yang dihasilkan
  baseServo.write(int(theta_1));
  armServo1.write(int(theta_2));
  armServo2.write(int(theta_3));
  armServo3.write(int(theta_4));

  // Tampilkan hasil
  Serial.println("Joint Angles:");
  Serial.print("Theta_1: "); Serial.println(theta_1);
  Serial.print("Theta_2: "); Serial.println(theta_2);
  Serial.print("Theta_3: "); Serial.println(theta_3);
  Serial.print("Theta_4: "); Serial.println(theta_4);

  delay(1000);  // Delay untuk memberikan waktu servo mencapai posisi
}
