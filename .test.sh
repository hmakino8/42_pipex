#!/usr/local/bin/bash

make re
i=1

echo -e "\e[31m =============== ERROR TEST ===============\n\e[m"

TEST="./pipex"
echo -e "\e[31m [test$((i++)): $TEST]\e[m"
$TEST

TEST="./pipex a b c d e"
echo -e "\n\e[31m [test$((i++)): $TEST]\e[m"
$TEST

echo -e "\n\e[31m =============== FILE CREATION TEST ===============\e[m"

TEST="./pipex nosuchfile nosuchcmd1 nosuchcmd2 testfile1"
echo -e "\n\e[31m [test$((i++)): $TEST]\e[m"
$TEST

if [ -f testfile1 ]; then
	echo -e "\e[32mtestfile is created!\e[m"
else
	echo -e "\e[31mtestfile is NOT created\e[m"
fi

echo -e "\n\e[31m => should behave in bash as:\e[m"
< nosuchfile nosuchcmd1 | nosuchcmd2 > testfile1-2

man pipe > manfile
TEST="./pipex manfile cat nosuchcmd testfile2"
echo -e "\n\e[31m [test$((i++)): $TEST]\e[m"
$TEST

if [ -f testfile2 ]; then
	echo -e "\e[32mtestfile is created!\e[m"
else
	echo -e "\e[31mtestfile is NOT created\e[m"
fi

echo -e "\n\e[31m => should behave in bash as:\e[m"
< manfile cat | nosuchcmd > testfile2-2

TEST="./pipex manfile nosuchcmd cat testfile3"
echo -e "\n\e[31m [test$((i++)): $TEST]\e[m"
$TEST

if [ -f testfile3 ]; then
	echo -e "\e[32mtestfile is created!\e[m"
else
	echo -e "\e[31mtestfile is NOT created\e[m"
fi

echo -e "\n\e[31m => should behave in bash as:\e[m"
< manfile nosuchcmd | cat > testfile3-2

echo -e "\n\e[31m =============== DIFF TEST ===============\e[m\n"
man pipe > manfile

echo -e "\n\e[31m [test$((i++)): "./pipex manfile cat \"grep PIPE\" testfile1"]\e[m"
./pipex manfile cat "grep PIPE" testfile1

< manfile cat | grep PIPE > testfile1-2
echo -e "\n\e[31m => diff testfile1 testfile1-2\e[m"
diff testfile1 testfile1-2

echo -e "\n\e[31m [test$((i++)): "./pipex manfile \"grep PIPE\" \"wc -c\" testfile1"]\e[m"
./pipex manfile "grep PIPE" "wc -c" testfile1

< manfile grep PIPE | wc -c > testfile1-2
echo -e "\n\e[31m => diff testfile1 testfile1-2\e[m"
diff testfile1 testfile1-2

echo -e "\n\e[31m [test$((i++)): "./pipex manfile \"grep PIPE\" \"awk '{print \$2}'\" testfile1"]\e[m"
./pipex manfile "grep PIPE" "awk '{print \$2}'" testfile1

< manfile grep PIPE | awk '{print $2}' > testfile1-2
echo -e "\n\e[31m => diff testfile1 testfile1-2\e[m"
diff testfile1 testfile1-2

ruby -e 'puts "a" * 100000000' > testfile

echo -e "\n\e[31m [test$((i++)): "./pipex testfile \"grep a\" \"wc -c\" testfile1"]\e[m"
./pipex testfile "grep a" "wc -c'" testfile1

< testfile grep a | wc -c > testfile1-2
echo -e "\n\e[31m => diff testfile1 testfile1-2\e[m"
diff testfile1 testfile1-2

rm d pipex manfile *testfile* 2&> /dev/null
make fclean > /dev/null
