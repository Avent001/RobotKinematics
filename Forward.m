clc;
% Define specific numerical values for angles
theta_1 = 0;  % Angles in degrees, change as needed
theta_2 = 16.75;  
theta_3 = 28.62;
theta_4 = 58.93;

% Define specific numerical values for angles
M1 = [cosd(theta_1), -sind(theta_1)*cosd(-90), sind(theta_1)*sind(-90), 0*cosd(theta_1);
      sind(theta_1), cosd(theta_1)*cosd(-90), -cosd(theta_1)*sind(-90), 0*sind(theta_1);
      0, sind(-90), cosd(-90), (4.7);
      0, 0, 0, 1];

M2 = [cosd(-90+theta_2), -sind(-90+theta_2)*cosd(0), sind(-90+theta_2)*sind(0), 5*cosd(-90+theta_2);
      sind(-90+theta_2), cosd(-90+theta_2)*cosd(0), -cosd(-90+theta_2)*sind(0), 5*sind(-90+theta_2);
      0, sind(0), cosd(0), 0;
      0, 0, 0, 1];

M3 = [cosd(theta_3), -sind(theta_3)*cosd(0), sind(theta_3)*sind(0), 5*cosd(theta_3);
      sind(theta_3), cosd(theta_3)*cosd(0), -cosd(theta_3)*sind(0), 5*sind(theta_3);
      0, sind(0), cosd(0), 0;
      0, 0, 0, 1];

M4 = [cosd(theta_4), -sind(theta_4)*cosd(0), sind(theta_4)*sind(0), 5*cosd(theta_4);
      sind(theta_4), cosd(theta_4)*cosd(0), -cosd(theta_4)*sind(0), 5*sind(theta_4);
      0, sind(0), cosd(0), 0;
      0, 0, 0, 1];

% Lakukan perkalian matriks
result=M1*M2*M3*M4;

disp('result')
disp(result)
disp('M1')
disp(M1)
disp('M2')
disp(M2)
disp('M3')
disp(M3)
disp('M4')