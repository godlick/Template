DIRS = lib intro file signal pipe msgqueue shmem semaphore thread network

all:
	#进入文件夹执行make操作
	@for i in $(DIRS); do \
		(cd $$i && echo "making $$i" && $(MAKE) ) || exit 1; \
	done
	

clean:
	#进入文件夹执行make clean 操作
	@for i in $(DIRS); do \
		(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
	done
