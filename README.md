# GTX-3080-Linux-Joke-Driver

![image](https://github.com/danlove99/GTX-3080-Linux-Joke-Driver/blob/master/gtx3080.png)

# About 

A joke lkm that shows gtx-3080 in the devices folder. The driver produces text to the system log when written to or read from. 

# How to
Setup<br/>
`make`<br/>
`sudo insmod GTX-3080.ko`<br/>
`cd /dev`<br/>
`sudo mknod -m 666 GTX-3080 c 240 0`<br/>
Check system log<br/>
`tail -f /var/log/syslog`<br/>
Write to the driver<br/>
`echo 'message' > /dev/GTX-3080`<br/>
Read from driver<br/>
`cat /dev/GTX-3080`<br/>
Delete from /dev<br/>
`rm GTX-3080`<br/>
Remove from kernel<br/>
`sudo rmmod GTX-3080`<br/>
