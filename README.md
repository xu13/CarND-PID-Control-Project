# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Reflection

### Effect of P, I, D components

* Proportional term: it produces an output that is proportional to the cross track error at time t. For a given cross track error, a large proportional gain will result in a large change in the output steering angle, and vice versa. If the proportional gain is set too high, the car will oscillate around the center of lane and result in an unstable behavior. On the other hand, if the proportional gain is set too low, the output steering angle will not be large enough to correct the cross track error, and result in an unresponsive behavior.

* Integral term: it produces an output that take into account the integral of the cross track error up to time t. This integral term accelerates the car moving towards the center of lane. It also eliminates the effect of systematic bias. However, since the integral term responds to accumulated errors, it can cause the system to overshoot.

* Derivative term: it produces an output that depends on the rate of change in the cross track error. It provides additional steer when the car moves away from the center of lane, and counter steers as the car moves towards the center of lane. This will help the car to smoothly steer towards the center of lane thus preventing the overshoot caused by the proportional term.

### Parameter tuning

The final parameters are tuned manually for a throttle of 70% which corresponds to vehicle driving around 75mph in the simulator. As the reference speed is high, the simulation needs to be run on the fastest graphics setting as the higher resolution leads to very control frequency which in turn causes the controller to be unstable.

First, I set the integral gain Ki and derivative gain Kd to zero, increase the proportional gain Kp until the car is oscillating around the center of lane when driving straight. Since the speed is high, we want small gain such that a small change in CTE won't result in a large steering angle. Then I increase the derivative gain Kd to smooth out the oscillation and it can smoothly pass the whole track. In the simulator, there is no systematic error, so even without the integral term, the car is able to drive around the track. Finally I increase Ki to help with the corners. This is because when the car is making a shape turn, the CTE quickly builds up, and integral term plays a role to push it back to the center. However, when the car goes back to the center, it needs to stay on the other side of the center for a while for the integral term to vanish. That's why I also saturate the integrated error to alleviate this problem.

Here is my result, click on the image to see the video on YouTube:

<a href="https://youtu.be/l2x5U3mv-LA" target="_blank">
<img src="http://img.youtube.com/vi/l2x5U3mv-LA/0.jpg"
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" />
</a>

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).
