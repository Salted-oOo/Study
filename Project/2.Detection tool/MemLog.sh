# @Author: salted_fish
# @Date:   2018-01-12 14:42:03
# @Last Modified by:   salted_fish
# @Last Modified time: 2018-01-16 19:29:06

#!/bin/bash
source ./PiHealth.conf
DyAver=$1       #动态平均值   $1 

if [[ x"$DyAver" = x ]]; then
	exit 1
fi

if [[ -f "$memory" ]]; then
	echo "log file does not exist."
	touch $Memlog
fi

MemValue=(`free -m | head -n 2 | tail -n 1 | awk '{printf("%s %s\n",$2,$3) }'`)            #获取内存总量和剩余容量

#MemAvaPrec=$[ $MemValue[1] * 100 / $MemValue[0] ]           #剩余百分比  整数

MemAvaPrec=`echo "scale=1;${MemValue[1]}*100/${MemValue[0]}" | bc`   #剩余百分比  小数

NowAver=`echo "scale=1;0.2*${MemAvaPrec}+0.8*${DyAver}" | bc`    #新的动态值

NowTime=`date +"%Y-%m-%d__%H:%M:%S"`                         #时间

#printf "%-20s " "abc"
echo "$NowTime ${MemValue[0]}M ${MemAvaPrec}% ${NowAver}%" >> $Memlog
