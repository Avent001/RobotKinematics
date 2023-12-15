
% Tambahkan bagian ini untuk meminta input dari pengguna

x_input = input('Masukkan nilai x: ');
y_input = input('Masukkan nilai y: ');
z_input = input('Masukkan nilai z: ');

% Gantilah nilai x, y, dan z dengan nilai yang dimasukkan oleh pengguna
targetX = x_input;
targetY = y_input;
targetZ = z_input;

% Hitung theta_1 (rotasi pada sumbu z)


% ...

theta_1 = atan2d(targetY, targetX);
de1 = targetZ - 4.7;
sa1 = targetX - 5;
mi1 = sqrt(de1^2 + sa1^2);

theta_3 = 180 - acosd((5^2 + 5^2 - mi1^2) / (2 * 5 * 5));
mi4 = sqrt(de1^2 + 5^2);
theta_4 = atand(de1 / 5);
theta_2 = 90 - (atand(de1 / sa1) + acosd((mi1^2 + 5^2 - 5^2) / (2 * mi1 * 5)));

jointAngles = [theta_1, theta_2, theta_3, theta_4];

% ...

% Hasilkan array sudut sendi



% Tampilkan hasil
disp('Joint Angles:');
disp(jointAngles);
