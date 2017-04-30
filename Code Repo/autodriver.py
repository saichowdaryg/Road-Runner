import socket
import sys
sys.path.append("/usr/local/lib/python2.7/site-packages/")
import cv2
import numpy as np

s = socket.socket()
host='127.0.0.1'
port=9999

try:
 s.connect((host,port))
except:
 s.close()
 exit()

def senddata(a):
 s.send(a)

#stat video capture using webcam
cap = cv2.VideoCapture(0)
while(1):
# Take each frame
 _, frame = cap.read()
# Convert to gray
 gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
#apply binary threshold to get binary image
 ret,thresh1 = cv2.threshold(gray,150,255,cv2.THRESH_BINARY)
#start processing
#look for left side white strip
 suml=0
 yl=0
 cl=0
 for i in range (6,319,3):
        suml = thresh1[239,i-1]+thresh1[239,i-2]+thresh1[239,i-3]+thresh1[239,i-4]+thresh1[239,i-5]+thresh1[239,i]+thresh1[239,i+1]+thresh1[239,i+2]+thresh1[239,i+3]+thresh1[239,i+4]+thresh1[239,i+5]
        if suml>=245 and suml<=250:
               yl=yl+i
               cl=cl+1
 if cl==0:
       l=0
 if cl!=0:
       l=yl/cl    
#print l            
#look for right side white strip
 sumr=0
 yr=0
 cr=0
 for i in range (319,633,3):
        sumr = thresh1[239,i-1]+thresh1[239,i-2]+thresh1[239,i-3]+thresh1[239,i-4]+thresh1[239,i-5]+thresh1[239,i]+thresh1[239,i+1]+thresh1[239,i+2]+thresh1[239,i+3]+thresh1[239,i+4]+thresh1[239,i+5]
        if sumr>=245 and sumr<=250:
               yr=yr+i
               cr=cr+1
 if cr==0:
       r=639
 if cr!=0:
       r=yr/cr
#print r    
#estimate the center point coordinate 
 path=(r+l)/2
 print path
#show the thresholded frame 
 cv2.imshow('binary',thresh1)
#show the actual frame
 cv2.imshow('frame',frame)
#exit on hitting 'escape' key
 k = cv2.waitKey(5) & 0xFF
 if k == 27:
       break
cv2.destroyAllWindows()
