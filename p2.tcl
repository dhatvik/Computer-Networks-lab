set ns [new Simulator]
set nf [open p2.nam w]
$ns namtrace-all $nf
set nd [open p2.tr w]
$ns trace-all $nd

proc finish { } {
global ns nf nd
$ns flush-trace
close $nf
close $nd
exec nam p2.nam &
exit 0    
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns simplex-link $n2 $n3 1Mb 10ms DropTail
$ns simplex-link $n3 $n2 1Mb 10ms DropTail
$ns queue-limit $n0 $n2 10
$ns simplex-link-op $n0 $n2 queuePos 0.5

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0
$ns connect $tcp0 $sink0
$tcp0 set fid_ 1

set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ftp0 set type ftp

set tcp1 [new Agent/TCP]
$ns attach-agent $n1 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n3 $sink1
$ns connect $tcp1 $sink1
$tcp1 set fid_ 2

set telnet [new Application/Telnet]
$telnet attach-agent $tcp1
$telnet set type Telnet

$ns at 0.5 "$ftp0 start"
$ns at 0.5 "$telnet start"
$ns at 24.5 "$ftp0 stop"
$ns at 24.5 "$telnet stop"
$ns at 25.0 "finish"
$ns run


