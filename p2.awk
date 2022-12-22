BEGIN {
cudp=0;
ctcp=0;    
}
{
pkt=$5;
if(pkt=="tcp")
ctcp++;
if(pkt=="cbr")
cudp++;
}
END {
printf("UDP Recieved is %d",cudp);
printf("TCP Recieved is %d",ctcp);
}