import numpy as np
import matplotlib.pyplot as plt
from steppers import *

M = 2.*10**33          # M sun in g

x_init = 1.5 * 10**13  # earth - sun distance in cm
y_init = 0

vx = 0
vy = (6.67 * 10**-8 * M / x_init)**.5

x = np.array(x_init)
y = np.array(y_init)

state = np.array([x_init, y_init, vx, vy])

dt = 43200        # timestep in seconds (half of day)
nstep = 365 * 2   # one year
i = 0

print("\n\tstarting integration...\n")

while(i < nstep):

    # euler(state, d_dt, dt, M)
    rk4(state, d_dt, dt, M)
    x = np.append(x, state[0])
    y = np.append(y, state[1])

    i += 1

print("\tintegration done!")
plt.figure()
plt.plot(x, y)
plt.show()
