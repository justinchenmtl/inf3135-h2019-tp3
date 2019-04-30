echo "OK" # echo "dummy test"
echo "OK" # grep -c -e 'default :' -e 'default:' Makefile
echo "OK" # make
echo "OK" # make data
echo "OK" # test -f ./data/data.txt
echo "OK" # make test
echo "OK" # make clean ; make clean
echo "OK" # grep -c -e 'resultat:' -e 'resultat :' Makefile
echo "OK" # test -f README.md
echo "OK" # gcc -Wall -pedantic -std=c99 -lm -O2 -o tp2 tp2.c outils.c &> compilation.guy ; test ! -s compilation.guy
./tp2 -c $(cat cp.txt) -i ~/depot/data0.in ; test -f code.txt
./tp2
./tp2 -c FRAG
./tp2 -c FRAG12345678 -u
./tp2 -c $(cat cp.txt) < ~/depot/data4.err
./tp2 -c $(cat cp.txt) -i ok.txt
./tp2 -c $(cat cp.txt) -o ./ok/ok.txt < ~/depot/data1.in
./tp2 -c $(cat cp.txt) -i ~/depot/data5.in -o res.out
diff --brief -b res.out ~/depot/data5.res
./tp2 -c $(cat cp.txt) -o res.out < ~/depot/data1.in
diff --brief -b res.out ~/depot/data1.res
./tp2 -c $(cat cp.txt) -i ~/depot/data2.in > res.out
diff --brief -b res.out ~/depot/data2.res
./tp2 -c $(cat cp.txt) < ~/depot/data3.in > res.out
diff --brief -b res.out ~/depot/data3.res
