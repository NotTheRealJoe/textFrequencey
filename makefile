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
wordFrequencyTester: wordFrequencyTester.o wordFrequency.o wordCount.o wordCountTester.in
	gcc wordFrequencyTester.o wordFrequency.o wordCount.o -o wordFrequencyTester
wordFrequencyTester.o: wordFrequencyTester.c
	gcc wordFrequencyTester.c -c
