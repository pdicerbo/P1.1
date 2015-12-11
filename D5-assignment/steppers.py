"""
Collection of first-order ODE steppers.

First-order differential equations can be solved numerically by
stepping through the solution in discrete increments of the
independent variable (here referred to as time 't'). Several methods
with varying convergence behaviours are implemented.

The function argument 'd_dt' is assumed to be a function which 
takes a state vector (np.array) s and returns ds/dt.
"""

import numpy as np

def euler(state, d_dt, dt, M):
    """
    Euler stepper.

    Evolve the system 'state' by the time derivative function 'd_dt'
    over the timestep dt, using the Euler method.
    """
    f = d_dt(state, M)
    state += f * dt
    

def rk4(state, d_dt, dt, M):
    """
    4th-order Runge-Kutta stepper.

    Evolve the system 'state' by the time derivative function 'd_dt'
    over the timestep dt, using Runge-Kutta 4th-order.
    """
    x0 = state
    f1 = d_dt(x0, M)
    x1 = x0 + f1 * dt/2.
    f2 = d_dt(x1, M)
    x2 = x0 + f2 * dt/2.
    f3 = d_dt(x2, M)
    x3 = x0 + f3 * dt
    f4 = d_dt(x3, M)
    f = ( f1 + 2*f2 + 2*f3 + f4 )/6.
    state += f * dt

def d_dt(state, M):
    """
    Derivative function.

    Perform the calculation of the derivative of the status
    """

    G = 6.67 * 10**-8 # Gravitational constant in cgs
    
    x = state[0]
    y = state[1]
    r = (x**2 + y**2)**.5

    ret = np.array([state[2], state[3], - G * M * x / r**3, - G * M * y / r**3])
    
    return ret
