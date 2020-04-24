# GTX-3080-Linux-Joke-Driver

![image](https://github.com/danlove99/GTX-3080-Linux-Joke-Driver/blob/master/gtx3080.png)

# About 

A joke lkm that shows gtx-3080 in the devices folder. The driver produces text to the system log when written to or read from. 

# How to
Setup
`make`
`sudo insmod GTX-3080.ko`
`cd /dev`
`sudo mknod -m 666 GTX-3080 240 0`
Check system log
`tail -f /var/log/syslog`
Write to the driver
`echo 'message' > /dev/GTX-3080`
Read from driver
`cat /dev/GTX-3080`
