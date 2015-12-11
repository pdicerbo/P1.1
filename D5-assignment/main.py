import numpy as np
import matplotlib.pyplot as plt
from steppers import *


print("\n\tChoose your initial condition.")
print("\tIf you put a negative value for the central Mass, \n\tthe program will load automatically the values of the sun - earth system.\n\n")

M_start = float(input("\tCentral Mass value (g): "))

M_start = -1.

if M_start >= 0.:
    M = M_start
    x_init = float(input("\tx coordinate of the second mass (cm): "))
    y_init = float(input("\ty coordinate of the second mass (cm): "))
    vx     = float(input("\tvelocity along x axis of the second mass (cm / s): "))
    vy     = float(input("\tvelocity along y axis of the second mass (cm / s): "))
    dt     = float(input("\ttime step (s): "))
    nstep  = float(input("\tnumber of time steps: "))
else:
    print("\tChoosing values for the sun - earth system")
    M = 2.*10**33          # M sun in g
    x_init = 1.5 * 10**13  # earth - sun distance in cm
    y_init = 0    
    vx = 0
    vy = (6.67 * 10**-8 * M / x_init)**.5
    dt = 43200        # timestep in seconds (half of day)
    nstep = 365 * 2   # one year (to obtain a circular orbit)
    
x = np.array(x_init)
y = np.array(y_init)

x_sun = np.array(0.)
y_sun = np.array(0.)

# state = np.array([x_init, y_init, vx, vy])
state = np.array([x_init, y_init, vx, vy, 0., 0., 0., 0.])
Mass = np.array([5.97 * 10.**27, M])

# print(multiple_d_dt(state, Mass))
# rk4(state, multiple_d_dt, dt, Mass)
# print(state)

i = 0

print("\n\tstarting integration...\n")

while(i < nstep):

    # euler(state, d_dt, dt, M)
    # rk4(state, d_dt, dt, M)
    rk4(state, multiple_d_dt, dt, Mass)
    x = np.append(x, state[0])
    y = np.append(y, state[1])
    x_sun = np.append(x_sun, state[4])
    y_sun = np.append(y_sun, state[5])
    i += 1

print("\tintegration done!")
plt.figure()
plt.plot(x, y)
plt.plot(x_sun, y_sun)
plt.title("Orbit")
plt.xlabel("x (cm)")
plt.ylabel("y (cm)")
plt.show()
