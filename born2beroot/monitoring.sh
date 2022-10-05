#!/bin/bash
freedisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{free += $2} END {print free}')
useddisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{used += $3} END {print used}')
percdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{free += $2} {used += $3} END {printf ("%d%%", used*100/free)}')


wall "  #Architecture: $(uname -a)
        #CPU physical : $(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
        #vCPU : $(grep '^processor' /proc/cpuinfo | wc -l)
        #Memory Usage: $(free -m | awk '$1 == "Mem:" {printf ("%d/%dMB (%.2f%%)", $3, $2, $3*100/$2)}')
        #Disk Usage: $useddisk/${freedisk}GB ($percdisk)
        #CPU load: $(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%", $1 + $3)}')
        #Last boot: $(who -b | awk '{print $3" "$4}')
        #LVM use: $(if [ $(lsblk | grep 'lvm' | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
        #Connections TCP : $(ss -neopt state established | wc -l) ESTABLISHED
        #User log: $(users | wc -w)
        #Network: IP $(hostname -I) ($(ip link show | grep 'ether' | awk '{print $2}'))
        #Sudo : $(journalctl _COMM=sudo | grep COMMAND | wc -l) cmd"
