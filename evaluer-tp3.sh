#!/bin/bash
# evaluer-tp3.sh

IFS=$'\n'

if [ -z $1 ]
then
	correction=inf3135-h2019-tp3.correction
else
	correction=$1
fi
wget -q https://github.com/guyfrancoeur/INF3135_H2019_TP3/raw/master/${correction} -O ${correction}
if [ ! -f inf3135-h2019-tp3.correction ]
then
	echo "erreur fatale, fichier correction inexistent."
    exit 1
fi
for line in `cat ${correction}`
do
   
	lire=`echo $line | cut -d ' ' -f 7-`
	temp=`echo $line | cut -d ' ' -f 2`
	cmd=`echo $lire | awk '$1=$1'`

	eval timeout $temp $cmd &> /dev/null
	code=`echo $?`	

	if [ $code -eq 0 ]
	then
		let i++
		echo "$i : reussi 1 pts"
		((count++))
		if [[ $cmd =~ "inf3135-h2019-tp2.correction" ]]
		then
			rm -f evaluer.sh
			touch evaluer.sh
			tp2=inf3135-h2019-tp2.correction
			for unit in `cat ${tp2}`
			do
				entre=`echo $unit | cut -d ' ' -f 7-`
				cmdline=`echo $entre | awk '$1=$1'`
			    echo $cmdline >> evaluer.sh
			done
			chmod +x evaluer.sh
		fi
	elif [ $code -eq 1 ] && ([[ $cmd =~ "./data/data.txt" ]] || [[ $cmd == "./tp2" ]])
	then
		let i++
		echo "$i : reussi 1 pts"
		((count++))
	elif [ $code -eq 2 ] && [[ $cmd == "./tp2 -c FRAG" ]]
	then
		let i++
		echo "$i : reussi 1 pts"
		((count++))
	elif [ $code -eq 3 ] && [[ $cmd == "./tp2 -c FRAG12345678 -u" ]]
	then
		let i++
		echo "$i : reussi 1 pts"
		((count++))
	elif [ $code -eq 4 ] && [[ $cmd =~ "< ~/depot/data4.err" ]]
	then
		let i++
		echo "$i : reussi 1 pts"
		((count++))
	elif [ $code -eq 5 ] && [[ $cmd =~ "-i ok.txt" ]]
	then
		let i++
		echo "$i : reussi 1 pts"
		((count++))
	elif [ $code -eq 6 ] && [[ $cmd =~ "-o ./ok/ok.txt < ~/depot/data1.in" ]]
	then
		let i++
		echo "$i : reussi 1 pts"
		((count++))
	else
		let i++
		echo "$i : echec"
	fi
done

echo "Note total pour $(cat cp.txt) dans inf3135-h2019-tp3: $count pts"
echo "$(cat cp.txt)	$count"


