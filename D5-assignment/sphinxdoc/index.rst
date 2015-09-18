Gravity simulation
##################

Physics background
==================

Solving the time evolution of a system of point masses
------------------------------------------------------

The state of any mechanical system at a given time :math:`t_0` can be fully described by a state vector of all positions and velocities involved.

.. math::
	
	\vec{s}(t_0) = \left( x_1(t_0), \vphantom{\binom{5}{4}} \ldots, x_i(t_0), \ldots, v_1(t_0), \ldots, v_i(t_0),\ldots \right)

To estimate the state of the system a short time later, at :math:`t_1=t_0+\Delta t`, we can make use of this definition of a derivative:

.. math::
	
	\frac{\text{d}\vec{s}}{\text{d}t}(t_0) \approx \frac{\vec{s}(t_1)-\vec{s}(t_0)}{\Delta t}

In a mechanical system the derivative on the left is a **known** quantity, made of velocities and accelerations, determined by the physics involved:

.. math::

	\frac{\text{d}\vec{s}}{\text{d}t}(t_0) = \left( v_1(t_0), \vphantom{\binom{5}{4}} \ldots, v_i(t_0), \ldots, a_1(t_0), \ldots, a_i(t_0),\ldots \right)


Therefore, we can rearrange for the unknown state :math:`\vec{s}(t_1)`:

.. math::

	\vec{s}(t_1)\approx\vec{s}(t_0)+\frac{\text{d}\vec{s}}{\text{d}t}(t_0)\,\Delta t

This can now be repeated for every following time step. The pre-prepared code ::

	steppers.euler( state, d_dt, dt )

implements this behaviour. Given a starting state vector :file:`state` at :math:`t_0`, a python **function** :file:`d_dt` which implements the derivative and a timestep :file:`dt`, it will return the new state vector at :math:`t_1`. The function :file:`d_dt` here takes a :file:`state` vector and returns the vector of the time derivative of the state.

Gravitational physics reminder
------------------------------

The acceleration of a point mass :math:`m` under gravitational attraction from another mass :math:`M` is

.. math::

	\vec{a} = \frac{1}{m}\,\vec{F} = \frac{1}{m}\,\frac{G\,mM}{{\left|\vec{r}\right|}^3}\vec{r} = \frac{G\,M}{{\left|\vec{r}\right|}^3}\vec{r}

where :math:`\vec{r}` is the vector from :math:`m` to :math:`M`.



Tasks
=====

Task 1 --- Single-body orbit
----------------------------

Simulate and plot the trajectory of a point mass which is gravitationally attracted by a fixed central mass. Choose interesting initial conditions to show a circular, elliptical and hyperbolic orbit.

The plot does not have to be animated.

Task 2 --- Flexible initial conditions
--------------------------------------

Initial conditions should be read interactively from the user, with sensible default values pre-set.

Task 3 --- Two-body system
--------------------------

Allow the position of the central body to vary, too. Plot several interesting binary star systems.

Task 4 --- Three-body system
----------------------------

Introduce a planet into your binary star system.

Task 5 --- User-defined many-body system
----------------------------------------

Make your program flexible enough to deal with an arbitrary number of bodies, 
selectable by the end user through a configuration file.
