main:filter.o randomizer.o
	gcc filter.o randomizer.o -lm -o main
filter.o:filter.c
	gcc filter.c -c
randomizer.o:randomizer.c
	gcc randomizer.c -c
wordFrequency.o: wordFrequency.c
	gcc wordFrequency.c -c
hashTable.o: hashTable.c
	gcc -D_GNU_SOURCE hashTable.c -c
wordCountTester: wordCountTester.o wordCount.o wordCountTester.h wordCountTester.in
	gcc wordCountTester.o wordCount.o -o wordCountTester
wordCount.o: wordCount.c
	gcc wordCount.c -c
wordFrequencyTester: wordFrequencyTester.o wordFrequency.o wordCount.o joeBST.o wordCountTester.in
	gcc wordFrequencyTester.o wordFrequency.o wordCount.o joeBST.o -o wordFrequencyTester
wordFrequencyTester.o: wordFrequencyTester.c
	gcc wordFrequencyTester.c -c
hashTableTest: hashTableTest.c
	gcc -D_GNU_SOURCE hashTableTest.c -o hashTableTest
joeBSTTester.o: joeBSTTester.c
	gcc joeBSTTester.c -c
joeBST.o: joeBST.c
	gcc joeBST.c -c
joeBSTTester: joeBSTTester.o joeBST.o
	gcc joeBST.o joeBSTTester.o -o joeBSTTester
compare.o: compare.c
	gcc compare.c -c
compare: joeBST.o compare.o
	gcc joeBST.o compare.o -o compare
clean:
	rm -f *.o hashTableTest wordFrequencyTester wordCountTester joeBSTTester main
