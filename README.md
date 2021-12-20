# Routh-hurwitz-stability-criteria-calulator

This the code for calculation of rh stability criteria


sample output:
//1
Enter the highest degree of characteristic equation(less than or equal to 7):6
Enter the coefficient of the characteristic equation upto degree 6
s^0: 3
s^1: 4
s^2: 5
s^3: -3
s^4: -5
s^5: 1
s^6: 2
THE ROUTH'S ARRAY IS
-------------------------------------------------------------
s^6 : 2.0000            -5.0000         5.0000          3.0000
s^5 : 1.0000            -3.0000         4.0000
s^4 : 1.0000            -3.0000         3.0000
s^3 : 4.0000            -6.0000         0.0000
s^2 : -1.5000           3.0000          0.0000
s^1 : 2.0000            0.0000          0.0000
s^0 : 3.0000            0.0000          0.0000
-------------------------------------------------------------
The system is unstable

//2
Enter the highest degree of characteristic equation(less than or equal to 7):4
Enter the coefficient of the characteristic equation upto degree 4
s^0: 3
s^1: 1
s^2: 2
s^3: 2
s^4: 4
THE ROUTH'S ARRAY IS
-------------------------------------------------------------
s^4 : 4.0000            2.0000          3.0000
s^3 : 2.0000            1.0000
s^2 : 6.0000            1.0000
s^1 : 0.6667            0.0000
s^0 : 1.0000            0.0000
s^-1 : 0.0000           0.0000
s^-2 : 0.0000           0.0000
-------------------------------------------------------------
Here derivative fuction is used to convert zero into values in s^4
The system is marginally stable
