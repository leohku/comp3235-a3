#!/bin/bash
# NOTE: Run this in the root directory of the project

tests_passed=0
num_of_tests=$(ls -1 ./tests/*.sc | wc -l | xargs)
test_names=(
    "1-mergesort"
    "2-quicksort"
    "3-binarysearch"
    "4-binomial"
    "5-lis"
    "6-primes"
    )
expected_outputs=(
    "1 2 3 4 5 6 7 8 "
    "1 2 3 4 5 6 7 8 "
    "23 found at index 5"
    "252"
    "2"
    "Find first n prime numbers (max 100): The first 10 prime numbers are: 2 3 5 7 11 13 17 19 23 29 "
    )

num_tests=${#test_names[@]}

for ((i = 0; i < num_tests; i++)); do
    test_name=${test_names[i]}
    expected_output=${expected_outputs[i]}
    output=$(echo 10 | ./nas/nas2 <(./src/c6c ./tests/$test_name.sc))

    if [ "$output" = "$expected_output" ]; then
        echo "Test $test_name: Output matches expected output: $output"
        tests_passed=$((tests_passed + 1))
    else
        echo "Test $test_name: Output does not match expected output!"
        echo "Expected output: $expected_output"
        echo "Actual output: $output"
    fi
done

echo
echo "$tests_passed/$num_of_tests tests passed"
