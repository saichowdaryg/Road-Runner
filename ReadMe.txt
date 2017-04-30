
Codes Required from Code Repo

road_run.py
mrbs.c
superio.c
superio.h

Compile Motor Code:

gcc mrbs.c superio.c superio.h -o MotorRunning
sudo ./MotorRunning

No other programme must be using port no. 9999.

Run Python Code:

python road_run.py
