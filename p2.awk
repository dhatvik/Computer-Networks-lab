BEGIN {
ntcp1=0;
ntcp2=0;
tcp1size=0;
tcp2size=0;
t0taltcp1=0;
totaltcp2=0;    
}
{
event=$1;
pkttype=$5;
pktSize=$6;
fromnode=$9;
$tonode=$10;
if(event=="r" && pkttype="tcp" && fromnode="0.0" && tonode="3.0")
{
ntcp1++;
tcp1size=pktSize;
}
if(event=="r" && pkttype="tcp" && fromnode="1.0" && tonode="3.1")
{
ntcp2++;
tcp2size=pktSize;
}
}
END {
totaltcp1=ntcp1*tcp1size*8;
totaltcp2=ntcp2*tcp2size*8;
throughput1 =totaltcp1/24;
throughput2 =totaltcp2/24;
printf("\nThroughput of ftp is %d",throughput1)    
printf("\nThroughput of telnet is %d",throughput2)    
}