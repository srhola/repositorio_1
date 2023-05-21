The file rcvxplane.cpp receives data from X-plane via udp, you have to define a port in x-plane to communicate with this script.   


You must add -lws2_32 when compiling with g++. 
Example:
g++.exe -o rcvxplane.exe rcvxplane.cpp -lws2_32

To execute on command line run 
rcvxplane.exe 49000
