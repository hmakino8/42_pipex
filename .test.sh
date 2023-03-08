#!/usr/local/bin/bash

i=1
echo -e "\n\e[31m =============== ERROR TEST ===============\n\e[m"

#test1
TEST="./pipex"
echo -e "\e[31m [test$((i++)): $TEST]\e[m"
$TEST

#test2
TEST="./pipex a b c d e"
echo -e "\n\e[31m [test$((i++)): $TEST]\e[m"
$TEST

echo -e "\n\e[31m =============== FILE CREATION TEST ===============\e[m"

#test3
TEST="./pipex nosuchfile nosuchcmd1 nosuchcmd2 testfile1"
echo -e "\n\e[31m [test$((i++)): $TEST]\e[m"
$TEST

if [ -f testfile1 ]; then
	echo -e "\e[32mtestfile is created!\e[m"
else
	echo -e "\e[31mtestfile is NOT created\e[m"
fi

echo -e "\n\e[36m => should behave in bash as:\e[m"
< nosuchfile nosuchcmd1 | nosuchcmd2 > testfile1-2

#test4
echo -e "\n\e[33m creating a manfile for linux pipe ... \e[m"
man pipe > manfile
TEST="./pipex manfile cat nosuchcmd testfile2"
echo -e "\n\e[31m [test$((i++)): $TEST]\e[m"
$TEST

if [ -f testfile2 ]; then
	echo -e "\e[32mtestfile is created!\e[m"
else
	echo -e "\e[31mtestfile is NOT created\e[m"
fi

echo -e "\n\e[36m => should behave in bash as:\e[m"
< manfile cat | nosuchcmd > testfile2-2

#test5
TEST="./pipex manfile nosuchcmd cat testfile3"
echo -e "\n\e[31m [test$((i++)): $TEST]\e[m"
$TEST

if [ -f testfile3 ]; then
	echo -e "\e[32mtestfile is created!\e[m"
else
	echo -e "\e[31mtestfile is NOT created\e[m"
fi

echo -e "\n\e[36m => should behave in bash as:\e[m"
< manfile nosuchcmd | cat > testfile3-2

echo -e "\n\e[31m =============== DIFF TEST ===============\e[m"

#test6
echo -e "\n\e[31m [test$((i++)): "./pipex manfile \"ls -l\" \"wc -l\" testfile1"]\e[m"
 ./pipex manfile "ls -l" "wc -l" testfile1

 < manfile ls -l | wc -l > testfile1-2
echo -e "\e[36m => diff testfile1 testfile1-2\e[m"
diff testfile1 testfile1-2

#test7
echo -e "\n\e[31m [test$((i++)): "./pipex manfile \"grep a1\" \"wc -w\" testfile1"]\e[m"
 ./pipex manfile "grep a1" "wc -w" testfile1

 < manfile grep a1 | wc -w > testfile1-2
echo -e "\e[36m => diff testfile1 testfile1-2\e[m"
diff testfile1 testfile1-2

#test8
echo -e "\n\e[31m [test$((i++)): "./pipex manfile cat \"grep PIPE\" testfile1"]\e[m"
./pipex manfile cat "grep PIPE" testfile1

< manfile cat | grep PIPE > testfile1-2
echo -e "\e[36m => diff testfile1 testfile1-2\e[m"
diff testfile1 testfile1-2

#test9
echo -e "\n\e[31m [test$((i++)): "./pipex manfile \"grep PIPE\" \"wc -c\" testfile1"]\e[m"
./pipex manfile "grep PIPE" "wc -c" testfile1

< manfile grep PIPE | wc -c > testfile1-2
echo -e "\e[36m => diff testfile1 testfile1-2\e[m"
diff testfile1 testfile1-2

#test10
echo -e "\n\e[31m [test$((i++)): "./pipex manfile \"grep PIPE\" \"awk '{print \$2}'\" testfile1"]\e[m"
./pipex manfile "grep PIPE" "awk '{print \$2}'" testfile1

< manfile grep PIPE | awk '{print $2}' > testfile1-2
echo -e "\e[36m => diff testfile1 testfile1-2\e[m"
diff testfile1 testfile1-2

#test11
echo -e "\n\e[31m [test$((i++)): "./pipex \"\" \"ls\" \"cat\" \"\""]\e[m"
./pipex "" "ls" "cat" ""

echo -e "\n\e[36m => should behave in bash as:\e[m"
< "" ls | cat > ""

#test12
echo -e "\n\e[31m [test$((i++)): "./pipex \"\" \"\" \"\" \"\""]\e[m"
./pipex "" "" "" ""

echo -e "\n\e[36m => should behave in bash as:\e[m"
< "" "" | "" > ""

#test13
echo -e "\n\e[33m creating a testfile with 100 million 'a' ... \e[m"
ruby -e 'puts "a" * 100000000' > testfile

echo -e "\n\e[31m [test$((i++)): "./pipex testfile \"grep a\" \"wc -c\" testfile1"]\e[m"
./pipex testfile "grep a" "wc -c'" testfile1

< testfile grep a | wc -c > testfile1-2
echo -e "\e[36m => diff testfile1 testfile1-2\e[m\n"
diff testfile1 testfile1-2

#test14
echo -e "\e[33m unset PATH ... \e[m"
TMP=$PATH
unset PATH

echo -e "\n\e[31m [test$((i++)): "./pipex testfile \"grep a\" \"wc -c\" testfile1"]\e[m"
./pipex testfile "grep a" "wc -c'" testfile1

echo -e "\n\e[36m => should behave in bash as:\e[m"
< testfile grep a | wc -c > testfile1-2
PATH=$TMP

rm pipex manfile *testfile* 2&> /dev/null
