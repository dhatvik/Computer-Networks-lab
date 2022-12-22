BEGIN {
dcount=0;
rcount=0;
}
{
event=$1;
if(event=="d")
dcount++;
if(event=="r")
rcount++;
}
END{
printf("\nDropped is %d:",dcount);
printf("\nReceived is %d:",rcount);    
}