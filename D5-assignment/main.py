import numpy as np
import matplotlib.pyplot as plt
from steppers import *


print("\n\tChoose your initial condition.")
print("\tIf you put a negative value for the central Mass, \n\tthe program will load automatically the values of the sun - earth system.\n\n")

M_start = float(input("\tCentral Mass value (g): "))

if M_start >= 0.:
    M = M_start
    x_init = float(input("\tx coordinate of the second mass (cm): "))
    y_init = float(input("\ty coordinate of the second mass (cm): "))
    vx     = float(input("\tvelocity along x axis of the second mass (cm / s): "))
    vy     = float(input("\tvelocity along y axis of the second mass (cm / s): "))
    dt     = float(input("\ttime step (s): "))
    nstep  = float(input("\tnumber of time steps: "))
else:
    print("\n\tChoosing values for the sun - earth - jupiter system")
    M = 2.*10**33          # M sun in g
    M_earth = 5.97 * 10.**27
    M_jup = 1.898 * 10**30
    Mass = np.array([M_earth, M, M_jup])
    # Mass = np.array([M_earth, M])
    x_init = 1.5 * 10**13 # earth - sun distance in cm
    y_init = 0.    
    vx = 0.
    vy = (6.67 * 10**-8 * M / x_init)**.5

    x_jup_init = 0.
    y_jup_init = 7.79 * 10.**13
    vx_jup = (6.67 * 10**-8 * M / y_jup_init)**.5
    vy_jup = 0.
    
    dt = 43200        # timestep in seconds (half of day)
    nstep = 365 * 2 * 10 # one year * 10 (to see also jupiter's orbit)

# arrays for plot 
x = np.array(x_init)
y = np.array(y_init)
x_jup = np.array(x_jup_init)
y_jup = np.array(y_jup_init)

# state = np.array([x_init, y_init, vx, vy])
# state = np.array([x_init, y_init, vx, vy, 0., 0., 0., 0.])
state = np.array([x_init, y_init, vx, vy, 0., 0., 0., 0., x_jup_init, y_jup_init, vx_jup, vy_jup])

i = 0

print("\n\tstarting integration...\n")

while(i < nstep):

    # euler(state, d_dt, dt, M)
    # rk4(state, d_dt, dt, M)
    rk4(state, multiple_d_dt, dt, Mass)
    x = np.append(x, state[0])
    y = np.append(y, state[1])
    x_jup = np.append(x_jup, state[8])
    y_jup = np.append(y_jup, state[9])
    # x_moon_plot = np.append(x_moon_plot, state[4])
    # y_moon_plot = np.append(y_moon_plot, state[5])
    i += 1

print("\tintegration done!")
plt.figure()
plt.plot(x, y)
plt.plot(x_jup, y_jup)
plt.title("Final Orbit")
plt.xlabel("x (cm)")
plt.ylabel("y (cm)")
plt.show()
