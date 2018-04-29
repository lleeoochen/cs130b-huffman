all: frequencies huffman encode decode

frequencies: compile-frequencies
	cat sample.in | ./frequencies

huffman: compile-huffman
	cat sample.in | ./frequencies | ./huffman

encode: compile-encode
	cat sample.in | ./encode codewords.txt > encoded

decode: compile-decode
	cat encoded | ./decode codewords.txt > decoded

compile-frequencies:
	g++ -std=c++11 -o frequencies frequencies.cpp

compile-huffman:
	g++ -std=c++11 -o huffman huffman.cpp

compile-encode:
	g++ -std=c++11 -o encode encode.cpp

compile-decode:
	g++ -std=c++11 -o decode decode.cpp

clean:
	rm frequencies huffman encode decode encoded decoded codewords.txt
