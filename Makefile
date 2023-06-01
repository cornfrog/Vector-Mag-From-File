all:
	@gcc vec-mag-fio.c -o vec-mag-fio -lm
	@mv vec-mag-fio bin
	@echo MAKE Success: use \'make run\' next

run:
	@./bin/vec-mag-fio

clean:
	@rm bin/vec-mag-fio
	@echo MAKE CLEAN Succes: use \'make\' to get exe back
