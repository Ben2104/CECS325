# This file is called sortrace.sh
# It must have execute privilege set to run
# run it as a background task like this: (see the 2 lines below)
#----------------------------------------------------------------------------------------------
# $ rm sortrace.log # start with fresh log file
# $ ./sortrace.sh >> sortrace.log & # this may take an hour
#----------------------------------------------------------------------------------------------
#
echo Generating 1000000 random numbers
sleep 1
./generate 1000000 -100000 100000 # Generate 1000000 random numbers between -100000 and 100000
sleep 1
echo Starting system sort
sleep 1
{ time sort -n numbers.dat > systemsort.out; } 2>&1>> sortrace.log # Sort numbers.dat using system sort and log the time
sleep 1
echo Starting mysort
sleep 1
{ time ./mysort numbers.dat sort.out; } 2>&1>> sortrace.log # Sort numbers.dat using mysort and log the time
sleep 1
wc sort.out # Count lines, words, and characters in sort.out
sort -c -n sort.out 2>> sortrace.log # Verify that sort.out is sorted and log any errors