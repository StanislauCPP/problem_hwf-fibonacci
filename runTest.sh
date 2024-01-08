for i in tests/*.test; do echo $i; cat $i; ./tests/test.out < $i; done
