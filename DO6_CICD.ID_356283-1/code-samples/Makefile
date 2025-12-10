SHELL := /bin/bash

all: main
	
main:
	gcc main.c -o DO

tests: main
	diff <(./DO 1) <(echo -e "Learning to Linux")	
	diff <(./DO 2) <(echo -e "Learning to work with Network")	
	diff <(./DO 3) <(echo -e "Learning to Monitoring")	
	diff <(./DO 4) <(echo -e "Learning to extra Monitoring")	
	diff <(./DO 5) <(echo -e "Learning to Docker")	
	diff <(./DO 6) <(echo -e "Learning to CI/CD")	
	diff <(./DO ) <(echo -e "Bad number of arguments!")	
	diff <(./DO k) <(echo -e "Bad number!")	
	
clean:
	rm -rf *.o DO
