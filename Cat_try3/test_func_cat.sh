#!/bin/bash
RED='\033[31m'
GREEN='\033[32m'
BLACK='\033[0m'

SUCCESS=0
FAIL=0
COUNTER=0
DIFF_RES=""

declare -a tests=(
"VAR test_case_cat.txt"
)

declare -a extra=(
"-b test_11_cat.txt"
"no_file.txt"
)

testing()
{
    t=$(echo $@ | sed "s/VAR/$var/")
    ./s21_cat $t > test_s21_cat.log
    cat $t > test_sys_cat.log
    DIFF_RES="$(diff -s test_s21_cat.log test_sys_cat.log)"
    (( COUNTER++ ))
    if [ "$DIFF_RES" == "Files test_s21_cat.log and test_sys_cat.log are identical" ]
    then
      (( SUCCESS++ ))
        printf "${RED}$FAIL${BLACK}/${GREEN}$SUCCESS${BLACK}/$COUNTER ${GREEN}success${BLACK} cat $t\n"
    else
      (( FAIL++ ))
        printf "${RED}$FAIL${BLACK}/${GREEN}$SUCCESS${BLACK}/$COUNTER ${RED}fail${BLACK} cat $t\n"
    fi
    rm test_s21_cat.log test_sys_cat.log
}

# специфические тесты
for i in "${extra[@]}"
do
    var="-"
    testing $i
done

# 1 параметр
for var1 in b e n s t v
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        testing $i
    done
done

printf "${RED}FAIL: $FAIL${BLACK}\n"
printf "${GREEN}SUCCESS: $SUCCESS${BLACK}\n"
printf "ALL: $COUNTER"
