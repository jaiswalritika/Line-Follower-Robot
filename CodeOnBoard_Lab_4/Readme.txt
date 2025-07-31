Link for youtube video:- https://youtu.be/n76jOY1SbKU

Steps to run:- 

In the main directory,  ./integrate.sh line_follower
Upload code using arduino ide and start the robot.

Description of states: 
BlackForward: we move to this state after our switch_condition is true. This state means our bot is moving in the forward direction on the blackline.
BlackStop, BlackRight, BlackLeft, BlackDriftRight, BlackDriftLeft are the states where we stop on the black line, we move right, we move left, we drift right and we drift left on the Black line respectively, according to our conditions.

ObstacleAvoidance is the state when our front IR sensors detect a obstacle, we move in that state, we pause for some time, we take a right turn from RightTurn1, then we move forward until our left IR sensor senses the obstacle, then we move a bit forward in the Move2 state, then we take a left turn from LeftTurn1 state. Then we move forward until our left IR sensor senses the object on its left. Then we move a little bit forward for our bot to have enough space to take the left turn. Then we take a left turn from LeftTurn2 state to face the blackline again, then we move forward until we detect the blackline again, then we turn right to move on the blackline again for our final course.

